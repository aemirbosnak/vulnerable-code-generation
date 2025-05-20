//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTION 100
#define MAX_OPTION 10
#define MAX_TIME 60
#define MAX_SCORE 100

int main() {
    // Initialize variables
    int questions[MAX_QUESTION];
    int options[MAX_QUESTION][MAX_OPTION];
    int score = 0;
    int time = MAX_TIME;

    // Generate questions and options
    for (int i = 0; i < MAX_QUESTION; i++) {
        questions[i] = rand() % 100 + 1;
        options[i][0] = rand() % 100 + 1;
        options[i][1] = rand() % 100 + 1;
    }

    // Display questions and options
    printf("Question 1: %d\n", questions[0]);
    printf("Options: %d, %d\n", options[0][0], options[0][1]);
    printf("Question 2: %d\n", questions[1]);
    printf("Options: %d, %d, %d\n", options[1][0], options[1][1], options[1][2]);

    // Simulate user input
    char choice[2];
    printf("Enter your choice: ");
    scanf("%s", choice);
    score += choice[0] - '0';

    // Check if time has elapsed
    if (time == 0) {
        printf("Time's up! Your score is %d out of %d.\n", score, MAX_SCORE);
    } else {
        printf("Your score is %d out of %d.\n", score, MAX_SCORE);
    }

    // Free memory
    for (int i = 0; i < MAX_QUESTION; i++) {
        free(options[i]);
    }
    free(options);

    return 0;
}