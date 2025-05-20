//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *input_string = NULL;
    int input_length = 0;
    char *output_string = NULL;
    int output_length = 0;

    // Get input string from user
    printf("Enter a string: ");
    if (fgets(input_string, 1000, stdin) == NULL) {
        printf("Error: Input string is too long.\n");
        return 1;
    }
    input_length = strlen(input_string);

    // Remove leading and trailing whitespace
    while (isspace(input_string[0])) {
        input_string++;
        input_length--;
    }
    while (isspace(input_string[input_length - 1])) {
        input_string[--input_length] = '\0';
    }

    // Convert to uppercase
    for (int i = 0; i < input_length; i++) {
        input_string[i] = toupper(input_string[i]);
    }

    // Reverse the string
    output_string = malloc(input_length + 1);
    output_length = 0;
    for (int i = input_length - 1; i >= 0; i--) {
        output_string[output_length++] = input_string[i];
    }
    output_string[output_length] = '\0';

    // Print the reversed string
    printf("Reversed string: %s\n", output_string);

    // Free memory
    free(input_string);
    free(output_string);

    return 0;
}