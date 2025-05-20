//FormAI DATASET v1.0 Category: Chess AI ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The dimensions of the chess board
#define BOARD_SIZE 8

// The maximum depth of the search algorithm
#define SEARCH_DEPTH 2

// The values representing different pieces on the board
#define EMPTY_SPACE 0
#define WHITE_PAWN 1
#define WHITE_KNIGHT 2
#define WHITE_BISHOP 3
#define WHITE_ROOK 4
#define WHITE_QUEEN 5
#define WHITE_KING 6
#define BLACK_PAWN -1
#define BLACK_KNIGHT -2
#define BLACK_BISHOP -3
#define BLACK_ROOK -4
#define BLACK_QUEEN -5
#define BLACK_KING -6

// This struct represents a move on the board
typedef struct {
    int from_row;
    int from_col;
    int to_row;
    int to_col;
    int value;
} Move;

// This function initializes a new chess board
int** initializeBoard() {
    int** board = (int**) malloc(sizeof(int*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (int*) malloc(sizeof(int) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 1) {
                board[i][j] = WHITE_PAWN;
            } else if (i == 0) {
                if (j == 0 || j == 7) {
                    board[i][j] = WHITE_ROOK;
                } else if (j == 1 || j == 6) {
                    board[i][j] = WHITE_KNIGHT;
                } else if (j == 2 || j == 5) {
                    board[i][j] = WHITE_BISHOP;
                } else if (j == 3) {
                    board[i][j] = WHITE_QUEEN;
                } else if (j == 4) {
                    board[i][j] = WHITE_KING;
                }
            } else if (i == 6) {
                board[i][j] = BLACK_PAWN;
            } else if (i == 7) {
                if (j == 0 || j == 7) {
                    board[i][j] = BLACK_ROOK;
                } else if (j == 1 || j == 6) {
                    board[i][j] = BLACK_KNIGHT;
                } else if (j == 2 || j == 5) {
                    board[i][j] = BLACK_BISHOP;
                } else if (j == 3) {
                    board[i][j] = BLACK_QUEEN;
                } else if (j == 4) {
                    board[i][j] = BLACK_KING;
                }
            } else {
                board[i][j] = EMPTY_SPACE;
            }
        }
    }
    return board;
}

// This function frees memory allocated for the chess board
void freeBoard(int** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);
}

// This function prints out the chess board
void printBoard(int** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY_SPACE:
                    printf(". ");
                    break;
                case WHITE_PAWN:
                    printf("P ");
                    break;
                case WHITE_KNIGHT:
                    printf("N ");
                    break;
                case WHITE_BISHOP:
                    printf("B ");
                    break;
                case WHITE_ROOK:
                    printf("R ");
                    break;
                case WHITE_QUEEN:
                    printf("Q ");
                    break;
                case WHITE_KING:
                    printf("K ");
                    break;
                case BLACK_PAWN:
                    printf("p ");
                    break;
                case BLACK_KNIGHT:
                    printf("n ");
                    break;
                case BLACK_BISHOP:
                    printf("b ");
                    break;
                case BLACK_ROOK:
                    printf("r ");
                    break;
                case BLACK_QUEEN:
                    printf("q ");
                    break;
                case BLACK_KING:
                    printf("k ");
                    break;
            }
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n\n");
}

// This function returns the value of a piece given its type
int pieceValue(int piece) {
    switch (piece) {
        case WHITE_PAWN:
        case BLACK_PAWN:
            return 1;
        case WHITE_KNIGHT:
        case BLACK_KNIGHT:
            return 3;
        case WHITE_BISHOP:
        case BLACK_BISHOP:
            return 3;
        case WHITE_ROOK:
        case BLACK_ROOK:
            return 5;
        case WHITE_QUEEN:
        case BLACK_QUEEN:
            return 9;
        case WHITE_KING:
        case BLACK_KING:
            return 100;
        default:
            return 0;
    }
}

// This function calculates the value of a board position for a given player
int evaluateBoard(int** board, int player) {
    int value = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int piece = board[i][j];
            if (piece * player > 0) {
                value += pieceValue(piece);
            } else if (piece * player < 0) {
                value -= pieceValue(piece);
            }
        }
    }
    return value;
}

// This function copies a chess board
int** copyBoard(int** board) {
    int** newBoard = initializeBoard();
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            newBoard[i][j] = board[i][j];
        }
    }
    return newBoard;
}

// This function checks if a position is within the bounds of the board
int inBounds(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

// This function generates all possible moves for a given player
Move* generateMoves(int** board, int player, int* numMoves) {
    Move* moves = (Move*) malloc(sizeof(Move) * BOARD_SIZE * BOARD_SIZE);
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int piece = board[i][j];
            if (piece * player > 0) {  // Check if the piece belongs to the player
                if (piece == WHITE_PAWN || piece == BLACK_PAWN) {  // Handle pawn moves
                    int direction = (piece / abs(piece));  // Determine the direction of the pawn
                    if (board[i+direction][j] == EMPTY_SPACE) {  // Check for single pawn move
                        moves[index].from_row = i;
                        moves[index].from_col = j;
                        moves[index].to_row = i + direction;
                        moves[index].to_col = j;
                        moves[index].value = 0;
                        index++;
                        if (i == 1 && board[i+(2*direction)][j] == EMPTY_SPACE) {  // Check for double pawn move
                            moves[index].from_row = i;
                            moves[index].from_col = j;
                            moves[index].to_row = i + (2 * direction);
                            moves[index].to_col = j;
                            moves[index].value = 0;
                            index++;
                        }
                    }
                    if (inBounds(i+direction, j-1) && board[i+direction][j-1] * player < 0) {  // Check for pawn capture to the left
                        moves[index].from_row = i;
                        moves[index].from_col = j;
                        moves[index].to_row = i + direction;
                        moves[index].to_col = j - 1;
                        moves[index].value = pieceValue(board[i+direction][j-1]);
                        index++;
                    }
                    if (inBounds(i+direction, j+1) && board[i+direction][j+1] * player < 0) {  // Check for pawn capture to the right
                        moves[index].from_row = i;
                        moves[index].from_col = j;
                        moves[index].to_row = i + direction;
                        moves[index].to_col = j + 1;
                        moves[index].value = pieceValue(board[i+direction][j+1]);
                        index++;
                    }
                } else {  // Handle moves for other pieces
                    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
                    if (piece == WHITE_KNIGHT || piece == BLACK_KNIGHT) {  // Handle knight moves
                        directions[0][0] = 2;
                        directions[1][0] = 1;
                        directions[2][0] = -1;
                        directions[3][0] = -2;
                    }
                    if (piece == WHITE_BISHOP || piece == BLACK_BISHOP || piece == WHITE_QUEEN || piece == BLACK_QUEEN) {  // Handle diagonal moves
                        directions[0][1] = 1;
                        directions[1][1] = 1;
                        directions[2][1] = -1;
                        directions[3][1] = -1;
                    }
                    if (piece == WHITE_ROOK || piece == BLACK_ROOK || piece == WHITE_QUEEN || piece == BLACK_QUEEN) {  // Handle horizontal and vertical moves
                        directions[0][0] = 1;
                        directions[1][1] = 1;
                        directions[2][0] = -1;
                        directions[3][1] = -1;
                    }
                    for (int k = 0; k < 4; k++) {
                        int row = i;
                        int col = j;
                        while (1) {
                            row += directions[k][0];
                            col += directions[k][1];
                            if (!inBounds(row, col)) {
                                break;
                            }
                            if (board[row][col] * player < 0) {  // Capture a piece of the other player
                                moves[index].from_row = i;
                                moves[index].from_col = j;
                                moves[index].to_row = row;
                                moves[index].to_col = col;
                                moves[index].value = pieceValue(board[row][col]);
                                index++;
                                break;
                            }
                            if (board[row][col] * player > 0) {  // Can't move through own pieces
                                break;
                            }
                            moves[index].from_row = i;
                            moves[index].from_col = j;
                            moves[index].to_row = row;
                            moves[index].to_col = col;
                            moves[index].value = 0;
                            index++;
                        }
                    }
                }
            }
        }
    }
    *numMoves = index;
    return moves;
}

// This function applies a move to the board
void applyMove(int** board, Move* move) {
    board[move->to_row][move->to_col] = board[move->from_row][move->from_col];
    board[move->from_row][move->from_col] = EMPTY_SPACE;
}

// This function undoes a move on the board
void undoMove(int** board, Move* move, int capturedPiece) {
    board[move->from_row][move->from_col] = board[move->to_row][move->to_col];
    board[move->to_row][move->to_col] = capturedPiece;
}

// This is the recursive function that handles the search algorithm
int minimax(int** board, int depth, int alpha, int beta, int maximizingPlayer) {
    if (depth == 0) {
        return evaluateBoard(board, maximizingPlayer);
    }
    int numMoves;
    Move* moves = generateMoves(board, maximizingPlayer, &numMoves);
    for (int i = 0; i < numMoves; i++) {
        int capturedPiece = board[moves[i].to_row][moves[i].to_col];
        applyMove(board, &moves[i]);
        int score = -minimax(board, depth - 1, -beta, -alpha, -maximizingPlayer);
        undoMove(board, &moves[i], capturedPiece);
        if (score >= beta) {  // Prune the tree if possible
            return beta;
        }
        if (score > alpha) {
            alpha = score;
        }
    }
    free(moves);
    return alpha;
}

// This function gets the best move for a given player using the minimax algorithm
Move getBestMove(int** board, int player) {
    int numMoves;
    Move* moves = generateMoves(board, player, &numMoves);
    Move bestMove = moves[0];
    int bestScore = -1000;
    for (int i = 0; i < numMoves; i++) {
        int capturedPiece = board[moves[i].to_row][moves[i].to_col];
        applyMove(board, &moves[i]);
        int score = -minimax(board, SEARCH_DEPTH - 1, -1000, 1000, -player);
        undoMove(board, &moves[i], capturedPiece);
        if (score > bestScore) {  // Update the best move if necessary
            bestMove = moves[i];
            bestScore = score;
        }
    }
    free(moves);
    return bestMove;
}

// This is the main function that runs the chess game
int main() {
    srand(time(NULL));
    int** board = initializeBoard();
    int player = 1;
    while (1) {
        printf("Player %d's turn:\n", player);
        printBoard(board);
        if (player == 1) {  // Get the player's move
            char move[6];
            printf("Enter your move (e.g. a2a4): ");
            scanf("%s", move);
            int from_row = 8 - (move[1] - '0');
            int from_col = move[0] - 'a';
            int to_row = 8 - (move[3] - '0');
            int to_col = move[2] - 'a';
            int foundMove = 0;
            int numMoves;
            Move* moves = generateMoves(board, player, &numMoves);
            for (int i = 0; i < numMoves; i++) {
                if (moves[i].from_row == from_row && moves[i].from_col == from_col &&
                    moves[i].to_row == to_row && moves[i].to_col == to_col) {
                    applyMove(board, &moves[i]);
                    foundMove = 1;
                    break;
                }
            }
            free(moves);
            if (!foundMove) {
                printf("Invalid move!\n");
                continue;
            }
        } else {  // Use the AI to get the computer's move
            Move computerMove = getBestMove(board, player);
            applyMove(board, &computerMove);
        }
        int winner = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == WHITE_KING) {
                    winner = -1;
                    break;
                } else if (board[i][j] == BLACK_KING) {
                    winner = 1;
                    break;
                }
            }
        }
        if (winner != 0) {
            printf("Player %d wins!\n", (winner == 1) ? 2 : 1);
            break;
        }
        player *= -1;  // Switch the player
    }
    freeBoard(board);
    return 0;
}