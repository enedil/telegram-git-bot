cmake_minimum_required(VERSION 3.5)
if ("${SEASTAR_TYPE}" STREQUAL "")
    message(STATUS "setting seastar type to release")
    set(SEASTAR_TYPE "release")
endif ()

set(SEASTAR_BUILD_DIR "${SEASTAR_DIR}/build/${SEASTAR_TYPE}")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${SEASTAR_BUILD_DIR}" "${SEASTAR_BUILD_DIR}/_cooking/installed")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SEASTAR_DIR}/cmake")

project(TelegramGit)
set(CMAKE_CXX_STANDARD 20)

find_package(Seastar QUIET)

add_executable("tgbot" "tgbot.cc")
target_link_libraries("tgbot" Seastar::seastar)
