/*
 * recurse.h - Recurse accessor pass
 *
 * When included after undef_macros.h (and after flat_count pass),
 * redefines __DECLARE_* macros so that re-including POUS.h (or iec_std_FB.h)
 * produces static inline __recurse() traversal functions.
 *
 * Uses flat_count/elem_count/type_enum constants from the flat_count pass.
 */

#define __DIM(...)
#define __INITIAL_VALUE(...)

/* --- Type macros generate __recurse function bodies --- */

#define __DECLARE_STRUCT_TYPE(type, members) \
  static inline int type##__recurse(type *p, __recurse_cb_t cb, \
      void *userdata, unsigned int *cumulated) { \
    unsigned int local = 0; int ret; \
    members \
    return 1; \
  }

#define __DECLARE_FB_TYPE(name, members) \
  static inline int name##__recurse(name##_data__ *p, __recurse_cb_t cb, \
      void *userdata, unsigned int *cumulated) { \
    unsigned int local = 0; int ret; \
    members \
    return 1; \
  }

#define __DECLARE_PROGRAM_TYPE(name, members) \
  static inline int name##__recurse(name##_data__ *p, __recurse_cb_t cb, \
      void *userdata, unsigned int *cumulated) { \
    unsigned int local = 0; int ret; \
    members \
    return 1; \
  }

/* Array of simple elements: flat loop with pointer arithmetic */
#define __DECLARE_ARRAY_TYPE(type, base, dims) \
  static inline int type##__recurse(type *p, __recurse_cb_t cb, \
      void *userdata, unsigned int *cumulated) { \
    unsigned int local = 0; \
    __IEC_##base##_t *items = (__IEC_##base##_t *)p->table; \
    for (unsigned int i = 0; i < type##__elem_count; i++) { \
      int ret = cb(base##_ENUM, &items[i], *cumulated, local, 1, NULL, userdata); \
      if (ret == 0) return 0; \
      if (ret == -2) return 1; \
      if (ret > 1) { unsigned int skip = ret - 1; i += skip; \
        *cumulated += skip; local += skip; } \
      else { *cumulated += 1; } \
      local += 1; \
    } return 1; \
  }

/* Array of complex elements: flat loop with recursion */
#define __DECLARE_ARRAY_OF_COMPLEX_TYPE(type, base, dims) \
  static inline int type##__recurse(type *p, __recurse_cb_t cb, \
      void *userdata, unsigned int *cumulated) { \
    unsigned int local = 0; \
    base *items = (base *)p->table; \
    for (unsigned int i = 0; i < type##__elem_count; i++) { \
      int ret = cb(base##__type_enum, &items[i], *cumulated, local, \
          base##__flat_count, NULL, userdata); \
      if (ret == 0) return 0; \
      if (ret == -2) return 1; \
      if (ret > 1) { unsigned int skip = ret - 1; i += skip; \
        *cumulated += skip * base##__flat_count; \
        local += skip * base##__flat_count; } \
      else if (ret == 1) { \
        int sub = base##__recurse(&items[i], cb, userdata, cumulated); \
        if (sub == 0) return 0; } \
      else { *cumulated += base##__flat_count; } \
      local += base##__flat_count; \
    } return 1; \
  }

/* --- Member macros generate callback + flow control --- */

/* Simple var (in struct or FB): callback, no recursion */
#define __DECLARE_VAR(type, name) \
  ret = cb(type##_ENUM, &(p->name), *cumulated, local, 1, #name, userdata); \
  if (ret == 0) return 0; if (ret == -2) return 1; \
  *cumulated += 1; local += 1;

/* Complex var in struct (unwrapped): callback + recurse, no .value */
#define __DECLARE_COMPLEX_VAR(type, name) \
  ret = cb(type##__type_enum, &(p->name), *cumulated, local, \
      type##__flat_count, #name, userdata); \
  if (ret == 0) return 0; if (ret == -2) return 1; \
  if (ret == 1) { \
    int sub = type##__recurse(&(p->name), cb, userdata, cumulated); \
    if (sub == 0) return 0; \
  } else { *cumulated += type##__flat_count; } \
  local += type##__flat_count;

/* Array var in FB (wrapped in __IEC_*_t): callback + recurse with .value */
#define __DECLARE_ARRAY_VAR(type, name) \
  ret = cb(ARRAY_ENUM, &(p->name), *cumulated, local, \
      type##__flat_count, #name, userdata); \
  if (ret == 0) return 0; if (ret == -2) return 1; \
  if (ret == 1) { \
    int sub = type##__recurse(&(p->name.value), cb, userdata, cumulated); \
    if (sub == 0) return 0; \
  } else { *cumulated += type##__flat_count; } \
  local += type##__flat_count;

/* Struct var in FB (wrapped in __IEC_*_t): callback + recurse with .value */
#define __DECLARE_STRUCT_VAR(type, name) \
  ret = cb(STRUCT_ENUM, &(p->name), *cumulated, local, \
      type##__flat_count, #name, userdata); \
  if (ret == 0) return 0; if (ret == -2) return 1; \
  if (ret == 1) { \
    int sub = type##__recurse(&(p->name.value), cb, userdata, cumulated); \
    if (sub == 0) return 0; \
  } else { *cumulated += type##__flat_count; } \
  local += type##__flat_count;

/* FB instance: callback + recurse into FB data struct */
#define __DECLARE_FB(type, name) \
  ret = cb(FB_ENUM, &(p->name), *cumulated, local, \
      type##__flat_count, #name, userdata); \
  if (ret == 0) return 0; if (ret == -2) return 1; \
  if (ret == 1) { \
    int sub = type##__recurse(&(p->name), cb, userdata, cumulated); \
    if (sub == 0) return 0; \
  } else { *cumulated += type##__flat_count; } \
  local += type##__flat_count;

/* External var (pointer): _P enum, no recursion */
#define __DECLARE_EXTERNAL(type, name) \
  ret = cb(type##_P_ENUM, &(p->name), *cumulated, local, 1, #name, userdata); \
  if (ret == 0) return 0; if (ret == -2) return 1; \
  *cumulated += 1; local += 1;

/* External array (pointer): callback + recurse via pointer .value */
#define __DECLARE_EXTERNAL_ARRAY(type, name) \
  ret = cb(ARRAY_ENUM, &(p->name), *cumulated, local, \
      type##__flat_count, #name, userdata); \
  if (ret == 0) return 0; if (ret == -2) return 1; \
  if (ret == 1) { \
    int sub = type##__recurse(p->name.value, cb, userdata, cumulated); \
    if (sub == 0) return 0; \
  } else { *cumulated += type##__flat_count; } \
  local += type##__flat_count;

/* External struct (pointer): callback + recurse via pointer .value */
#define __DECLARE_EXTERNAL_STRUCT(type, name) \
  ret = cb(STRUCT_ENUM, &(p->name), *cumulated, local, \
      type##__flat_count, #name, userdata); \
  if (ret == 0) return 0; if (ret == -2) return 1; \
  if (ret == 1) { \
    int sub = type##__recurse(p->name.value, cb, userdata, cumulated); \
    if (sub == 0) return 0; \
  } else { *cumulated += type##__flat_count; } \
  local += type##__flat_count;

/* External FB (pointer to FB): callback + recurse via pointer */
#define __DECLARE_EXTERNAL_FB(type, name) \
  ret = cb(FB_ENUM, p->name, *cumulated, local, \
      type##__flat_count, #name, userdata); \
  if (ret == 0) return 0; if (ret == -2) return 1; \
  if (ret == 1) { \
    int sub = type##__recurse(p->name, cb, userdata, cumulated); \
    if (sub == 0) return 0; \
  } else { *cumulated += type##__flat_count; } \
  local += type##__flat_count;

/* Located var (pointer): _P enum, no recursion — same as external */
#define __DECLARE_LOCATED(type, name) \
  ret = cb(type##_P_ENUM, &(p->name), *cumulated, local, 1, #name, userdata); \
  if (ret == 0) return 0; if (ret == -2) return 1; \
  *cumulated += 1; local += 1;

/* No-ops in recurse mode */
#define __DECLARE_ENUMERATED_TYPE(type, ...)
#define __DECLARE_DERIVED_TYPE(type, base)
#define __DECLARE_REFTO_TYPE(type, name)
