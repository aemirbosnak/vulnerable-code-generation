//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20
#define MAX_TEST_DURATION 60 // in seconds

typedef struct {
    char word[MAX_WORD_LEN];
    int length;
} Word;

Word words[MAX_WORDS];
int numWords;

void generateWords() {
    srand(time(NULL));
    numWords = 0;
    FILE *file = fopen("words.txt", "r");
    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, file)!= NULL && numWords < MAX_WORDS) {
        int len = strlen(line);
        if (len > 0 && isalpha(line[0])) {
            strcpy(words[numWords].word, line);
            words[numWords].length = len;
            numWords++;
        }
    }
    fclose(file);
}

void shuffleWords() {
    for (int i = 0; i < numWords; i++) {
        int j = rand() % numWords;
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

int main() {
    generateWords();
    shuffleWords();
    int score = 0;
    int incorrect = 0;
    int currentWord = 0;
    int startTime = time(NULL);
    char buffer[MAX_WORD_LEN];
    while (time(NULL) - startTime < MAX_TEST_DURATION) {
        printf("Type the word '%s': ", words[currentWord].word);
        fgets(buffer, MAX_WORD_LEN, stdin);
        if (strcasecmp(buffer, words[currentWord].word) == 0) {
            score++;
        } else {
            incorrect++;
        }
        currentWord++;
        if (currentWord >= numWords) {
            currentWord = 0;
        }
    }
    printf("\nTest complete.\n");
    printf("Score: %d out of %d\n", score, numWords);
    printf("Incorrect: %d\n", incorrect);
    return 0;
}