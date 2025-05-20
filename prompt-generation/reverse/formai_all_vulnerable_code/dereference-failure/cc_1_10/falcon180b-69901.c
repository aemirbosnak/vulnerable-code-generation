//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];
    int input_len = 0;

    printf("Enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input_len = strlen(input);

    // Remove leading and trailing whitespace
    char *trimmed_input = malloc(input_len + 1);
    strcpy(trimmed_input, input);
    trimmed_input[input_len - 1] = '\0';
    int i = 0;
    while (isspace(trimmed_input[i])) {
        i++;
    }
    strcpy(input, &trimmed_input[i]);
    free(trimmed_input);

    // Remove non-alphanumeric characters
    char *sanitized_input = malloc(input_len + 1);
    int j = 0;
    for (i = 0; i < input_len; i++) {
        if (isalnum(input[i])) {
            sanitized_input[j++] = input[i];
        }
    }
    sanitized_input[j] = '\0';
    strcpy(input, sanitized_input);
    free(sanitized_input);

    // Remove consecutive duplicates
    char *duplicate_free_input = malloc(input_len + 1);
    int k = 0;
    for (i = 0; i < input_len; i++) {
        if (i == 0 || input[i]!= input[i - 1]) {
            duplicate_free_input[k++] = input[i];
        }
    }
    duplicate_free_input[k] = '\0';
    strcpy(input, duplicate_free_input);
    free(duplicate_free_input);

    printf("Sanitized input: %s\n", input);

    return 0;
}