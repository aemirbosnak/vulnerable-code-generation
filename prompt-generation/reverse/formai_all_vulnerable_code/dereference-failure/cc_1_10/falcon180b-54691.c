//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUMBERS 1000

typedef struct {
    int *numbers;
    int count;
} NumberArray;

NumberArray *create_array(void) {
    NumberArray *array = malloc(sizeof(NumberArray));
    if (array == NULL) {
        fprintf(stderr, "Could not allocate memory for array.\n");
        exit(1);
    }
    array->numbers = malloc(MAX_NUMBERS * sizeof(int));
    if (array->numbers == NULL) {
        fprintf(stderr, "Could not allocate memory for numbers.\n");
        exit(1);
    }
    array->count = 0;
    return array;
}

void add_number(NumberArray *array, int number) {
    if (array->count >= MAX_NUMBERS) {
        fprintf(stderr, "Array is full.\n");
        exit(1);
    }
    array->numbers[array->count++] = number;
}

int sum_array(NumberArray *array) {
    int sum = 0;
    for (int i = 0; i < array->count; i++) {
        sum += array->numbers[i];
    }
    return sum;
}

int main(int argc, char **argv) {
    NumberArray *array = create_array();

    int choice;
    do {
        printf("Enter 1 to add a number, 2 to calculate the sum, or 0 to exit:\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a number:\n");
            int number;
            scanf("%d", &number);
            add_number(array, number);
            break;
        case 2:
            printf("The sum is %d.\n", sum_array(array));
            break;
        default:
            printf("Exiting...\n");
        }
    } while (choice!= 0);

    free(array->numbers);
    free(array);
    return 0;
}