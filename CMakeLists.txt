cmake_minimum_required(VERSION 3.16)
set(CMAKE_TOOLCHAIN_FILE "toolchain.cmake")
project("LearnC51")
SET(CMAKE_FIND_ROOT_PATH /usr/share/sdcc)

function(ihx_to_hex bin)
    add_custom_command(TARGET ${bin} POST_BUILD COMMAND packihx ${bin}.ihx > ${bin}.hex)
    add_custom_command(TARGET ${bin} POST_BUILD COMMAND pwd)
endfunction(ihx_to_hex)

include_directories("include" /usr/share/sdcc/include ./include)
add_executable(${PROJECT_NAME} include/c52/regx52.h
        include/utils/delay.h include/utils/delay.c
        include/lcd/LCD1602.c include/lcd/LCD1602.h
        include/key/key.c include/key/key.h
        src/main.c include/timer/time.c include/timer/time.h)
ihx_to_hex(${PROJECT_NAME})
