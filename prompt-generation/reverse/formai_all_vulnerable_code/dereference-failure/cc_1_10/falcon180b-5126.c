//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_STRING_LENGTH 256

typedef struct {
    char* value;
    int length;
} string_t;

void string_init(string_t* str) {
    str->value = NULL;
    str->length = 0;
}

void string_free(string_t* str) {
    if (str->value!= NULL) {
        free(str->value);
    }
    str->value = NULL;
    str->length = 0;
}

void string_copy(string_t* dest, const string_t* src) {
    if (dest->value!= NULL) {
        free(dest->value);
    }
    dest->value = malloc(src->length + 1);
    assert(dest->value!= NULL);
    strncpy(dest->value, src->value, src->length);
    dest->value[src->length] = '\0';
    dest->length = src->length;
}

void string_concat(string_t* dest, const string_t* src1, const string_t* src2) {
    int total_length = src1->length + src2->length;
    char* new_value = malloc(total_length + 1);
    assert(new_value!= NULL);
    strncpy(new_value, src1->value, src1->length);
    strncat(new_value, src2->value, src2->length);
    new_value[total_length] = '\0';
    string_free(dest);
    dest->value = new_value;
    dest->length = total_length;
}

void string_print(const string_t* str) {
    printf("%s", str->value);
}

int main() {
    string_t str1, str2, str3;
    string_init(&str1);
    string_init(&str2);
    string_init(&str3);

    string_copy(&str1, &str2);
    string_concat(&str2, &str1, &str2);
    string_print(&str1);
    string_print(&str2);
    string_print(&str3);

    string_free(&str1);
    string_free(&str2);
    string_free(&str3);

    return 0;
}