//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vote(char **candidates, int num_candidates, int voter_id)
{
    int i;
    char choice;

    printf("Enter your vote for candidate: ");
    scanf("%c", &choice);

    for (i = 0; i < num_candidates; i++)
    {
        if (candidates[i] == choice)
        {
            candidates[i]++;
            break;
        }
    }

    if (i == num_candidates)
    {
        printf("Invalid vote. Please try again.\n");
        vote(candidates, num_candidates, voter_id);
    }

    return;
}

int main()
{
    char **candidates;
    int num_candidates, voter_id;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    candidates = (char **)malloc(num_candidates * sizeof(char *));
    for (int i = 0; i < num_candidates; i++)
    {
        candidates[i] = (char *)malloc(20 * sizeof(char));
    }

    printf("Enter the voter ID: ");
    scanf("%d", &voter_id);

    vote(candidates, num_candidates, voter_id);

    return 0;
}