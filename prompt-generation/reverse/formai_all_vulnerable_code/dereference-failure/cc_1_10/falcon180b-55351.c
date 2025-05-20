//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_LENGTH 5
#define NUM_WORDS 10
#define MAX_ATTEMPTS 3
#define DELAY_TIME 1000

char words[NUM_WORDS][WORD_LENGTH + 1] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};
int word_indices[NUM_WORDS];
int attempt_count = 0;

void shuffle_words() {
    for (int i = 0; i < NUM_WORDS; i++) {
        int j = rand() % NUM_WORDS;
        char temp[WORD_LENGTH + 1];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
        word_indices[i] = j;
    }
}

int main() {
    srand(time(NULL));
    shuffle_words();

    int correct_attempts = 0;
    int incorrect_attempts = 0;

    for (int i = 0; i < NUM_WORDS || attempt_count >= MAX_ATTEMPTS; i++) {
        printf("Word %d: ", i + 1);
        char input[WORD_LENGTH + 1];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i]) == 0) {
            correct_attempts++;
        } else {
            incorrect_attempts++;
        }

        if (attempt_count == MAX_ATTEMPTS) {
            printf("You ran out of attempts. Your final score is %d out of %d.\n", correct_attempts, NUM_WORDS);
            return 0;
        }

        attempt_count++;

        if (correct_attempts == NUM_WORDS) {
            printf("Congratulations! You got all %d words correct!\n", NUM_WORDS);
            return 0;
        }

        if (incorrect_attempts == MAX_ATTEMPTS - 1) {
            printf("One more incorrect attempt and you're out of the game.\n");
        }

        usleep(DELAY_TIME);
    }

    return 0;
}