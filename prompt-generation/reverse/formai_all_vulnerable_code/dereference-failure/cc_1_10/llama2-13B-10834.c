//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_DIGITS 10
#define MAX_NUMBERS 1000

typedef struct {
    int digits[MAX_DIGITS];
    int frequency[MAX_DIGITS];
} number_t;

void init_numbers(number_t *numbers) {
    int i, j;
    for (i = 0; i < MAX_NUMBERS; i++) {
        for (j = 0; j < MAX_DIGITS; j++) {
            numbers[i].digits[j] = (j + 1) % 10;
        }
    }
}

void count_digits(number_t *numbers) {
    int i, j;
    for (i = 0; i < MAX_NUMBERS; i++) {
        for (j = 0; j < MAX_DIGITS; j++) {
            numbers[i].frequency[numbers[i].digits[j] - '0']++;
        }
    }
}

void print_results(number_t *numbers) {
    int i, j;
    for (i = 0; i < MAX_NUMBERS; i++) {
        for (j = 0; j < MAX_DIGITS; j++) {
            printf("%d:%d", i, numbers[i].frequency[j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    number_t *numbers = malloc(MAX_NUMBERS * sizeof(number_t));
    init_numbers(numbers);
    count_digits(numbers);
    print_results(numbers);
    free(numbers);
    return 0;
}