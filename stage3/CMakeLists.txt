project(stage3 LANGUAGES C CXX)

add_library(${PROJECT_NAME} STATIC
    stage3.cc 
	flow_control_analysis.cc 
	fill_candidate_datatypes.cc 
	narrow_candidate_datatypes.cc 
	forced_narrow_candidate_datatypes.cc 
	print_datatypes_error.cc 
	datatype_functions.cc 
	lvalue_check.cc 
	array_range_check.cc 
	case_elements_check.cc 
    constant_folding.cc 
    declaration_check.cc 
    enum_declaration_check.cc 
    remove_forward_dependencies.cc
)
target_include_directories(${PROJECT_NAME} PUBLIC
    "."
)
target_link_libraries(${PROJECT_NAME} PUBLIC
	absyntaax_utils
)