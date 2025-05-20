//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define BOARD_SIZE 4
#define NUM_PAIRS 8

// Data Structures
typedef struct {
    int row;
    int col;
    int value;
    int is_revealed;
} Card;

typedef struct {
    Card **cards;
    int num_revealed;
} Board;

// Function Declarations
void init_board(Board *board);
void print_board(Board *board);
int get_player_input(Board *board);
int check_match(Board *board, int card1, int card2);
int check_win(Board *board);

// Main Function
int main() {
    // Initialize the board
    Board board;
    init_board(&board);

    // Main game loop
    while (!check_win(&board)) {
        // Print the board
        print_board(&board);

        // Get player input
        int card1 = get_player_input(&board);
        int card2 = get_player_input(&board);

        // Check if the cards match
        if (check_match(&board, card1, card2)) {
            printf("Match! You've uncovered a pair of lovebirds.\n");
        } else {
            printf("No match. Your lovebirds have flown the coop for now.\n");
        }
    }

    // Print the final board
    print_board(&board);

    // Congratulate the player
    printf("Congratulations! You've reunited all the lovebirds. Love conquers all!\n");

    return 0;
}

// Function Definitions
void init_board(Board *board) {
    // Allocate memory for the board
    board->cards = (Card **)malloc(BOARD_SIZE * sizeof(Card *));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->cards[i] = (Card *)malloc(BOARD_SIZE * sizeof(Card));
    }

    // Initialize the cards
    int values[NUM_PAIRS];
    for (int i = 0; i < NUM_PAIRS; i++) {
        values[i] = i + 1;
    }
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int index = rand() % NUM_PAIRS;
            board->cards[i][j].row = i;
            board->cards[i][j].col = j;
            board->cards[i][j].value = values[index];
            board->cards[i][j].is_revealed = 0;
        }
    }

    // Shuffle the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int r1 = rand() % BOARD_SIZE;
            int c1 = rand() % BOARD_SIZE;
            int r2 = rand() % BOARD_SIZE;
            int c2 = rand() % BOARD_SIZE;
            Card temp = board->cards[r1][c1];
            board->cards[r1][c1] = board->cards[r2][c2];
            board->cards[r2][c2] = temp;
        }
    }

    // Set the number of revealed cards to 0
    board->num_revealed = 0;
}

void print_board(Board *board) {
    // Print the column headers
    printf(" ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d", i + 1);
    }
    printf("\n");

    // Print the rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cards[i][j].is_revealed) {
                printf(" %d", board->cards[i][j].value);
            } else {
                printf(" X");
            }
        }
        printf("\n");
    }
}

int get_player_input(Board *board) {
    // Get the row and column of the card
    int row, col;
    printf("Choose a card: ");
    scanf("%d %d", &row, &col);

    // Check if the card is valid
    if (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE) {
        printf("Invalid card. Please try again.\n");
        return -1;
    }

    // Check if the card is already revealed
    if (board->cards[row - 1][col - 1].is_revealed) {
        printf("Card is already revealed. Please try again.\n");
        return -1;
    }

    // Reveal the card
    board->cards[row - 1][col - 1].is_revealed = 1;
    board->num_revealed++;

    // Return the index of the card
    return row * BOARD_SIZE + col;
}

int check_match(Board *board, int card1, int card2) {
    // Get the rows and columns of the cards
    int row1 = (card1 - 1) / BOARD_SIZE;
    int col1 = (card1 - 1) % BOARD_SIZE;
    int row2 = (card2 - 1) / BOARD_SIZE;
    int col2 = (card2 - 1) % BOARD_SIZE;

    // Check if the cards match
    return board->cards[row1][col1].value == board->cards[row2][col2].value;
}

int check_win(Board *board) {
    // Check if all the cards are revealed
    return board->num_revealed == BOARD_SIZE * BOARD_SIZE;
}