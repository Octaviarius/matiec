/*
 * Copyright (C) 2007-2011: Edouard TISSERANT and Laurent BESSARD
 *
 * See COPYING and COPYING.LESSER files for copyright details.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License 
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef IEC_TYPES_ALL_H
#define IEC_TYPES_ALL_H

#include <stddef.h>
#include "iec_types_list.h"

/*********************/
/*  IEC Types defs   */
/*********************/

/* Include non windows.h clashing typedefs */
#include "iec_types.h"

#ifndef TRUE
  #define TRUE 1
  #define FALSE 0
#endif

#define __IEC_FORCE_FLAG 0x02
#define __IEC_RETAIN_FLAG 0x04

#define __DECLARE_IEC_TYPE(type)\
typedef IEC_##type type;\
\
typedef struct {\
  IEC_BYTE flags;\
  IEC_##type value;\
} __IEC_##type##_t;\
\
typedef struct {\
  IEC_BYTE flags;\
  IEC_##type *value;\
} __IEC_##type##_p;

/* Those typdefs clash with windows.h */
/* i.e. this file cannot be included aside windows.h */
__ANY(__DECLARE_IEC_TYPE)

/* Ersatz for ENUMs to map them to int in variable access */
typedef int IEC_ENUM;
__DECLARE_IEC_TYPE(ENUM)

/* Enumerate native types */
#define __decl_enum_type(TYPENAME) TYPENAME##_ENUM,
#define __decl_enum_pointer(TYPENAME) TYPENAME##_P_ENUM,
#define __decl_enum_output(TYPENAME) TYPENAME##_O_ENUM,
typedef enum{
  SIMPLE_ENUM = 0,
  __ANY(__decl_enum_type)
  POINTED_ENUM = 32,
  __ANY(__decl_enum_pointer)
  OUTPUT_ENUM = 64,
  __ANY(__decl_enum_output)
  FB_ENUM = 96,
  STRUCT_ENUM = 128,
  ARRAY_ENUM = 160,
  ENUM_ENUM = 192,
  ENUM_O_ENUM = 193,
  ENUM_P_ENUM = 194,
  UNKNOWN_ENUM = 255
} __IEC_types_enum;

/* Get size of type from its number */
#define __decl_size_case(TYPENAME) \
	case TYPENAME##_ENUM:\
	case TYPENAME##_O_ENUM:\
	case TYPENAME##_P_ENUM:\
		return sizeof(TYPENAME);
static inline USINT __get_type_enum_size(__IEC_types_enum t){
 switch(t){
  __ANY(__decl_size_case)
  /* size do not correspond to real struct.
   * only a bool is used to represent state*/
  default:
	  return 0;
 }
 return 0;
}

/* Callback for __recurse visitor functions.
 * Returns: 0=stop, 1=continue/recurse, -1=step over, -2=step out, N>1=jump N */
typedef int (*__recurse_cb_t)(
    __IEC_types_enum type,
    void *ptr,
    unsigned int cumulated_index,
    unsigned int local_index,
    unsigned int member_flat_count,
    const char *name,
    void *userdata
);

#endif /*IEC_TYPES_ALL_H*/
