//FormAI DATASET v1.0 Category: Chess AI ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for chess pieces
typedef struct{
    char type[10];   //type of piece (king, queen, bishop, knight, rook, pawn)
    char color[6];   //color of piece (white, black)
}Piece;

//Function to create a new chess board
Piece** createBoard(){
    Piece** board = (Piece**)malloc(8*sizeof(Piece*));
    for(int i=0;i<8;i++)
        board[i] = (Piece*)malloc(8*sizeof(Piece));

    //initialize the board for starting position
    //white pieces
    strcpy(board[0][0].type,"rook");
    strcpy(board[0][0].color,"white");
    strcpy(board[0][1].type,"knight");
    strcpy(board[0][1].color,"white");
    strcpy(board[0][2].type,"bishop");
    strcpy(board[0][2].color,"white");
    strcpy(board[0][3].type,"queen");
    strcpy(board[0][3].color,"white");
    strcpy(board[0][4].type,"king");
    strcpy(board[0][4].color,"white");
    strcpy(board[0][5].type,"bishop");
    strcpy(board[0][5].color,"white");
    strcpy(board[0][6].type,"knight");
    strcpy(board[0][6].color,"white");
    strcpy(board[0][7].type,"rook");
    strcpy(board[0][7].color,"white");
    for(int i=0;i<8;i++){
        strcpy(board[1][i].type,"pawn");
        strcpy(board[1][i].color,"white");
    }

    //black pieces
    strcpy(board[7][0].type,"rook");
    strcpy(board[7][0].color,"black");
    strcpy(board[7][1].type,"knight");
    strcpy(board[7][1].color,"black");
    strcpy(board[7][2].type,"bishop");
    strcpy(board[7][2].color,"black");
    strcpy(board[7][3].type,"queen");
    strcpy(board[7][3].color,"black");
    strcpy(board[7][4].type,"king");
    strcpy(board[7][4].color,"black");
    strcpy(board[7][5].type,"bishop");
    strcpy(board[7][5].color,"black");
    strcpy(board[7][6].type,"knight");
    strcpy(board[7][6].color,"black");
    strcpy(board[7][7].type,"rook");
    strcpy(board[7][7].color,"black");
    for(int i=0;i<8;i++){
        strcpy(board[6][i].type,"pawn");
        strcpy(board[6][i].color,"black");
    }

    //initialize the empty squares with null values
    for(int i=2;i<6;i++)
        for(int j=0;j<8;j++)
            strcpy(board[i][j].type,"null");

    return board;
}

int main(){
    //create a new chess board
    Piece** board = createBoard();

    //print the starting position of the board
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
            printf("%s ",board[i][j].type);
        printf("\n");
    }

    //free memory
    for(int i=0;i<8;i++)
        free(board[i]);
    free(board);

    return 0;
}