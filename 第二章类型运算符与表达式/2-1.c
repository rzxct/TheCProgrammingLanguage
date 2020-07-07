#include <stdio.h>
#include <limits.h>
#include <float.h>
int main()
{
    printf("char:\t%d\t%d\n",            CHAR_MIN,  CHAR_MAX);
    printf("signed char:\t%d\t%d\n",     SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char:\t%u\t%u\n\n", 0,         UCHAR_MAX);

    printf("short:\t%d\t%d\n",            SHRT_MIN, SHRT_MAX);
    printf("unsigned short:\t%u\t%u\n\n", 0,        USHRT_MAX);

    printf("int:\t%d\t%d\n",            INT_MIN, INT_MAX);
    printf("unsigned int:\t%u\t%u\n\n", 0,       UINT_MAX);

    printf("long:\t%ld\t%ld\n",           LONG_MIN, LONG_MAX);
    printf("unsigned long:\t%d\t%lu\n\n", 0,        ULONG_MAX);

    printf("long long:\t%lld\t%lld\n",          LLONG_MIN, LLONG_MAX);
    printf("unsigned long long:\t%d\t%llu\n\n", 0,         ULLONG_MAX);

    printf("float:\t%d\n",         FLT_MANT_DIG);
    printf("double:\t%d\n",        DBL_MANT_DIG);
    printf("long double:\t%d\n\n", LDBL_MANT_DIG);

    printf("float:\t%d\t%d\n",         FLT_MIN_10_EXP,  FLT_MAX_10_EXP);
    printf("double:\t%d\t%d\n",        DBL_MIN_10_EXP,  DBL_MAX_10_EXP );
    printf("long double:\t%d\t%d\n\n", LDBL_MIN_10_EXP, LDBL_MAX_10_EXP );

    printf("float:\t%e\t%e\n",           FLT_MIN,  FLT_MAX);
    printf("double:\t%e\t%e\n",          DBL_MIN,  DBL_MAX);
    printf("long double:\t%Le\t%Le\n\n", LDBL_MIN, LDBL_MAX);
    return 0;
}
