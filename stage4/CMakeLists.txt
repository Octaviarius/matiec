project(stage4 LANGUAGES C CXX)

add_library(${PROJECT_NAME} STATIC
	stage4.cc
)
target_include_directories(${PROJECT_NAME} PUBLIC
	"."
)

add_subdirectory(generate_c)
add_subdirectory(generate_iec)