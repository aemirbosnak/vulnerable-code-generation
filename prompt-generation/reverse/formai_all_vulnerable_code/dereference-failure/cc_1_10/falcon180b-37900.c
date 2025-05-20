//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    // Declare and initialize variables
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    char *delimiter = " ";
    int length, i, j;

    // Get input from user
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove leading and trailing spaces
    length = strlen(input);
    for (i = 0; i < length; i++) {
        if (isspace(input[i]) && i == 0) {
            input[i] = '\0';
        } else if (isspace(input[i]) && i == length - 1) {
            input[i] = '\0';
        }
    }

    // Reverse the string
    length = strlen(input);
    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }

    // Split the string into words
    char *token = strtok(input, delimiter);
    strcpy(output, token);
    while ((token = strtok(NULL, delimiter))!= NULL) {
        strcat(output, " ");
        strcat(output, token);
    }

    // Convert to uppercase
    for (i = 0; i < strlen(output); i++) {
        output[i] = toupper(output[i]);
    }

    // Print the result
    printf("The reversed and uppercase string is: %s\n", output);

    return 0;
}