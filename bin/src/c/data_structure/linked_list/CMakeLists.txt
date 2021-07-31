cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(linked_list VERSION 1.0.0 LANGUAGES C)
add_library(linked_list SHARED linked_list.c linked_list.def)
add_executable(linked_list_exc linked_list.c)

set_target_properties(linked_list PROPERTIES
  PUBLIC_HEADER linked_list.h
  VERSION ${PROJECT_VERSION}
  SOVERSION 1
  OUTPUT_NAME "data_struct_linked_list"
  XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "Hex_Identity_ID_Goes_Here"
)
