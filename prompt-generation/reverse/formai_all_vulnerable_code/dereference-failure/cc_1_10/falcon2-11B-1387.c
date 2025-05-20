//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct Card {
    int value;
    int suit;
} Card;

typedef struct Game {
    Card* cards;
    int size;
    int turn;
} Game;

int main() {
    Game game;
    game.cards = (Card*) malloc(sizeof(Card) * 12);
    game.size = 12;
    game.turn = 0;

    game.cards[0].value = 1;
    game.cards[0].suit = 0;

    game.cards[1].value = 2;
    game.cards[1].suit = 0;

    //...

    int correct = 0;
    for (int i = 0; i < game.size; i++) {
        printf("%d of %s (%d)\n", game.cards[i].value,
               game.cards[i].suit == 0? "Clubs" :
               game.cards[i].suit == 1? "Diamonds" :
               game.cards[i].suit == 2? "Hearts" : "Spades");
        if (i % 2 == game.turn) {
            printf("Turn: %d\n", game.turn);
            int num1 = game.cards[i].value;
            int num2 = game.cards[i+1].value;
            int suit1 = game.cards[i].suit;
            int suit2 = game.cards[i+1].suit;
            if (num1 == num2 && suit1 == suit2) {
                printf("Correct!\n");
                correct++;
            } else {
                printf("Wrong!\n");
            }
        } else {
            printf("Wrong!\n");
        }
    }

    printf("You got %d correct out of %d\n", correct, game.size);

    free(game.cards);

    return 0;
}