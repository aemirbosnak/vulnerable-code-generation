//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 1000
#define MAX_PLAYERS 10

typedef struct {
    int id;
    char name[20];
    int cards[MAX_CARDS];
} Player;

void shuffleCards(int cards[], int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void printCard(int card) {
    if (card < 10) {
        printf("0%d ", card);
    } else {
        printf("%d ", card);
    }
}

void printCards(int cards[], int n) {
    for (int i = 0; i < n; i++) {
        printCard(cards[i]);
    }
}

int main() {
    srand(time(NULL));

    int numCards;
    printf("Enter the number of cards: ");
    scanf("%d", &numCards);

    int cards[numCards];
    for (int i = 0; i < numCards; i++) {
        cards[i] = i + 1;
    }

    shuffleCards(cards, numCards);

    int numPlayers;
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    Player players[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        players[i].id = i + 1;
        printf("Enter the name of player %d: ", players[i].id);
        scanf("%s", players[i].name);
    }

    int cardsPerPlayer = numCards / numPlayers;
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < cardsPerPlayer; j++) {
            players[i].cards[j] = cards[i * cardsPerPlayer + j];
        }
    }

    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d's cards: ", players[i].id);
        printCards(players[i].cards, cardsPerPlayer);
        printf("\n");
    }

    return 0;
}