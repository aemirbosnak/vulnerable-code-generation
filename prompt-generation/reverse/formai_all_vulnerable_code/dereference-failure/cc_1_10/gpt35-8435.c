//FormAI DATASET v1.0 Category: Poker Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum { Clubs, Diamonds, Hearts, Spades } Suits;
typedef enum { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King } Ranks;
typedef struct card {
    Suits suit;
    Ranks rank;
    struct card *next;
} Card;

Card *deck = NULL;

void create_deck();
void shuffle_deck();
void deal_cards(int num_players);
void display_hand(Card *hand);
int get_card_value(Card *card);
int evaluate_hand(Card *hand);

int main()
{
    create_deck();
    shuffle_deck();
    deal_cards(4); // change to number of players
    return 0;
}

void create_deck()
{
    int s, r;
    deck = malloc(sizeof(Card));
    Card *current = deck;
    for (s = 0; s < 4; s++) {
        for (r = 0; r < 13; r++) {
            current->suit = s;
            current->rank = r;
            current->next = malloc(sizeof(Card));
            current = current->next;
        }
    }
    current->next = NULL;
}

void shuffle_deck()
{
    Card *current = deck;
    int i, j;
    srand(time(NULL));
    for (i = 0; i < 52; i++) {
        int r = rand() % (52 - i) + i;
        Card temp = current[i];
        current[i] = current[r];
        current[r] = temp;
    }
}

void deal_cards(int num_players)
{
    int i, j, k;
    Card *hands[num_players];
    for (i = 0; i < num_players; i++) {
        hands[i] = malloc(sizeof(Card) * 5);
        Card *current = hands[i];
        for (j = 0; j < 5; j++) {
            *current = deck[i * 5 + j];
            current->next = NULL;
            Card *prev = NULL;
            for (k = 0; k < j; k++) {
                prev = &hands[i][k];
            }
            if (prev != NULL) {
                prev->next = current;
            }
            current++;
        }
        printf("PLAYER %d HAND:\n", i + 1);
        display_hand(hands[i]);
        printf("\n");
        printf("PLAYER %d EVALUATION: %d\n", i + 1, evaluate_hand(hands[i]));
        printf("\n");
        free(hands[i]);
    }
}

void display_hand(Card *hand)
{
    Card *current = hand;
    while (current != NULL) {
        switch (current->rank) {
            case Ace: printf("A"); break;
            case Two: printf("2"); break;
            case Three: printf("3"); break;
            case Four: printf("4"); break;
            case Five: printf("5"); break;
            case Six: printf("6"); break;
            case Seven: printf("7"); break;
            case Eight: printf("8"); break;
            case Nine: printf("9"); break;
            case Ten: printf("10"); break;
            case Jack: printf("J"); break;
            case Queen: printf("Q"); break;
            case King: printf("K"); break;
        }
        switch (current->suit) {
            case Clubs: printf("C "); break;
            case Diamonds: printf("D "); break;
            case Hearts: printf("H "); break;
            case Spades: printf("S "); break;
        }
        current = current->next;
    }
}

int get_card_value(Card *card)
{
    int value = card->rank;
    if (card->rank >= Ten) {
        value = 10;
    } else if (card->rank == Ace) {
        value = 11; // will adjust later if needed
    }
    return value;
}

int evaluate_hand(Card *hand)
{
    int value = 0;
    int ace_count = 0;
    Card *current = hand;
    while (current != NULL) {
        value += get_card_value(current);
        if (current->rank == Ace) {
            ace_count++;
        }
        current = current->next;
    }
    while (value > 21 && ace_count > 0) {
        value -= 10;
        ace_count--;
    }
    return value;
}