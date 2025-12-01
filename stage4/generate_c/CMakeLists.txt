project(stage4_c LANGUAGES C CXX)

add_library(${PROJECT_NAME} STATIC
	generate_c.cc
    ../stage4.cc
)
target_include_directories(${PROJECT_NAME} PUBLIC
    "."
    "../"
)