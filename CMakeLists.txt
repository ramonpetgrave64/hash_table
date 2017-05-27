cmake_minimum_required(VERSION 3.6)
project(hash_table)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp hashtable.h hashtable.template bst.h bst.template hash_bucket.h linked_list.template linked_list.h hash_bucket.template)
add_executable(hash_table ${SOURCE_FILES})