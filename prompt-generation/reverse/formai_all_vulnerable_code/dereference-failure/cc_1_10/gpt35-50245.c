//FormAI DATASET v1.0 Category: Poker Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define HAND_SIZE 5

struct card
{
    int rank;
    int suit;
};

typedef struct card Card;

void shuffle(Card *deck[]);
void swap(Card **card1, Card **card2);
void print_hand(Card *hand[]);
int count_pairs(Card *hand[]);
int count_flush(Card *hand[]);
int count_straight(Card *hand[]);
int evaluate_hand(Card *hand[]);

int main()
{
    srand((unsigned)time(NULL));

    Card *deck[NUM_CARDS];
    Card *hand[HAND_SIZE];

    int i, j;
    for (i = 0; i < NUM_RANKS; i++)
    {
        for (j = 0; j < NUM_SUITS; j++)
        {
            deck[NUM_SUITS * i + j] = malloc(sizeof(Card));
            deck[NUM_SUITS * i + j]->rank = i;
            deck[NUM_SUITS * i + j]->suit = j;
        }
    }

    shuffle(deck);

    for (i = 0; i < HAND_SIZE; i++)
    {
        hand[i] = deck[i];
    }

    printf("Your hand:\n");
    print_hand(hand);

    int score = evaluate_hand(hand);

    if (score == 9)
    {
        printf("You have a straight flush!\n");
    }
    else if (score == 8)
    {
        printf("You have four of a kind!\n");
    }
    else if (score == 7)
    {
        printf("You have a full house!\n");
    }
    else if (score == 6)
    {
        printf("You have a flush!\n");
    }
    else if (score == 5)
    {
        printf("You have a straight!\n");
    }
    else if (score == 4)
    {
        printf("You have three of a kind!\n");
    }
    else if (score == 3)
    {
        printf("You have two pairs!\n");
    }
    else if (score == 2)
    {
        printf("You have one pair!\n");
    }
    else
    {
        printf("You have a high card!\n");
    }

    return 0;
}

void shuffle(Card *deck[])
{
    int i;
    for (i = 0; i < NUM_CARDS; i++)
    {
        int random_index = rand() % NUM_CARDS;
        swap(&deck[i], &deck[random_index]);
    }
}

void swap(Card **card1, Card **card2)
{
    Card *temp = *card1;
    *card1 = *card2;
    *card2 = temp;
}

void print_hand(Card *hand[])
{
    int i;
    for (i = 0; i < HAND_SIZE; i++)
    {
        printf("%d%c ", hand[i]->rank, hand[i]->suit == 0 ? 'C' : hand[i]->suit == 1 ? 'D' : hand[i]->suit == 2 ? 'H' : 'S');
    }
    printf("\n");
}

int count_pairs(Card *hand[])
{
    int i, j, pairs = 0;
    for (i = 0; i < HAND_SIZE; i++)
    {
        for (j = i + 1; j < HAND_SIZE; j++)
        {
            if (hand[i]->rank == hand[j]->rank)
            {
                pairs++;
            }
        }
    }
    return pairs;
}

int count_flush(Card *hand[])
{
    int i, flush = 1;
    for (i = 0; i < HAND_SIZE - 1; i++)
    {
        if (hand[i]->suit != hand[i + 1]->suit)
        {
            flush = 0;
            break;
        }
    }
    return flush;
}

int count_straight(Card *hand[])
{
    int i, straight = 1;
    for (i = 0; i < HAND_SIZE - 1; i++)
    {
        if (hand[i]->rank != hand[i + 1]->rank - 1)
        {
            straight = 0;
            break;
        }
    }
    return straight;
}

int evaluate_hand(Card *hand[])
{
    int pairs = count_pairs(hand);
    int flush = count_flush(hand);
    int straight = count_straight(hand);

    if (flush && straight)
    {
        return 9; // Straight flush
    }
    else if (pairs == 6)
    {
        return 8; // Four of a kind
    }
    else if (pairs == 4)
    {
        return 7; // Full house
    }
    else if (flush)
    {
        return 6; // Flush
    }
    else if (straight)
    {
        return 5; // Straight
    }
    else if (pairs == 3)
    {
        return 4; // Three of a kind
    }
    else if (pairs == 2)
    {
        return 3; // Two pairs
    }
    else if (pairs == 1)
    {
        return 2; // One pair
    }
    else
    {
        return 1; // High card
    }
}