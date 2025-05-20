//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_WORDS 20
#define WORD_LENGTH 5
#define TIMER_DURATION 60

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
    "lemon",
    "mango",
    "nectarine",
    "orange",
    "pear",
    "quince",
    "raspberry",
    "strawberry",
    "tangerine",
    "watermelon",
    "xylophone"
};

int main() {
    int i, j, score = 0, correct = 0, incorrect = 0;
    char input[WORD_LENGTH + 1];
    char correct_word[WORD_LENGTH + 1];
    time_t start_time, end_time;
    double elapsed_time;

    srand(time(NULL));
    for (i = 0; i < NUM_WORDS; i++) {
        strcpy(correct_word, words[i]);
        j = rand() % WORD_LENGTH;
        strcpy(input, correct_word + j);
        strcat(input, correct_word);
    }

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have %d seconds to type as many words as possible.\n", TIMER_DURATION);
    printf("Press enter to begin:\n");
    getchar();

    start_time = time(NULL);
    while (difftime(time(NULL), start_time) < TIMER_DURATION) {
        printf("%s\n", input);
        fflush(stdout);
        fgets(input, WORD_LENGTH + 1, stdin);
        if (strcmp(input, correct_word) == 0) {
            correct++;
        } else {
            incorrect++;
        }
        score += strlen(input);
        memset(input, 0, WORD_LENGTH + 1);
        strcpy(input, correct_word);
        strcat(input, correct_word);
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("\nTest complete! Your score is %d points.\n", score);
    printf("You typed %d words correctly and %d words incorrectly.\n", correct, incorrect);
    printf("Your typing speed is %d words per minute.\n", (int) (score / (elapsed_time / 60)));

    return 0;
}