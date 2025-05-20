//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 256

void sanitizeInput(char *input);

int main() {
    char input[MAX_INPUT_LEN];

    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LEN, stdin);

    printf("Your original input: %s\n", input);
    sanitizeInput(input);
    printf("Your sanitized input: %s\n", input);
    
    return 0;
}

void sanitizeInput(char *input) {
    int i, j;
    
    // remove leading and trailing whitespaces
    i = 0;
    while (input[i] == ' ') {
        i++;
    }

    j = strlen(input) - 1;
    while (input[j] == ' ' || input[j] == '\n' || input[j] == '\r') {
        input[j] = '\0';
        j--;
    }

    // remove any non-alphanumeric characters
    for (i = 0; i < strlen(input); i++) {
        if (!isalnum(input[i])) {
            for (j = i; j < strlen(input); j++) {
                input[j] = input[j + 1];
            }
            i--;
        }
    }

    // convert all alphabetical characters to lowercase
    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            input[i] = tolower(input[i]);
        }
    }
}