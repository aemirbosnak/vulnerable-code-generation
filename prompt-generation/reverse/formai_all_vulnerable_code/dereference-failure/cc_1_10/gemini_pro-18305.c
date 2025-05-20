//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of characters
char *generate_string(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = (rand() % 26) + 'a';
    }
    string[length] = '\0';
    return string;
}

// Function to test the user's typing speed
int test_typing_speed(char *string) {
    printf("Type the following string as quickly and accurately as possible:\n\n%s\n", string);

    // Start the timer
    clock_t start_time = clock();

    // Get the user's input
    char *input = malloc(strlen(string) + 1);
    scanf("%s", input);

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the user's typing speed
    int time_taken = (end_time - start_time) / CLOCKS_PER_SEC;
    int typing_speed = strlen(string) / time_taken;

    // Free the allocated memory
    free(string);
    free(input);

    return typing_speed;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random string of characters
    char *string = generate_string(100);

    // Test the user's typing speed
    int typing_speed = test_typing_speed(string);

    // Print the user's typing speed
    printf("Your typing speed is %d words per minute.\n", typing_speed);

    return 0;
}