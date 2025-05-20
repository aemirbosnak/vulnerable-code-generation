//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10

typedef struct {
    char *word;
    int length;
} Word;

int main() {
    int i, j, score = 0, correct = 0;
    char input[50];
    Word words[MAX_WORDS];
    srand(time(NULL));

    // Initialize words array
    for (i = 0; i < MAX_WORDS; i++) {
        words[i].word = (char*)malloc(10 * sizeof(char));
        words[i].length = rand() % 10 + 1;
        for (j = 0; j < words[i].length; j++) {
            words[i].word[j] = rand() % 26 + 'a';
        }
        words[i].word[words[i].length] = '\0';
    }

    // Start typing test
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will be typing %d words.\n", MAX_WORDS);
    printf("Each word will appear on the screen for 5 seconds.\n\n");

    for (i = 0; i < MAX_WORDS; i++) {
        printf("Word %d: %s\n", i+1, words[i].word);
        sleep(5);
        fgets(input, sizeof(input), stdin);

        // Check if input matches word
        correct = 1;
        for (j = 0; j < words[i].length; j++) {
            if (input[j]!= words[i].word[j]) {
                correct = 0;
                break;
            }
        }

        // Update score
        if (correct) {
            score++;
        }
    }

    // Display results
    printf("\nYour score is: %d out of %d\n", score, MAX_WORDS);

    return 0;
}