//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10

typedef struct {
    char name[30];
    int guess;
} Player;

void playGame(Player players[], int numPlayers, int secretNumber, int maxAttempts, int attempt);
void getPlayerGuesses(Player players[], int numPlayers);
int isGuessCorrect(int guess, int secretNumber);

int main() {
    int numPlayers, maxAttempts, rangeUpper;
    srand(time(NULL));

    printf("Welcome to the Multiplayer Number Guessing Game!\n");
    
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    if(numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting...\n");
        return -1;
    }

    printf("Enter the upper range for the secret number: ");
    scanf("%d", &rangeUpper);
    
    printf("Enter the maximum number of attempts each player can make: ");
    scanf("%d", &maxAttempts);

    int secretNumber = rand() % rangeUpper + 1;
    printf("A secret number has been generated between 1 and %d. Get ready to guess!\n", rangeUpper);

    Player players[MAX_PLAYERS];

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    playGame(players, numPlayers, secretNumber, maxAttempts, 0);
    
    return 0;
}

void playGame(Player players[], int numPlayers, int secretNumber, int maxAttempts, int attempt) {
    if (attempt >= maxAttempts) {
        printf("All players have exhausted their guesses. The secret number was %d.\n", secretNumber);
        return;
    }

    printf("\nAttempt %d:\n", attempt + 1);
    getPlayerGuesses(players, numPlayers);
    
    for (int i = 0; i < numPlayers; i++) {
        printf("%s guessed: %d. ", players[i].name, players[i].guess);
        if (isGuessCorrect(players[i].guess, secretNumber)) {
            printf("Congratulations, %s! You guessed correctly!\n", players[i].name);
            return; // End game if someone guesses correctly
        } else if (players[i].guess < secretNumber) {
            printf("Too low!\n");
        } else {
            printf("Too high!\n");
        }
    }

    // Recursively call playGame for the next attempt
    playGame(players, numPlayers, secretNumber, maxAttempts, attempt + 1);
}

void getPlayerGuesses(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("%s, enter your guess: ", players[i].name);
        scanf("%d", &players[i].guess);
    }
}

int isGuessCorrect(int guess, int secretNumber) {
    return guess == secretNumber;
}