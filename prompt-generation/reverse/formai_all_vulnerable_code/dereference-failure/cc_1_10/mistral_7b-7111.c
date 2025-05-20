//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define WORD_LENGTH 30
#define NUM_ROUNDS 5

// Function to generate random words
char* generateWord(int length) {
    char *word = (char*)malloc(length * sizeof(char));
    int i;
    for (i = 0; i < length; i++) {
        word[i] = 65 + rand() % 26; // Generate random character from alphabet
    }
    word[length] = '\0'; // Null terminate the string
    return word;
}

// Function to print a word on the console
void printWord(char* word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        printf("%c", word[i]);
        fflush(stdout); // Flush output buffer to ensure immediate display
        usleep(50000); // Sleep for 50ms to simulate typing delay
    }
    printf("\n");
}

int main() {
    int rounds, i, j, k;
    char* words[MAX_WORDS];
    clock_t start, end;

    srand(time(NULL)); // Seed random number generator

    // Generate words
    for (i = 0; i < MAX_WORDS; i++) {
        words[i] = generateWord(rand() % WORD_LENGTH + WORD_LENGTH);
    }

    printf("Welcome to the Typing Speed Test!\n");
    printf("Press enter to begin...\n");
    getchar();

    // Start timer
    start = clock();

    for (rounds = 0; rounds < NUM_ROUNDS; rounds++) {
        int score = 0;
        for (i = 0; i < MAX_WORDS; i++) {
            printf("\nType the following word: ");
            printWord(words[i]);
            scanf("%s", words[i]);
            if (strcmp(words[i], words[i]) == 0) { // Compare entered word with the original word
                score += strlen(words[i]);
            }
        }
        printf("\nRound %d completed. Your score for this round is %d characters.\n", rounds + 1, score);
    }

    // End timer
    end = clock();

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTotal time taken to complete all rounds: %.2f seconds.\n", timeTaken);
    printf("\nYour average typing speed is %.2f characters per second.\n", (MAX_WORDS * WORD_LENGTH) / timeTaken);

    // Free memory allocated for words
    for (i = 0; i < MAX_WORDS; i++) {
        free(words[i]);
    }

    return 0;
}