//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 100

// Function to get user input
int get_user_input(char *name, int *age) {
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    printf("Enter your age: ");
    int age_input;
    scanf("%d", &age_input);
    *age = age_input;

    if (age_input < 0 || age_input > MAX_AGE) {
        printf("Invalid age. Please enter a valid age between 0 and %d.\n", MAX_AGE);
        return 0; // Exit function if age is invalid
    }

    return 1; // Return 1 if input is valid
}

// Function to print a message and exit
void print_error_message(const char *message) {
    perror(message);
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

int main() {
    char name[MAX_NAME_LENGTH];
    int age;

    // Get user input
    if (!get_user_input(name, &age)) {
        print_error_message("Invalid input");
    }

    // Do something with the input
    printf("Hello, %s! You are %d years old.\n", name, age);

    // Clean up
    free(name);

    return 0;
}