//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: modular
#include <stdio.h>
#include <stdlib.h>

char** create_board(int size) {
    char** board = (char**) malloc(size * sizeof(char*));
    for(int i = 0; i < size; i++) {
        board[i] = (char*) malloc(size * sizeof(char));
        for(int j = 0; j < size; j++) {
            board[i][j] = '-';
        }
    }
    return board;
}

void print_board(char** board, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int game_over(char** board, int size) {
    int rows, cols, diags;
    for(int i = 0; i < size; i++) {
        rows = 0;
        cols = 0;
        diags = 0;
        for(int j = 0; j < size; j++) {
            // check rows
            if(board[i][j] == 'X') rows++;
            else if(board[i][j] == 'O') rows--;
            // check cols
            if(board[j][i] == 'X') cols++;
            else if(board[j][i] == 'O') cols--;
            // check diags
            if(i == j && board[i][j] == 'X') diags++;
            else if(i == j && board[i][j] == 'O') diags--;
            if(i == size - j - 1 && board[i][j] == 'X') diags++;
            else if(i == size - j - 1 && board[i][j] == 'O') diags--;
        }
        if(rows == size || cols == size || diags == size) return 1;
        else if(rows == -size || cols == -size || diags == -size) return -1;
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(board[i][j] == '-') return 0;
        }
    }
    return 2;
}

int minimax(char** board, int size, int depth, int player) {
    int score = game_over(board, size);
    if(score != 0) return score;
    if(player == 1) {
        int max_score = -100;
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = 'X';
                    int current_score = minimax(board, size, depth+1, -1);
                    if(current_score > max_score) {
                        max_score = current_score;
                    }
                    board[i][j] = '-';
                }
            }
        }
        return max_score;
    } else {
        int min_score = 100;
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = 'O';
                    int current_score = minimax(board, size, depth+1, 1);
                    if(current_score < min_score) {
                        min_score = current_score;
                    }
                    board[i][j] = '-';
                }
            }
        }
        return min_score;
    }
}

void make_move(char** board, int size, int *x, int *y) {
    int max_score = -100;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(board[i][j] == '-') {
                board[i][j] = 'X';
                int current_score = minimax(board, size, 0, -1);
                if(current_score > max_score) {
                    max_score = current_score;
                    *x = i;
                    *y = j;
                }
                board[i][j] = '-';
            }
        }
    }
}

int main() {
    int size = 3, move_count = 0, x, y;
    char **board = create_board(size);
    while(1) {
        printf("Enter your move (row column) [0-%d]: ", size-1);
        scanf("%d %d", &x, &y);
        if(board[x][y] != '-') {
            printf("Invalid move, try again!\n");
            continue;
        }
        board[x][y] = 'O';
        move_count++;
        print_board(board, size);
        if(game_over(board, size) != 0) break;
        printf("AI is thinking...\n");
        make_move(board, size, &x, &y);
        board[x][y] = 'X';
        move_count++;
        print_board(board, size);
        if(game_over(board, size) != 0) break;
    }
    if(game_over(board, size) == 1) printf("AI wins!\n");
    else if(game_over(board, size) == -1) printf("You win!\n");
    else printf("Draw!\n");
    return 0;
}