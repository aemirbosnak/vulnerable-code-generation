//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    char *name;
    int (*func)(void);
} test_t;

static int test_add(void) {
    int sum = 0;
    for (int i = 0; i < 1000000; ++i) {
        sum += i;
    }
    return sum;
}

static int test_mul(void) {
    int prod = 1;
    for (int i = 0; i < 1000000; ++i) {
        prod *= i;
    }
    return prod;
}

static int test_sqrt(void) {
    int num = 123456789;
    return sqrt(num);
}

static test_t tests[] = {
    {"Addition", test_add},
    {"Multiplication", test_mul},
    {"Square Root", test_sqrt}
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <test_name>\n", argv[0]);
        return 1;
    }

    char *test_name = argv[1];
    bool found = false;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        if (strcmp(tests[i].name, test_name) == 0) {
            found = true;
            tests[i].func();
        }
    }

    if (!found) {
        printf("Invalid test name: %s\n", test_name);
    }

    return 0;
}