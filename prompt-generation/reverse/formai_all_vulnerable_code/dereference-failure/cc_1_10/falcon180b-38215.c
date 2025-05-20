//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct bingoCard {
    char numbers[5][5];
    int valid;
};

void generateCard(struct bingoCard *card) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            card->numbers[i][j] = 'B' + (rand() % 15);
        }
    }
    card->valid = 1;
}

int checkWin(struct bingoCard *card, int direction) {
    int i, j, k;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (direction == 1) {
                k = 0;
                while (k < 5) {
                    if (card->numbers[i][j]!= 'B' + (k + j) % 15) {
                        break;
                    }
                    k++;
                }
                if (k == 5) {
                    return 1;
                }
            } else {
                k = 0;
                while (k < 5) {
                    if (card->numbers[i][j]!= 'B' + (j + k) % 15) {
                        break;
                    }
                    k++;
                }
                if (k == 5) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int numPlayers;
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);
    struct bingoCard *cards = malloc(numPlayers * sizeof(struct bingoCard));
    int i;
    for (i = 0; i < numPlayers; i++) {
        generateCard(&cards[i]);
    }
    int numCalls;
    printf("Enter number of ball calls: ");
    scanf("%d", &numCalls);
    int ball;
    int winners = 0;
    for (i = 0; i < numCalls; i++) {
        printf("Ball %d: ", i + 1);
        scanf("%d", &ball);
        int j;
        for (j = 0; j < numPlayers; j++) {
            if (checkWin(&cards[j], 1) || checkWin(&cards[j], 2)) {
                printf("Player %d wins!\n", j + 1);
                winners++;
                break;
            }
        }
        if (winners == numPlayers) {
            break;
        }
    }
    free(cards);
    return 0;
}