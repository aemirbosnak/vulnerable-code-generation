//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function to generate a random string of characters
char* generate_random_string(int length) {
    char* str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = (char)(rand() % 26 + 97);
    }
    str[length] = '\0';
    return str;
}

// Function to calculate the typing speed
int calculate_typing_speed(char* target_string, char* typed_string, int time_taken) {
    int correct_characters = 0;
    for (int i = 0; i < strlen(target_string); i++) {
        if (target_string[i] == typed_string[i]) {
            correct_characters++;
        }
    }
    int typing_speed = (correct_characters * 60) / time_taken;
    return typing_speed;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random string of characters
    int length = 100;
    char* target_string = generate_random_string(length);

    // Display the target string to the user
    printf("Type the following string as accurately and quickly as possible:\n");
    printf("%s\n", target_string);

    // Start the timer
    time_t start_time = time(NULL);

    // Get the user's input
    char typed_string[length + 1];
    scanf("%s", typed_string);

    // Stop the timer
    time_t end_time = time(NULL);

    // Calculate the time taken
    int time_taken = end_time - start_time;

    // Calculate the typing speed
    int typing_speed = calculate_typing_speed(target_string, typed_string, time_taken);

    // Display the typing speed to the user
    printf("Your typing speed is %d words per minute.\n", typing_speed);

    return 0;
}