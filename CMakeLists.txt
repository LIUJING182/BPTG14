cmake_minimum_required(VERSION 3.21)
project(TDSC_DT_BGV)

set(CMAKE_CXX_STANDARD 17)

add_executable(TDSC_DT_BGV main.cpp Eval_DT.h)

target_link_libraries(TDSC_DT_BGV libgmp.so libhelib.so /usr/local/lib/libntl.so libpthread.a libflint.so)