//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

// Function to check if a character is valid
int is_valid_char(char c) {
    if (c >= 32 && c <= 126) {
        return 1;
    }
    return 0;
}

// Function to sanitize input
void sanitize_input(char* input) {
    int i, j;
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (is_valid_char(input[i])) {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';
}

// Function to get input from user
char* get_input(char* prompt) {
    char input[MAX_INPUT_SIZE];
    printf("%s", prompt);
    fgets(input, MAX_INPUT_SIZE, stdin);
    sanitize_input(input);
    return strdup(input);
}

int main() {
    char* name;

    // Get user's name
    name = get_input("What is your name? ");
    printf("Hello, %s! \n", name);

    // Get user's age
    char* age_input = get_input("How old are you? ");
    int age;
    if (sscanf(age_input, "%d", &age)!= 1 || age < 0) {
        printf("Invalid age. \n");
    } else {
        printf("You are %d years old. \n", age);
    }

    return 0;
}