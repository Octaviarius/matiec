project(stage1_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Найдём flex/bison
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

bison_target(stage1_2_bison iec_bison.yy iec_bison.cc DEFINES_FILE iec_bison.hh COMPILE_FLAGS -d)
flex_target(stage1_2_flex iec_flex.ll iec_flex.cc COMPILE_FLAGS "--warn -o")

add_library(${PROJECT_NAME} STATIC
    ${BISON_stage1_2_bison_OUTPUTS}
    ${FLEX_stage1_2_flex_OUTPUTS}
    create_enumtype_conversion_functions.cc
    stage1_2.cc
)
target_compile_definitions(${PROJECT_NAME} PRIVATE
    DEFAULT_LIBDIR="lib"
    YY_BUF_SIZE=65536
)
target_compile_options(${PROJECT_NAME} PRIVATE -fpermissive)
target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_CURRENT_BINARY_DIR}
)
target_link_libraries(${PROJECT_NAME} PUBLIC absyntax)