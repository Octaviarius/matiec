/*
 * flat_count.h - Flat member count pass
 *
 * When included after undef_macros.h, redefines __DECLARE_* macros so that
 * re-including POUS.h (or iec_std_FB.h) produces enum constant declarations
 * for each type's flat member count.
 */

/* Base IEC type flat counts (all elementary types have flat_count = 1) */
#define __decl_flat_count(TYPENAME) enum { TYPENAME##__flat_count = 1 };
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
#define __DECLARE_EXTERNAL_ARRAY(type, name)      + type##__flat_count
#define __DECLARE_EXTERNAL_STRUCT(type, name)     + type##__flat_count
#define __DECLARE_EXTERNAL_FB(type, name)         + type##__flat_count
#define __DECLARE_LOCATED(type, name)             + type##__flat_count

/* Type macros produce enum constant declarations */
#define __DECLARE_ARRAY_TYPE(type, base, dims) \
  enum { type##__flat_count = base##__flat_count dims }; \
  enum { type##__elem_count = 1 dims }; \
  enum { type##__type_enum = ARRAY_ENUM };

#define __DECLARE_ARRAY_OF_COMPLEX_TYPE(type, base, dims) \
  enum { type##__flat_count = base##__flat_count dims }; \
  enum { type##__elem_count = 1 dims }; \
  enum { type##__type_enum = ARRAY_ENUM };

#define __DECLARE_STRUCT_TYPE(type, members) \
  enum { type##__flat_count = 0 members }; \
  enum { type##__type_enum = STRUCT_ENUM };

#define __DECLARE_FB_TYPE(name, members) \
  enum { name##__flat_count = 0 members };

#define __DECLARE_PROGRAM_TYPE(name, members) \
  enum { name##__flat_count = 0 members };

#define __DECLARE_ENUMERATED_TYPE(type, ...) \
  enum { type##__flat_count = 1 }; \
  enum { type##_ENUM = ENUM_ENUM }; \
  enum { type##_P_ENUM = ENUM_P_ENUM };

#define __DECLARE_DERIVED_TYPE(type, base) \
  enum { type##__flat_count = base##__flat_count }; \
  enum { type##_ENUM = base##_ENUM }; \
  enum { type##_P_ENUM = base##_P_ENUM };

/* Alias of an array datatype: inherit the base array's counts and type_enum
 * (arrays use __type_enum/__elem_count, not the scalar _ENUM). */
#define __DECLARE_ARRAY_DERIVED_TYPE(type, base) \
  enum { type##__flat_count = base##__flat_count }; \
  enum { type##__elem_count = base##__elem_count }; \
  enum { type##__type_enum = ARRAY_ENUM };

#define __DECLARE_REFTO_TYPE(type, name) \
  enum { type##_ENUM = base##_P_ENUM };

