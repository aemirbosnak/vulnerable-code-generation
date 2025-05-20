//FormAI DATASET v1.0 Category: Poker Game ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Definition of card structure
struct Card{
    char *suit;
    char *faceValue;
};

// Function to create the deck of cards
struct Card* createDeck(){
    struct Card* deck = (struct Card*) malloc(52 * sizeof(struct Card));

    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *faceValues[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

    int i, j, k = 0;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 13; j++){
            deck[k].suit = suits[i];
            deck[k].faceValue = faceValues[j];
            k++;
        }
    }

    return deck;
}

// Function to shuffle the deck of cards
void shuffleDeck(struct Card *deck){
    srand(time(NULL));

    int i, j, k;
    struct Card temp;

    for(i = 0; i < 52; i++){
        j = rand() % 52;
        k = rand() % 52;

        temp = deck[j];
        deck[j] = deck[k];
        deck[k] = temp;
    }
}

// Function to deal cards to each player
void dealCards(struct Card *deck, struct Card *player1Cards, struct Card *player2Cards){
    int i;

    for(i = 0; i < 5; i++){
        player1Cards[i] = deck[i];
        player2Cards[i] = deck[i+5];
    }
}

// Function to determine the winner of the game
void determineWinner(struct Card *player1Cards, struct Card *player2Cards){
    int i, player1Score = 0, player2Score = 0;

    // Calculation of score
    for(i = 0; i < 5; i++){
        if(player1Cards[i].faceValue == "Ace"){
            player1Score += 14;
        } 
        else if(player1Cards[i].faceValue == "King"){
            player1Score += 13;
        } 
        else if(player1Cards[i].faceValue == "Queen"){
            player1Score += 12;
        } 
        else if(player1Cards[i].faceValue == "Jack"){
            player1Score += 11;
        } 
        else{
            player1Score += atoi(player1Cards[i].faceValue);
        }

        if(player2Cards[i].faceValue == "Ace"){
            player2Score += 14;
        } 
        else if(player2Cards[i].faceValue == "King"){
            player2Score += 13;
        } 
        else if(player2Cards[i].faceValue == "Queen"){
            player2Score += 12;
        } 
        else if(player2Cards[i].faceValue == "Jack"){
            player2Score += 11;
        } 
        else{
            player2Score += atoi(player2Cards[i].faceValue);
        }
    }

    // Comparison of scores
    if(player1Score > player2Score){
        printf("Player 1 wins!\n");
    } else if(player2Score > player1Score){
        printf("Player 2 wins!\n");
    } else{
        printf("It's a tie!\n");
    }
}

// Driver function
int main(){
    struct Card* deck = createDeck();
    shuffleDeck(deck);

    struct Card player1Cards[5], player2Cards[5];
    dealCards(deck, player1Cards, player2Cards);

    int i;

    printf("\nPlayer 1 cards: \n");
    for(i = 0; i < 5; i++){
        printf("%s of %s\n", player1Cards[i].faceValue, player1Cards[i].suit);
    }

    printf("\nPlayer 2 cards: \n");
    for(i = 0; i < 5; i++){
        printf("%s of %s\n", player2Cards[i].faceValue, player2Cards[i].suit);
    }

    determineWinner(player1Cards, player2Cards);

    return 0;
}