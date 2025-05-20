//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS (BOARD_SIZE * BOARD_SIZE) / 2
#define NUM_CARDS (BOARD_SIZE * BOARD_SIZE)

// Card values
enum {
    CARD_BLANK,
    CARD_1,
    CARD_2,
    CARD_3,
    CARD_4,
    CARD_5,
    CARD_6,
    CARD_7,
    CARD_8,
};

// Card states
enum {
    CARD_FACE_DOWN,
    CARD_FACE_UP,
    CARD_MATCHED,
};

// Game state
enum {
    GAME_IN_PROGRESS,
    GAME_OVER,
    GAME_WON,
};

// Card struct
struct card {
    int value;
    int state;
};

// Game struct
struct game {
    struct card board[NUM_CARDS];
    int state;
    int num_pairs_matched;
};

// Create a new game
struct game *new_game() {
    struct game *game = malloc(sizeof(struct game));
    for (int i = 0; i < NUM_CARDS; i++) {
        game->board[i].value = CARD_BLANK;
        game->board[i].state = CARD_FACE_DOWN;
    }
    game->state = GAME_IN_PROGRESS;
    game->num_pairs_matched = 0;
    return game;
}

// Free the game
void free_game(struct game *game) {
    free(game);
}

// Shuffle the cards
void shuffle_cards(struct game *game) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        struct card tmp = game->board[i];
        game->board[i] = game->board[j];
        game->board[j] = tmp;
    }
}

// Flip a card
void flip_card(struct game *game, int index) {
    if (game->board[index].state == CARD_FACE_DOWN) {
        game->board[index].state = CARD_FACE_UP;
    } else if (game->board[index].state == CARD_FACE_UP) {
        game->board[index].state = CARD_FACE_DOWN;
    }
}

// Check if two cards match
int cards_match(struct card *card1, struct card *card2) {
    return card1->value == card2->value;
}

// Check if the game is over
int is_game_over(struct game *game) {
    return game->state == GAME_OVER || game->state == GAME_WON;
}

// Check if the game is won
int is_game_won(struct game *game) {
    return game->num_pairs_matched == NUM_PAIRS;
}

// Print the game board
void print_board(struct game *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int index = i * BOARD_SIZE + j;
            switch (game->board[index].state) {
                case CARD_FACE_DOWN:
                    printf("[_]");
                    break;
                case CARD_FACE_UP:
                    printf("[%d]", game->board[index].value);
                    break;
                case CARD_MATCHED:
                    printf("[ ]");
                    break;
            }
        }
        printf("\n");
    }
}

// Get user input
int get_input() {
    int index;
    printf("Enter the index of the card you want to flip: ");
    scanf("%d", &index);
    return index;
}

// Play the game
void play_game(struct game *game) {
    int index1, index2;
    while (!is_game_over(game)) {
        print_board(game);
        index1 = get_input();
        flip_card(game, index1);
        print_board(game);
        index2 = get_input();
        flip_card(game, index2);
        if (cards_match(&game->board[index1], &game->board[index2])) {
            game->board[index1].state = CARD_MATCHED;
            game->board[index2].state = CARD_MATCHED;
            game->num_pairs_matched++;
            if (is_game_won(game)) {
                game->state = GAME_WON;
                printf("You win!\n");
            }
        } else {
            flip_card(game, index1);
            flip_card(game, index2);
        }
    }
}

// Main function
int main() {
    struct game *game = new_game();
    shuffle_cards(game);
    play_game(game);
    free_game(game);
    return 0;
}