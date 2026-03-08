cmake_minimum_required(VERSION 3.20)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(project_6_rasteriser_image)

target_sources(app PRIVATE src/main.c src/dog.c)
