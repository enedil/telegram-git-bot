cmake_minimum_required(VERSION 3.5)
if ("${SEASTAR_TYPE}" STREQUAL "")
    message(STATUS "setting seastar type to release")
    set(SEASTAR_TYPE "release")
endif ()

add_compile_options(-g -Wall -Wextra)

set(SEASTAR_BUILD_DIR "${SEASTAR_DIR}/build/${SEASTAR_TYPE}")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${SEASTAR_BUILD_DIR}" "${SEASTAR_BUILD_DIR}/_cooking/installed")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SEASTAR_DIR}/cmake")

project(TelegramGit)
find_package(Seastar QUIET)

function (seastar_generate_swagger)
  set (one_value_args TARGET VAR IN_FILE OUT_DIR)
  cmake_parse_arguments (args "" "${one_value_args}" "" ${ARGN})
  get_filename_component (in_file_name ${args_IN_FILE} NAME)
  set (generator ${Seastar_SOURCE_DIR}/scripts/seastar-json2code.py)
  set (header_out ${args_OUT_DIR}/${in_file_name}.hh)
  set (source_out ${args_OUT_DIR}/${in_file_name}.cc)

  add_custom_command (
    DEPENDS
      ${args_IN_FILE}
      ${generator}
    OUTPUT ${header_out} ${source_out}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${args_OUT_DIR}
    COMMAND ${generator} --create-cc -f ${args_IN_FILE} -o ${header_out})

  add_custom_target (${args_TARGET}
    DEPENDS
      ${header_out}
      ${source_out})

  set (${args_VAR} ${header_out} ${source_out} PARENT_SCOPE)
endfunction ()


seastar_generate_swagger (
  TARGET app_httpd_swagger
  VAR app_httpd_swagger_files
  IN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/demo.json
  OUT_DIR ${CMAKE_CURRENT_BINARY_DIR})



add_executable("tgbot" "tgbot.cc")
add_executable("httpd" "main.cc")
target_link_libraries("tgbot" Seastar::seastar)
target_link_libraries("httpd" Seastar::seastar)
