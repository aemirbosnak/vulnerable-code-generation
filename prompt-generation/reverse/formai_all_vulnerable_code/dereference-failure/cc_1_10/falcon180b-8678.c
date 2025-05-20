//Falcon-180B DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to tokenize a string
int tokenize(char* input, char* tokens[], int max_tokens) {
    int i = 0;
    char* token = strtok(input, " ");
    while (token!= NULL && i < max_tokens) {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return i;
}

// Function to reverse a string
char* reverse_string(char* input) {
    int length = strlen(input);
    char* reversed = malloc(length + 1);
    int i = 0;
    for (int j = length - 1; j >= 0; j--) {
        reversed[i++] = input[j];
    }
    reversed[i] = '\0';
    return reversed;
}

// Function to capitalize a string
char* capitalize_string(char* input) {
    int length = strlen(input);
    char* capitalized = malloc(length + 1);
    int i = 0;
    for (int j = 0; j < length; j++) {
        if (isalpha(input[j])) {
            capitalized[i++] = toupper(input[j]);
        } else {
            capitalized[i++] = input[j];
        }
    }
    capitalized[i] = '\0';
    return capitalized;
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s input\n", argv[0]);
        return 1;
    }
    char* input = argv[1];
    char* tokens[100];
    int num_tokens = tokenize(input, tokens, 100);
    for (int i = 0; i < num_tokens; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");
    for (int i = 0; i < num_tokens; i++) {
        char* reversed = reverse_string(tokens[i]);
        printf("%s ", reversed);
        free(reversed);
    }
    printf("\n");
    for (int i = 0; i < num_tokens; i++) {
        char* capitalized = capitalize_string(tokens[i]);
        printf("%s ", capitalized);
        free(capitalized);
    }
    printf("\n");
    return 0;
}