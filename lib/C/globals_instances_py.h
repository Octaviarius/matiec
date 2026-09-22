/* Undefine all __DECLARE_* macros between multi-pass POUS.h inclusions */
#define __DECLARE_GLOBAL(type, domain, name)\
  (#name, #domain, #type, TypeClass.SIMPLE, type##__flat_count),
#define __DECLARE_GLOBAL_ARRAY(type, domain, name)\
  (#name, #domain, #type, TypeClass.ARRAY, type##__flat_count),
#define __DECLARE_GLOBAL_STRUCT(type, domain, name)\
  (#name, #domain, #type, TypeClass.STRUCT, type##__flat_count),
#define __DECLARE_GLOBAL_FB(type, domain, name)\
  (#name, #domain, #type, TypeClass.FB, type##__flat_count),
#define __DECLARE_GLOBAL_LOCATION(type, location)
#define __DECLARE_GLOBAL_LOCATED(type, resource, name)\
  (#name, #resource, #type, TypeClass.LOCATED, type##__flat_count),
#define __DECLARE_GLOBAL_LOCATED_ARRAY(type, resource, name)\
  (#name, #resource, #type, TypeClass.LOCATED_ARRAY, type##__flat_count),
#define __DECLARE_GLOBAL_LOCATED_STRUCT(type, resource, name)\
  (#name, #resource, #type, TypeClass.LOCATED_STRUCT, type##__flat_count),
#define __DECLARE_PROGRAM_INSTANCE(type, resource, name)\
  (#name, #resource, #type, TypeClass.PROGRAM, type##__flat_count),
#define __DECLARE_CONFIGURATION(configuration_name, tick_time)
