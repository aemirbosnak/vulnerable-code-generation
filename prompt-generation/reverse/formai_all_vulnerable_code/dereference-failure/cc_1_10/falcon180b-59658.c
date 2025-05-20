//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    char input[MAX_LEN];
    char output[MAX_LEN];
    char *token;
    int count = 0;

    printf("Enter a string: ");
    fgets(input, MAX_LEN, stdin);

    // Remove leading/trailing spaces
    input[strcspn(input, "\n")] = '\0';
    strcpy(output, input);
    strtok(output, " ");
    strcpy(input, output);

    // Count words
    token = strtok(input, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    // Reverse string
    char *start = input;
    char *end = input + strlen(input) - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    // Convert to uppercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Print results
    printf("Original string: %s\n", input);
    printf("Number of words: %d\n", count);
    printf("Reversed string: %s\n", input);
    printf("Uppercase string: %s\n", input);

    return 0;
}