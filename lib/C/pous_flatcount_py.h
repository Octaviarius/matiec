/*
 * flat_count.h - Flat member count pass
 *
 * When included after undef_macros.h, redefines __DECLARE_* macros so that
 * re-including POUS.h (or iec_std_FB.h) produces enum constant declarations
 * for each type's flat member count.
 */

 /* Base IEC type flat counts (all elementary types have flat_count = 1) */
#define __decl_flat_count(TYPENAME) TYPENAME##__flat_count = 1;
__ANY(__decl_flat_count)
#undef __decl_flat_count

#define __DIM(...) * __VA_ARGS__
#define __INITIAL_VALUE(...)

/* Member macros expand to additive terms */
#define __DECLARE_VAR(type, name)                 + type##__flat_count
#define __DECLARE_COMPLEX_VAR(type, name)         + type##__flat_count
#define __DECLARE_ARRAY_VAR(type, name)           + type##__flat_count
#define __DECLARE_STRUCT_VAR(type, name)          + type##__flat_count
#define __DECLARE_FB(type, name)                  + type##__flat_count
#define __DECLARE_EXTERNAL(type, name)            + type##__flat_count
#define __DECLARE_EXTERNAL_ARRAY(type, name, ...) + type##__flat_count
#define __DECLARE_EXTERNAL_STRUCT(type, name)     + type##__flat_count
#define __DECLARE_EXTERNAL_FB(type, name)         + type##__flat_count
#define __DECLARE_LOCATED(type, name)             + type##__flat_count
#define __DECLARE_LOCATED_ARRAY(type, name)       + type##__flat_count
#define __DECLARE_LOCATED_STRUCT(type, name)      + type##__flat_count

/* Type macros produce enum constant declarations */
#define __DECLARE_ARRAY_TYPE(type, base, dims)\
type##__flat_count = base##__flat_count dims;\
type##__elem_count = 1 dims;

#define __DECLARE_ARRAY_OF_COMPLEX_TYPE(type, base, dims)\
type##__flat_count = base##__flat_count dims;\
type##__elem_count = 1 dims;

#define __DECLARE_STRUCT_TYPE(type, members)\
type##__flat_count = 0 members;

#define __DECLARE_FB_TYPE(name, members)\
name##__flat_count = 0 members;

#define __DECLARE_PROGRAM_TYPE(name, members) \
name##__flat_count = 0 members;

#define __DECLARE_ENUMERATED_TYPE(type, ...) \
type##__flat_count = 1;

#define __DECLARE_DERIVED_TYPE(type, base) \
type##__flat_count = base##__flat_count;

#define __DECLARE_ARRAY_DERIVED_TYPE(type, base) \
type##__flat_count = base##__flat_count;\
type##__elem_count = base##__elem_count;

#define __DECLARE_REFTO_TYPE(type, name)

