//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: protected
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MIN_WORD_LENGTH 2 // minimum length of random words
#define MAX_WORD_LENGTH 15 // maximum length of random words
#define TIME_LIMIT 60 // time limit for typing test in seconds

char* getRandomWord() {
    static const char alphanum[] =
        "abcdefghijklmnopqrstuvwxyz";
    int length = rand() % (MAX_WORD_LENGTH - MIN_WORD_LENGTH + 1) + MIN_WORD_LENGTH;
    char* word = malloc(length + 1);
    for(int i = 0; i < length; i++) {
        word[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    word[length] = '\0';
    return word;
}

void printTestStart() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("Your goal is to type as many random words as you can within %d seconds\n", TIME_LIMIT);
    printf("Press ENTER to start the test\n");
    getchar(); // wait for user to press ENTER
    printf("Test starts now!\n");
}

void printTestResults(int wordsTyped, int secondsElapsed) {
    printf("\n\n");
    printf("Time's up!\n");
    printf("You typed %d words in %d seconds\n", wordsTyped, secondsElapsed);
    printf("Your typing speed is %.2f words per minute\n", wordsTyped * 60.0 / secondsElapsed);
}

int main() {
    srand(time(NULL)); // seed for random number generator
    printTestStart();
    int wordsTyped = 0;
    time_t startTime = time(NULL);
    while(time(NULL) - startTime < TIME_LIMIT) { // run for TIME_LIMIT seconds
        char* word = getRandomWord();
        printf("%s ", word);
        fflush(stdout); // flush output buffer to ensure immediate printing
        char buffer[MAX_WORD_LENGTH + 1];
        fgets(buffer, sizeof(buffer), stdin);
        if(strcmp(buffer, word) == 0) {
            wordsTyped++;
        }
        free(word);
    }
    time_t endTime = time(NULL);
    printTestResults(wordsTyped, endTime - startTime);
    return 0;
}