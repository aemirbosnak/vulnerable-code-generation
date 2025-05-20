//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string
char* generate_random_string(int length) {
    char* str = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        str[i] = (rand() % 26) + 'a';
    }

    str[length] = '\0';

    return str;
}

// Function to test the typing speed
int test_typing_speed(char* str) {
    int length = strlen(str);

    // Start the timer
    time_t start = time(NULL);

    // Get the user's input
    char* input = malloc(length + 1);
    scanf("%s", input);

    // Stop the timer
    time_t end = time(NULL);

    // Calculate the elapsed time
    double elapsed_time = difftime(end, start);

    // Calculate the typing speed
    double typing_speed = (double)length / elapsed_time;

    // Free the allocated memory
    free(str);
    free(input);

    return (int)typing_speed;
}

// Function to print the results
void print_results(int typing_speed) {
    printf("Your typing speed is %d words per minute.\n", typing_speed);

    if (typing_speed >= 60) {
        printf("Excellent!");
    } else if (typing_speed >= 40) {
        printf("Good!");
    } else if (typing_speed >= 20) {
        printf("Fair!");
    } else {
        printf("Needs improvement!");
    }
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random string
    char* str = generate_random_string(100);

    // Test the typing speed
    int typing_speed = test_typing_speed(str);

    // Print the results
    print_results(typing_speed);

    return 0;
}