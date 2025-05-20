//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("\t\t\t\t\tWelcome to Bingo Simulator!\n\n");

    int rows, cols, numPlayers;
    printf("Enter Number Of Rows: ");
    scanf("%d", &rows);
    printf("Enter Number Of Columns: ");
    scanf("%d", &cols);
    printf("Enter Number Of Players: ");
    scanf("%d", &numPlayers);

    int numElements = rows * cols;

    // Creating a 2D array for the game board
    int **gameBoard = (int **)malloc(rows * sizeof(int *)); // Initializing the row pointers
    for(int i = 0; i < rows; i++) {
        gameBoard[i] = (int *)malloc(cols * sizeof(int)); // Initializing the columns
    }

    // Initializing the game board elements
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int element = (j+1) + (i*cols);
            gameBoard[i][j] = element;
        }
    }

    printf("\n\t\t\t\t\tGame Board:\n");

    // Displaying the game board
    for(int i = 0; i < rows; i++) {
        printf("+-----+-----+-----+-----+-----+-----+\n");
        for(int j = 0; j < cols; j++) {
            printf("|  %d  ", gameBoard[i][j]);
        }
        printf("|\n");
    }
    printf("+-----+-----+-----+-----+-----+-----+\n");

    // Initializing the player cards
    int ***playerCards = (int ***)malloc(numPlayers * sizeof(int **)); // Initializing the player pointers
    for(int i = 0; i < numPlayers; i++) {
        playerCards[i] = (int **)malloc(rows * sizeof(int *)); // Initializing the row pointers
        for(int j = 0; j < rows; j++) {
            playerCards[i][j] = (int *)malloc(cols * sizeof(int)); // Initializing the columns
        }
    }

    printf("\n");

    // Filling the player cards
    for(int i = 0; i < numPlayers; i++) {
        printf("Player %d's Card:\n", i+1);
        for(int j = 0; j < rows; j++) {
            for(int k = 0; k < cols; k++) {
                int randomNumber = (rand() % numElements) + 1;
                playerCards[i][j][k] = randomNumber;
                printf("| %d ", playerCards[i][j][k]);
            }
            printf("|\n");
        }
        printf("\n");
    }

    // Beginning the game
    int winnerDeclared = 0;
    while(!winnerDeclared) {

        // Drawing a random number from the game board
        int randomNumber = (rand() % numElements) + 1;
        printf("The drawn number is: %d\n", randomNumber);

        // Checking each player's card for the drawn number
        for(int i = 0; i < numPlayers; i++) {
            printf("\nChecking Player %d's card...\n", i+1);
            int found = 0; // Indicates whether the number was found in the player's card
            for(int j = 0; j < rows; j++) {
                for(int k = 0; k < cols; k++) {
                    if(playerCards[i][j][k] == randomNumber) {
                        printf("Number Found: %d\n", randomNumber);
                        playerCards[i][j][k] = -1; // Marking the found number as negative
                        found = 1;
                        break;
                    }
                }
                if(found) break;
            }

            // Checking if the player has won
            int cardSum = 0;
            for(int j = 0; j < rows; j++) {
                for(int k = 0; k < cols; k++) {
                    if(playerCards[i][j][k] < 0) {
                        cardSum += playerCards[i][j][k];
                    }
                }
            }
            if(cardSum == -1*numElements) {
                printf("\nBingo! Player %d Wins!", i+1);
                winnerDeclared = 1;
                break;
            }
        }

        printf("\n");
    }

    // Freeing the dynamically allocated memory
    for(int i = 0; i < rows; i++) {
        free(gameBoard[i]);
    }
    free(gameBoard);

    for(int i = 0; i < numPlayers; i++) {
        for(int j = 0; j < rows; j++) {
            free(playerCards[i][j]);
        }
        free(playerCards[i]);
    }
    free(playerCards);

    return 0;
}