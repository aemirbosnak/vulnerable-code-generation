//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define TEXT_SIZE 100  // Size of the text to be typed
#define BUFF_SIZE 100 // Size of the buffer for user input

// Function to generate random text
char *generate_text(int size) {
    char *text = malloc(size + 1);
    for (int i = 0; i < size; i++) {
        text[i] = 'a' + rand() % 26;
    }
    text[size] = '\0';
    return text;
}

// Function to get user input
void get_user_input(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strlen(buffer) - 1] = '\0';  // Remove newline character
}

// Function to compare user input to the original text
int compare_input(char *input, char *text) {
    int errors = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != text[i]) {
            errors++;
        }
    }
    return errors;
}

// Function to calculate typing speed
double calculate_speed(int errors, int time) {
    double speed = (TEXT_SIZE - errors) / (time / 60.0);
    return speed;
}

// Function to run the typing test
void run_test() {
    // Generate random text
    char *text = generate_text(TEXT_SIZE);

    // Display the text to the user
    printf("Type the following text:\n%s\n", text);

    // Get user input
    char buffer[BUFF_SIZE];
    get_user_input(buffer, BUFF_SIZE);

    // Calculate time taken
    time_t start = time(NULL);
    time_t end = time(NULL);
    int time_taken = end - start;

    // Compare user input to the original text
    int errors = compare_input(buffer, text);

    // Calculate typing speed
    double speed = calculate_speed(errors, time_taken);

    // Display the results
    printf("Errors: %d\n", errors);
    printf("Time taken: %d seconds\n", time_taken);
    printf("Typing speed: %.2f words per minute\n", speed);

    // Free the allocated memory
    free(text);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Run the typing test
    run_test();

    return 0;
}