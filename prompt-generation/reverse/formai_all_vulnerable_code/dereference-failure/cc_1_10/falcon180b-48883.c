//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    char *new_string;
    int length, i;

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    length = strlen(input);

    // Remove leading and trailing spaces
    for (i = 0; i < length; i++) {
        if (isspace(input[i])) {
            input[i] = '\0';
            length--;
        } else if (i == length - 1) {
            input[i] = '\0';
        }
    }

    // Reverse the string
    for (i = 0; i < length / 2; i++) {
        char temp = input[i];
        input[i] = input[length - i - 1];
        input[length - i - 1] = temp;
    }

    // Convert to uppercase
    for (i = 0; i < length; i++) {
        input[i] = toupper(input[i]);
    }

    // Create a new string with every other character
    new_string = malloc(length / 2 + 1);
    i = 0;
    for (int j = 0; j < length; j += 2) {
        new_string[i++] = input[j];
    }
    new_string[i] = '\0';

    // Print the original and manipulated strings
    printf("Original string: %s\n", input);
    printf("Manipulated string: %s\n", new_string);

    return 0;
}