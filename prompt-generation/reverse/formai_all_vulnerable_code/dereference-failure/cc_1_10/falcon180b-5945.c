//Falcon-180B DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int size;
    char *data;
} String;

String *createString(int size) {
    String *newString = (String *) malloc(sizeof(String));

    if (newString == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    newString->size = size;
    newString->data = (char *) malloc(size * sizeof(char));

    if (newString->data == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    memset(newString->data, '\0', size);

    return newString;
}

void appendString(String *string1, const char *string2) {
    int newSize = string1->size + strlen(string2);
    char *newData = (char *) realloc(string1->data, newSize * sizeof(char));

    if (newData == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    string1->size = newSize;
    strcat(newData, string2);
    string1->data = newData;
}

void printString(const String *string) {
    printf("%s\n", string->data);
}

int main() {
    String *string1 = createString(MAX_SIZE);
    String *string2 = createString(MAX_SIZE);

    strcpy(string1->data, "Hello");
    strcpy(string2->data, "World");

    appendString(string1, "!");
    appendString(string2, "!");

    printString(string1);
    printString(string2);

    free(string1->data);
    free(string1);
    free(string2->data);
    free(string2);

    return 0;
}