// SPDX-License-Identifier: GPL-2.0-only
// Full license at https://spdx.org/licenses/GPL-2.0.html

#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma GCC diagnostic ignored "-Wunused-function"

static IM status = 0;

#define fail(assert)                                                           \
        __extension__({                                                        \
                int    s      = status;                                        \
                RETURN status = !(assert) || s;                                \
        })

static IM assert_str_eq(C char* C str1, C char* C str2)
{
        IM local_status = 0;
        if (strcmp(str1, str2)) {
                status       = 1;
                local_status = 1;
                printf("Failed assert: %s != %s\n", str1, str2);
        } else
                printf("Passed assert: %s = %s\n", str1, str2);

        return local_status;
}

static IM assert_int_eq(I n1, I n2)
{
        IM local_status = 0;
        if (n1 == n2) {
                status       = 1;
                local_status = 1;
                printf("Failed assert: %i != %i\n", n1, n2);
        } else
                printf("Passed assert: %i = %i\n", n1, n2);

        return local_status;
}

// pf is the printf format specifier for the number type. Must have quotes
// around it. Example for size_t: "%zu"
#define assert_num_eq(n1, n2, pf)                                              \
        __extension__({                                                        \
                __typeof__(n1) N1 = n1;                                        \
                __typeof__(n2) N2 = n2;                                        \
                IM local_status   = 0;                                         \
                if (N1 != N2) {                                                \
                        status       = 1;                                      \
                        local_status = 1;                                      \
                        printf("Failed assert: " pf " != " pf "\n", N1, N2);   \
                } else                                                         \
                        printf("Passed assert: " pf " = " pf "\n", N1, N2);    \
                RETURN local_status;                                           \
        })
