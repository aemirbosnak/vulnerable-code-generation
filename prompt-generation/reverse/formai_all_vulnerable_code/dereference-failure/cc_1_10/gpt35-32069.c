//FormAI DATASET v1.0 Category: Poker Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUIT_SIZE 13
#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum 
{
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
} suit_t;

typedef struct 
{
    suit_t suit;
    int value;
} card_t;

void shuffle(card_t *deck) 
{
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE - 1; i++) 
    {
        int j = i + rand() / (RAND_MAX / (DECK_SIZE - i) + 1);
        card_t temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

void print_card(card_t card) 
{
    switch (card.value) 
    {
        case 1:
            printf("Ace");
            break;
        case 11:
            printf("Jack");
            break;
        case 12:
            printf("Queen");
            break;
        case 13:
            printf("King");
            break;
        default:
            printf("%d", card.value);
            break;
    }

    printf(" of ");

    switch (card.suit) 
    {
        case HEARTS:
            printf("Hearts");
            break;
        case DIAMONDS:
            printf("Diamonds");
            break;
        case CLUBS:
            printf("Clubs");
            break;
        case SPADES:
            printf("Spades");
            break;
    }
}

void print_hand(card_t hand[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        print_card(hand[i]);
        printf("\n");
    }
}

int evaluate_hand(card_t hand[], int size) 
{
    int values[SUIT_SIZE] = {0};
    int suits[SUIT_SIZE] = {0};
    int straight = 0;
    int flush = 0;
    int ace = 0;
    int pairs = 0;
    int triple = 0;
    int quadruple = 0;

    for (int i = 0; i < size; i++) 
    {
        values[hand[i].value - 1]++;
        suits[hand[i].suit]++;
        if (hand[i].value == 1) 
        {
            ace = 1;
        }
    }

    for (int i = 0; i < SUIT_SIZE; i++) 
    {
        if (values[i] == 4) 
        {
            quadruple = 1;
        } 
        else if (values[i] == 3) 
        {
            triple = 1;
        } 
        else if (values[i] == 2) 
        {
            pairs++;
        }
    }

    for (int i = 0; i < SUIT_SIZE - 4; i++) 
    {
        straight = 0;
        for (int j = i; j < i + 5; j++) 
        {
            if (values[j] == 1) 
            {
                straight++;
            }
        }
        if (straight == 5) 
        {
            break;
        }
    }

    for (int i = 0; i < SUIT_SIZE; i++) 
    {
        if (suits[i] == 5) 
        {
            flush = 1;
            break;
        }
    }

    if (straight && flush) 
    {
        if (ace && straight == 5) 
        {
            return 10; // Royal flush
        }
        return 9; // Straight flush
    }

    if (quadruple) 
    {
        return 8; // Four of a kind
    }

    if (triple && pairs) 
    {
        return 7; // Full house
    }

    if (flush) 
    {
        return 6; // Flush
    }

    if (straight) 
    {
        return 5; // Straight
    }

    if (triple) 
    {
        return 4; // Three of a kind
    }

    if (pairs == 2) 
    {
        return 3; // Two pairs
    }

    if (pairs == 1) 
    {
        return 2; // One pair
    }

    return 1; // High card
}

void sort_hand(card_t hand[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (hand[j].value < hand[i].value) 
            {
                card_t temp = hand[j];
                hand[j] = hand[i];
                hand[i] = temp;
            }
        }
    }
}

card_t* deal_hand(card_t *deck) 
{
    card_t *hand = (card_t*)malloc(HAND_SIZE * sizeof(card_t));
    for (int i = 0; i < HAND_SIZE; i++) 
    {
        hand[i] = deck[i];
    }
    return hand;
}

int main() 
{
    card_t deck[DECK_SIZE];
    int score = 0;

    for (int i = 0; i < DECK_SIZE; i++) 
    {
        deck[i].suit = i / SUIT_SIZE;
        deck[i].value = i % SUIT_SIZE + 1;
    }

    shuffle(deck);
    card_t *hand = deal_hand(deck);
    sort_hand(hand, HAND_SIZE);

    printf("Your hand:\n");
    print_hand(hand, HAND_SIZE);
    score = evaluate_hand(hand, HAND_SIZE);

    printf("\n");
    switch (score) 
    {
        case 10:
            printf("Royal flush\n");
            break;
        case 9:
            printf("Straight flush\n");
            break;
        case 8:
            printf("Four of a kind\n");
            break;
        case 7:
            printf("Full house\n");
            break;
        case 6:
            printf("Flush\n");
            break;
        case 5:
            printf("Straight\n");
            break;
        case 4:
            printf("Three of a kind\n");
            break;
        case 3:
            printf("Two pairs\n");
            break;
        case 2:
            printf("One pair\n");
            break;
        case 1:
            printf("High card\n");
            break;
    }

    free(hand);
    return 0;
}