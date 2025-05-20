//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of a given length
char *generate_random_string(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = 'a' + rand() % 26;
    }
    string[length] = '\0';
    return string;
}

// Function to get the accuracy of the user's input
float get_accuracy(char *original, char *input) {
    int correct_characters = 0;
    for (int i = 0; i < strlen(original); i++) {
        if (original[i] == input[i]) {
            correct_characters++;
        }
    }
    return (float)correct_characters / strlen(original);
}

// Function to get the speed of the user's input in words per minute (WPM)
float get_speed(char *original, char *input, int time_taken) {
    float words_per_minute = (float)(strlen(original) / 5) * (60 / time_taken);
    return words_per_minute;
}

// Function to run the typing speed test
void run_typing_speed_test() {
    // Generate a random string of 200 characters
    char *original_string = generate_random_string(200);

    // Print the original string to the user
    printf("Type the following string as accurately and quickly as possible:\n\n%s\n", original_string);

    // Start the timer
    clock_t start_time = clock();

    // Get the user's input
    char *input_string = malloc(201);
    scanf("%s", input_string);

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the time taken to type the string
    float time_taken = ((float)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Calculate the accuracy and speed of the user's input
    float accuracy = get_accuracy(original_string, input_string);
    float speed = get_speed(original_string, input_string, time_taken);

    // Print the results to the user
    printf("\nYour accuracy was %.2f%%\n", accuracy * 100);
    printf("Your speed was %.2f WPM\n", speed);

    // Free the allocated memory
    free(original_string);
    free(input_string);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Run the typing speed test
    run_typing_speed_test();

    return 0;
}