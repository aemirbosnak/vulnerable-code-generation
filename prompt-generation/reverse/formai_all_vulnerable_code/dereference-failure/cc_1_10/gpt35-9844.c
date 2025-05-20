//FormAI DATASET v1.0 Category: Poker Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define the suits and ranks
const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 52

// define a card
typedef struct
{
    char suit[9];
    char rank[3];
} Card;

// define a deck of cards
typedef struct
{
    Card cards[NUM_CARDS];
    int num_cards;
} Deck;

// shuffle the deck of cards
void shuffle_deck(Deck *deck)
{
    srand(time(NULL));
    for (int i = 0; i < deck->num_cards; i++)
    {
        int j = rand() % deck->num_cards;
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

// print the deck of cards
void print_deck(Deck *deck)
{
    for (int i = 0; i < deck->num_cards; i++)
    {
        printf("%s of %s\n", deck->cards[i].rank, deck->cards[i].suit);
    }
}

// create a new deck of cards
Deck* new_deck()
{
    Deck *deck = malloc(sizeof(Deck));
    deck->num_cards = NUM_CARDS;
    int index = 0;
    for (int i = 0; i < NUM_SUITS; i++)
    {
        for (int j = 0; j < NUM_RANKS; j++)
        {
            Card card = {suits[i], ranks[j]};
            deck->cards[index++] = card;
        }
    }
    shuffle_deck(deck);
    return deck;
}

// deal a card from the deck
Card* deal_card(Deck *deck)
{
    Card *card = NULL;
    if (deck->num_cards > 0)
    {
        card = &deck->cards[--deck->num_cards];
    }
    return card;
}

// print the player's hand
void print_hand(Card **hand, int num_cards)
{
    for (int i = 0; i < num_cards; i++)
    {
        printf("%s of %s\n", hand[i]->rank, hand[i]->suit);
    }
}

// determine the value of the hand
int hand_value(Card **hand, int num_cards)
{
    int value = 0;
    int aces = 0;
    for (int i = 0; i < num_cards; i++)
    {
        if (strcmp(hand[i]->rank, "J") == 0 ||
            strcmp(hand[i]->rank, "Q") == 0 ||
            strcmp(hand[i]->rank, "K") == 0)
        {
            value += 10;
        }
        else if (strcmp(hand[i]->rank, "A") == 0)
        {
            aces += 1;
            value += 11;
        }
        else
        {
            value += atoi(hand[i]->rank);
        }
    }
    while (aces > 0 && value > 21)
    {
        value -= 10;
        aces--;
    }
    return value;
}

int main()
{
    printf("*** Welcome to the Poker Game! ***\n");

    // create a deck of cards
    Deck *deck = new_deck();

    // deal the cards
    Card *player_hand[2];
    Card *dealer_hand[2];
    player_hand[0] = deal_card(deck);
    dealer_hand[0] = deal_card(deck);
    player_hand[1] = deal_card(deck);
    dealer_hand[1] = deal_card(deck);

    // print the hands
    printf("\nPlayer's Hand:\n");
    print_hand(player_hand, 2);
    printf("\nDealer's Hand:\n");
    printf("%s of %s\n", dealer_hand[0]->rank, dealer_hand[0]->suit);
    printf("Hidden card\n");

    // prompt player for hit or stand
    char choice[10];
    printf("\nDo you want to hit or stand? ");
    scanf("%s", choice);
    while (strcmp(choice, "hit") == 0)
    {
        // deal another card to player
        player_hand[2] = deal_card(deck);
        printf("\nPlayer's Hand:\n");
        print_hand(player_hand, 3);
        if (hand_value(player_hand, 3) > 21)
        {
            printf("\nBust! Player loses.\n");
            return 0;
        }
        printf("\nDo you want to hit or stand? ");
        scanf("%s", choice);
    }

    // reveal dealer's hidden card
    printf("\nDealer's Hand:\n");
    print_hand(dealer_hand, 2);
    while (hand_value(dealer_hand, 2) < 17)
    {
        dealer_hand[2] = deal_card(deck);
        printf("\nDealer hits:\n");
        printf("%s of %s\n", dealer_hand[2]->rank, dealer_hand[2]->suit);
        if (hand_value(dealer_hand, 3) > 21)
        {
            printf("\nDealer busts! Player wins.\n");
            return 0;
        }
    }

    // determine the winner
    printf("\nPlayer's Hand:\n");
    print_hand(player_hand, 2);
    printf("\nDealer's Hand:\n");
    print_hand(dealer_hand, 3);
    int player_hand_value = hand_value(player_hand, 2);
    int dealer_hand_value = hand_value(dealer_hand, 3);
    if (player_hand_value > dealer_hand_value)
    {
        printf("\nPlayer wins!\n");
    }
    else if (dealer_hand_value > player_hand_value)
    {
        printf("\nDealer wins!\n");
    }
    else
    {
        printf("\nTie!\n");
    }

    // free memory from deck
    free(deck);

    return 0;
}