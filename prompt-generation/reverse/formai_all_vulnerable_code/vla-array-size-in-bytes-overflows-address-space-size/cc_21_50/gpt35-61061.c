//FormAI DATASET v1.0 Category: Table Game ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int row, col, i, j, flag, turn=1, num=0;
    char player1[20], player2[20];
    
    printf("Enter the name of player 1: ");
    scanf("%s", &player1);
    printf("Enter the name of player 2: ");
    scanf("%s", &player2);
    
    printf("\nEnter the number of rows you want in the game: ");
    scanf("%d",&row);
    printf("Enter the number columns you want in the game: ");
    scanf("%d",&col);
    
    int arr[row][col];
    
    //placing all 0s in the array
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            arr[i][j]=0;
        }
    }
    
    //Printing the rules
    printf("\nWELCOME TO C TABLE GAME\n");
    printf("RULES:\n");
    printf("1. Two players need to take alternate turns to fill the cells of the table\n");
    printf("2. Player who fills all the values of the row or column will be declared as winner\n");
    printf("3. To fill the cells of the table, you need to give the number of row and column respectively.\n");

    //Game loop
    while(num<row*col){
        flag=0;
        
        //Printing the table
        printf("\n");
        for(i=0; i<row; i++){
            printf("        ");
            for(j=0; j<col; j++){
                if(arr[i][j]==0){
                    printf("-  ");
                }
                else if(arr[i][j]==1){
                    printf("X  ");
                }
                else{
                    printf("O  ");
                }
            }
            printf("\n");
        }

        //Checking for winner
        for(i=0; i<row; i++){
            //Horizontal
            if(arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2] && arr[i][0]!=0){
                printf("\n%s WINS!\n", (arr[i][0]==1)? player1:player2);
                flag=1;
                break;
            }
            //Vertical
            if(arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i] && arr[0][i]!=0){
                printf("\n%s WINS!\n", (arr[0][i]==1)?player1:player2);
                flag=1;
                break;
            }
        }
        //Diagonal
        if((arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] && arr[0][0]!=0) || (arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0] && arr[0][2]!=0)){
            printf("\n%s WINS!\n", (arr[1][1]==1)?player1:player2);
            flag=1;
        }
        if(flag==1){
            break;
        }

        //Tossing the turn
        if(turn%2==0){
            printf("\n%s's Turn:", player2);
        }
        else{
            printf("\n%s's Turn:", player1);
        }
        turn++;
        
        //Getting input for placing marks
        printf("\nEnter the row number: ");
        scanf("%d",&i);
        printf("Enter the column number: ");
        scanf("%d",&j);

        while(i>row || j>col || i<1 || j<1 || arr[i-1][j-1]!=0){
            printf("\nEnter correct row and column number: ");
            scanf("%d",&i);
            printf("Enter correct column number: ");
            scanf("%d",&j);
        }
        
        //Placing the mark of the current player
        if(turn%2==0){
            arr[i-1][j-1]=2;
        }
        else{
            arr[i-1][j-1]=1;
        }
        num++;
    }
    
    //Printing the final table
    printf("\n");
    for(i=0; i<row; i++){
        printf("        ");
        for(j=0; j<col; j++){
            if(arr[i][j]==0){
                printf("-  ");
            }
            else if(arr[i][j]==1){
                printf("X  ");
            }
            else{
                printf("O  ");
            }
        }
        printf("\n");
    }
}