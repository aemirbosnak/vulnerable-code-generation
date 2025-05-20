//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STR_LEN 1024
#define MAX_ARR_SIZE 10

typedef struct {
    char *str;
    size_t len;
} str_t;

typedef struct {
    int arr[MAX_ARR_SIZE];
    size_t size;
} arr_t;

void init_str(str_t *str) {
    str->str = NULL;
    str->len = 0;
}

void init_arr(arr_t *arr) {
    for (size_t i = 0; i < MAX_ARR_SIZE; i++) {
        arr->arr[i] = 0;
    }
    arr->size = 0;
}

void free_str(str_t *str) {
    if (str->str != NULL) {
        free(str->str);
        str->str = NULL;
        str->len = 0;
    }
}

void free_arr(arr_t *arr) {
    for (size_t i = 0; i < MAX_ARR_SIZE; i++) {
        if (arr->arr[i] != 0) {
            free(arr->arr[i]);
        }
    }
    arr->size = 0;
}

void secure_strcpy(str_t *dest, const str_t *src) {
    size_t len = src->len;
    if (dest->str == NULL) {
        dest->str = malloc(len + 1);
        if (dest->str == NULL) {
            perror("malloc failed");
            return;
        }
    } else {
        if (dest->len < len) {
            size_t new_len = dest->len + len;
            char *new_str = realloc(dest->str, new_len + 1);
            if (new_str == NULL) {
                perror("realloc failed");
                return;
            }
            dest->str = new_str;
        }
    }
    memcpy(dest->str, src->str, len);
    dest->len = len;
    dest->str[len] = '\0';
}

void secure_strcat(str_t *dest, const str_t *src) {
    size_t len = dest->len;
    size_t src_len = src->len;
    if (len + src_len >= MAX_STR_LEN) {
        dest->str = realloc(dest->str, len + src_len + 1);
        if (dest->str == NULL) {
            perror("realloc failed");
            return;
        }
    }
    memcpy(dest->str + len, src->str, src_len);
    dest->len += src_len;
    dest->str[len + src_len] = '\0';
}

int main() {
    str_t str1 = {"Hello", 5};
    str_t str2 = {"World", 5};
    arr_t arr = {{1, 2, 3, 4, 5}, 5};

    init_str(&str1);
    init_str(&str2);
    init_arr(&arr);

    secure_strcpy(&str1, &str2);
    secure_strcat(&str1, &arr);

    printf("%s\n", str1.str);

    free_str(&str1);
    free_arr(&arr);

    return 0;
}