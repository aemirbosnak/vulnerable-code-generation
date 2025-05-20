//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random string
char *generate_random_string(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = 'a' + rand() % 26;
    }
    string[length] = '\0';
    return string;
}

// Function to test typing speed
void test_typing_speed() {
    // Generate a random string
    char *string = generate_random_string(100);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char input[101];
    printf("Type the following string as quickly as possible:\n%s\n", string);
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    int typing_speed = (int)(strlen(string) / time_taken) * 60;

    // Print the results
    printf("Your typing speed is %d words per minute.\n", typing_speed);

    // Free the memory allocated for the string
    free(string);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Test the user's typing speed
    test_typing_speed();

    return 0;
}