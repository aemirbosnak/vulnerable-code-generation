//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5

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
        if (strcmp(candidates[i].name, candidate) == 0)
        {
            candidates[i].votes++;
            break;
        }
    }
}

int main()
{
    int i, num_votes;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Get the number of votes
    printf("Enter the number of votes: ");
    scanf("%d", &num_votes);

    // Cast votes
    for (i = 0; i < num_votes; i++)
    {
        char candidate;

        printf("Enter the candidate's name: ");
        scanf("%s", candidate);

        vote(candidate);
    }

    // Print the results
    printf("The results are:\n");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s has %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}