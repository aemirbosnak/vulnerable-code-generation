//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Function to generate a random word
char* generateRandomWord() {
    char* words[] = {"zombie", "survival", "apocalypse", "mutant", "radioactive", "desolation", "wasteland", "shelter", "supplies", "weapon", "ammo", "raid", "scavenge", "bandit", "raider", "settlement", "community"};
    return words[rand() % 16];
}

// Function to measure typing speed
int measureTypingSpeed(char* word, int time) {
    printf("Type the word '%s' as many times as you can in %d seconds:\n", word, time);
    int count = 0;
    char input[100];

    for (int i = 0; i < time; i++) {
        scanf("%s", input);
        if (strcmp(input, word) == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    srand(time(NULL));

    int numWords;
    printf("How many words do you want to type? ");
    scanf("%d", &numWords);

    int totalTime = 0;
    int totalWordsTyped = 0;

    for (int i = 0; i < numWords; i++) {
        char* word = generateRandomWord();
        int time = rand() % 21 + 5; // Random time between 5 and 25 seconds

        int wordsTyped = measureTypingSpeed(word, time);
        totalWordsTyped += wordsTyped;
        totalTime += time;

        printf("You typed '%s' %d times in %d seconds.\n", word, wordsTyped, time);
    }

    int wpm = (totalWordsTyped / totalTime) * 60;
    printf("Your average typing speed is %d words per minute.\n", wpm);

    return 0;
}