//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: interoperable
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

void vote(Candidate *candidates, int candidateIndex)
{
    candidates[candidateIndex].votes++;
}

int main()
{
    Candidate candidates[MAX_CANDIDATES] = {
        {"John Doe", 0},
        {"Jane Doe", 0},
        {"Bill Smith", 0},
        {"Alice White", 0},
        {"Tom Brown", 0}
    };

    int votes[MAX_VOTES] = {0};

    // Voting process
    for (int i = 0; i < MAX_VOTES; i++)
    {
        printf("Enter candidate's index: ");
        int candidateIndex = atoi(stdin);

        if (candidateIndex >= 0 && candidateIndex < MAX_CANDIDATES)
        {
            vote(candidates, candidateIndex);
            votes[candidateIndex]++;
        }
    }

    // Results
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s received %d votes\n", candidates[i].name, votes[i]);
    }

    return 0;
}