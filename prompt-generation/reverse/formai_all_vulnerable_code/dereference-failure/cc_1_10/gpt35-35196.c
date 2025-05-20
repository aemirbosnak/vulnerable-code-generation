//FormAI DATASET v1.0 Category: Log analysis ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rounds, num_players;

    printf("Welcome to the Log Analyzer!\n\n");
    printf("How many rounds would you like to play?: ");
    scanf("%d", &rounds);

    printf("\nHow many players will be playing?: ");
    scanf("%d", &num_players);

    // Dynamically allocate 2D array to hold log data
    int **logs = (int **)malloc(num_players * sizeof(int *));
    for(int i = 0; i < num_players; i++)
        logs[i] = (int *)malloc(rounds * sizeof(int));

    // Ask for log data for each player for each round
    int player_num, round_num, log_val;
    for(int i = 0; i < rounds; i++)
    {
        printf("\nRound %d:\n", i+1);
        for(int j = 0; j < num_players; j++)
        {
            printf("Player %d enter log value: ", j+1);
            scanf("%d", &log_val);
            logs[j][i] = log_val;
        }
    }

    // Analyze log data and print results
    int sum = 0, max_val = 0, max_player = 0;
    for(int j = 0; j < num_players; j++)
    {
        sum = 0;
        for(int i = 0; i < rounds; i++)
        {
            sum += logs[j][i];
            if(logs[j][i] > max_val)
            {
                max_val = logs[j][i];
                max_player = j+1;
            }
        }
        printf("\nPlayer %d average log value: %.2f", j+1, (float)sum/rounds);
    }

    printf("\n\nThe player with the highest log value was Player %d with a value of %d.\n", max_player, max_val);

    // Free dynamically allocated memory
    for(int i = 0; i < num_players; i++)
        free(logs[i]);
    free(logs);

    return 0;
}