//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
#define FILTER_SIZE 5

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct { float value; } datum_t;
typedef struct { datum_t* data; int len; } vec_t;

datum_t zero = { 0 };
vec_t input, filter, output;

// ∞ sign for indefinite length input vector
void read_input(void) {
    int i = 0;
    while (true) {
        scanf("%f", &input.data[i]);
        i++;
        input.len = i;
        if (feof(stdin)) break;
    }
}

// create moving average filter
void create_filter(void) {
    int i;
    filter.data = calloc(FILTER_SIZE, sizeof(datum_t));

    for (i = 0; i < FILTER_SIZE; i++)
        filter.data[i] = zero;

    filter.len = FILTER_SIZE;
}

// process one sample using moving average filter
void process_sample(void) {
    int i, sum = 0;
    float avg;

    for (i = 0; i < FILTER_SIZE; i++) {
        sum += filter.data[i].value;
        filter.data[i] = input.data[i];
    }

    avg = (float)sum / FILTER_SIZE;
    output.data[0].value = avg;
}

// print vector content
void print_vector(const char* label, vec_t vec) {
    int i;

    printf("%s: [", label);
    for (i = 0; i < vec.len; i++) {
        printf("%.2f, ", vec.data[i].value);
        if (i == vec.len - 1) printf("\b\b]\n");
    }
}

// apply moving average filter to input vector and print result
int main(void) {
    create_filter();

    read_input();

    for (int i = 0; i < input.len; i++) {
        process_sample();
        if (i % 10 == 0) print_vector("Input: ", input);
        if (i % 10 == 9) {
            print_vector("Filter: ", filter);
            print_vector("Output: ", output);
            printf("\n");
        }
        if (i < input.len - 1) {
            input = output;
            output.len = 1;
        }
    }

    free(filter.data);

    return 0;
}