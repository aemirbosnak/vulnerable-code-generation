//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WORDS 100
#define WORD_LENGTH 10
#define MAX_USER_NAME_LENGTH 20

struct User {
    char name[MAX_USER_NAME_LENGTH];
    int wordsPerMinute;
};

void getUserName(struct User* user);
int getWordsPerMinute(struct User* user);
void generateWords(char* words[]);
int getRandomIndex(int maxIndex);
void displayWords(char* words[], int numWords);
int getNumCorrectWords(char* words[], char* userInput);

int main() {
    struct User user;
    getUserName(&user);
    int wordsPerMinute = getWordsPerMinute(&user);
    char* words[NUM_WORDS];
    generateWords(words);
    int numCorrectWords = 0;
    for (int i = 0; i < NUM_WORDS; i++) {
        numCorrectWords += getNumCorrectWords(words, user.name);
    }
    printf("Your typing speed is %d words per minute.\n", wordsPerMinute);
    printf("You got %d out of %d words correct.\n", numCorrectWords, NUM_WORDS);
    return 0;
}

void getUserName(struct User* user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
}

int getWordsPerMinute(struct User* user) {
    int wordsPerMinute;
    printf("How many words per minute can you type? ");
    scanf("%d", &wordsPerMinute);
    return wordsPerMinute;
}

void generateWords(char* words[]) {
    for (int i = 0; i < NUM_WORDS; i++) {
        int randomIndex = getRandomIndex(NUM_WORDS);
        int j = 0;
        while (j < WORD_LENGTH) {
            words[randomIndex][j] = 'a' + rand() % 26;
            j++;
        }
    }
}

int getRandomIndex(int maxIndex) {
    return rand() % maxIndex;
}

void displayWords(char* words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

int getNumCorrectWords(char* words[], char* userInput) {
    int numCorrectWords = 0;
    for (int i = 0; i < NUM_WORDS; i++) {
        if (strcmp(userInput, words[i]) == 0) {
            numCorrectWords++;
        }
    }
    return numCorrectWords;
}