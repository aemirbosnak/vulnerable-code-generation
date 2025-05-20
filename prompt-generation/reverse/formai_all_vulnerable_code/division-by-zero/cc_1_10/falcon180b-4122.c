//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10

typedef struct {
    char name[50];
    int score;
    int card[MAX_CARDS];
} Player;

void generateCard(int card[MAX_CARDS]) {
    srand(time(NULL));
    for (int i = 0; i < MAX_CARDS; i++) {
        card[i] = rand() % 15 + 1;
    }
}

void printCard(int card[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        printf("%d ", card[i]);
    }
    printf("\n");
}

int checkBingo(int card[MAX_CARDS], int row, int col) {
    int count = 0;
    for (int i = 0; i < MAX_CARDS; i++) {
        if (i % 5 == col && card[i]!= 0) {
            count++;
        }
        if (card[i] == 0) {
            count = 0;
        }
    }
    if (count == 5) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int numPlayers;
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    Player players[MAX_PLAYERS];
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        generateCard(players[i].card);
    }

    int currentPlayer = 0;
    while (1) {
        int choice;
        printf("Current player: %s\n", players[currentPlayer].name);
        printf("1. Draw a card\n2. Check for bingo\n3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateCard(players[currentPlayer].card);
                printf("You drew a card: ");
                printCard(players[currentPlayer].card);
                break;
            case 2:
                if (checkBingo(players[currentPlayer].card, 0, 0)) {
                    printf("%s got bingo!\n", players[currentPlayer].name);
                    players[currentPlayer].score++;
                }
                break;
            case 3:
                printf("Player %s quit.\n", players[currentPlayer].name);
                return 0;
            default:
                printf("Invalid choice.\n");
        }

        currentPlayer = (currentPlayer + 1) % numPlayers;
    }

    return 0;
}