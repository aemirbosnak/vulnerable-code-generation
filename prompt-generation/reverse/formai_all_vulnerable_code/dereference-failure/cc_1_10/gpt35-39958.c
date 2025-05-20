//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* inputSanitizer(char* input);

int main() {

    printf("Please enter your input: ");
    char input[100];
    fgets(input, sizeof(input), stdin);

    char* sanitizedInput = inputSanitizer(input);

    printf("The sanitized input is: %s\n", sanitizedInput);

    free(sanitizedInput);

    return 0;
}

char* inputSanitizer(char* input) {

    int inputLength = strlen(input);

    // Removing any trailing new line characters
    if(input[inputLength - 1] == '\n') {
        input[inputLength - 1] = '\0';
        inputLength--;
    }

    // Removing any leading white space
    int startIndex = 0;
    while(input[startIndex] == ' ' || input[startIndex] == '\t' || input[startIndex] == '\r') {
        startIndex++;
        inputLength--;
    }

    char* sanitizedInput = (char*)malloc(sizeof(char) * (inputLength + 1));
    int sanitizedIndex = 0;

    for(int i = startIndex; i < inputLength; i++) {
        if(input[i] != '<' && input[i] != '>' && input[i] != '"' && input[i] != '\'') {
            sanitizedInput[sanitizedIndex] = input[i];
            sanitizedIndex++;
        }
    }

    sanitizedInput[sanitizedIndex] = '\0';

    return sanitizedInput;
}