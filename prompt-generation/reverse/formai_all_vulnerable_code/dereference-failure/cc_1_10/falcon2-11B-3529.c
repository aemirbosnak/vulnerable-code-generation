//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_PAIRS 10
#define NUM_SHUFFLES 5

// Initialize pairs
void initPairs(int **pairs) {
    srand(time(0));
    for (int i = 0; i < NUM_PAIRS; i++) {
        pairs[i][0] = rand() % NUM_PAIRS;
        pairs[i][1] = rand() % NUM_PAIRS;
    }
}

// Display pairs
void displayPairs(int **pairs) {
    for (int i = 0; i < NUM_PAIRS; i++) {
        printf("%d %d\n", pairs[i][0], pairs[i][1]);
    }
}

// Shuffle pairs
void shufflePairs(int **pairs) {
    for (int i = 0; i < NUM_PAIRS; i++) {
        int temp = pairs[i][0];
        pairs[i][0] = pairs[i][1];
        pairs[i][1] = temp;
    }
}

// Play game
void playGame(int **pairs, int *score) {
    int tries = 0;
    int correct = 0;
    int incorrect = 0;
    for (int i = 0; i < NUM_PAIRS; i++) {
        printf("Guess pair %d: ", i + 1);
        int guess;
        scanf("%d", &guess);
        if (guess == pairs[i][0] || guess == pairs[i][1]) {
            correct++;
            tries++;
        } else {
            incorrect++;
            tries++;
        }
        if (tries == NUM_SHUFFLES) {
            break;
        }
        shufflePairs(pairs);
    }
    printf("Game over. You got %d correct out of %d tries.\n", correct, tries);
    printf("Your score is %d.\n", score[0] + correct);
}

int main() {
    int **pairs;
    initPairs(pairs);
    int score[2] = {0, 0};
    int tries = 0;
    int correct = 0;
    int incorrect = 0;
    for (int i = 0; i < NUM_SHUFFLES; i++) {
        playGame(pairs, score);
        printf("\n");
    }
    return 0;
}