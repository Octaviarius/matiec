cmake_minimum_required(VERSION 3.5)

project(matiec)

add_compile_options(-g -Wall -Wpointer-arith -Wwrite-strings -Wno-unused)

set(PACKAGE_NAME "")
set(PACKAGE_VERSION "")


# iec2c
add_executable(iec2c 
    "main.cc"
)
target_include_directories(iec2c PUBLIC
    "."
)
target_link_libraries(iec2c PUBLIC
    state1_2
    stage3
    libstage4_c
    absyntax
    libabsyntax_utils
    getopt
)
target_compile_definitions(iec2c PUBLIC
    PACKAGE_NAME=\"${PACKAGE_NAME}\"
    PACKAGE_VERSION=\"${PACKAGE_VERSION}\"
)

# iec2iec
add_executable(iec2iec 
    "main.cc"
)
target_include_directories(iec2iec PUBLIC
    "."
)
target_link_libraries(iec2iec PUBLIC
    state1_2
    stage3
    libstage4_iec
    absyntax
    libabsyntax_utils
    getopt
)
target_compile_definitions(iec2iec PUBLIC
    PACKAGE_NAME=\"${PACKAGE_NAME}\"
    PACKAGE_VERSION=\"${PACKAGE_VERSION}\"
)


add_subdirectory("absyntax")
add_subdirectory("absyntax_utils")
add_subdirectory("stage1_2")
add_subdirectory("stage3")
add_subdirectory("stage4")
add_subdirectory("getopt")