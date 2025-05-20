//Falcon-180B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct string_t {
    char *data;
    size_t length;
} string_t;

string_t *string_create(const char *value) {
    size_t length = strlen(value);
    string_t *string = malloc(sizeof(string_t));
    string->data = malloc(length + 1);
    strcpy(string->data, value);
    string->length = length;
    return string;
}

void string_destroy(string_t *string) {
    free(string->data);
    free(string);
}

string_t *string_copy(const string_t *value) {
    size_t length = value->length;
    string_t *string = malloc(sizeof(string_t));
    string->data = malloc(length + 1);
    strcpy(string->data, value->data);
    string->length = length;
    return string;
}

string_t *string_concat(const string_t *left, const string_t *right) {
    size_t left_length = left->length;
    size_t right_length = right->length;
    size_t total_length = left_length + right_length;
    string_t *result = malloc(sizeof(string_t));
    result->data = malloc(total_length + 1);
    strcpy(result->data, left->data);
    strcat(result->data, right->data);
    result->length = total_length;
    return result;
}

void string_print(const string_t *string) {
    printf("%s", string->data);
}

int main() {
    string_t *string1 = string_create("Hello");
    string_t *string2 = string_create("World");
    string_t *string3 = string_concat(string1, string2);
    string_t *string4 = string_copy(string3);

    string_print(string1);
    string_print(string2);
    string_print(string3);
    string_print(string4);

    string_destroy(string1);
    string_destroy(string2);
    string_destroy(string3);
    string_destroy(string4);

    return 0;
}