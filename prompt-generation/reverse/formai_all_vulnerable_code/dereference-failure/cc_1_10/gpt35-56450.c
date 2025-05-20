//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_OUTPUT_LENGTH 5000

int main(void) {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_OUTPUT_LENGTH] = "";
    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character
    int input_length = strlen(input);
    if (input_length > MAX_INPUT_LENGTH - 1) {
        printf("Error: Input exceeds maximum length (%d)\n", MAX_INPUT_LENGTH - 1);
        exit(EXIT_FAILURE);
    }
    // Step 1: Check for dangerous characters
    const char *dangerous_characters = "<>&\"'";
    for (int i = 0; i < input_length; i++) {
        if (strchr(dangerous_characters, input[i]) != NULL) {
            printf("Error: Input contains dangerous character '%c'\n", input[i]);
            exit(EXIT_FAILURE);
        }
    }
    // Step 2: Encode string for output
    for (int i = 0; i < input_length; i++) {
        char encoded[4];
        switch (input[i]) {
            case '<':
                strcpy(encoded, "&lt;");
                break;
            case '>':
                strcpy(encoded, "&gt;");
                break;
            case '&':
                strcpy(encoded, "&amp;");
                break;
            case '\"':
                strcpy(encoded, "&quot;");
                break;
            case '\'':
                strcpy(encoded, "&#39;");
                break;
            default:
                sprintf(encoded, "%c", input[i]);
        }
        strcat(output, encoded);
    }
    printf("Encoded text: %s\n", output);
    return 0;
}