//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOARD_SIZE 3

void display_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n");
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[BOARD_SIZE][BOARD_SIZE],char player)
{
    for(int i=0;i<BOARD_SIZE;i++){
        if(board[i][0]==player&&board[i][1]==player&&board[i][2]==player){
            return 1;
        }
        if(board[0][i]==player&&board[1][i]==player&&board[2][i]==player){
            return 1;
        }
    }
    if(board[0][0]==player&&board[1][1]==player&&board[2][2]==player){
        return 1;
    }
    if(board[2][0]==player&&board[1][1]==player&&board[0][2]==player){
        return 1;
    }
    return 0;
}

int evaluate_board(char board[BOARD_SIZE][BOARD_SIZE],char ai,char human)
{
    int score = 0;
    if(check_winner(board,ai)){
        score = 1;
    } else if(check_winner(board,human)){
        score = -1;
    }
    return score;
}

int minimax(char board[BOARD_SIZE][BOARD_SIZE],int depth,int alpha,int beta,int is_maximizing_player,char ai,char human)
{
    int score;
    if(check_winner(board,ai)){
        return 1;
    }
    if(check_winner(board,human)){
        return -1;
    }
    if(depth==0){
        return 0;
    }

    if(is_maximizing_player){
        int max_score = -9999;
        for(int i=0;i<BOARD_SIZE;i++){
            for(int j=0;j<BOARD_SIZE;j++){
                if(board[i][j]==' '){
                    board[i][j] = ai;
                    score = minimax(board,depth-1,alpha,beta,0,ai,human);
                    board[i][j] = ' ';
                    if(score > max_score){
                        max_score = score;
                    }
                    if(max_score > alpha){
                        alpha = max_score;
                    }
                    if(alpha >= beta){
                        return max_score;
                    }
                }
            }
        }
        return max_score;
    } else {
        int min_score = 9999;
        for(int i=0;i<BOARD_SIZE;i++){
            for(int j=0;j<BOARD_SIZE;j++){
                if(board[i][j]==' '){
                    board[i][j] = human;
                    score = minimax(board,depth-1,alpha,beta,1,ai,human);
                    board[i][j] = ' ';
                    if(score < min_score){
                        min_score = score;
                    }
                    if(min_score < beta){
                        beta = min_score;
                    }
                    if(beta <= alpha){
                        return min_score;
                    }
                }
            }
        }
        return min_score;
    }
}

void ai_turn(char board[BOARD_SIZE][BOARD_SIZE],char ai,char human)
{
    int x,y;
    int best_score = -9999;
    int score;
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j]==' '){
                board[i][j] = ai;
                score = minimax(board,10,-10000,10000,0,ai,human);
                board[i][j] = ' ';
                if(score > best_score){
                    best_score = score;
                    x = i;
                    y = j;
                }
            }
        }
    }
    board[x][y] = ai;
}

void human_turn(char board[BOARD_SIZE][BOARD_SIZE],char human)
{
    int x,y;
    printf("Enter coordinates: ");
    scanf("%d %d",&x,&y);
    x--;
    y--;
    if(board[x][y]==' '){
        board[x][y] = human;
    } else {
        printf("Invalid move, try again\n");
        human_turn(board,human);
    }
}

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    char human;
    char ai;
    srand(time(NULL));
    int random_num = rand()%101;
    if(random_num < 50){
        human = 'X';
        ai = 'O';
    } else {
        human = 'O';
        ai = 'X';
        ai_turn(board,ai,human);
        display_board(board);
    }
    int game_over = 0;
    int current_player = 1;
    while(!game_over){
        if(current_player==1){
            human_turn(board,human);
            display_board(board);
            if(check_winner(board,human)){
                printf("You win!\n");
                game_over = 1;
            }
            current_player = 2;
        } else {
            ai_turn(board,ai,human);
            display_board(board);
            if(check_winner(board,ai)){
                printf("You lose!\n");
                game_over = 1;
            }
            current_player = 1;
        }
        int empty_spaces = 0;
        for(int i=0;i<BOARD_SIZE;i++){
            for(int j=0;j<BOARD_SIZE;j++){
                if(board[i][j]==' '){
                    empty_spaces = 1;
                }
            }
        }
        if(!empty_spaces){
            printf("It's a tie!\n");
            game_over = 1;
        }
    }
    return 0;
}