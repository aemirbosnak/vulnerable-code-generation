//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_INPUT_LENGTH 1000

/* Function to sanitize user input */
void sanitize_input(char *input) {
    int i;
    for(i = 0; input[i]!= '\0'; i++) {
        if(!isprint(input[i])) {
            input[i] = '_';
        }
    }
}

/* Function to get user input */
char* get_input(char* prompt) {
    char input[MAX_INPUT_LENGTH];
    printf("%s", prompt);
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    sanitize_input(input);
    return strdup(input);
}

/* Function to check if input is valid */
int is_valid_input(char* input) {
    int i;
    for(i = 0; input[i]!= '\0'; i++) {
        if(!isprint(input[i])) {
            return 0;
        }
    }
    return 1;
}

/* Function to get valid user input */
char* get_valid_input(char* prompt) {
    char* input = get_input(prompt);
    while(!is_valid_input(input)) {
        printf("Invalid input. Please try again.\n");
        free(input);
        input = get_input(prompt);
        sanitize_input(input);
    }
    return input;
}

int main() {
    char* name = get_valid_input("Enter your name: ");
    printf("Hello, %s!\n", name);
    free(name);
    return 0;
}