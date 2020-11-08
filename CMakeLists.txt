cmake_minimum_required( VERSION 3.5)
project(preprocessForKeywordsRecommendation)
set(SOURCES 
      src/main.cc
      src/configure.cc
      src/dictProducer.cc
)
add_executable( ${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)

# Include the boost headers
target_include_directories( ${PROJECT_NAME}
    PRIVATE ${Boost_INCLUDE_DIRS}
)

# link against the boost libraries
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
      #sub::cppjieba
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