/* Undefine all __DECLARE_* macros between multi-pass POUS.h inclusions */
#define __DECLARE_GLOBAL(type, domain, name)
#define __DECLARE_GLOBAL_ARRAY(type, domain, name)
#define __DECLARE_GLOBAL_STRUCT(type, domain, name)
#define __DECLARE_GLOBAL_FB(type, domain, name)
#define __DECLARE_PROGRAM_INSTANCE(type, resource, name)
#define __DECLARE_TICKTIME(value) Ticktime = value

