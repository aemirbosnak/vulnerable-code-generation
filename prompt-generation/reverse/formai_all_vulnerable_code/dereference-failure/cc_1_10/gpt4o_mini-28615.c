//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_NUM 75
#define BINGO_SIZE 5

typedef struct {
    int numbers[BINGO_SIZE][BINGO_SIZE];
    int marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

void initializeCard(BingoCard *card);
void printCard(BingoCard card);
int markNumber(BingoCard *card, int number);
int checkBingo(BingoCard card);
int drawNumber();
void playBingo(int numPlayers);

int main() {
    int numPlayers;

    printf("Welcome to the Bingo Game!\n");
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    playBingo(numPlayers);
    return 0;
}

void initializeCard(BingoCard *card) {
    int used[MAX_BINGO_NUM + 1] = {0};
    int num;

    // Generate Bingo Card Numbers
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            do {
                num = rand() % MAX_BINGO_NUM + 1;
            } while (used[num]);
            used[num] = 1;
            card->numbers[i][j] = num;
            card->marked[i][j] = 0; // Initialize all as unmarked
        }
    }
    card->marked[BINGO_SIZE / 2][BINGO_SIZE / 2] = 1; // Mark the free space
}

void printCard(BingoCard card) {
    printf("Bingo Card:\n");
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card.marked[i][j]) {
                printf("[%2d] ", card.numbers[i][j]);
            } else {
                printf(" %2d  ", card.numbers[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int markNumber(BingoCard *card, int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card->numbers[i][j] == number) {
                card->marked[i][j] = 1;
                return 1; // Number marked
            }
        }
    }
    return 0; // Number not found
}

int checkBingo(BingoCard card) {
    // Check rows and columns for Bingo
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (checkRow(card, i) || checkColumn(card, i)) {
            return 1; // Bingo found
        }
    }
    if (checkMainDiagonal(card) || checkAntiDiagonal(card)) {
        return 1; // Bingo found
    }
    return 0; // No Bingo
}

int checkRow(BingoCard card, int row) {
    for (int j = 0; j < BINGO_SIZE; j++) {
        if (!card.marked[row][j]) {
            return 0; // Row not marked
        }
    }
    return 1; // Row is marked
}

int checkColumn(BingoCard card, int col) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (!card.marked[i][col]) {
            return 0; // Column not marked
        }
    }
    return 1; // Column is marked
}

int checkMainDiagonal(BingoCard card) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (!card.marked[i][i]) {
            return 0; // Main diagonal not marked
        }
    }
    return 1; // Main diagonal is marked
}

int checkAntiDiagonal(BingoCard card) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (!card.marked[i][BINGO_SIZE - i - 1]) {
            return 0; // Anti-diagonal not marked
        }
    }
    return 1; // Anti-diagonal is marked
}

int drawNumber() {
    return rand() % MAX_BINGO_NUM + 1;
}

void playBingo(int numPlayers) {
    BingoCard *cards = malloc(numPlayers * sizeof(BingoCard));
    int *bingoFound = malloc(numPlayers * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < numPlayers; i++) {
        initializeCard(&cards[i]);
        bingoFound[i] = 0; // Mark that no Bingo has been found yet
    }

    while (1) {
        int number = drawNumber();
        printf("Drawn Number: %d\n", number);
        
        for (int i = 0; i < numPlayers; i++) {
            if (!bingoFound[i]) {
                markNumber(&cards[i], number);
                if (checkBingo(cards[i])) {
                    printf("Player %d has Bingo!\n", i + 1);
                    bingoFound[i] = 1; // Mark Player as having Bingo
                }
            }
        }
        
        // Check if all players have Bingo
        int allBingo = 1;
        for (int i = 0; i < numPlayers; i++) {
            if (!bingoFound[i]) {
                allBingo = 0;
                printCard(cards[i]);
            }
        }
        
        if (allBingo) {
            printf("All players have Bingo! Game Over!\n");
            break;
        }
        
        printf("\n");
    }

    free(cards);
    free(bingoFound);
}