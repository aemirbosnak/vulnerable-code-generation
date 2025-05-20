//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100
#define MIN_NUMBER 0
#define MAX_NUMBER 1000

void generate_random_numbers(int *numbers);
void print_numbers(int *numbers);
void check_user_input(int *numbers, int *user_input, int size);
int main() {
    int *numbers = malloc(ARRAY_SIZE * sizeof(int));
    int *user_input = malloc(ARRAY_SIZE * sizeof(int));
    int i;

    if (numbers == NULL || user_input == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    srand(time(NULL));
    generate_random_numbers(numbers);

    printf("Type the following numbers as fast as you can:\n");
    print_numbers(numbers);

    clock_t start = clock();
    for (i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &user_input[i]);
        check_user_input(numbers, user_input, i);
    }
    clock_t end = clock();

    free(numbers);
    free(user_input);

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to complete the test: %.2fs\n", time_taken);

    return 0;
}

void generate_random_numbers(int *numbers) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
    }
}

void print_numbers(int *numbers) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void check_user_input(int *numbers, int *user_input, int index) {
    if (numbers[index] != user_input[index]) {
        printf("Incorrect input at index %d. Please try again.\n", index);
        scanf("%d", &user_input[index]);
    }
}