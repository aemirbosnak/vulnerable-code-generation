//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t size;
    char* data;
} MyString;

void my_strcpy(MyString* dest, const char* src) {
    if (dest->size < strlen(src) + 1) {
        dest->size = strlen(src) + 1;
        dest->data = realloc(dest->data, dest->size);
    }
    strcpy(dest->data, src);
}

MyString* my_strnew(const char* src) {
    MyString* str = malloc(sizeof(MyString));
    str->size = strlen(src) + 1;
    str->data = malloc(str->size);
    strcpy(str->data, src);
    return str;
}

void my_strfree(MyString* str) {
    free(str->data);
    free(str);
}

int main() {
    const char* str1 = "Hello, World!";
    const char* str2 = "FooBarBaz";

    MyString* str1_my = my_strnew(str1);
    MyString* str2_my = my_strnew(str2);

    printf("Original Strings:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    printf("\nCopied with my_strcpy:\n");
    my_strcpy(str1_my, str1);
    my_strcpy(str2_my, str2);

    printf("str1_my: %s\n", str1_my->data);
    printf("str2_my: %s\n", str2_my->data);

    printf("\nMemory usage:\n");
    printf("str1: %p\n", str1);
    printf("str1_my: %p\n", str1_my);

    printf("str2: %p\n", str2);
    printf("str2_my: %p\n", str2_my);

    printf("\nFreeing memory:\n");
    my_strfree(str1_my);
    my_strfree(str2_my);

    printf("After freeing memory:\n");
    printf("str1_my: %p\n", str1_my);
    printf("str2_my: %p\n", str2_my);

    return 0;
}