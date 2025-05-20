//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// A rudimentary function to generate a random string of length n
char *generate_random_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

int main() {
    srand(time(NULL));

    printf("Elementary, my dear Watson! Let us test your typing speed.\n");
    printf("Prepare to transcribe the following passage at your utmost haste:\n\n");

    char *passage = generate_random_string(200);
    printf("%s\n", passage);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char *user_input = malloc(201);
    scanf("%s", user_input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the typing speed in words per minute (WPM)
    double time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    int num_words = user_input[0] == '\0' ? 0 : 1;
    for (int i = 1; i < strlen(user_input); i++) {
        if (user_input[i] == ' ') {
            num_words++;
        }
    }
    double wpm = num_words / time_elapsed * 60;

    // Check if the user's input matches the passage
    int is_correct = strcmp(user_input, passage) == 0;

    // Print the results
    printf("Your typing speed is %.2f WPM.\n", wpm);
    if (is_correct) {
        printf("Well done, Watson! Your transcription is correct.\n");
    } else {
        printf("Alas, Watson, your transcription contains errors.\n");
    }

    free(passage);
    free(user_input);

    return 0;
}