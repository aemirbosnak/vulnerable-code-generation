//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_LENGTH 5
#define NUM_WORDS 10

char words[NUM_WORDS][WORD_LENGTH] = {
    "apple",
    "banana",
    "cherry",
    "date",
    "elderberry",
    "fig",
    "grape",
    "honeydew",
    "kiwi",
    "lemon"
};

int main() {
    int i, j, correct = 0, incorrect = 0, skipped = 0;
    char input[WORD_LENGTH];
    int score = 0;
    int wpm = 0;
    int cpm = 0;
    int elapsed_time = 0;
    int characters_typed = 0;
    int words_typed = 0;
    int errors = 0;
    int total_words = NUM_WORDS;
    int current_word = 0;
    int current_letter = 0;
    time_t start_time, end_time;

    srand(time(NULL));
    current_word = rand() % NUM_WORDS;
    printf("Type the following words:\n");
    for (i = 0; i < current_word; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    start_time = time(NULL);
    while (current_word < NUM_WORDS) {
        for (j = 0; j < WORD_LENGTH; j++) {
            if (words[current_word][j] == '\0') {
                current_word++;
                break;
            }
            printf("%c", words[current_word][j]);
        }
        current_letter++;
        if (current_letter == WORD_LENGTH) {
            current_word++;
            current_letter = 0;
            printf("\n");
        }
        fflush(stdout);
    }

    end_time = time(NULL);
    elapsed_time = end_time - start_time;

    printf("\nTest complete.\n");
    printf("Elapsed time: %d seconds\n", elapsed_time);
    characters_typed = current_word * WORD_LENGTH;
    words_typed = current_word;
    wpm = (characters_typed / 5) * 60;
    cpm = characters_typed / (elapsed_time / 60);

    printf("Words per minute: %d\n", wpm);
    printf("Characters per minute: %d\n", cpm);
    printf("Accuracy: %.2f%%\n", ((float) correct / words_typed) * 100);
    printf("Errors: %d\n", errors);

    return 0;
}