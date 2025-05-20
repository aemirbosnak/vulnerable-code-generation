//FormAI DATASET v1.0 Category: Poker Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle cards
void shuffle(int *deck, int n)
{
    srand(time(0)); // Set seed for rand()
    for(int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to deal cards to players
void deal(int *deck, int n, int players, int **hands)
{
    for(int i = 0; i < players; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            hands[i][j] = deck[i * 2 + j];
        }
    }
}

// Function to print a card
void printCard(int card)
{
    int faceValue = card % 13;
    int suit = card / 13;

    switch(faceValue)
    {
        case 0:
            printf("A");
            break;
        case 10:
            printf("J");
            break;
        case 11:
            printf("Q");
            break;
        case 12:
            printf("K");
            break;
        default:
            printf("%d", faceValue + 1);
            break;
    }

    switch(suit)
    {
        case 0:
            printf("C ");
            break;
        case 1:
            printf("D ");
            break;
        case 2:
            printf("H ");
            break;
        case 3:
            printf("S ");
            break;
    }
}

// Function to print a hand
void printHand(int *hand)
{
    for(int i = 0; i < 2; i++)
    {
        printCard(hand[i]);
    }
}

// Main program
int main()
{
    // Initialize deck and hands
    int deck[52];
    int *hands[2];
    for(int i = 0; i < 2; i++)
    {
        hands[i] = malloc(2 * sizeof(int));
    }

    // Populate deck with cards 0-51
    for(int i = 0; i < 52; i++)
    {
        deck[i] = i;
    }

    // Shuffle deck and deal cards
    shuffle(deck, 52);
    deal(deck, 52, 2, hands);

    // Print hands
    printf("Player 1: ");
    printHand(hands[0]);
    printf("\n");
    printf("Player 2: ");
    printHand(hands[1]);
    printf("\n");

    return 0;
}