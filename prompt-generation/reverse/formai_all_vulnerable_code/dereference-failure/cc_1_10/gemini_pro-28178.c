//GEMINI-pro DATASET v1.0 Category: Educational ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARANOID_CHECK(expr) ({       \
        int _n = (expr);             \
        if (!(_n)) {                 \
            fprintf(stderr, "Error: %s", #expr); \
            exit(1);                  \
        }                               \
        _n; })

#define PARANOID_CHECK_NULL(ptr) ({    \
        void *_n = (ptr);             \
        if (!(_n)) {                 \
            fprintf(stderr, "Error: %s is NULL", #ptr); \
            exit(1);                  \
        }                               \
        _n; })

#define PARANOID_CHECK_STRLEN(str) ({   \
        size_t _n = strlen(str);        \
        if (!_n) {                     \
            fprintf(stderr, "Error: %s has no length", #str); \
            exit(1);                  \
        }                               \
        _n; })

void paranoid_strcpy(char *dst, const char *src)
{
    PARANOID_CHECK_NULL(dst);
    PARANOID_CHECK_NULL(src);
    size_t len = PARANOID_CHECK_STRLEN(src);
    memcpy(dst, src, len);
    dst[len] = '\0';
}

void paranoid_strcat(char *dst, const char *src)
{
    PARANOID_CHECK_NULL(dst);
    PARANOID_CHECK_NULL(src);
    size_t len_dst = PARANOID_CHECK_STRLEN(dst);
    size_t len_src = PARANOID_CHECK_STRLEN(src);
    memcpy(dst + len_dst, src, len_src);
    dst[len_dst + len_src] = '\0';
}

int paranoid_atoi(const char *str)
{
    PARANOID_CHECK_NULL(str);
    PARANOID_CHECK_STRLEN(str);
    int num = atoi(str);
    if (num == 0) {
        fprintf(stderr, "Error: %s is not a valid number", str);
        exit(1);
    }
    return num;
}

void paranoid_free(void *ptr)
{
    if (ptr) {
        free(ptr);
    } else {
        fprintf(stderr, "Error: Attempting to free NULL pointer");
        exit(1);
    }
}

int paranoid_random(int max)
{
    PARANOID_CHECK(max > 0);
    int num = rand() % max;
    if (num < 0) {
        fprintf(stderr, "Error: Random number is negative");
        exit(1);
    }
    return num;
}

int main(int argc, char *argv[])
{
    PARANOID_CHECK(argc >= 2);
    PARANOID_CHECK_STRLEN(argv[1]);
    char *str = malloc(strlen(argv[1]) + 1);
    PARANOID_CHECK_NULL(str);
    paranoid_strcpy(str, argv[1]);
    printf("Welcome to the Paranoid Program v1.0.0\n");
    printf("Your input string is: '%s'\n", str);
    int num = paranoid_atoi(str);
    printf("Your input number is: %d\n", num);
    char *new_str = malloc(num + 1);
    PARANOID_CHECK_NULL(new_str);
    paranoid_strcat(new_str, "Hello, world!");
    printf("Your new string is: '%s'\n", new_str);
    paranoid_free(str);
    paranoid_free(new_str);
    return 0;
}