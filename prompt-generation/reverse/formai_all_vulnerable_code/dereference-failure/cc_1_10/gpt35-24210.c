//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define WIDTH 50
#define HEIGHT 50
#define MAX_COLOR 255

void initBoard(char board[HEIGHT][WIDTH]){
    int i,j;
    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[HEIGHT][WIDTH]){
    int i,j;
    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
}

void drawPixel(char board[HEIGHT][WIDTH],int x,int y,int r,int g,int b){
    if(x<0 || x>=WIDTH || y<0 || y>=HEIGHT) return;
    int color = ((r*MAX_COLOR/255)<<16) | ((g*MAX_COLOR/255)<<8) | ((b*MAX_COLOR/255)<<0);
    board[y][3*x] = 219;
    board[y][3*x+1] = '|';
    board[y][3*x+2] = '\\';
    board[y+1][3*x] = '-';
    board[y+1][3*x+1] = 216;
    board[y+1][3*x+2] = '-';
    board[y+2][3*x] = '/';
    board[y+2][3*x+1] = '|';
    board[y+2][3*x+2] = 219;
}

int main(){
    char board[HEIGHT][WIDTH];
    initBoard(board);
    srand(time(NULL));
    int i,j,x,y,r,g,b;
    for(i=0;i<100;i++){
        x = rand()%WIDTH;
        y = rand()%HEIGHT;
        r = rand()%256;
        g = rand()%256;
        b = rand()%256;
        drawPixel(board,x,y,r,g,b);
    }
    printBoard(board);
    return 0;
}