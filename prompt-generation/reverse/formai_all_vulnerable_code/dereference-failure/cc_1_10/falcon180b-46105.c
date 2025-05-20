//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct {
    char *str;
    int length;
} String;

String *string_create(const char *s) {
    String *str = malloc(sizeof(String));
    str->str = strdup(s);
    str->length = strlen(s);
    return str;
}

void string_destroy(String *str) {
    free(str->str);
    free(str);
}

int string_length(String *str) {
    return str->length;
}

char *string_get_c_str(String *str) {
    return str->str;
}

String *string_concat(String *str1, String *str2) {
    char *result = malloc(strlen(str1->str) + strlen(str2->str) + 1);
    strcat(result, str1->str);
    strcat(result, str2->str);
    String *new_str = malloc(sizeof(String));
    new_str->str = result;
    new_str->length = strlen(result);
    return new_str;
}

String *string_copy(String *str) {
    char *result = malloc(strlen(str->str) + 1);
    strcpy(result, str->str);
    String *new_str = malloc(sizeof(String));
    new_str->str = result;
    new_str->length = strlen(result);
    return new_str;
}

int string_compare(String *str1, String *str2) {
    return strcmp(str1->str, str2->str);
}

void string_print(String *str) {
    printf("%s", str->str);
}

int main() {
    String *s1 = string_create("Hello");
    String *s2 = string_create("World");
    String *s3 = string_concat(s1, s2);
    String *s4 = string_copy(s3);
    string_print(s1);
    string_print(s2);
    string_print(s3);
    string_print(s4);
    int result = string_compare(s1, s2);
    if (result == 0) {
        printf("s1 and s2 are equal\n");
    } else {
        printf("s1 and s2 are not equal\n");
    }
    string_destroy(s1);
    string_destroy(s2);
    string_destroy(s3);
    string_destroy(s4);
    return 0;
}