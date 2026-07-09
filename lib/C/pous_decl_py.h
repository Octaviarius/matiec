/*
 * pous_py.h — CPP macro definitions for generating POUS.py from POUS.h
 *
 */

#define __DIM(...) __VA_ARGS__,
#define __INITIAL_VALUE(...)

/* Member macros */
#define __DECLARE_VAR(type, name)                 (#name, #type),
#define __DECLARE_COMPLEX_VAR(type, name)         (#name, #type),
#define __DECLARE_ARRAY_VAR(type, name)           (#name, #type),
#define __DECLARE_STRUCT_VAR(type, name)          (#name, #type),
#define __DECLARE_FB(type, name)                  (#name, #type),
#define __DECLARE_EXTERNAL(type, name)            (#name, #type),
#define __DECLARE_EXTERNAL_ARRAY(type, name)      (#name, #type),
#define __DECLARE_EXTERNAL_STRUCT(type, name)     (#name, #type),
#define __DECLARE_EXTERNAL_FB(type, name)         (#name, #type),
#define __DECLARE_LOCATED(type, name)             (#name, #type),

/* Type macros */
#define __DECLARE_STRUCT_TYPE(name, members) \
  (#name, TypeClass.STRUCT, name##__flat_count, [members]),

#define __DECLARE_FB_TYPE(name, members) \
  (#name, TypeClass.FB, name##__flat_count, [members]),

#define __DECLARE_PROGRAM_TYPE(name, members) \
  (#name, TypeClass.PROGRAM, name##__flat_count, [members]),

#define __DECLARE_ARRAY_TYPE(name, base, dims) \
  (#name, TypeClass.ARRAY, #base, name##__flat_count, (dims)),

#define __DECLARE_ARRAY_OF_COMPLEX_TYPE(name, base, dims) \
  (#name, TypeClass.ARRAY, #base, name##__flat_count, (dims)),

#define __DECLARE_ENUMERATED_TYPE(name, ...) \
  (#name, TypeClass.ENUM),

#define __DECLARE_DERIVED_TYPE(name, base) \
  (#name, TypeClass.DERIVED, #base),

/* A named array type is described as a derived alias of its structural array type. */
#define __DECLARE_ARRAY_DERIVED_TYPE(name, base) \
  (#name, TypeClass.DERIVED, #base),

#define __DECLARE_REFTO_TYPE(type, name)
