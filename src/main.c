#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>
#include <lvgl.h>


int main(void) {
    printk("\n--- Project 6: CHERI Image Renderer ---\n");

    const struct device *display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
    if (!device_is_ready(display_dev)) {
        printk("Display not ready!\n");
        return 0;
    }

    lv_obj_t * title = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_color(title, lv_color_white(), 0);
    lv_label_set_text(title, "CHERI DOG GRAPHICS");
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 0);

    LV_IMG_DECLARE(dog_sprite);
    lv_obj_t * img = lv_img_create(lv_scr_act());
    lv_img_set_src(img, &dog_sprite);
    lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);

    char info_text[128];
    snprintf(info_text, sizeof(info_text), "Image Buffer: %d bytes", dog_sprite.data_size);

    lv_obj_t * info = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_color(info, lv_color_white(), 0);
    lv_label_set_text(info, info_text);
    lv_obj_align(info, LV_ALIGN_TOP_MID, 0, 50);

    display_blanking_off(display_dev);

    while (1) {
        lv_timer_handler();
        k_sleep(K_MSEC(10));
    }
    return 0;
}