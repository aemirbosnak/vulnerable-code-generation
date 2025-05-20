//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if a number is prime or not
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a random number between 100 and 1000
int generateNumber() {
    return (rand() % (1000 - 100 + 1)) + 100;
}

int main() {
    int numPlayers, numRounds;

    printf("Enter number of players: ");
    scanf("%d", &numPlayers);

    printf("Enter number of rounds: ");
    scanf("%d", &numRounds);

    srand(time(0));

    int playerScores[numPlayers]; // Array to store each player's score

    for (int i = 0; i < numPlayers; i++) {
        playerScores[i] = 0;
    }

    for (int i = 1; i <= numRounds; i++) {
        printf("Round %d:\n", i);
        for (int j = 0; j < numPlayers; j++) {
            int num = generateNumber();
            printf("Player %d, enter a prime number between 100 and 1000: ", j+1);
            int guess;
            scanf("%d", &guess);
            if (isPrime(guess) && guess >= 100 && guess <= 1000) {
                if (num == guess) {
                    printf("Correct!\n");
                    playerScores[j]++;
                } else {
                    printf("Wrong. The number was %d\n", num);
                }
            } else {
                printf("Invalid input\n");
            }
        }
        printf("\n");
    }

    // Find the winner
    int maxScore = 0;
    int winner = 0;
    for (int i = 0; i < numPlayers; i++) {
        if (playerScores[i] > maxScore) {
            maxScore = playerScores[i];
            winner = i+1;
        }
    }

    printf("The winner is player %d with a score of %d\n", winner, maxScore);

    return 0;
}