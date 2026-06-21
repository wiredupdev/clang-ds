cmake_minimum_required(VERSION 4.2.2)

project(CDataStructure VERSION 1.0 LANGUAGES C)

add_library(${PROJECT_NAME}
        src/Stack.c
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

set_target_properties(${PROJECT_NAME} PROPERTIES C_VISIBILITY_PRESET hidden)

enable_testing()

add_executable(CDataStructureTests
    tests/StackTest.c
)

target_link_libraries(CDataStructureTests PRIVATE ${PROJECT_NAME})

add_test(NAME CDataStructureTest COMMAND CDataStructureTests)
