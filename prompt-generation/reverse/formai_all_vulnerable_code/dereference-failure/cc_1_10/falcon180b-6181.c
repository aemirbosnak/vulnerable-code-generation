//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100

int main() {
    char *input_string = (char *)malloc(MAX_SIZE * sizeof(char));
    char *output_string = (char *)malloc(MAX_SIZE * sizeof(char));

    printf("Enter a string: ");
    fgets(input_string, MAX_SIZE, stdin);
    int input_length = strlen(input_string);

    // Initialize the output string to the first character of the input string
    strcpy(output_string, input_string);

    // Initialize the previous character to null
    char previous_char = '\0';

    // Initialize the current character to the first character of the input string
    char current_char = toupper(input_string[0]);

    // Initialize the count of consecutive uppercase characters to 1
    int count = 1;

    // Loop through the input string starting from the second character
    for (int i = 1; i < input_length; i++) {
        // Get the current character
        char c = toupper(input_string[i]);

        // Check if the current character is uppercase
        if (isalpha(c)) {
            // Check if the previous character is uppercase
            if (previous_char!= '\0' && isalpha(previous_char) && isupper(previous_char)) {
                // If the previous character is uppercase, update the count
                count++;
            } else {
                // If the previous character is not uppercase, reset the count
                count = 1;
            }

            // Update the previous character to the current character
            previous_char = c;

            // Update the current character to the next character
            current_char = c;
        } else {
            // If the current character is not uppercase, update the count to 1
            count = 1;

            // Update the previous character to null
            previous_char = '\0';

            // Update the current character to the next character
            current_char = toupper(input_string[i + 1]);
        }

        // Check if the current character is the last character of the input string
        if (i == input_length - 1) {
            // Update the previous character to null
            previous_char = '\0';
        }
    }

    // Convert the output string to lowercase
    for (int i = 0; i < strlen(output_string); i++) {
        output_string[i] = tolower(output_string[i]);
    }

    // Print the output string
    printf("Output string: %s\n", output_string);

    return 0;
}