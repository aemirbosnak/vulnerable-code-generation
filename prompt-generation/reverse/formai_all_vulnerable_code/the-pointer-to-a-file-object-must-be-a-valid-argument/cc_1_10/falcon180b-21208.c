//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 10

// Function to generate a random word
char* generateRandomWord() {
    char word[WORD_LENGTH];
    for (int i = 0; i < WORD_LENGTH; i++) {
        word[i] = 'a' + rand() % 26;
    }
    return strdup(word);
}

// Function to measure typing speed
int measureTypingSpeed(char* word) {
    int startTime = clock();
    printf("Type the word: %s\n", word);
    scanf("%s", word);
    int endTime = clock();
    int elapsedTime = (endTime - startTime) / CLOCKS_PER_SEC;
    int length = strlen(word);
    int speed = length / elapsedTime;
    return speed;
}

// Main function
int main() {
    srand(time(NULL));

    // Load words from file
    FILE* fp = fopen("words.txt", "r");
    char* words[MAX_WORDS];
    int numWords = 0;
    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        words[numWords++] = strdup(line);
        if (numWords >= MAX_WORDS) {
            break;
        }
    }
    fclose(fp);

    // Test typing speed
    int numWordsToTest = 10;
    int totalScore = 0;
    for (int i = 0; i < numWordsToTest; i++) {
        char* word = words[rand() % numWords];
        int speed = measureTypingSpeed(word);
        printf("Your typing speed for '%s' is %d words per minute.\n", word, speed);
        totalScore += speed;
    }

    // Print average typing speed
    double avgSpeed = (double) totalScore / numWordsToTest;
    printf("Your average typing speed is %.2f words per minute.\n", avgSpeed);

    return 0;
}