//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_TIME 60

typedef struct {
    char word[20];
    int len;
} Word;

Word words[MAX_WORDS];
int numWords = 0;

void initWords() {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error opening words file.\n");
        exit(1);
    }
    char line[100];
    while (fgets(line, 100, fp)!= NULL) {
        strcpy(words[numWords].word, line);
        words[numWords].len = strlen(line);
        numWords++;
    }
    fclose(fp);
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
    int score = 0;
    int wrong = 0;
    int timeLeft = MAX_TIME;
    int wordIndex = rand() % numWords;
    initWords();
    shuffleWords();
    printf("Welcome to the Typing Speed Test!\n");
    printf("You have %d seconds to type as many words as possible.\n", MAX_TIME);
    printf("Press enter to begin...\n");
    getchar();
    while (timeLeft > 0) {
        printf("%s", words[wordIndex].word);
        fflush(stdout);
        char input[20];
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, words[wordIndex].word) == 0) {
            score++;
        } else {
            wrong++;
        }
        wordIndex = (wordIndex + 1) % numWords;
        timeLeft--;
    }
    printf("\nTime's up! Your final score is %d out of %d.\n", score, numWords);
    printf("You made %d mistakes.\n", wrong);
    return 0;
}