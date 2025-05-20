//FormAI DATASET v1.0 Category: Memory Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define TOTAL_CARDS BOARD_SIZE * BOARD_SIZE / 2

// Game board and card structs
typedef struct {
    int row;
    int col;
    int value;
    int is_paired;
} Card;

typedef struct {
    Card* cards[BOARD_SIZE][BOARD_SIZE];
    int num_cards;
} Board;

// Function prototypes
void init_board(Board* board);
void shuffle_cards(Card** cards, int length);
void swap_cards(Card** a, Card** b);
void print_board(Board* board);
void print_card(Card* card);
Card* get_card(Board* board, int row, int col);
int is_valid_card(Board* board, int row, int col);
void flip_card(Board* board, int row, int col);
void check_pair(Board* board, Card* card1, Card* card2);
void game_loop(Board* board);

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize game board
    Board board;
    init_board(&board);

    // Play the game loop
    game_loop(&board);

    return 0;
}

// Initialize the game board
void init_board(Board* board) {
    // Initialize array to hold cards
    Card* cards[TOTAL_CARDS * 2];

    // Generate pairs of cards
    for (int i = 0; i < TOTAL_CARDS; i++) {
        Card* card1 = (Card*) malloc(sizeof(Card));
        Card* card2 = (Card*) malloc(sizeof(Card));

        card1->value = i;
        card2->value = i;
        card1->is_paired = 0;
        card2->is_paired = 0;

        cards[i * 2] = card1;
        cards[i * 2 + 1] = card2;
    }

    // Shuffle the cards
    shuffle_cards(cards, TOTAL_CARDS * 2);

    // Place the cards on the board
    board->num_cards = BOARD_SIZE * BOARD_SIZE;
    int card_index = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            Card* card = cards[card_index];
            card->row = row;
            card->col = col;
            board->cards[row][col] = card;
            card_index++;
        }
    }
}

// Shuffle an array of cards
void shuffle_cards(Card** cards, int length) {
    for (int i = 0; i < length; i++) {
        int random_index = rand() % length;
        swap_cards(&cards[i], &cards[random_index]);
    }
}

// Swap two cards
void swap_cards(Card** a, Card** b) {
    Card* temp = *a;
    *a = *b;
    *b = temp;
}

// Print the game board
void print_board(Board* board) {
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            Card* card = board->cards[row][col];
            print_card(card);
        }
        printf("\n");
    }
}

// Print a card
void print_card(Card* card) {
    if (card->is_paired) {
        printf(" [%d] ", card->value);
    } else {
        printf(" [?] ");
    }
}

// Get a card at a given location on the board
Card* get_card(Board* board, int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return NULL;
    }
    return board->cards[row][col];
}

// Check if a row and column correspond to a valid card location on the board
int is_valid_card(Board* board, int row, int col) {
    return get_card(board, row, col) != NULL;
}

// Flip a card on the board
void flip_card(Board* board, int row, int col) {
    Card* card = get_card(board, row, col);
    if (card != NULL && !card->is_paired) {
        card->is_paired = 1;
    }
}

// Check if two flipped cards on the board form a pair
void check_pair(Board* board, Card* card1, Card* card2) {
    if (card1 != NULL && card2 != NULL && card1->value == card2->value) {
        card1->is_paired = 1;
        card2->is_paired = 1;
        board->num_cards -= 2;
    }
}

// Game loop for playing the memory game
void game_loop(Board* board) {
    int moves = 0;

    while (board->num_cards > 0) {
        // Print the game board
        print_board(board);

        // Get input for the next card to flip
        int row, col;
        printf("Enter row and column of the card to flip (e.g. 1 2): ");
        scanf("%d %d", &row, &col);

        // Flip the card
        if (is_valid_card(board, row, col)) {
            flip_card(board, row, col);
        } else {
            printf("Invalid card location.\n");
            continue;
        }

        // Check if a pair has been found
        Card* card1 = get_card(board, row, col);
        Card* card2 = NULL;
        if (board->num_cards % 2 == 1) {
            // If there is an odd number of cards left, the last card flipped can't form a pair
            print_board(board);
            continue;
        } else {
            // Look for the last flipped card that hasn't been paired yet
            for (int row2 = 0; row2 < BOARD_SIZE; row2++) {
                for (int col2 = 0; col2 < BOARD_SIZE; col2++) {
                    Card* temp = get_card(board, row2, col2);
                    if (temp != NULL && !temp->is_paired) {
                        card2 = temp;
                        break;
                    }
                }
                if (card2 != NULL) {
                    break;
                }
            }
        }
        check_pair(board, card1, card2);

        moves++;
    }

    // Game over
    printf("\nCongratulations, you won in %d moves!\n", moves);
}