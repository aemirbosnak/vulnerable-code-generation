//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char *generate_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to count the number of words in a string
int count_words(char *str) {
    int count = 0;
    int in_word = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
    }
    return count;
}

// Function to test the typing speed of the user
void typing_speed_test() {
    // Get the user's name
    char name[100];
    printf("Enter your name, fair maiden or noble knight: ");
    scanf("%s", name);

    // Generate a random string of length 100
    char *str = generate_string(100);

    // Print the string to the user
    printf("\nHark! Thou art tasked with typing this fair string:\n\n%s\n\n", str);

    // Get the current time
    time_t start_time = time(NULL);

    // Get the user's input
    char input[101];
    printf("Begin thy typing, brave adventurer! When thou art finished, press the Enter key: ");
    scanf("%s", input);

    // Get the current time
    time_t end_time = time(NULL);

    // Calculate the time taken
    double time_taken = difftime(end_time, start_time);

    // Calculate the typing speed
    int words_typed = count_words(input);
    double typing_speed = (double)words_typed / time_taken;

    // Print the results
    printf("\nThy typing speed is %.2f words per minute, brave %s!\n", typing_speed, name);

    // Free the allocated memory
    free(str);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Run the typing speed test
    typing_speed_test();

    return 0;
}