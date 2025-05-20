//FormAI DATASET v1.0 Category: Poker Game ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef enum { CLUB, DIAMOND, HEART, SPADE } Suit; // enumeration for card suit
typedef enum { JACK=11, QUEEN, KING, ACE } Face; // enumeration for card face
typedef struct { Face face; Suit suit; } Card; // structure for card

// function to generate a deck of cards
Card* generateDeck(){
    Card* deck = (Card*) malloc(52*sizeof(Card));
    int index = 0;
    for(int i=1; i<=4; i++){
        for(int j=2; j<=14; j++){
            deck[index].face = (Face) j;
            deck[index].suit = (Suit) i;
            index++;
        }
    }
    return deck;
}

// function to shuffle the deck
void shuffleDeck(Card* deck){
    srand(time(NULL));
    for(int i=51; i>=0; i--){
        int j = rand()%(i+1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// function to display a card
void displayCard(Card card){
    switch(card.face){
        case JACK: printf("J"); break;
        case QUEEN: printf("Q"); break;
        case KING: printf("K"); break;
        case ACE: printf("A"); break;
        default: printf("%d", card.face);
    }
    switch(card.suit){
        case CLUB: printf("C "); break;
        case DIAMOND: printf("D "); break;
        case HEART: printf("H "); break;
        case SPADE: printf("S "); break;
    }
}

// function to display a hand
void displayHand(Card* hand, int numCards){
    for(int i=0; i<numCards; i++){
        displayCard(hand[i]);
    }
    printf("\n");
}

// function to compare two cards
int compareCards(Card card1, Card card2){
    if(card1.face > card2.face){
        return 1;
    } else if(card1.face == card2.face){
        if(card1.suit > card2.suit){
            return 1;
        } else if(card1.suit == card2.suit){
            return 0;
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

// function to evaluate a hand
int evaluateHand(Card* hand, int numCards){
    int score = 0;
    int numAces = 0;
    for(int i=0; i<numCards; i++){
        if(hand[i].face >= 10){
            score += 10;
        } else if(hand[i].face == ACE){
            numAces++;
            score += 11;
        } else {
            score += hand[i].face;
        }
    }
    while(numAces > 0 && score > 21){
        score -= 10;
        numAces--;
    }
    return score;
}

int main(){
    Card* deck = generateDeck();
    shuffleDeck(deck);
    int playerScore = 0;
    int dealerScore = 0;
    Card playerHand[10];
    Card dealerHand[10];
    int numPlayerCards = 0;
    int numDealerCards = 0;
    // deal cards to player and dealer
    playerHand[numPlayerCards++] = deck[0];
    dealerHand[numDealerCards++] = deck[1];
    playerHand[numPlayerCards++] = deck[2];
    dealerHand[numDealerCards++] = deck[3];
    printf("Dealer's hand: ");
    displayCard(dealerHand[0]);
    printf("?\n");
    printf("Your hand: ");
    displayHand(playerHand, numPlayerCards);
    playerScore = evaluateHand(playerHand, numPlayerCards);
    while(playerScore < 21){
        char choice;
        printf("Hit or stand? (h/s): ");
        scanf(" %c", &choice);
        if(choice == 'h'){
            playerHand[numPlayerCards++] = deck[numPlayerCards+numDealerCards];
            printf("Your hand: ");
            displayHand(playerHand, numPlayerCards);
            playerScore = evaluateHand(playerHand, numPlayerCards);
        } else {
            break;
        }
    }
    while(dealerScore < 17){
        dealerHand[numDealerCards++] = deck[numPlayerCards+numDealerCards];
        dealerScore = evaluateHand(dealerHand, numDealerCards);
    }
    printf("Dealer's hand: ");
    displayHand(dealerHand, numDealerCards);
    printf("Dealer's score: %d\n", dealerScore);
    printf("Your score: %d\n", playerScore);
    if(playerScore > 21){
        printf("Bust! You lose.\n");
    } else if(dealerScore > 21){
        printf("Dealer busts! You win.\n");
    } else if(playerScore > dealerScore){
        printf("You win!\n");
    } else if(playerScore < dealerScore){
        printf("You lose.\n");
    } else {
        printf("Push.\n");
    }
    free(deck);
    return 0;
}