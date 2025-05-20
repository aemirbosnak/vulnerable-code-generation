//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int length;
} Word;

int main() {
    srand(time(NULL));

    // Generate a list of random words
    Word words[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i].length = rand() % MAX_WORD_LENGTH + 1;
        words[i].word = malloc(words[i].length + 1);
        for (int j = 0; j < words[i].length; j++) {
            words[i].word[j] = 'a' + rand() % 26;
        }
        words[i].word[words[i].length] = '\0';
    }

    // Get the user's input
    char input[MAX_WORD_LENGTH + 1];
    printf("Type the following words as fast as you can:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[i].word);
    }
    printf("\n");
    scanf("%s", input);

    // Compare the user's input to the list of words
    int correct = 0;
    int incorrect = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(input, words[i].word) == 0) {
            correct++;
        } else {
            incorrect++;
        }
    }

    // Print the results
    printf("Results:\n");
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);

    // Free the memory allocated for the words
    for (int i = 0; i < MAX_WORDS; i++) {
        free(words[i].word);
    }

    return 0;
}