project(stage4_c LANGUAGES C CXX)

add_library(${PROJECT_NAME} STATIC
	 generate_c.cc
)
target_include_directories(${PROJECT_NAME} PUBLIC
    "."
)
target_link_libraries(${PROJECT_NAME} PUBLIC stage4)