//FormAI DATASET v1.0 Category: Poker Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int randRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to draw cards for a player or dealer and return the total value
int drawCards(char* name, int cards[]) {
    int total = 0;
    int cardIndex = 0;
    char input;

    printf("%s's Turn:\n", name);
    do {
        int cardValue = randRange(1, 10);
        cards[cardIndex++] = cardValue;
        total += cardValue;

        printf("Drew a %d (total value: %d)\n", cardValue, total);

        if (total > 21) {
            printf("%s Busts!\n", name);
            return total;
        }

        printf("Would you like to draw another card? (y/n) ");
        input = getchar();
    } while (input == 'y');

    printf("\n");
    return total;
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Post-Apocalyptic Poker Game!\n\n");

    // Initialize player and dealer hands
    int playerCards[10] = { 0 };
    int dealerCards[10] = { 0 };

    // Draw cards for player and dealer
    int playerTotal = drawCards("Player", playerCards);
    int dealerTotal = drawCards("Dealer", dealerCards);

    // Dealer's turn
    if (dealerTotal <= 16) {
        int cardValue = randRange(1, 10);
        dealerCards[2] = cardValue;
        dealerTotal += cardValue;
    }

    // Determine winner
    printf("Player's Hand: ");
    for (int i = 0; playerCards[i] != 0; i++) {
        printf("%d ", playerCards[i]);
    }
    printf("(Total: %d)\n", playerTotal);

    printf("Dealer's Hand: ");
    for (int i = 0; dealerCards[i] != 0; i++) {
        printf("%d ", dealerCards[i]);
    }
    printf("(Total: %d)\n", dealerTotal);

    if (playerTotal > dealerTotal || dealerTotal > 21) {
        printf("Congratulations! You've won the game!\n");
    }
    else if (dealerTotal > playerTotal) {
        printf("I'm sorry, you've lost the game. Better luck next time!\n");
    }
    else {
        printf("It's a tie game!\n");
    }

    return 0;
}