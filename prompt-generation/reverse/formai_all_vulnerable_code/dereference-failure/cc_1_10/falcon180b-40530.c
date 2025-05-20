//Falcon-180B DATASET v1.0 Category: Memory management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FACTORS 100
#define MAX_SIZE 100

typedef struct {
    int *factors;
    int size;
} FactorArray;

FactorArray *create_array(int size) {
    FactorArray *array = (FactorArray *) malloc(sizeof(FactorArray));
    array->factors = (int *) malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

void destroy_array(FactorArray *array) {
    free(array->factors);
    free(array);
}

void add_factor(FactorArray *array, int factor) {
    if (array->size == MAX_FACTORS) {
        printf("Error: Array is full.\n");
        return;
    }
    array->factors[array->size++] = factor;
}

int main() {
    FactorArray *array = create_array(MAX_SIZE);
    int choice;

    do {
        printf("Enter 1 to add a factor.\n");
        printf("Enter 2 to print the factors.\n");
        printf("Enter 3 to exit.\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a factor: ");
                int factor;
                scanf("%d", &factor);
                add_factor(array, factor);
                break;
            case 2:
                printf("Factors: ");
                for (int i = 0; i < array->size; i++) {
                    printf("%d ", array->factors[i]);
                }
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                destroy_array(array);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}