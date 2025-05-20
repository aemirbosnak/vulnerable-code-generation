//FormAI DATASET v1.0 Category: Table Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// function to generate a random number between 1 and 6
int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    // initialize game variables
    int playerPos = 0;
    int endPos = 100;
    int numPlayers, currentPlayer = 0;
    char playerName[50];
    srand(time(NULL));

    // get number of players
    printf("Welcome to the post-apocalyptic version of Snakes and Ladders! How many players will be playing (2-4)? ");
    scanf("%d", &numPlayers);

    // create array of player names
    char playerNames[numPlayers][50];
    for(int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", &playerNames[i]);
    }

    // start game loop
    while(playerPos < endPos) {
        // print current player's turn
        printf("\nIt is %s's turn.\n", playerNames[currentPlayer]);

        // roll dice
        int diceRoll = rollDice();
        printf("You rolled a %d.\n", diceRoll);

        // update player position
        playerPos += diceRoll;

        // check for snake or ladder
        switch(playerPos) {
            case 14:
                printf("Oh no! You fell into a pit and dropped back to position 7.\n");
                playerPos = 7;
                break;
            case 25:
                printf("Amazing! You found a hidden cache of supplies and moved up to position 66.\n");
                playerPos = 66;
                break;
            case 44:
                printf("Sorry! You tripped on a piece of rubble and fell back to position 22.\n");
                playerPos = 22;
                break;
            case 72:
                printf("You found a secret passage and moved up to position 90.\n");
                playerPos = 90;
                break;
            case 87:
                printf("You were attacked by mutantrats and were pushed back to position 61.\n");
                playerPos = 61;
                break;
            case 98:
                printf("You finally found the safe haven, congratulations you won!\n");
                playerPos = endPos;
                break;
            default:
                break;
        }

        // check for game over
        if(playerPos >= endPos) {
            printf("\nCongratulations %s, you have reached the safe haven and won the game!\n", playerNames[currentPlayer]);
            break;
        }

        // print player position
        printf("You are now at position %d.\n", playerPos);

        // switch to next player
        if(currentPlayer == numPlayers-1) {
            currentPlayer = 0;
        }
        else {
            currentPlayer++;
        }
    }

    // end game
    printf("\nThank you for playing Snakes and Ladders, post-apocalyptic style!\n");
    return 0;
}