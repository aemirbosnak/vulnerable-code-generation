//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_COUNT 10
#define WORD_LENGTH 10
#define WPM_THRESHOLD 60
#define MAX_ERRORS 3

struct word {
    char word[WORD_LENGTH];
    int length;
};

struct word words[WORD_COUNT] = {
    {"programming", 11},
    {"typing", 6},
    {"speed", 5},
    {"test", 4},
    {"example", 7},
    {"code", 4},
    {"snippet", 7},
    {"expert", 6},
    {"style", 5},
    {"unique", 6}
};

int main() {
    int i, j, errors = 0, wpm = 0;
    char input[WORD_LENGTH];
    time_t start, end;
    struct tm *t;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will be typing %d words with a minimum WPM of %d.\n", WORD_COUNT, WPM_THRESHOLD);
    printf("Press enter to begin...\n");
    getchar();

    time(&start);

    for (i = 0; i < WORD_COUNT; i++) {
        printf("Word %d: ", i + 1);
        for (j = 0; j < words[i].length; j++) {
            printf("*");
        }
        printf("\n");
        fflush(stdout);
        gets(input);
        if (strcmp(input, words[i].word)!= 0) {
            errors++;
        }
    }

    time(&end);
    t = localtime(&end);

    wpm = (WORD_COUNT - errors) * 60 / (end - start);

    if (wpm >= WPM_THRESHOLD) {
        printf("Congratulations! You have passed the C Typing Speed Test!\n");
    } else {
        printf("Sorry, you did not pass the C Typing Speed Test.\n");
    }

    printf("Your final WPM is: %d\n", wpm);
    printf("Your accuracy is: %d%%\n", (100 - errors * 10));

    return 0;
}