//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(char candidate)
{
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        if (candidates[i].name[0] == candidate)
        {
            candidates[i].votes++;
        }
    }
}

int main()
{
    // Initialize candidates
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Get candidate names
    printf("Enter candidate names, separated by commas: ");
    char input[200];
    scanf("%s", input);

    // Parse candidate names and vote
    char* token = strtok(input, ",");
    while (token)
    {
        vote(token[0]);
        token = strtok(NULL, ",");
    }

    // Print results
    printf("Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        if (candidates[i].name[0] != '\0')
        {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }
    }

    // Find winner
    int winner = -1;
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        if (candidates[i].votes > winner)
        {
            winner = i;
        }
    }

    // Announce winner
    if (winner != -1)
    {
        printf("Winner: %s\n", candidates[winner].name);
    }
    else
    {
        printf("No winner\n");
    }

    return 0;
}