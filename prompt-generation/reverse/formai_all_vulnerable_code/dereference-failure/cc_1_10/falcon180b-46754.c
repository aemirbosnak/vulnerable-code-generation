//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    int size;
    int *data;
} IntArray;

IntArray createArray(int size) {
    IntArray array;
    array.size = size;
    array.data = (int *)malloc(size * sizeof(int));
    return array;
}

void destroyArray(IntArray array) {
    free(array.data);
}

void printArray(IntArray array) {
    int i;
    for (i = 0; i < array.size; i++) {
        printf("%d ", array.data[i]);
    }
    printf("\n");
}

int main() {
    char filename[MAX_SIZE];
    FILE *fp;
    int size, i;
    int *data;

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(fp, "%d", &size);
    data = (int *)malloc(size * sizeof(int));

    for (i = 0; i < size; i++) {
        fscanf(fp, "%d", &data[i]);
    }

    fclose(fp);

    IntArray array = createArray(size);
    memcpy(array.data, data, size * sizeof(int));

    printf("Original array:\n");
    printArray(array);

    printf("Enter the element to search for: ");
    int searchElement;
    scanf("%d", &searchElement);

    int index = -1;
    for (i = 0; i < array.size; i++) {
        if (array.data[i] == searchElement) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }

    destroyArray(array);
    free(data);

    return 0;
}