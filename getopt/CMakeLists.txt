project(getopt)

add_library(${PROJECT_NAME} STATIC
    getopt.c
)
target_include_directories(${PROJECT_NAME} PUBLIC
    "."
)
target_compile_definitions(${PROJECT_NAME} PUBLIC "STATIC_GETOPT")