//FormAI DATASET v1.0 Category: Checkers Game ; Style: sophisticated
#include <stdio.h>

#define ROW     8
#define COLUMN  8

#define BLACK   'B'
#define RED     'R'

#define EMPTY   '.'

typedef struct{
    char player;    // the player that occupies this square, 'R', 'B' or '.'
    int row;        // the row location of this square
    int col;        // the column location of this square
} Square;

Square* board[ROW][COLUMN]; // the board in the game

// initialize the board at the start of each game
void initialize_board(){
    // initialize all squares to empty
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            board[i][j] = malloc(sizeof(Square));
            board[i][j]->player = EMPTY;
            board[i][j]->row = i;
            board[i][j]->col = j;
        }
    }
    // set pieces in their starting positions
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            if(i % 2 != j % 2){
                if(i < 3){
                    board[i][j]->player = RED;
                }
                else if(i > 4){
                    board[i][j]->player = BLACK;
                }
            }
        }
    }
}

// print the board
void print_board(){
    printf("  ");
    for(int j = 0; j < COLUMN; j++){
        printf("%d ", j);
    }
    printf("\n");
    for(int i = 0; i < ROW; i++){
        printf("%d ", i);
        for(int j = 0; j < COLUMN; j++){
            printf("%c ", board[i][j]->player);
        }
        printf("\n");
    }
}

// return 1 if the given player has no more pieces on the board, 0 otherwise
int game_finished(char player){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            if(board[i][j]->player == player){
                return 0;
            }
        }
    }
    return 1;
}

// check if the move is legal
int move_legal(int start_row, int start_col, int end_row, int end_col){
    // check if the end square is empty
    if(board[end_row][end_col]->player != EMPTY){
        return 0;
    }
    // check if the start square contains a piece that belongs to the current player
    if(board[start_row][start_col]->player != BLACK && board[start_row][start_col]->player != RED){
        return 0;
    }
    // check if the move is diagonal
    if(abs(start_row - end_row) != abs(start_col - end_col)){
        return 0;
    }
    // check if the move is within the bounds of the board
    if(start_row < 0 || start_row >= ROW || start_col < 0 || start_col >= COLUMN || end_row < 0 || end_row >= ROW || end_col < 0 || end_col >= COLUMN){
        return 0;
    }
    // check if the move is only one square away diagonally
    if(abs(start_row - end_row) != 1){
        return 0;
    }
    // check if the move is forward for black and red player, respectively
    if(board[start_row][start_col]->player == BLACK){
        if(end_row <= start_row){
            return 0;
        }
    }
    else if(board[start_row][start_col]->player == RED){
        if(end_row >= start_row){
            return 0;
        }
    }
    return 1;
}

// perform a move
int perform_move(int start_row, int start_col, int end_row, int end_col){
    // check if the move is legal
    if(move_legal(start_row, start_col, end_row, end_col)){
        // move the piece to the end square
        board[end_row][end_col]->player = board[start_row][start_col]->player;
        // remove the piece from the start square
        board[start_row][start_col]->player = EMPTY;
        // check if the piece has reached the last row
        if((board[end_row][end_col]->player == BLACK && end_row == ROW - 1) || (board[end_row][end_col]->player == RED && end_row == 0)){
            board[end_row][end_col]->player = toupper(board[end_row][end_col]->player);
        }
        return 1;
    }
    return 0;
}

int main(){
    initialize_board();
    print_board();
    while(!game_finished(BLACK) && !game_finished(RED)){
        printf("BLACK'S TURN:\n");
        int start_row, start_col, end_row, end_col;
        printf("Enter start row: ");
        scanf("%d", &start_row);
        printf("Enter start column: ");
        scanf("%d", &start_col);
        printf("Enter end row: ");
        scanf("%d", &end_row);
        printf("Enter end column: ");
        scanf("%d", &end_col);
        if(!perform_move(start_row, start_col, end_row, end_col)){
            printf("Invalid move.\n");
            continue;
        }
        print_board();
        if(game_finished(BLACK) || game_finished(RED)){
            break;
        }
        printf("RED'S TURN:\n");
        printf("Enter start row: ");
        scanf("%d", &start_row);
        printf("Enter start column: ");
        scanf("%d", &start_col);
        printf("Enter end row: ");
        scanf("%d", &end_row);
        printf("Enter end column: ");
        scanf("%d", &end_col);
        if(!perform_move(start_row, start_col, end_row, end_col)){
            printf("Invalid move.\n");
            continue;
        }
        print_board();
    }
    if(game_finished(BLACK)){
        printf("RED WINS!\n");
    }
    else if(game_finished(RED)){
        printf("BLACK WINS!\n");
    }
    return 0;
}