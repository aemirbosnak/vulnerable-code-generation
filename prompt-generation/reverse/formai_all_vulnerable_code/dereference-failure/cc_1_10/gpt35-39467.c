//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// function to print the tic-tac-toe board
void print_board(char** board) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j != 2) printf("|");
        }
        printf("\n");
        if (i != 2) printf("-----------\n");
    }
    printf("\n");
}

// function to check if a player has won
int check_win(char** board, char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

// function to evaluate the score of the current board state
int evaluate(char** board, char player, char opponent) {
    if (check_win(board, player)) {
        return 10;
    } else if (check_win(board, opponent)) {
        return -10;
    } else {
        return 0;
    }
}

// function to implement the minimax algorithm
int minimax(char** board, int depth, int is_max, char player, char opponent, int alpha, int beta) {
    int score = evaluate(board, player, opponent);
    if (score == 10 || score == -10) {
        return score;
    }
    if (depth == 9) {
        return 0;
    }
    if (is_max) {
        int best_score = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = player;
                    int score = minimax(board, depth + 1, 0, player, opponent, alpha, beta);
                    board[i][j] = '_';
                    if (score > best_score) {
                        best_score = score;
                    }
                    alpha = alpha > best_score ? alpha : best_score;
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return best_score;
    } else {
        int best_score = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = opponent;
                    int score = minimax(board, depth + 1, 1, player, opponent, alpha, beta);
                    board[i][j] = '_';
                    if (score < best_score) {
                        best_score = score;
                    }
                    beta = beta < best_score ? beta : best_score;
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return best_score;
    }
}

// function to get the optimal move for the AI
void get_computer_move(char** board, char player, char opponent, int* row, int* col) {
    int best_score = -1000;
    *row = -1;
    *col = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '_') {
                board[i][j] = player;
                int score = minimax(board, 0, 0, player, opponent, -1000, 1000);
                board[i][j] = '_';
                if (score > best_score) {
                    best_score = score;
                    *row = i;
                    *col = j;
                }
            }
        }
    }
}

// function to play the game
void play_game() {
    char** board = (char**) malloc(3 * sizeof(char*)); // allocate memory for board
    for (int i = 0; i < 3; i++) {
        board[i] = (char*) malloc(3 * sizeof(char));
        for (int j = 0; j < 3; j++) {
            board[i][j] = '_'; // initialize board with empty spaces
        }
    }
    char player = 'X';
    char opponent = 'O';
    int row, col;
    print_board(board);
    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            printf("Your turn (X), choose your move (row column): ");
            scanf("%d %d", &row, &col);
            row--;
            col--;
            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '_') {
                printf("Invalid move, please try again.\n");
                i--;
            } else {
                board[row][col] = player;
                print_board(board);
                if (check_win(board, player)) {
                    printf("Congratulations, you win!\n");
                    return;
                }
            }
        } else {
            printf("My turn (O), I am thinking...\n");
            get_computer_move(board, opponent, player, &row, &col);
            board[row][col] = opponent;
            print_board(board);
            if (check_win(board, opponent)) {
                printf("Sorry, you lose.\n");
                return;
            }
        }
    }
    printf("It's a draw.\n");
}

int main() {
    play_game();
    return 0;
}