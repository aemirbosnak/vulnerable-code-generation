//FormAI DATASET v1.0 Category: Checkers Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// define the player colors
#define PLAYER_1 'W'
#define PLAYER_2 'B'

// define the board squares
#define EMPTY_SQUARE '-'
#define PLAYER_1_PAWN 'w'
#define PLAYER_1_KING 'W'
#define PLAYER_2_PAWN 'b'
#define PLAYER_2_KING 'B'

// define the moves
#define MOVE_UP_LEFT -9
#define MOVE_UP_RIGHT -7
#define MOVE_DOWN_LEFT 7
#define MOVE_DOWN_RIGHT 9

// function prototypes
char* create_board();
void print_board(char* board);
int index_of_left_diagonal(int index);
int index_of_right_diagonal(int index);
int can_move(char* board, int current_pos, int move);
char get_other_player(char current_player);
int is_valid_move(char* board, int current_pos, int new_pos);
void make_move(char* board, int current_pos, int new_pos);
int get_game_winner(char* board, char current_player);
int is_game_over(char* board, char current_player);

int main() {
    char* board = create_board();
    char current_player = PLAYER_1;
    int current_pos, new_pos;
    while (1) {
        print_board(board);
        printf("It is %c's turn.\n", current_player);
        printf("Enter the current position of the piece you want to move: ");
        scanf("%d", &current_pos);
        printf("Enter the new position: ");
        scanf("%d", &new_pos);
        if (is_valid_move(board, current_pos, new_pos)) {
            make_move(board, current_pos, new_pos);
            if (is_game_over(board, current_player)) {
                break;
            }
            current_player = get_other_player(current_player);
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
    int winner = get_game_winner(board, current_player);
    if (winner == 0) {
        printf("The game is a tie!");
    } else {
        printf("%c is the winner!", winner);
    }
    free(board);
    return 0;
}

// function to create and initialize the checker board
char* create_board() {
    char* board = (char*)malloc(BOARD_SIZE * BOARD_SIZE * sizeof(char));
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        if (i % BOARD_SIZE % 2 == 0) {
            if (i / BOARD_SIZE < 3) {
                board[i] = PLAYER_2_PAWN;
            } else if (i / BOARD_SIZE > 4) {
                board[i] = PLAYER_1_PAWN;
            } else {
                board[i] = EMPTY_SQUARE;
            }
        } else {
            if (i / BOARD_SIZE < 3) {
                board[i] = EMPTY_SQUARE;
            } else if (i / BOARD_SIZE > 4) {
                board[i] = EMPTY_SQUARE;
            } else {
                board[i] = PLAYER_1_PAWN;
            }
        }
    }
    return board;
}

// function to print the checker board
void print_board(char* board) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i * BOARD_SIZE + j]);
        }
        printf("\n");
    }
}

// function to get the index of the left diagonal square
int index_of_left_diagonal(int index) {
    if (index % BOARD_SIZE == 0) {
        return -1;
    }
    if (index / BOARD_SIZE == 0) {
        return -1;
    }
    return index + MOVE_UP_LEFT;
}

// function to get the index of the right diagonal square
int index_of_right_diagonal(int index) {
    if (index % BOARD_SIZE == BOARD_SIZE - 1) {
        return -1;
    }
    if (index / BOARD_SIZE == 0) {
        return -1;
    }
    return index + MOVE_UP_RIGHT;
}

// function to check if the current piece can move in the specified direction
int can_move(char* board, int current_pos, int move) {
    // check if the move is within the bounds of the board
    int new_pos = current_pos + move;
    if (new_pos < 0 || new_pos > 63) {
        return 0;
    }
    // check if the new square is empty
    if (board[new_pos] != EMPTY_SQUARE) {
        return 0;
    }
    // check if the move is a jump
    int jump_pos = current_pos + move / 2;
    if (board[jump_pos] == EMPTY_SQUARE) {
        return 1;
    } else {
        return 0;
    }
}

// function to get the other player
char get_other_player(char current_player) {
    if (current_player == PLAYER_1) {
        return PLAYER_2;
    } else {
        return PLAYER_1;
    }
}

// function to check if the move is a valid move
int is_valid_move(char* board, int current_pos, int new_pos) {
    char current_player = board[current_pos];
    // check if the current player owns the piece at the current position
    if (current_player != PLAYER_1_PAWN && current_player != PLAYER_1_KING &&
            current_player != PLAYER_2_PAWN && current_player != PLAYER_2_KING) {
        return 0;
    }
    // check if the new position is within the bounds of the board
    if (new_pos < 0 || new_pos > 63) {
        return 0;
    }
    // check if the new position is on the same diagonal as the current position
    if (index_of_left_diagonal(current_pos) == new_pos ||
            index_of_right_diagonal(current_pos) == new_pos) {
        // check if the piece can move in that direction
        if (can_move(board, current_pos, new_pos - current_pos)) {
            return 1;
        }
    }
    return 0;
}

// function to make the move
void make_move(char* board, int current_pos, int new_pos) {
    board[new_pos] = board[current_pos];
    board[current_pos] = EMPTY_SQUARE;
    // check if the piece has reached the end of the board to become a king
    if ((board[new_pos] == PLAYER_1_PAWN && new_pos >= 56) ||
            (board[new_pos] == PLAYER_2_PAWN && new_pos <= 7)) {
        board[new_pos] = (board[new_pos] == PLAYER_1_PAWN) ? PLAYER_1_KING : PLAYER_2_KING;
    }
    // check if the move is a jump and remove the jumped piece
    if (new_pos - current_pos == MOVE_UP_LEFT) {
        board[current_pos + MOVE_UP_LEFT / 2] = EMPTY_SQUARE;
    } else if (new_pos - current_pos == MOVE_UP_RIGHT) {
        board[current_pos + MOVE_UP_RIGHT / 2] = EMPTY_SQUARE;
    } else if (new_pos - current_pos == MOVE_DOWN_LEFT) {
        board[current_pos + MOVE_DOWN_LEFT / 2] = EMPTY_SQUARE;
    } else if (new_pos - current_pos == MOVE_DOWN_RIGHT) {
        board[current_pos + MOVE_DOWN_RIGHT / 2] = EMPTY_SQUARE;
    }
}

// function to get the winner of the game
int get_game_winner(char* board, char current_player) {
    int player_1_pieces = 0, player_2_pieces = 0;
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        if (board[i] == PLAYER_1_PAWN || board[i] == PLAYER_1_KING) {
            player_1_pieces++;
        } else if (board[i] == PLAYER_2_PAWN || board[i] == PLAYER_2_KING) {
            player_2_pieces++;
        }
    }
    if (player_1_pieces == 0 && player_2_pieces == 0) {
        return 0;
    }
    if (player_1_pieces == 0) {
        return PLAYER_2;
    }
    if (player_2_pieces == 0) {
        return PLAYER_1;
    }
    return current_player;
}

// function to check if the game is over
int is_game_over(char* board, char current_player) {
    int player_1_pieces = 0, player_2_pieces = 0;
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        if (board[i] == PLAYER_1_PAWN || board[i] == PLAYER_1_KING) {
            player_1_pieces++;
        } else if (board[i] == PLAYER_2_PAWN || board[i] == PLAYER_2_KING) {
            player_2_pieces++;
        }
    }
    if (player_1_pieces == 0 || player_2_pieces == 0) {
        return 1;
    }
    int current_player_pieces = (current_player == PLAYER_1) ? player_1_pieces : player_2_pieces;
    char other_player = get_other_player(current_player);
    int other_player_pieces = (other_player == PLAYER_1) ? player_1_pieces : player_2_pieces;
    if (current_player_pieces == 0 || other_player_pieces == 0) {
        return 1;
    }
    return 0;
}