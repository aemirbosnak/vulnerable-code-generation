//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_LENGTH 20
#define NUM_WORDS 10
#define DELAY 1000000

void print_words(char *words[]) {
    int i;

    for (i = 0; i < NUM_WORDS; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

int main() {
    char *words[NUM_WORDS];
    char input[NUM_WORDS][WORD_LENGTH];
    int i;

    srand(time(NULL));

    for (i = 0; i < NUM_WORDS; i++) {
        words[i] = malloc(WORD_LENGTH * sizeof(char));
        for (int j = 0; j < WORD_LENGTH; j++) {
            input[i][j] = 65 + rand() % 26; // Randomly generate words with only lowercase letters
            words[i][j] = toupper(words[i][j]); // Display words in uppercase for easier reading
        }
        words[i][WORD_LENGTH] = '\0'; // Null terminate each word
    }

    printf("Preparing words...\n");
    print_words(words);
    printf("Ready? Type the following words as fast as you can:\n");

    clock_t start = clock();
    for (i = 0; i < NUM_WORDS; i++) {
        fflush(stdout); // Flush output buffer to ensure words are displayed before comparing input
        scanf("%s", input[i]);
        if (strcmp(input[i], words[i]) != 0) {
            printf("Incorrect: %s, Expected: %s\n", input[i], words[i]);
            i--; // Try again if incorrect
        }
    }

    clock_t end = clock();
    double time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Words typed correctly in %.2f seconds.\n", time_spent);

    for (i = 0; i < NUM_WORDS; i++) {
        free(words[i]);
    }

    return 0;
}