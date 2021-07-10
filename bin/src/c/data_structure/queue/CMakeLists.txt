cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(queue VERSION 1.0.0 LANGUAGES C)
add_library(queue SHARED queue.c queue.def)
add_executable(queue_exec queue.c)

set_target_properties(queue PROPERTIES
  PUBLIC_HEADER queue.h
  VERSION ${PROJECT_VERSION}
  SOVERSION 1
  OUTPUT_NAME "data_struct_queue"
  XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "Hex_Identity_ID_Goes_Here"
)
