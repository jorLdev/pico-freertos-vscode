cmake_minimum_required(VERSION 3.24.2)

# Pull in PICO SDK (must be before project)
include(pico_sdk_import.cmake)

project(blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_EXAMPLE_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()

add_executable(blink
            main.c
            )
# Pull in our pic_stdlib which pulls in commonly.?.?
target_link_libraries(blink 
        pico_stdlib              # for core functionality
        pico_cyw43_arch_none     # we need Wifi to access the GPIO, but we don't need anything else
        freertos
        )

# create map/bin/hex files etx.
pico_add_extra_outputs(blink)

add_subdirectory(freertos)

