//FormAI DATASET v1.0 Category: Checkers Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, WHITE, BLACK } Square;

// Function prototypes
Square** create_board();
void print_board(Square** board);
void move_piece(Square** board, int from_x, int from_y, int to_x, int to_y);
int get_piece_direction(Square piece, int y_pos);
int is_move_valid(Square** board, int from_x, int from_y, int to_x, int to_y, Square player);
int can_capture(Square** board, int x, int y, int dx, int dy, Square player);
int has_any_capture(Square** board, int x, int y, Square player);
int make_capture(Square** board, int from_x, int from_y, int to_x, int to_y, Square player);

int main() {
    Square** board = create_board();
    int turn_number = 1;
    Square current_player = WHITE;

    while (1) {
        printf("Turn %d: ", turn_number++);
        if (current_player == WHITE) {
            printf("White's turn\n");
        } else {
            printf("Black's turn\n");
        }
        print_board(board);

        // Get player's move
        int from_x, from_y, to_x, to_y;
        printf("Enter coordinates of the piece you want to move: ");
        scanf("%d %d", &from_x, &from_y);
        printf("Enter coordinates of the square you want to move it to: ");
        scanf("%d %d", &to_x, &to_y);

        // Check if move is valid
        if (is_move_valid(board, from_x, from_y, to_x, to_y, current_player)) {
            // Move piece
            move_piece(board, from_x, from_y, to_x, to_y);

            // Check if piece has become a king
            if (current_player == WHITE && to_y == BOARD_SIZE - 1) {
                board[to_y][to_x] = WHITE;
            } else if (current_player == BLACK && to_y == 0) {
                board[to_y][to_x] = BLACK;
            }

            // Check if player has any captures left
            if (has_any_capture(board, to_x, to_y, current_player)) {
                printf("You can capture again with this piece.\n");
            } else {
                // Switch to next player
                if (current_player == WHITE) {
                    current_player = BLACK;
                } else {
                    current_player = WHITE;
                }
            }

        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}

Square** create_board() {
    Square** board = (Square**) malloc(sizeof(Square*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (Square*) malloc(sizeof(Square) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = EMPTY;
            } else if (i < 3) {
                board[i][j] = BLACK;
            } else if (i > BOARD_SIZE - 4) {
                board[i][j] = WHITE;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
    return board;
}

void print_board(Square** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(". ");
                    break;
                case WHITE:
                    printf("w ");
                    break;
                case BLACK:
                    printf("b ");
                    break;
            }
        }
        printf("\n");
    }
}

void move_piece(Square** board, int from_x, int from_y, int to_x, int to_y) {
    board[to_y][to_x] = board[from_y][from_x];
    board[from_y][from_x] = EMPTY;
}

int get_piece_direction(Square piece, int y_pos) {
    if (piece == WHITE) {
        return -1;
    } else if (piece == BLACK) {
        return 1;
    } else {
        return 0;
    }
}

int is_move_valid(Square** board, int from_x, int from_y, int to_x, int to_y, Square player) {
    // Check if move is inside the board
    if (to_x < 0 || to_x >= BOARD_SIZE || to_y < 0 || to_y >= BOARD_SIZE) {
        return 0;
    }

    // Check if target square is empty
    if (board[to_y][to_x] != EMPTY) {
        return 0;
    }

    // Check if player is moving their own piece
    if (board[from_y][from_x] != player && board[from_y][from_x] != player + 1) {
        return 0;
    }

    // Check if move is diagonal
    int dx = to_x - from_x;
    int dy = to_y - from_y;
    if (dx == 0 || dy == 0 || abs(dx) != abs(dy)) {
        return 0;
    }

    // Check if piece is moving in the right direction
    int direction = get_piece_direction(board[from_y][from_x], from_y);
    if (direction * dy > 0 && !has_any_capture(board, from_x, from_y, player)) {
        return 0;
    }

    // Check if move is a capture move
    int capture_dx = dx / abs(dx);
    int capture_dy = dy / abs(dy);
    if (can_capture(board, from_x, from_y, capture_dx, capture_dy, player)) {
        if (abs(dx) == 2 && abs(dy) == 2) {
            return 1;
        } else {
            return 0;
        }
    }

    // Check if move is a non-capture move
    if (abs(dx) == 1 && abs(dy) == 1) {
        return 1;
    }

    // Move is invalid
    return 0;
}

int can_capture(Square** board, int x, int y, int dx, int dy, Square player) {
    int opponent = player == WHITE ? BLACK : WHITE;
    int new_x = x + dx;
    int new_y = y + dy;
    int capture_x = new_x + dx;
    int capture_y = new_y + dy;
    if (capture_x < 0 || capture_x >= BOARD_SIZE || capture_y < 0 || capture_y >= BOARD_SIZE) {
        return 0;
    }
    return board[new_y][new_x] == opponent || board[new_y][new_x] == opponent + 1;
}

int has_any_capture(Square** board, int x, int y, Square player) {
    for (int dx = -2; dx <= 2; dx += 4) {
        for (int dy = -2; dy <= 2; dy += 4) {
            if (can_capture(board, x, y, dx, dy, player)) {
                int capture_x = x + dx * 2;
                int capture_y = y + dy * 2;
                if (is_move_valid(board, x, y, capture_x, capture_y, player)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int make_capture(Square** board, int from_x, int from_y, int to_x, int to_y, Square player) {
    int dx = to_x - from_x;
    int dy = to_y - from_y;
    int capture_x = from_x + dx / 2;
    int capture_y = from_y + dy / 2;
    board[capture_y][capture_x] = EMPTY;
    move_piece(board, from_x, from_y, to_x, to_y);
    if (has_any_capture(board, to_x, to_y, player)) {
        printf("You can capture again with this piece.\n");
        return 1;
    } else {
        return 0;
    }
}