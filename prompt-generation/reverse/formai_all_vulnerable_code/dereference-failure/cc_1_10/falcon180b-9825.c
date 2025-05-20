//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} IntArray;

void init_array(IntArray *arr) {
    arr->data = (int *)malloc(MAX_SIZE * sizeof(int));
    arr->size = 0;
}

void add_element(IntArray *arr, int val) {
    if (arr->size >= MAX_SIZE) {
        printf("Error: Array is full.\n");
        return;
    }
    arr->data[arr->size++] = val;
}

void print_array(IntArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main() {
    IntArray arr;
    init_array(&arr);

    int choice, val;

    while (TRUE) {
        printf("\n");
        printf("1. Add element\n");
        printf("2. Print array\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &val);
                add_element(&arr, val);
                break;
            case 2:
                print_array(&arr);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}