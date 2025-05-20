//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100

char **input_array;
int num_inputs;

void initialize_input_array(void) {
    input_array = (char **)malloc(MAX_SIZE * sizeof(char *));
    num_inputs = 0;
}

void add_input(char *input) {
    if (num_inputs >= MAX_SIZE) {
        printf("Error: Input limit reached.\n");
        return;
    }

    input_array[num_inputs] = strdup(input);
    num_inputs++;
}

void print_input_array(void) {
    for (int i = 0; i < num_inputs; i++) {
        printf("%s ", input_array[i]);
    }
    printf("\n");
}

void free_input_array(void) {
    for (int i = 0; i < num_inputs; i++) {
        free(input_array[i]);
    }
    free(input_array);
}

int main(void) {
    initialize_input_array();

    char input[MAX_SIZE];
    while (true) {
        printf("Enter an input (or type 'done' to finish): ");
        fgets(input, MAX_SIZE, stdin);

        if (strcmp(input, "done") == 0) {
            break;
        }

        add_input(input);
    }

    printf("Input array:\n");
    print_input_array();

    free_input_array();

    return 0;
}