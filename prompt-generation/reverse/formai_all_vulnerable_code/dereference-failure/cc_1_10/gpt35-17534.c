//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Sherlock Holmes
// The Adventure of the Coded Drone

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 100

// Function prototypes
char* encode(char* message);
bool validate(char* code);

int main(void) {
    char message[MAX_LEN];
    printf("Enter message to encode: ");
    fgets(message, MAX_LEN, stdin);
    message[strcspn(message, "\n")] = '\0';  // Remove newline character
    printf("Encoded message: %s\n\n", encode(message));

    char code[MAX_LEN];
    printf("Enter code: ");
    fgets(code, MAX_LEN, stdin);
    code[strcspn(code, "\n")] = '\0';  // Remove newline character
    if (validate(code)) {
        printf("\nCode is valid. Drone activated!\n");
        // Code to send signal to activate drone goes here
    } else {
        printf("\nCode is invalid. Drone not activated.\n");
    }

    return 0;
}

/*
 * Encodes a message as per the following rules:
 * - Replace each space with a random uppercase letter
 * - Replace each uppercase letter with its corresponding ASCII code
 * - Append a randomized positive integer as a suffix
 *
 * Returns the encoded message as a dynamically-allocated string.
 */
char* encode(char* message) {
    char* result = malloc(sizeof(char) * (strlen(message) + 10));  // Allocate memory for result
    int suffix = rand() % 10000;  // Generate suffix value
    int i = 0, j = 0;  // Loop variables

    while (message[i] != '\0') {
        if (message[i] == ' ') {
            // Replace space with random uppercase letter
            result[j] = 'A' + rand() % 26;
            j++;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            // Replace uppercase letter with its corresponding ASCII code
            sprintf(&result[j], "%d", (int) message[i]);
            j += strlen(&result[j]);
        } else {
            // Copy over any other character as is
            result[j] = message[i];
            j++;
        }
        i++;
    }

    // Append suffix to result
    sprintf(&result[j], "%d", suffix);

    return result;
}

/*
 * Validates a code as follows:
 * - Must be at least 10 characters long
 * - Must end with a positive integer
 * - All other characters must be either uppercase letters or between 65 and 90 inclusive
 *
 * Returns true if the code is valid, false otherwise.
 */
bool validate(char* code) {
    int len = strlen(code);
    if (len < 10) {
        // Code too short
        return false;
    }

    // Check if last characters are a positive integer
    int i = len - 1;
    while (code[i] >= '0' && code[i] <= '9') {
        i--;
    }
    if (i == len - 1 || i < len - 5) {
        // Last characters are not a valid positive integer
        return false;
    }

    // Check if all other characters are valid
    i = 0;
    while (code[i] != '\0' && i < len - 5) {
        if (code[i] == ' ' || code[i] < 'A' || (code[i] > 'Z' && code[i] < 65) || code[i] > 90) {
            // Invalid character found
            return false;
        }
        i++;
    }

    return true;
}