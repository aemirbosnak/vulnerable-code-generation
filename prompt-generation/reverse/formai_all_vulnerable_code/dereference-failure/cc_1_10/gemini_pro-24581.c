//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS (BOARD_SIZE * BOARD_SIZE) / 2

// Card struct represents a single card on the board
typedef struct {
    int value;
    int is_flipped;
} Card;

// Board struct represents the entire game board
typedef struct {
    Card cards[BOARD_SIZE][BOARD_SIZE];
    int num_turns;
    int num_pairs_found;
} Board;

// Function to create a new game board
Board* new_board() {
    Board* board = malloc(sizeof(Board));
    
    // Initialize the board with random values
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->cards[i][j].value = rand() % NUM_PAIRS;
            board->cards[i][j].is_flipped = 0;
        }
    }
    
    // Shuffle the board to mix up the values
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        int r1 = rand() % BOARD_SIZE;
        int c1 = rand() % BOARD_SIZE;
        int r2 = rand() % BOARD_SIZE;
        int c2 = rand() % BOARD_SIZE;
        
        Card temp = board->cards[r1][c1];
        board->cards[r1][c1] = board->cards[r2][c2];
        board->cards[r2][c2] = temp;
    }
    
    // Initialize other board properties
    board->num_turns = 0;
    board->num_pairs_found = 0;
    
    return board;
}

// Function to print the game board to the console
void print_board(Board* board) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cards[i][j].is_flipped) {
                printf("%2d ", board->cards[i][j].value);
            } else {
                printf("  X ");
            }
        }
        printf("\n");
    }
    
    printf("Number of turns: %d\n", board->num_turns);
    printf("Number of pairs found: %d\n", board->num_pairs_found);
    printf("\n");
}

// Function to check if two cards match
int cards_match(Card* card1, Card* card2) {
    return card1->value == card2->value;
}

// Function to handle a player's turn
void player_turn(Board* board) {
    int r1, c1, r2, c2;
    
    // Get the first card's coordinates
    printf("Enter the coordinates of the first card (row, column): ");
    scanf("%d %d", &r1, &c1);
    
    // Check if the card is already flipped
    if (board->cards[r1][c1].is_flipped) {
        printf("That card is already flipped!\n");
        return;
    }
    
    // Flip the first card
    board->cards[r1][c1].is_flipped = 1;
    
    // Get the second card's coordinates
    printf("Enter the coordinates of the second card (row, column): ");
    scanf("%d %d", &r2, &c2);
    
    // Check if the card is already flipped
    if (board->cards[r2][c2].is_flipped) {
        printf("That card is already flipped!\n");
        return;
    }
    
    // Flip the second card
    board->cards[r2][c2].is_flipped = 1;
    
    // Increment the number of turns
    board->num_turns++;
    
    // Check if the cards match
    if (cards_match(&board->cards[r1][c1], &board->cards[r2][c2])) {
        printf("Congratulations! You found a pair!\n");
        
        // Increment the number of pairs found
        board->num_pairs_found++;
    } else {
        printf("Sorry, those cards don't match.\n");
        
        // Flip the cards back over
        board->cards[r1][c1].is_flipped = 0;
        board->cards[r2][c2].is_flipped = 0;
    }
}

// Function to check if the game is over
int game_over(Board* board) {
    return board->num_pairs_found == NUM_PAIRS;
}

int main() {
    // Create a new game board
    Board* board = new_board();
    
    // Play the game until it is over
    while (!game_over(board)) {
        print_board(board);
        player_turn(board);
    }
    
    // Print the final game board
    print_board(board);
    
    // Free the game board
    free(board);
    
    return 0;
}