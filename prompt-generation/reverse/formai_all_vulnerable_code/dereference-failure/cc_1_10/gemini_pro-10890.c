//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// Global variables
char *text, *user_text;
int text_len, user_len, errors, chars_per_sec;
pthread_t tid;

// Thread function to calculate typing speed
void *calc_speed(void *arg) {
    int i;
    time_t start = time(NULL);
    for (i = 0; i < text_len; i++) {
        if (user_text[i] != text[i]) {
            errors++;
        }
    }

    chars_per_sec = user_len / (time(NULL) - start);

    return NULL;
}

int main() {
    // Get the text to be typed
    printf("Enter the text to be typed:\n");
    text = malloc(1024);
    fgets(text, 1024, stdin);
    text_len = strlen(text);

    // Get the user's input
    user_text = malloc(1024);
    printf("Start typing (press Enter to finish):\n");
    fgets(user_text, 1024, stdin);
    user_len = strlen(user_text);

    // Create a thread to calculate typing speed
    pthread_create(&tid, NULL, calc_speed, NULL);

    // Wait for the thread to finish
    pthread_join(tid, NULL);

    // Print the results
    printf("Errors: %d\n", errors);
    printf("Typing speed: %d characters per second\n", chars_per_sec);

    // Free memory
    free(text);
    free(user_text);

    return 0;
}