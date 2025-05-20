//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    int input_length;

    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input_length = strlen(input);

    // Remove leading and trailing whitespaces
    while (isspace(input[0])) {
        strcpy(input, input + 1);
        input_length--;
    }
    while (isspace(input[input_length - 1])) {
        input[input_length - 1] = '\0';
        input_length--;
    }

    // Remove multiple consecutive whitespaces
    char* output = input;
    char* temp = output;
    while ((temp = strstr(temp, "  "))!= NULL) {
        strcpy(temp, temp + 1);
    }

    // Remove non-alphanumeric characters
    temp = output;
    while ((temp = strpbrk(temp, "!@#$%^&*()_+-=[]{}|;:,.<>?/"))!= NULL) {
        *temp = '\0';
        temp++;
    }

    // Remove leading and trailing whitespaces again
    while (isspace(output[0])) {
        strcpy(output, output + 1);
    }
    while (isspace(output[strlen(output) - 1])) {
        output[strlen(output) - 1] = '\0';
    }

    printf("Sanitized string: %s\n", output);

    return 0;
}