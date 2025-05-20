//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    int size;
} String;

void initString(String *str) {
    str->data = NULL;
    str->size = 0;
}

void setString(String *str, char *data) {
    int len = strlen(data);
    if (len > MAX_SIZE) {
        printf("Error: string too long\n");
        return;
    }
    if (str->data!= NULL) {
        free(str->data);
    }
    str->data = malloc(len + 1);
    str->size = len;
    strcpy(str->data, data);
}

void printString(String str) {
    printf("%s\n", str.data);
}

int main() {
    String str1, str2;
    initString(&str1);
    initString(&str2);

    setString(&str1, "Hello, world!");
    setString(&str2, "Ada Lovelace");

    printString(str1);
    printString(str2);

    free(str1.data);
    free(str2.data);

    return 0;
}