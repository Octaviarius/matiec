project(stage4_iec LANGUAGES C CXX)

add_library(${PROJECT_NAME} STATIC
	 generate_iec.cc
)
target_include_directories(${PROJECT_NAME} PUBLIC
    "."
)
target_link_libraries(${PROJECT_NAME} PUBLIC stage4)