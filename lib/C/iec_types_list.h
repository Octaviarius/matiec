/*
 * Copyright (C) 2007-2026: Edouard TISSERANT
 * Copyright (C) 2007-2011: Laurent BESSARD
 *
 * See COPYING and COPYING.LESSER files for copyright details.
 *
 */

/* Macro that expand to subtypes */
#define __ANY(DO)                 __ANY_ELEMENTARY(DO)
#define __ANY_ELEMENTARY(DO)      __ANY_MAGNITUDE(DO) __ANY_BIT(DO) __ANY_STRING(DO) __ANY_DATE(DO)
#define __ANY_MAGNITUDE(DO)       __ANY_NUM(DO) DO(TIME)
#define __ANY_BIT(DO)             __ANY_NBIT(DO) DO(BOOL)
#define __ANY_NBIT(DO)            DO(BYTE) DO(WORD) DO(DWORD) DO(LWORD)
#define __ANY_STRING(DO)          DO(STRING)
#define __ANY_DATE(DO)            DO(DATE) DO(TOD) DO(DT)
#define __ANY_NUM(DO)             __ANY_REAL(DO) __ANY_INT(DO)
#define __ANY_REAL(DO)            DO(REAL) DO(LREAL)
#define __ANY_INT(DO)             __ANY_SINT(DO) __ANY_UINT(DO)
#define __ANY_SINT(DO)            DO(SINT) DO(INT) DO(DINT) DO(LINT)
#define __ANY_UINT(DO)            DO(USINT) DO(UINT) DO(UDINT) DO(ULINT)


/* Macro that expand to subtypes */
#define __ANY_1(DO,P1)            __ANY_ELEMENTARY_1(DO,P1)
#define __ANY_ELEMENTARY_1(DO,P1) __ANY_MAGNITUDE_1(DO,P1) __ANY_BIT_1(DO,P1) __ANY_STRING_1(DO,P1) __ANY_DATE_1(DO,P1)
#define __ANY_MAGNITUDE_1(DO,P1)  __ANY_NUM_1(DO,P1) DO(TIME,P1)
#define __ANY_BIT_1(DO,P1)        __ANY_NBIT_1(DO,P1) DO(BOOL,P1)
#define __ANY_NBIT_1(DO,P1)       DO(BYTE,P1) DO(WORD,P1) DO(DWORD,P1) DO(LWORD,P1)
#define __ANY_STRING_1(DO,P1)     DO(STRING,P1)
#define __ANY_DATE_1(DO,P1)       DO(DATE,P1) DO(TOD,P1) DO(DT,P1)
#define __ANY_NUM_1(DO,P1)        __ANY_REAL_1(DO,P1) __ANY_INT_1(DO,P1)
#define __ANY_REAL_1(DO,P1)       DO(REAL,P1) DO(LREAL,P1)
#define __ANY_INT_1(DO,P1)        __ANY_SINT_1(DO,P1) __ANY_UINT_1(DO,P1)
#define __ANY_SINT_1(DO,P1)       DO(SINT,P1) DO(INT,P1) DO(DINT,P1) DO(LINT,P1)
#define __ANY_UINT_1(DO,P1)       DO(USINT,P1) DO(UINT,P1) DO(UDINT,P1) DO(ULINT,P1)

