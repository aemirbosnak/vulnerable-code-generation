//Falcon-180B DATASET v1.0 Category: Memory management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    int size;
} String;

void init(String *str) {
    str->data = NULL;
    str->size = 0;
}

void destroy(String *str) {
    if (str->data!= NULL) {
        free(str->data);
        str->data = NULL;
        str->size = 0;
    }
}

int length(String str) {
    return str.size;
}

void concatenate(String *str1, String str2) {
    int new_size = str1->size + str2.size + 1;
    char *new_data = realloc(str1->data, new_size);
    if (new_data == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    str1->data = new_data;
    str1->size = new_size;
    strcat(str1->data, str2.data);
}

void copy(String *dest, String src) {
    int size = src.size;
    char *data = malloc(size + 1);
    if (data == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    strcpy(data, src.data);
    destroy(dest);
    init(dest);
    dest->data = data;
    dest->size = size;
}

int main() {
    String str1, str2;
    init(&str1);
    init(&str2);

    strcpy(str1.data, "Hello");
    strcpy(str2.data, "world");

    printf("str1: %s\n", str1.data);
    printf("str2: %s\n", str2.data);

    concatenate(&str1, str2);
    printf("Concatenated: %s\n", str1.data);

    copy(&str1, str2);
    printf("Copied: %s\n", str1.data);

    destroy(&str1);
    destroy(&str2);

    return 0;
}