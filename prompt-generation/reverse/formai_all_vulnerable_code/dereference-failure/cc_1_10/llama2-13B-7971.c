//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX_LENGTH 1024

// Function to handle errors
void handle_error(const char *func, const char *msg) {
    printf("Error in %s(): %s\n", func, msg);

    // Print the error code and message
    printf("Error code: %d (%s)\n", errno, strerror(errno));

    // Exit the program with a non-zero status
    exit(EXIT_FAILURE);
}

int main() {
    // Variables to store user input
    char name[MAX_LENGTH];
    int age;

    // Ask the user for their name and age
    printf("What is your name? ");
    fgets(name, MAX_LENGTH, stdin);
    printf("How old are you? ");
    scanf("%d", &age);

    // Check for invalid input
    if (name[0] == '\0' || age < 0) {
        handle_error("main", "Invalid input");
    }

    // Perform some calculations and check for errors
    int result = calculate_result(name, age);

    if (result < 0) {
        handle_error("calculate_result", "Error calculating result");
    }

    // Print the result
    printf("Your result is %d\n", result);

    return 0;
}

int calculate_result(const char *name, int age) {
    // Perform some calculations
    int result = age * 2;

    // Check for errors
    if (result < 0) {
        handle_error("calculate_result", "Error calculating result");
    }

    return result;
}