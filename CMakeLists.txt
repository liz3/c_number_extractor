cmake_minimum_required(VERSION 3.12)
project(phone_extractor C)

set(CMAKE_C_STANDARD 99)

add_executable(phone_extractor main.c http/http_utils.c http/http_utils.h regex_lib/re.c regex_lib/re.h)

target_link_libraries(phone_extractor curl)