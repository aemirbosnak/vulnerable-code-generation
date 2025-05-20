//FormAI DATASET v1.0 Category: Table Game ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n, i, j, k, sum1=0, sum2=0;
    printf("Enter number of rows and columns of your board game: ");
    scanf("%d",&n);

    int board[n][n];
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            board[i][j] = rand()%100;
        }
    }
    printf("Board game:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    int player1_posx=0, player1_posy=0, player2_posx=n-1, player2_posy=n-1;
    printf("Initial positions:\nPlayer1: (%d,%d)\nPlayer2: (%d,%d)\n",player1_posx,player1_posy,player2_posx,player2_posy);

    while(player1_posx!=(n-1) || player1_posy!=(n-1) || player2_posx!=0 || player2_posy!=0)
    {
        //Player1 turn
        printf("\nPlayer1 turn\n");
        printf("Enter number of steps to move: ");
        scanf("%d",&k);
        if(player1_posx+k<=n-1)
        {
            player1_posx+=k;
        }
        else
        {
            player1_posy = player1_posx + k - (n-1);
            player1_posx = n-1;
        }
        if(board[player1_posx][player1_posy]%2==0)
        {
            sum1+=board[player1_posx][player1_posy];
            printf("Even number! Player1 adding %d points. New score: %d\n",board[player1_posx][player1_posy],sum1);
        }
        else
        {
            sum1-=board[player1_posx][player1_posy];
            printf("Odd number! Player1 subtracting %d points. New score: %d\n",board[player1_posx][player1_posy],sum1);
        }
        printf("Player1 position: (%d,%d)\n", player1_posx, player1_posy);
        if(player1_posx==(n-1) && player1_posy==(n-1))
        {
            printf("Player1 wins!\n");
            break;
        }

        //Player2 turn
        printf("\nPlayer2 turn\n");
        printf("Enter number of steps to move: ");
        scanf("%d",&k);
        if(player2_posx-k>=0)
        {
            player2_posx-=k;
        }
        else
        {
            player2_posy = abs(player2_posx-k);
            player2_posx = 0;
        }
        if(board[player2_posx][player2_posy]%2==0)
        {
            sum2+=board[player2_posx][player2_posy];
            printf("Even number! Player2 adding %d points. New score: %d\n",board[player2_posx][player2_posy],sum2);
        }
        else
        {
            sum2-=board[player2_posx][player2_posy];
            printf("Odd number! Player2 subtracting %d points. New score: %d\n",board[player2_posx][player2_posy],sum2);
        }
        printf("Player2 position: (%d,%d)\n", player2_posx, player2_posy);
        if(player2_posx==0 && player2_posy==0)
        {
            printf("Player2 wins!\n");
            break;
        }
    }
    return 0;
}