//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    char *str;
    int len;
} String;

typedef struct {
    String *arr;
    int size;
} StringArray;

void init(StringArray *arr) {
    arr->size = 0;
    arr->arr = (String *) malloc(MAX_SIZE * sizeof(String));
}

void add(StringArray *arr, char *str) {
    String s;
    s.str = str;
    s.len = strlen(str);
    arr->arr[arr->size++] = s;
}

void sort(StringArray *arr) {
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = i + 1; j < arr->size; j++) {
            if (strcmp(arr->arr[i].str, arr->arr[j].str) > 0) {
                String temp = arr->arr[i];
                arr->arr[i] = arr->arr[j];
                arr->arr[j] = temp;
            }
        }
    }
}

void search(StringArray *arr, char *str) {
    for (int i = 0; i < arr->size; i++) {
        if (strcmp(arr->arr[i].str, str) == 0) {
            printf("Found string: %s\n", arr->arr[i].str);
            return;
        }
    }
    printf("String not found.\n");
}

int main() {
    StringArray arr;
    init(&arr);
    add(&arr, "apple");
    add(&arr, "banana");
    add(&arr, "cherry");
    add(&arr, "date");
    add(&arr, "elderberry");
    add(&arr, "fig");
    sort(&arr);
    search(&arr, "banana");
    search(&arr, "grape");
    return 0;
}