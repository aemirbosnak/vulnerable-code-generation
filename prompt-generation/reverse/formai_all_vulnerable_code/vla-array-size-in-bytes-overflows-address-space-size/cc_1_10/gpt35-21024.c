//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int parties, voters, i, j, choice, choose, flag = 0, max = 0, winner;
    printf("Enter the number of parties: ");
    scanf("%d", &parties);
    char party[parties][20];
    int votes[parties];

    // Taking input of party names
    for(i=0;i<parties;i++)
    {
        printf("Enter the name of party %d: ", i+1);
        scanf("%s", party[i]);
        votes[i] = 0;
    }

    // Taking input of number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &voters);

    // Generating random voter id
    srand(time(NULL));
    int id[voters];
    for(i=0;i<voters;i++)
    {
        id[i] = rand()%5001 + 1000;
    }

    // Voting process
    for(i=0;i<voters;i++)
    {
        printf("\nEnter your voter id: ");
        scanf("%d", &choose);
        for(j=0;j<voters;j++)
        {
            if(choose==id[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            printf("\nYou are not authorized to vote.\n");
        }
        else
        {
            printf("\nVoter id validated. Please choose your party.\n");
            for(j=0;j<parties;j++)
            {
                printf("%d. %s\n", j+1, party[j]);
            }
            scanf("%d", &choice);
            votes[choice-1] += 1;
            flag = 0;
        }
    }

    // Finding the winner
    for(i=0;i<parties;i++)
    {
        if(votes[i]>max)
        {
            max = votes[i];
            winner = i;
        }
    }
    printf("\nThe winner of the election is %s with %d votes.\n", party[winner], max);
    return 0;
}