//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define constant values for maximum and minimum word lengths, and wait time
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 10
#define WAIT_TIME 5

char* generateRandomWord(int min, int max) {
    // Define a list of characters to choose from
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    // Generate a random word based on the specified length range
    int wordLength = rand() % (max - min + 1) + min;
    char* word = (char*)malloc((wordLength + 1) * sizeof(char));
    
    for(int i = 0; i < wordLength; i++) {
        word[i] = alphabet[rand() % 26];
    }

    word[wordLength] = '\0';

    return word;
}

int main() {
    // Seed the random generator
    srand(time(NULL));

    printf("Welcome to the C Typing Speed Test program!\n");
    printf("You will be shown a random word, and you need to type it as quickly and accurately as possible.\n");
    printf("You will be timed, so get ready!\n");
    printf("Press ENTER to begin the test.\n");
    getchar();

    // Define variables to hold the start and end times, and the user input
    time_t startTime, endTime;
    char input[MAX_WORD_LENGTH + 1];
    int correctCount, totalCount;

    // Start the test loop
    do {
        // Generate a random word and display it to the user
        char* word = generateRandomWord(MIN_WORD_LENGTH, MAX_WORD_LENGTH);
        printf("Your word is: %s\n", word);

        // Record the start time
        startTime = time(NULL);

        // Wait for the user to input their response
        fgets(input, sizeof(input), stdin);

        // Record the end time
        endTime = time(NULL);

        // Calculate the elapsed time and display the result to the user
        double elapsed = difftime(endTime, startTime);
        printf("Elapsed time: %.2f seconds\n", elapsed);

        // Check the user's input against the generated word
        correctCount = 0;
        totalCount = strlen(word);

        for(int i = 0; i < totalCount; i++) {
            if(input[i] == word[i]) {
                correctCount++;
            }
        }

        // Display the user's accuracy result
        printf("You typed %d out of %d characters correctly.\n", correctCount, totalCount);

        // Wait for a short period of time before displaying the next word
        printf("Get ready for the next word...\n");
        for(int i = WAIT_TIME; i > 0; i--) {
            printf("%d...\n", i);
            sleep(1);
        }

        free(word);
    } while(1);

    return 0;
}