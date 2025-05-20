//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string
void generate_string(char* str, int len) {
    for (int i = 0; i < len; i++) {
        str[i] = rand() % 26 + 'a'; // Generate a random lowercase letter
    }
    str[len] = '\0'; // Add null terminator
}

// Function to check if the user's input matches the generated string
int check_input(char* input, char* correct) {
    for (int i = 0; i < strlen(correct); i++) {
        if (input[i]!= correct[i]) {
            return 0; // Input does not match
        }
    }
    return 1; // Input matches
}

int main() {
    int num_tests, max_len, min_len, correct_count = 0;
    char input[100];

    // Get user input for number of tests and string length range
    printf("Enter number of tests: ");
    scanf("%d", &num_tests);
    printf("Enter minimum string length: ");
    scanf("%d", &min_len);
    printf("Enter maximum string length: ");
    scanf("%d", &max_len);

    // Seed random number generator with current time
    srand(time(NULL));

    for (int i = 0; i < num_tests; i++) {
        int len = rand() % (max_len - min_len + 1) + min_len; // Generate random length within range
        char correct[100];
        generate_string(correct, len); // Generate random string

        // Print the string for the user to type
        printf("Test %d: %s\n", i + 1, correct);

        // Get user input and check if it matches the correct string
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character from input
        if (check_input(input, correct)) {
            correct_count++;
        }
    }

    // Print results
    printf("You got %d out of %d correct.\n", correct_count, num_tests);

    return 0;
}