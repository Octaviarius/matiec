project(absyntax LANGUAGES C CXX)

add_library(${PROJECT_NAME} STATIC
    absyntax.cc
    visitor.cc
)
target_include_directories(${PROJECT_NAME} PUBLIC
    "."
)