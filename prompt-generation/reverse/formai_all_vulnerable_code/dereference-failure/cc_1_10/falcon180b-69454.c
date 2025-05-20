//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_NUM_INPUTS 10

char inputs[MAX_NUM_INPUTS][MAX_INPUT_LENGTH];
int num_inputs;

void sanitize_input(char* input) {
    int length = strlen(input);
    int i;

    // Remove leading and trailing whitespace
    while (isspace(input[0])) {
        input++;
        length--;
    }
    while (isspace(input[length-1])) {
        input[length-1] = '\0';
        length--;
    }

    // Remove any non-alphanumeric characters
    for (i = 0; i < length; i++) {
        if (!isalnum(input[i])) {
            input[i] = '\0';
            length--;
        }
    }

    // Make the string all lowercase
    for (i = 0; i < length; i++) {
        input[i] = tolower(input[i]);
    }
}

int main() {
    int i, j;
    char input[MAX_INPUT_LENGTH];

    num_inputs = 0;

    printf("Enter up to %d inputs:\n", MAX_NUM_INPUTS);

    while (num_inputs < MAX_NUM_INPUTS && fgets(input, MAX_INPUT_LENGTH, stdin)!= NULL) {
        sanitize_input(input);
        strcpy(inputs[num_inputs], input);
        num_inputs++;
    }

    printf("Num inputs: %d\n", num_inputs);

    for (i = 0; i < num_inputs; i++) {
        printf("Input %d: %s\n", i+1, inputs[i]);
    }

    return 0;
}