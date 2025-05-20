//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the game board
#define BOARD_SIZE 4

// Define the number of cards in the deck
#define NUM_CARDS 8

// Define the states of a card
#define CARD_FACE_UP 1
#define CARD_FACE_DOWN 0

// Define the suits of the cards
#define SUIT_HEARTS 1
#define SUIT_DIAMONDS 2
#define SUIT_CLUBS 3
#define SUIT_SPADES 4

// Define the ranks of the cards
#define RANK_ACE 1
#define RANK_TWO 2
#define RANK_THREE 3
#define RANK_FOUR 4
#define RANK_FIVE 5
#define RANK_SIX 6
#define RANK_SEVEN 7
#define RANK_EIGHT 8

// Define the structure of a card
typedef struct {
    int suit;
    int rank;
    int state;
} Card;

// Define the structure of the game board
typedef struct {
    Card cards[BOARD_SIZE][BOARD_SIZE];
} GameBoard;

// Create a new deck of cards
Card* create_deck() {
    Card* deck = malloc(sizeof(Card) * NUM_CARDS);

    int i = 0;
    for (int suit = SUIT_HEARTS; suit <= SUIT_SPADES; suit++) {
        for (int rank = RANK_ACE; rank <= RANK_EIGHT; rank++) {
            deck[i].suit = suit;
            deck[i].rank = rank;
            deck[i].state = CARD_FACE_DOWN;
            i++;
        }
    }

    return deck;
}

// Shuffle the deck of cards
void shuffle_deck(Card* deck) {
    srand(time(NULL));

    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;

        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Create a new game board
GameBoard* create_game_board() {
    GameBoard* game_board = malloc(sizeof(GameBoard));

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game_board->cards[i][j].state = CARD_FACE_DOWN;
        }
    }

    return game_board;
}

// Flip a card face up
void flip_card_face_up(GameBoard* game_board, int row, int col) {
    game_board->cards[row][col].state = CARD_FACE_UP;
}

// Flip a card face down
void flip_card_face_down(GameBoard* game_board, int row, int col) {
    game_board->cards[row][col].state = CARD_FACE_DOWN;
}

// Check if two cards match
int cards_match(Card* card1, Card* card2) {
    return card1->suit == card2->suit && card1->rank == card2->rank;
}

// Check if the game is over
int is_game_over(GameBoard* game_board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game_board->cards[i][j].state == CARD_FACE_DOWN) {
                return 0;
            }
        }
    }

    return 1;
}

// Print the game board
void print_game_board(GameBoard* game_board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game_board->cards[i][j].state == CARD_FACE_UP) {
                printf("%2d%c ", game_board->cards[i][j].rank, game_board->cards[i][j].suit);
            } else {
                printf("XX ");
            }
        }
        printf("\n");
    }
}

// Play the game
void play_game() {
    // Create a new deck of cards
    Card* deck = create_deck();

    // Shuffle the deck of cards
    shuffle_deck(deck);

    // Create a new game board
    GameBoard* game_board = create_game_board();

    // Deal the cards to the game board
    int deck_index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game_board->cards[i][j] = deck[deck_index++];
        }
    }

    // Print the game board
    print_game_board(game_board);

    // Get the user's input
    int row1, col1, row2, col2;
    printf("Enter the row and column of the first card: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the row and column of the second card: ");
    scanf("%d %d", &row2, &col2);

    // Flip the first card face up
    flip_card_face_up(game_board, row1, col1);

    // Print the game board
    print_game_board(game_board);

    // Flip the second card face up
    flip_card_face_up(game_board, row2, col2);

    // Print the game board
    print_game_board(game_board);

    // Check if the cards match
    if (cards_match(&game_board->cards[row1][col1], &game_board->cards[row2][col2])) {
        printf("Cards match!\n");

        // Remove the cards from the game board
        game_board->cards[row1][col1].state = CARD_FACE_DOWN;
        game_board->cards[row2][col2].state = CARD_FACE_DOWN;
    } else {
        printf("Cards don't match!\n");

        // Flip the cards back face down
        flip_card_face_down(game_board, row1, col1);
        flip_card_face_down(game_board, row2, col2);
    }

    // Check if the game is over
    if (is_game_over(game_board)) {
        printf("Game over!\n");
    } else {
        // Play the game again
        play_game();
    }

    // Free the memory allocated for the deck and the game board
    free(deck);
    free(game_board);
}

// Main function
int main() {
    play_game();

    return 0;
}