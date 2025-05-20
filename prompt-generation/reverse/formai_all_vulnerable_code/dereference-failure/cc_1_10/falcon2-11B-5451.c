//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

typedef struct card{
    int suit;
    int rank;
}Card;

typedef struct hand{
    Card *cards;
    int size;
}Hand;

typedef struct deck{
    int suits;
    int ranks;
    Card *cards;
}Deck;

void sort_hand(Hand* hand){
    for(int i=0;i<hand->size;i++){
        for(int j=i+1;j<hand->size;j++){
            if(hand->cards[i].rank > hand->cards[j].rank){
                Card temp = hand->cards[i];
                hand->cards[i] = hand->cards[j];
                hand->cards[j] = temp;
            }
        }
    }
}

void print_hand(Hand* hand){
    for(int i=0;i<hand->size;i++){
        printf("%d of %d\n", hand->cards[i].rank, hand->cards[i].suit);
    }
}

int main(){
    srand(time(NULL));
    Deck deck;
    Hand hand;
    int num_players = 2;
    
    deck.suits = 4;
    deck.ranks = 13;
    deck.cards = (Card*) malloc(deck.suits * deck.ranks * sizeof(Card));

    for(int i=0;i<deck.suits;i++){
        for(int j=0;j<deck.ranks;j++){
            deck.cards[i * deck.ranks + j].suit = i;
            deck.cards[i * deck.ranks + j].rank = j + 1;
        }
    }

    for(int i=0;i<num_players;i++){
        hand.size = 5;
        hand.cards = (Card*) malloc(hand.size * sizeof(Card));

        for(int j=0;j<hand.size;j++){
            hand.cards[j].rank = rand() % 13 + 1;
            hand.cards[j].suit = rand() % 4 + 1;
        }
        sort_hand(&hand);
        printf("Player %d's hand: ", i+1);
        print_hand(&hand);
        printf("\n");
    }

    return 0;
}