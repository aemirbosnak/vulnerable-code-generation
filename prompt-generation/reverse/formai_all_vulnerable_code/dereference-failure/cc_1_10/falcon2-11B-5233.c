//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct bingo_card {
    int nums[5];
    int mark[5];
} BingoCard;

typedef struct bingo_game {
    BingoCard *cards;
    int num_cards;
} BingoGame;

int main() {
    srand(time(NULL));

    BingoGame *game = malloc(sizeof(BingoGame));
    game->num_cards = 10;
    game->cards = malloc(sizeof(BingoCard) * game->num_cards);

    for (int i = 0; i < game->num_cards; i++) {
        for (int j = 0; j < 5; j++) {
            game->cards[i].nums[j] = rand() % 75 + 1;
            game->cards[i].mark[j] = 0;
        }
    }

    int num_drawn = 0;
    while (num_drawn < 5) {
        printf("Draw %d:\n", num_drawn + 1);
        for (int i = 0; i < game->num_cards; i++) {
            printf("%d ", game->cards[i].nums[num_drawn]);
        }
        printf("\n");
        num_drawn++;
    }

    printf("**************************************************\n");
    printf("BINGO!\n");

    for (int i = 0; i < game->num_cards; i++) {
        for (int j = 0; j < 5; j++) {
            if (game->cards[i].nums[j] == 75) {
                printf("%d ", game->cards[i].nums[j]);
                game->cards[i].mark[j] = 1;
            } else if (game->cards[i].mark[j] == 1) {
                printf("%d ", game->cards[i].nums[j]);
            }
        }
        printf("\n");
    }

    free(game->cards);
    free(game);

    return 0;
}