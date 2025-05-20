//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of length n
char *generate_random_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to calculate the typing speed
int calculate_typing_speed(char *str, int time) {
    int len = strlen(str);
    return (len / time) * 60;
}

// Function to print the results
void print_results(int speed) {
    printf("Your typing speed is %d words per minute.\n", speed);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random string of length 100
    char *str = generate_random_string(100);

    // Start the timer
    time_t start = time(NULL);

    // Get the input from the user
    char input[101];
    printf("Type the following string as fast as you can:\n%s\n", str);
    scanf("%s", input);

    // Stop the timer
    time_t end = time(NULL);

    // Calculate the time taken
    int time = end - start;

    // Calculate the typing speed
    int speed = calculate_typing_speed(str, time);

    // Print the results
    print_results(speed);

    return 0;
}