//FormAI DATASET v1.0 Category: Memory Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

// function to print the game board
void print_board(int **board) {
    printf("\n\n============== MEMORY GAME ==============\n\n");
    printf("   ");
    for(int i=0;i<COLS;i++) {
        printf("%-5d",i+1);
    }
    printf("\n");
    for(int i=0;i<ROWS;i++) {
        printf("%-2d ",i+1);
        for(int j=0;j<COLS;j++) {
            if(board[i][j] == -1) {
                printf("  *  ");
            } else {
                printf("%-5d",board[i][j]);
            }
        }
        printf("\n");
    }
}

// function to shuffle the cards
void shuffle_cards(int **cards, int n) {
    srand(time(NULL));
    int k,temp;
    for(int i=n-1;i>=0;i--) {
        k = rand() % (i+1);
        temp = cards[k][0];
        cards[k][0] = cards[i][0];
        cards[i][0] = temp;
    }
}

// function to initialize the board
void initialize_board(int **board) {
    int count = 0;
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            board[i][j] = -1;
        }
    }
    int **cards = (int**)malloc(ROWS*COLS*sizeof(int*));
    for(int i=0;i<ROWS*COLS/2;i++) {
        cards[count] = (int*)malloc(2*sizeof(int));
        cards[count][0] = count+1;
        cards[count][1] = 0;
        count++;
    }
    count = 0;
    for(int i=ROWS*COLS/2;i<ROWS*COLS;i++) {
        cards[count] = (int*)malloc(2*sizeof(int));
        cards[count][0] = count+1-ROWS*COLS/2;
        cards[count][1] = 0;
        count++;
    }
    shuffle_cards(cards,ROWS*COLS);
    count = 0;
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            board[i][j] = cards[count][0];
            count++;
        }
    }
}

int main() {
    int **board = (int**)malloc(ROWS*sizeof(int*));
    for(int i=0;i<ROWS;i++) {
        board[i] = (int*)malloc(COLS*sizeof(int));
    }
    initialize_board(board);
    int row1,row2,col1,col2,count=0;
    while(1) {
        print_board(board);
        printf("\n\nEnter the coordinates of the first card: ");
        scanf("%d %d",&row1,&col1);
        row1--;
        col1--;
        if(board[row1][col1]<=0) {
            printf("\nInvalid Input!");
            continue;
        }
        printf("\nEnter the coordinates of the second card: ");
        scanf("%d %d",&row2,&col2);
        row2--;
        col2--;
        if(board[row2][col2]<=0) {
            printf("\nInvalid Input!");
            continue;
        }
        if(board[row1][col1] == board[row2][col2]) {
            board[row1][col1] = -2;
            board[row2][col2] = -2;
            count++;
            if(count == ROWS*COLS/2) {
                printf("\nCongratulations! You have matched all the pairs!");
                break;
            }
        } else {
            printf("\nSorry, the cards do not match!");
        }
    }
    return 0;
}