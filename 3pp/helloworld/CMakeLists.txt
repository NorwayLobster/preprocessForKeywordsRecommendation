cmake_minimum_required(VERSION 3.5)
project(helloworld)
add_library(${PROJECT_NAME} SHARED src/helloworld.cc)
add_library(sub::helloworld ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib) 
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION include) 