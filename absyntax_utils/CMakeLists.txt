project(absyntax_utils LANGUAGES C CXX)

add_library(${PROJECT_NAME} STATIC
    absyntax_utils.cc
	add_en_eno_param_decl.cc
	decompose_var_instance_name.cc
	array_dimension_iterator.cc
	case_element_iterator.cc
	function_call_iterator.cc
	function_call_param_iterator.cc
	function_param_iterator.cc
	get_sizeof_datatype.cc
	get_var_name.cc
	search_il_label.cc
	search_base_type.cc
	search_fb_instance_decl.cc
	search_fb_typedecl.cc
	search_varfb_instance_type.cc
	search_var_instance_decl.cc
	spec_init_separator.cc
	type_initial_value.cc
	search_varfb_instance_type.cc
	search_var_instance_decl.cc
	spec_init_separator.cc
	type_initial_value.cc
	debug_ast.cc
	get_datatype_info.cc
)
target_include_directories(${PROJECT_NAME} PUBLIC
    "."
)