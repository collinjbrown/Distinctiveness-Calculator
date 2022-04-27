# CMakeList.txt : CMake project for a Distinctiveness Calculator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (distinctiveness-calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(BASE_SRCS
    main.cpp
    )

# Add source to this project's executable.
add_executable (distinctiveness-calculator ${BASE_SRCS})

add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_LIST_DIR}/copy-assets.cmake
)

add_dependencies(distinctiveness-calculator copy_assets)

if(NOT DEFINED CMAKE_SUPPRESS_DEVELOPER_WARNINGS)
     set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE INTERNAL "No dev warnings")
endif()

set_target_properties(distinctiveness-calculator PROPERTIES CXX_EXTENSIONS OFF)
