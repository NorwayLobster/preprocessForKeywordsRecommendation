cmake_minimum_required( VERSION 3.5)
project(preprocessForKeywordsRecommendation)
set(SOURCES 
      src/configure.cc
      src/main.cc
      ...
)
add_executable( ${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${PROJECT_NAME}
      boost::filesystem 
      sub::cppjieba
)



if( CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT )
  message(STATUS "Setting default CMAKE_INSTALL_PREFIX path to ${CMAKE_BINARY_DIR}/install")
  set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE STRING "The path to use for make install" FORCE)
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION bin) 
# how to install sub library, install(TARGETS ${} DESTINATION bin) 
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION include) 
install(FILES ${PROJECT_SOURCE_DIR}/config/conf.dat DESTINATION etc) 
####Install