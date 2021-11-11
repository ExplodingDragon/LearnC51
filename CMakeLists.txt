cmake_minimum_required(VERSION 3.16)
set(CMAKE_TOOLCHAIN_FILE "toolchain.cmake")
project("LearnC51")
SET(CMAKE_FIND_ROOT_PATH /usr/share/sdcc)

function(ihx_to_hex bin)
    add_custom_command(TARGET ${bin} POST_BUILD COMMAND packihx ${bin}.ihx > ${bin}.hex)
    add_custom_command( TARGET ${bin} POST_BUILD COMMAND pwd)
endfunction(ihx_to_hex)

include_directories("include" /usr/share/sdcc/include)
add_executable(${PROJECT_NAME} src/main.c src/delay.h src/delay.c)
ihx_to_hex(${PROJECT_NAME})
