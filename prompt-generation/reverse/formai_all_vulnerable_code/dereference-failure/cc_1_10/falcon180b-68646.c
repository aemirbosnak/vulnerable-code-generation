//Falcon-180B DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char* data;
    int size;
} String;

String* createString(int size) {
    String* str = malloc(sizeof(String));
    if (str == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    str->data = malloc(size * sizeof(char));
    if (str->data == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    str->size = size;
    return str;
}

void destroyString(String* str) {
    free(str->data);
    free(str);
}

void appendString(String* str, char* data, int size) {
    if (str->size + size > MAX_SIZE) {
        printf("Error: String is too long.\n");
        exit(1);
    }
    str->data = realloc(str->data, str->size + size);
    if (str->data == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    str->size += size;
    memcpy(str->data + str->size - size, data, size);
}

void printString(String* str) {
    printf("%s", str->data);
}

int main() {
    String* str1 = createString(10);
    String* str2 = createString(20);
    String* str3 = createString(30);

    appendString(str1, "Hello", 5);
    appendString(str2, "World", 5);
    appendString(str3, "Testing", 7);

    printString(str1);
    printString(str2);
    printString(str3);

    destroyString(str1);
    destroyString(str2);
    destroyString(str3);

    return 0;
}