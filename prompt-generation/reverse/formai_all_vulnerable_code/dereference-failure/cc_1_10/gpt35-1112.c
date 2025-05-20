//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define WIN_SCORE 2048

void printBoard(int **board) {
    printf("\nScore: %d\n", board[BOARD_SIZE][BOARD_SIZE]);
    printf("┌────┬────┬────┬────┐\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("│%4d", board[i][j]);
        }
        printf("│\n");
        if(i != BOARD_SIZE-1)
            printf("├────┼────┼────┼────┤\n");
    }
    printf("└────┴────┴────┴────┘\n");
}

int canMerge(int cell1, int cell2, int merge) {
    if(!cell1 || (cell1 != cell2 && merge))
        return 0;
    return 1;
}

int addTile(int **board) {
    int emptyCells = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == 0)
                emptyCells++;
        }
    }
    if(!emptyCells)
        return 0;
    int cellIdx = rand()%emptyCells + 1;
    emptyCells = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == 0) {
                emptyCells++;
                if(emptyCells == cellIdx) {
                    board[i][j] = (rand()%10 < 9) ? 2 : 4;
                    return 1;
                }
            }
        }
    }
}

int merge(int **board, int k, int reverse) {
    int merged = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            int i1 = reverse ? BOARD_SIZE-i-1 : i;
            int j1 = reverse ? BOARD_SIZE-j-1 : j;
            if(board[i1][j1] && i1-k >= 0 && canMerge(board[i1][j1], board[i1-k][j1], !merged)) {
                board[i1-k][j1] += board[i1][j1];
                board[i1][j1] = 0;
                board[BOARD_SIZE][BOARD_SIZE] += board[i1-k][j1];
                merged = 1;
            }
        }
    }
    return merged;
}

int moveUp(int **board) {
    return merge(board, 1, 0);
}

int moveDown(int **board) {
    return merge(board, 1, 1);
}

int moveLeft(int **board) {
    return merge(board, 1, 0);
}

int moveRight(int **board) {
    return merge(board, 1, 1);
}

int hasWon(int **board) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == WIN_SCORE)
                return 1;
        }
    }
    return 0;
}

int hasLost(int **board) {
    int moves[4] = {0};
    int same = 1;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(!board[i][j])
                return 0;
            if(i && canMerge(board[i][j], board[i-1][j], 0))
                moves[0] = 1;
            if(i < BOARD_SIZE-1 && canMerge(board[i][j], board[i+1][j], 0))
                moves[1] = 1;
            if(j && canMerge(board[i][j], board[i][j-1], 0))
                moves[2] = 1;
            if(j < BOARD_SIZE-1 && canMerge(board[i][j], board[i][j+1], 0))
                moves[3] = 1;
            if(j && board[i][j] == board[i][j-1])
                same = 0;
            if(i && board[i][j] == board[i-1][j])
                same = 0;
        }
    }
    if(same)
        return 0;
    if(moves[0] || moves[1] || moves[2] || moves[3])
        return 0;
    return 1;
}

int main() {
    srand(time(0));
    int **board = (int **)calloc(BOARD_SIZE+1, sizeof(int *));
    for(int i=0; i<BOARD_SIZE+1; i++) {
        board[i] = (int *)calloc(BOARD_SIZE+1, sizeof(int));
    }
    addTile(board);
    addTile(board);
    printBoard(board);

    while(1) {
        char move;
        scanf(" %c", &move);
        int moved = 0;
        switch(move) {
            case 'w':
                moved = moveUp(board);
                break;
            case 's':
                moved = moveDown(board);
                break;
            case 'a':
                moved = moveLeft(board);
                break;
            case 'd':
                moved = moveRight(board);
                break;
            case 'q':
                printf("Exiting game...\n");
                exit(0);
        }
        if(moved)
            addTile(board);

        printBoard(board);
        if(hasWon(board)) {
            printf("You won!\n");
            break;
        }
        if(hasLost(board)) {
            printf("Game over!\n");
            break;
        }
    }
    return 0;
}