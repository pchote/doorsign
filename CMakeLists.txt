cmake_minimum_required(VERSION 3.12)

set(NAME doorsign)
set(PICO_SDK_PATH "~/src/pico-sdk")
set(PIMORONI_PICO_PATH "~/src/pimoroni-pico")

include(pico_sdk_import.cmake)
include(pimoroni_pico_import.cmake)
project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${NAME} main.cpp)

pico_set_program_name(${NAME} "doorsign")
pico_set_program_version(${NAME} "1.0")
pico_enable_stdio_uart(${NAME} 0)
pico_enable_stdio_usb(${NAME} 1)

include(libraries/badger2040/badger2040)

target_link_libraries(${NAME} badger2040)

pico_add_extra_outputs(${NAME})

