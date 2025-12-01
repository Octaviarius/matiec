project(stage4_iec LANGUAGES C CXX)

add_library(${PROJECT_NAME} STATIC
	generate_iec.cc
    ../stage4.cc
)
target_include_directories(${PROJECT_NAME} PUBLIC
    "."
)