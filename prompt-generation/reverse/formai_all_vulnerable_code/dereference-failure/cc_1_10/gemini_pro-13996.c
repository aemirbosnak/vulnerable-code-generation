//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char *generate_random_string(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = 'a' + rand() % 26;
    }
    string[length] = '\0';
    return string;
}

// Function to get the time in milliseconds
double get_time_in_milliseconds() {
    struct timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    return (double)time.tv_sec * 1000.0 + (double)time.tv_nsec / 1000000.0;
}

// Function to run the typing speed test
void run_typing_speed_test() {
    // Generate a random string of length 100
    char *string = generate_random_string(100);

    // Get the starting time
    double start_time = get_time_in_milliseconds();

    // Prompt the user to type the string
    printf("Type the following string as quickly and accurately as possible:\n\n%s\n\n", string);

    // Get the user's input
    char *input = malloc(101);
    scanf("%s", input);

    // Get the ending time
    double end_time = get_time_in_milliseconds();

    // Calculate the time taken
    double time_taken = end_time - start_time;

    // Calculate the typing speed in words per minute (WPM)
    double wpm = ((double)strlen(string) / 5.0) / (time_taken / 60000.0);

    // Print the results
    printf("\nYour typing speed is %.2f WPM.\n", wpm);

    // Free the allocated memory
    free(string);
    free(input);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Run the typing speed test
    run_typing_speed_test();

    return 0;
}