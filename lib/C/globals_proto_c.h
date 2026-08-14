/*
 * globals_proto_c.h - Global variables prototypes pass
 *
 * When included after accessor.h, redefines __DECLARE_GLOBAL* macros so that
 * including GLOBALS.h declares accessor function prototypes for each IEC global
 * variable, instead of defining their storage.
 *
 * Allows code outside of generated PLC, such as beremiz extensions, to access
 * IEC global variables without knowing the name of the IEC configuration, and
 * thus without including generated <configuration_name>.h.
 */

#undef __DECLARE_GLOBAL
#undef __DECLARE_GLOBAL_ARRAY
#undef __DECLARE_GLOBAL_STRUCT
#undef __DECLARE_GLOBAL_FB
#undef __DECLARE_GLOBAL_LOCATION
#undef __DECLARE_GLOBAL_LOCATED
#undef __DECLARE_PROGRAM_INSTANCE
#undef __DECLARE_CONFIGURATION

#define __DECLARE_GLOBAL(type, domain, name)           __DECLARE_GLOBAL_PROTOTYPE(type, name)
#define __DECLARE_GLOBAL_ARRAY(type, domain, name)     __DECLARE_GLOBAL_PROTOTYPE(type, name)
#define __DECLARE_GLOBAL_STRUCT(type, domain, name)    __DECLARE_GLOBAL_PROTOTYPE(type, name)
#define __DECLARE_GLOBAL_FB(type, domain, name)        __DECLARE_GLOBAL_PROTOTYPE_FB(type, name)
#define __DECLARE_GLOBAL_LOCATION(type, location)
#define __DECLARE_GLOBAL_LOCATED(type, resource, name) __DECLARE_GLOBAL_PROTOTYPE(type, name)
#define __DECLARE_PROGRAM_INSTANCE(type, resource, name)
#define __DECLARE_CONFIGURATION(configuration_name, tick_time)
