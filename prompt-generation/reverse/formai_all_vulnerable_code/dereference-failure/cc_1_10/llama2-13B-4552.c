//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Function to handle errors
void handle_error(const char *message) {
    // Print the error message and the corresponding error number
    fprintf(stderr, "%s: %s\n", message, strerror(errno));

    // Exit the program with a non-zero status
    exit(EXIT_FAILURE);
}

int main() {
    // Get the name and age from the user
    char name[MAX_NAME_LENGTH];
    int age;
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    printf("Enter your age: ");
    scanf("%d", &age);

    // Check if the name is valid
    if (name[0] == '\0' || name[MAX_NAME_LENGTH - 1] == '\0') {
        handle_error("Invalid name");
    }

    // Check if the age is valid
    if (age < 0 || age > MAX_AGE) {
        handle_error("Invalid age");
    }

    // Do some work here
    printf("Hello, %s! You are %d years old.\n", name, age);

    // Handle errors that may occur during the work
    if (do_some_work() == -1) {
        handle_error("Error during work");
    }

    return 0;
}

int do_some_work() {
    // Perform some calculations
    int result = calculate_something();

    // Check if the calculation failed
    if (result == -1) {
        handle_error("Calculation failed");
    }

    return result;
}

int calculate_something() {
    // Perform some calculations
    int result = 0;

    // Check if the calculation failed
    if (result == 0) {
        handle_error("Calculation failed");
    }

    return result;
}