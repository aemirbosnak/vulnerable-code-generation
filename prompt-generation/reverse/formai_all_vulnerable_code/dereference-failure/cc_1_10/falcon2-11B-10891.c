//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARDS 4

typedef struct {
    char card[2];
    int value;
} Card;

typedef struct {
    int hands[2];
    int total;
} Hand;

typedef struct {
    char name[50];
    int chips;
    int bet;
} Player;

typedef struct {
    int hands[2];
    int total;
} Computer;

Card cards[MAX_CARDS];
Player player;
Computer computer;

void shuffle(Card *cards) {
    for (int i = 0; i < 52; i++) {
        int random = rand() % 52;
        int temp = cards[i].value;
        cards[i].value = cards[random].value;
        cards[random].value = temp;
    }
}

void deal(Card *cards) {
    int numCards = 0;
    int j = 0;
    int i = 0;
    while (numCards < MAX_CARDS) {
        j = rand() % 52;
        if (cards[j].value!= 0) {
            cards[i].card[0] = 'A' + j / 13;
            cards[i].card[1] = 'A' + j % 13 + 1;
            cards[i].value = j;
            i++;
            numCards++;
        }
    }
}

int getHandValue(Card *cards, int numCards) {
    int value = 0;
    for (int i = 0; i < numCards; i++) {
        value += cards[i].value;
    }
    return value;
}

void getPlayerHand(Card *cards, int numCards) {
    for (int i = 0; i < numCards; i++) {
        printf("%c%c: %d\n", cards[i].card[0], cards[i].card[1], cards[i].value);
    }
}

void getComputerHand(Card *cards, int numCards) {
    for (int i = 0; i < numCards; i++) {
        printf("%c%c: %d\n", cards[i].card[0], cards[i].card[1], cards[i].value);
    }
}

int compareHands(Card *cards1, Card *cards2, int numCards) {
    int value1 = getHandValue(cards1, numCards);
    int value2 = getHandValue(cards2, numCards);

    if (value1 == value2) {
        return 0;
    }
    else if (value1 > value2) {
        return 1;
    }
    else {
        return -1;
    }
}

void playGame() {
    printf("Welcome to Poker!\n");
    printf("Please enter your name:\n");
    scanf("%s", player.name);
    printf("Enter your bet amount:\n");
    scanf("%d", &player.bet);

    printf("Dealing cards...\n");
    shuffle(cards);
    deal(cards);
    getPlayerHand(cards, 5);
    getComputerHand(cards, 5);

    printf("\n\nPlayer Hand: %d\n", getHandValue(cards, 5));
    printf("Computer Hand: %d\n\n", getHandValue(cards, 5));

    if (compareHands(cards, cards, 5) == 0) {
        printf("Player and Computer have the same hand, it's a tie!\n");
        return;
    }

    printf("Player wins!\n");
    player.chips += player.bet;
    return;
}

void playGame2() {
    printf("Welcome to Poker!\n");
    printf("Please enter your name:\n");
    scanf("%s", player.name);
    printf("Enter your bet amount:\n");
    scanf("%d", &player.bet);

    printf("Dealing cards...\n");
    shuffle(cards);
    deal(cards);
    getPlayerHand(cards, 5);
    getComputerHand(cards, 5);

    printf("\n\nPlayer Hand: %d\n", getHandValue(cards, 5));
    printf("Computer Hand: %d\n\n", getHandValue(cards, 5));

    if (compareHands(cards, cards, 5) == 0) {
        printf("Player and Computer have the same hand, it's a tie!\n");
        return;
    }

    if (compareHands(cards, cards, 5) > 0) {
        printf("Computer wins!\n");
        player.chips -= player.bet;
    }
    else {
        printf("Player wins!\n");
        player.chips += player.bet;
    }
    return;
}

int main() {
    int choice = 0;
    while (choice!= 6) {
        printf("What would you like to do?\n");
        printf("1. Play Game\n");
        printf("2. Play Game 2\n");
        printf("3. Exit\n");
        printf("Please enter your choice:\n");
        scanf("%d", &choice);

        if (choice == 1) {
            playGame();
        }
        else if (choice == 2) {
            playGame2();
        }
        else if (choice == 3) {
            printf("Exiting program...\n");
            break;
        }
        else {
            printf("Invalid choice, try again.\n");
        }
    }

    printf("Bye!\n");
    return 0;
}