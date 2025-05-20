//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FIELD_SIZE 100
#define DELIMITER ","

typedef struct {
    char *data;
    int size;
} DynamicArray;

DynamicArray *createDynamicArray(int initialSize) {
    DynamicArray *array = (DynamicArray *) malloc(sizeof(DynamicArray));
    array->data = (char *) malloc(initialSize * sizeof(char));
    array->size = initialSize;
    return array;
}

void resizeDynamicArray(DynamicArray *array, int newSize) {
    array->size = newSize;
    array->data = (char *) realloc(array->data, newSize * sizeof(char));
}

void appendCharToDynamicArray(DynamicArray *array, char c) {
    if (array->size - strlen(array->data) <= 1) {
        resizeDynamicArray(array, array->size + 1);
    }
    strcat(array->data, &c);
}

void clearDynamicArray(DynamicArray *array) {
    array->data[0] = '\0';
    array->size = strlen(array->data);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_SIZE];
    char delimiter = DELIMITER[0];
    int numFields = 0;
    char **fields = (char **) malloc(MAX_FIELD_SIZE * sizeof(char *));
    int i = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        numFields = 0;
        fields[numFields] = strtok(line, &delimiter);
        while (fields[numFields]!= NULL) {
            numFields++;
            fields = (char **) realloc(fields, numFields * sizeof(char *));
            fields[numFields - 1] = strtok(NULL, &delimiter);
        }
        for (i = 0; i < numFields; i++) {
            printf("%s\n", fields[i]);
        }
    }

    fclose(file);
    for (i = 0; i < numFields; i++) {
        free(fields[i]);
    }
    free(fields);

    return 0;
}