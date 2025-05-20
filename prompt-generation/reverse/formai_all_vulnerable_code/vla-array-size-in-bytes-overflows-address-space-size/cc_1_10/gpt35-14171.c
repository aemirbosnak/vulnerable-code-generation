//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to check if the temperature is in the safe range
int range_check(int temp)
{
    if(temp>=0 && temp<=100)
        return 1;
    else
        return 0;
}

//function to check if all players have entered their temperature
int all_players_checked(int *temp, int num_players)
{
    for(int i=0;i<num_players;i++)
    {
        if(temp[i]==-1)
            return 0;
    }
    return 1;
}

int main()
{
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d",&num_players);

    //initialize array to store player temperatures to -1
    int temp[num_players];
    for(int i=0;i<num_players;i++)
    {
        temp[i]=-1;
    }

    srand(time(NULL));
    int secret_temp=rand()%101;

    printf("\n\nPlayer 1, guess the temperature: ");
    scanf("%d",&temp[0]);

    //loop until all players have entered their temperature
    while(!all_players_checked(temp,num_players))
    {
        int player=(rand()%num_players);
        if(temp[player]==-1)
        {
            printf("\n\nPlayer %d, guess the temperature: ",player+1);
            scanf("%d",&temp[player]);
        }
    }

    //calculate the average of the player temperatures and display
    int sum=0;
    for(int i=0;i<num_players;i++)
    {
        sum+=temp[i];
    }
    int avg=sum/num_players;
    printf("\n\nThe average temperature guessed by all players is %d degrees Celsius.",avg);

    //check if the secret temperature is within the safe range
    if(range_check(secret_temp))
        printf("\nThe secret temperature is within the safe range.");
    else
        printf("\nThe secret temperature is NOT within the safe range.");

    return 0;
}