//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define WORD_LENGTH 6
#define DELAY_TIME 1

char words[MAX_WORDS][WORD_LENGTH] = {
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
    "xylophone",
    "yellow",
    "zebra"
};

int main() {
    int numWords = 0, correctWords = 0;
    int startTime, endTime, elapsedTime;
    char input[WORD_LENGTH + 1];

    srand(time(NULL));
    numWords = rand() % MAX_WORDS + 1;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will have %d seconds to type as many words as possible.\n", DELAY_TIME);
    printf("Press enter to begin...\n");

    fgets(input, sizeof(input), stdin);

    startTime = clock();

    while (numWords > 0) {
        int wordIndex = rand() % MAX_WORDS;
        char *word = words[wordIndex];

        printf("%s\n", word);
        fgets(input, sizeof(input), stdin);

        if (strcmp(word, input) == 0) {
            correctWords++;
        }

        numWords--;
    }

    endTime = clock();
    elapsedTime = (endTime - startTime) / (double)CLOCKS_PER_SEC;

    printf("\nYou typed %d words correctly out of %d.\n", correctWords, numWords);
    printf("Your typing speed is %d words per second.\n", (int)(numWords / elapsedTime));

    return 0;
}