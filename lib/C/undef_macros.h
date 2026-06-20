/* Undefine all macros defined by accessor.h (and sibling headers) between
 * multi-pass POUS.h inclusions, so they can be redefined for the next pass. */

/* types declaration macros */
#undef __INITIAL_VALUE
#undef __DECLARE_DERIVED_TYPE
#undef __DECLARE_COMPLEX_STRUCT
#undef __DECLARE_ENUMERATED_TYPE
#undef __DIM
#undef __DECLARE_ARRAY_TYPE
#undef __DECLARE_ARRAY_OF_COMPLEX_TYPE
#undef __DECLARE_STRUCT_TYPE
#undef __DECLARE_REFTO_TYPE

/* variable declaration macros */
#undef __DECLARE_VAR
#undef __DECLARE_COMPLEX_VAR
#undef __DECLARE_ARRAY_VAR
#undef __DECLARE_STRUCT_VAR
#undef __DECLARE_FB
#undef __DECLARE_FB_TYPE
#undef __DECLARE_PROGRAM_TYPE
#undef __DECLARE_GLOBAL
#undef __DECLARE_GLOBAL_ARRAY
#undef __DECLARE_GLOBAL_STRUCT
#undef __DECLARE_GLOBAL_FB
#undef __DECLARE_GLOBAL_LOCATION
#undef __DECLARE_GLOBAL_LOCATED
#undef __DECLARE_GLOBAL_PROTOTYPE
#undef __DECLARE_GLOBAL_PROTOTYPE_FB
#undef __DECLARE_EXTERNAL
#undef __DECLARE_EXTERNAL_ARRAY
#undef __DECLARE_EXTERNAL_STRUCT
#undef __DECLARE_EXTERNAL_FB
#undef __DECLARE_LOCATED
#undef __DECLARE_PROGRAM_INSTANCE
#undef __DECLARE_CONFIGURATION

/* variable initialization macros */
#undef __INIT_RETAIN
#undef __INIT_VAR
#undef __INIT_GLOBAL
#undef __INIT_GLOBAL_FB
#undef __INIT_GLOBAL_LOCATED
#undef __INIT_EXTERNAL
#undef __INIT_EXTERNAL_FB
#undef __INIT_LOCATED
#undef __INIT_LOCATED_VALUE

/* variable getting macros */
#undef __GET_VAR
#undef __GET_EXTERNAL
#undef __GET_EXTERNAL_FB
#undef __GET_LOCATED
#undef __GET_VAR_BY_REF
#undef __GET_EXTERNAL_BY_REF
#undef __GET_EXTERNAL_FB_BY_REF
#undef __GET_LOCATED_BY_REF
#undef __GET_VAR_REF
#undef __GET_EXTERNAL_REF
#undef __GET_EXTERNAL_FB_REF
#undef __GET_LOCATED_REF
#undef __GET_VAR_DREF
#undef __GET_EXTERNAL_DREF
#undef __GET_EXTERNAL_FB_DREF
#undef __GET_LOCATED_DREF

/* variable setting macros */
#undef __SET_VAR
#undef __SET_EXTERNAL
#undef __SET_EXTERNAL_FB
#undef __SET_LOCATED
