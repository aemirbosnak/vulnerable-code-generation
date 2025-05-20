//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numPlayers;
    printf("How many players will be playing? ");
    scanf("%d", &numPlayers);

    int bingoCards[numPlayers][5][5];
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                bingoCards[i][j][k] = rand() % 15 + 1;
            }
        }
    }

    int calledNumbers[75];
    int numCalled = 0;

    srand(time(NULL));
    for (int i = 0; i < 75; i++) {
        int num = rand() % 75 + 1;
        while (num == 0 || num == 1 || num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9) {
            num = rand() % 75 + 1;
        }
        calledNumbers[i] = num;
        numCalled++;
    }

    int winner = -1;
    int winnerCard[5][5];

    while (winner == -1 && numCalled < 75) {
        printf("Called number: %d\n", calledNumbers[numCalled]);
        for (int i = 0; i < numPlayers; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (bingoCards[i][j][k] == calledNumbers[numCalled]) {
                        if (j == 4 && k == 4) {
                            winner = i;
                            for (int l = 0; l < 5; l++) {
                                for (int m = 0; m < 5; m++) {
                                    winnerCard[l][m] = bingoCards[i][l][m];
                                }
                            }
                        }
                    }
                }
            }
        }
        numCalled++;
    }

    if (winner == -1) {
        printf("No winner.\n");
    } else {
        printf("Winner: %d\n", winner + 1);
        printf("Winning card:\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%d ", winnerCard[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}