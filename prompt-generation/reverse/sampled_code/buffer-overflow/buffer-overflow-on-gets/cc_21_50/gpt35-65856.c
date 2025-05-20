//FormAI DATASET v1.0 Category: Checkers Game ; Style: irregular
#include<stdio.h>

int main() {
    
    printf("\n\tWELCOME TO THE MOST IRREGULAR CHECKERS GAME.\n");
    printf("\n\tPREPARE YOURSELF FOR AN EXPERIENCE LIKE NO OTHER.\n");
    printf("\n\tIN THIS VERSION OF THE GAME, THERE IS NO BOARD.\n");
    printf("\n\tTHERE ARE NO PIECES.\n");
    printf("\n\tBUT DON'T WORRY, THIS GAME IS EASY TO PLAY.\n\n");
    
    printf("\tTHE RULES ARE AS FOLLOWS:\n\n");
    printf("\t1. PLAYER 1 CHOOSES AN EMPTY SPACE IN THEIR FIELD.\n");
    printf("\t2. PLAYER 2 MUST THEN ALSO CHOOSE AN EMPTY SPACE IN PLAYER 1'S FIELD.\n");
    printf("\t3. THE FIRST PLAYER TO COMPLETE A LINE OF 5 CONTINUOUS SPACES WINS.\n");
    
    printf("\n\tIN THIS GAME, BEING ABLE TO REMEMBER YOUR CHOICES IS KEY TO WINNING.\n");
    
    char player1[20], player2[20], choice1[5], choice2[5], field[15][15];
    int i, j, count1 = 0, count2 = 0, winner = 0, turns = 0;
    
    printf("\n\nENTER PLAYER 1 NAME: ");
    gets(player1);
    printf("\nENTER PLAYER 2 NAME: ");
    gets(player2);
    
    printf("\n\nLET THE IRREGULAR CHECKERS GAME BEGIN!\n\n");
    
    for(i = 0; i < 15; i++) {
        for(j = 0; j < 15; j++) {
            field[i][j] = '-';
        }
    }
    
    while(turns < 225) {
        printf("\n%s's TURN (SELECT AN EMPTY SPACE): ", player1);
        gets(choice1);
        for(i = 0; i < 15; i++) {
            for(j = 0; j < 15; j++) {
                if(field[i][j] == choice1[0]) {
                    field[i][j] = 'X';
                    count1++;
                }
            }
        }
        turns++;
        
        if(count1 >= 5) {
            for(i = 0; i < 15; i++) {
                for(j = 0; j < 11; j++) {
                    if(field[i][j] == 'X' && field[i][j+1] == 'X' && field[i][j+2] == 'X' && field[i][j+3] == 'X' && field[i][j+4] == 'X') {
                        winner = 1;
                        break;
                    }
                }
            }
        }
        
        printf("\n\n");
        for(i = 0; i < 15; i++) {
            for(j = 0; j < 15; j++) {
                printf("%c ", field[i][j]);
            }
            printf("\n");
        }
        
        if(winner == 1) {
            printf("\n\n****CONGRATULATIONS %s! YOU HAVE WON THE GAME!****", player1);
            break;
        }
        winner = 0;
        
        printf("\n%s's TURN (SELECT AN EMPTY SPACE): ", player2);
        gets(choice2);
        for(i = 0; i < 15; i++) {
            for(j = 0; j < 15; j++) {
                if(field[i][j] == choice2[0]) {
                    field[i][j] = 'O';
                    count2++;
                }
            }
        }
        turns++;
        
        if(count2 >= 5) {
            for(i = 0; i < 15; i++) {
                for(j = 0; j < 11; j++) {
                    if(field[j][i] == 'O' && field[j+1][i] == 'O' && field[j+2][i] == 'O' && field[j+3][i] == 'O' && field[j+4][i] == 'O') {
                        winner = 2;
                        break;
                    }
                }
            }
        }
        
        printf("\n\n");
        for(i = 0; i < 15; i++) {
            for(j = 0; j < 15; j++) {
                printf("%c ", field[i][j]);
            }
            printf("\n");
        }
        
        if(winner == 2) {
            printf("\n\n****CONGRATULATIONS %s! YOU HAVE WON THE GAME!****", player2);
            break;
        }
        winner = 0;
    }
    
    printf("\n\nTHANK YOU FOR PLAYING THE MOST IRREGULAR CHECKERS GAME!");

    return 0;
}