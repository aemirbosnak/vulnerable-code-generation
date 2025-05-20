//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_NUMBER_OF_CONVERTIONS 10

typedef struct {
    char* input;
    int input_length;
    char* output;
    int output_length;
} conversion_t;

void convert(conversion_t* conversions, int number_of_conversions) {
    int i;
    for (i = 0; i < number_of_conversions; i++) {
        if (conversions[i].input_length > 0) {
            // Convert the input string to uppercase
            char* uppercase_input = malloc(conversions[i].input_length * sizeof(char));
            for (int j = 0; j < conversions[i].input_length; j++) {
                uppercase_input[j] = toupper(conversions[i].input[j]);
            }

            // Convert the input number to a string
            char* number_as_string = malloc(sizeof(char) * 10);
            sprintf(number_as_string, "%d", conversions[i].input_length);

            // Print the converted input and number
            printf("Input: %s\n", uppercase_input);
            printf("Number: %s\n", number_as_string);

            // Free memory
            free(uppercase_input);
            free(number_as_string);
        }
    }
}

int main() {
    conversion_t conversions[MAX_NUMBER_OF_CONVERTIONS];
    int number_of_conversions = 0;

    // Get input from the user
    printf("Enter up to 10 input strings and numbers, separated by a newline:\n");
    char* input;
    int input_length;
    while (number_of_conversions < MAX_NUMBER_OF_CONVERTIONS && (input = fgets(stdin, 1024, &input_length)) != NULL) {
        conversions[number_of_conversions].input = input;
        conversions[number_of_conversions].input_length = input_length;
        number_of_conversions++;
    }

    // Convert the input strings and numbers
    convert(conversions, number_of_conversions);

    return 0;
}