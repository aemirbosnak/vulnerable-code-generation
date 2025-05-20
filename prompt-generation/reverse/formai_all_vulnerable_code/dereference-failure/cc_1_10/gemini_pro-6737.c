//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: secure
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UINT32_DIGITS 10
#define MAX_INT32_DIGITS 11

static bool is_valid_uint32_str(const char *str) {
    size_t len = strlen(str);
    if (len > MAX_UINT32_DIGITS) {
        return false;
    }
    for (size_t i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

static bool is_valid_int32_str(const char *str) {
    size_t len = strlen(str);
    if (len > MAX_INT32_DIGITS) {
        return false;
    }
    if (str[0] == '-') {
        if (len == 1) {
            return false;
        }
        for (size_t i = 1; i < len; i++) {
            if (!isdigit(str[i])) {
                return false;
            }
        }
    } else {
        for (size_t i = 0; i < len; i++) {
            if (!isdigit(str[i])) {
                return false;
            }
        }
    }
    return true;
}

static uint32_t str_to_uint32(const char *str) {
    assert(is_valid_uint32_str(str));
    size_t len = strlen(str);
    uint32_t result = 0;
    for (size_t i = 0; i < len; i++) {
        result *= 10;
        result += str[i] - '0';
    }
    return result;
}

static int32_t str_to_int32(const char *str) {
    assert(is_valid_int32_str(str));
    size_t len = strlen(str);
    int32_t result = 0;
    bool negative = false;
    if (str[0] == '-') {
        negative = true;
        str++;
        len--;
    }
    for (size_t i = 0; i < len; i++) {
        result *= 10;
        result += str[i] - '0';
    }
    return negative ? -result : result;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <uint32> <int32>\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (!is_valid_uint32_str(argv[1]) || !is_valid_int32_str(argv[2])) {
        fprintf(stderr, "Invalid input\n");
        return EXIT_FAILURE;
    }
    uint32_t a = str_to_uint32(argv[1]);
    int32_t b = str_to_int32(argv[2]);
    printf("%u + %d = %u\n", a, b, a + b);
    printf("%u - %d = %u\n", a, b, a - b);
    printf("%u * %d = %u\n", a, b, a * b);
    if (b != 0) {
        printf("%u / %d = %u\n", a, b, a / b);
        printf("%u %% %d = %u\n", a, b, a % b);
    }
    printf("%u & %d = %u\n", a, b, a & b);
    printf("%u | %d = %u\n", a, b, a | b);
    printf("%u ^ %d = %u\n", a, b, a ^ b);
    printf("~%u = %u\n", a, ~a);
    printf("-%d = %d\n", b, -b);
    return EXIT_SUCCESS;
}