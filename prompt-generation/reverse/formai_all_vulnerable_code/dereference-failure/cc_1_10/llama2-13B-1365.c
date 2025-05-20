//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BRAVE_MODE 1

int main() {
    int i, j, k;
    char *arr[3];
    char *word;

    // Brave Mode Activated! 💪
    if (BRAVE_MODE) {
        printf("Welcome to the Brave C Programming Adventure! 🌟\n");
    }

    // Generate a Random Word
    word = malloc(10 * sizeof(char));
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        arr[i] = malloc(1 * sizeof(char));
        arr[i][0] = 'a' + (rand() % 26);
    }
    strcat(word, arr[rand() % 3]);

    // Brave Mode Challenges 🔥
    if (BRAVE_MODE) {
        printf("Your challenge is to guess the word: %s\n", word);
        printf("You have 3 attempts left. Good luck! 🍀\n");
    }

    // Guessing Loop
    for (i = 0; i < 3; i++) {
        printf("Enter your guess: ");
        scanf("%s", arr[i]);
        if (strcmp(arr[i], word) == 0) {
            printf("Correct! You guessed it right! 🎉\n");
            break;
        } else {
            printf("Incorrect. Try again! 😅\n");
        }
    }

    // Brave Mode Conclusion 💥
    if (BRAVE_MODE) {
        printf("You have completed the Brave C Programming Adventure! 🎉\n");
        printf("You guessed the word: %s\n", word);
    }

    // Free Memory 🧾
    for (i = 0; i < 3; i++) {
        free(arr[i]);
    }
    free(word);

    return 0;
}