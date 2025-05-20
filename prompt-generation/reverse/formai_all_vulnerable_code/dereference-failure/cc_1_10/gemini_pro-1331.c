//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store test results
typedef struct {
    int words_per_minute;
    float accuracy;
} TestResult;

// Function to generate random text
char *generate_text(int length) {
    char *text = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        char c = 'a' + rand() % 26;
        text[i] = c;
    }
    text[length] = '\0';
    return text;
}

// Function to get user input
char *get_user_input() {
    char *input = NULL;
    size_t len = 0;
    getline(&input, &len, stdin);
    return input;
}

// Function to calculate words per minute
int calculate_wpm(char *text, char *input) {
    // Remove trailing whitespace from input
    int input_len = strlen(input);
    while (input_len > 0 && isspace(input[input_len - 1])) {
        input_len--;
    }
    input[input_len] = '\0';

    // Calculate number of words in text
    int text_words = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (isspace(text[i])) {
            text_words++;
        }
    }
    text_words++;

    // Calculate number of correct words in input
    int correct_words = 0;
    char *input_ptr = input;
    char *text_ptr = text;
    while (*input_ptr != '\0' && *text_ptr != '\0') {
        if (*input_ptr == *text_ptr) {
            correct_words++;
            input_ptr++;
            text_ptr++;
        } else {
            if (isspace(*input_ptr)) {
                input_ptr++;
            } else if (isspace(*text_ptr)) {
                text_ptr++;
            } else {
                input_ptr++;
                text_ptr++;
            }
        }
    }

    // Calculate words per minute
    return (int) ((float) correct_words / text_words * 60);
}

// Function to calculate accuracy
float calculate_accuracy(char *text, char *input) {
    // Remove trailing whitespace from input
    int input_len = strlen(input);
    while (input_len > 0 && isspace(input[input_len - 1])) {
        input_len--;
    }
    input[input_len] = '\0';

    // Calculate number of correct characters in input
    int correct_chars = 0;
    for (int i = 0; i < strlen(text) && i < input_len; i++) {
        if (text[i] == input[i]) {
            correct_chars++;
        }
    }

    // Calculate accuracy
    return (float) correct_chars / strlen(text);
}

// Main function
int main() {
    // Generate random text
    char *text = generate_text(500);

    // Get user input
    printf("Type the following text as accurately and quickly as possible:\n\n");
    printf("%s\n", text);
    printf("\nPress Enter to start the test.\n");
    getchar();

    time_t start_time = time(NULL);
    char *input = get_user_input();
    time_t end_time = time(NULL);

    // Calculate test results
    int wpm = calculate_wpm(text, input);
    float accuracy = calculate_accuracy(text, input);

    // Print test results
    printf("\nTest Results:\n");
    printf("Words per minute: %d\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy * 100);

    // Free memory
    free(text);
    free(input);

    return 0;
}