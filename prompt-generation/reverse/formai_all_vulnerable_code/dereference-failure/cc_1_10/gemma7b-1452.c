//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/sha.h>

#define MAX_CANDIDATES 10

typedef struct Candidate
{
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

Candidate* createCandidate(char* name)
{
    Candidate* candidate = malloc(sizeof(Candidate));
    strcpy(candidate->name, name);
    candidate->votes = 0;
    candidate->next = NULL;
    return candidate;
}

void addVote(Candidate* candidate)
{
    candidate->votes++;
}

int main()
{
    Candidate* candidates = NULL;
    candidates = createCandidate("John Doe");
    candidates = createCandidate("Jane Doe");
    candidates = createCandidate("Peter Pan");

    char vote = 'a';
    while (vote != 'q')
    {
        printf("Enter vote (a-z, q): ");
        scanf("%c", &vote);

        switch (vote)
        {
            case 'a':
                addVote(candidates->next);
                break;
            case 'b':
                addVote(candidates);
                break;
            case 'c':
                addVote(candidates->next->next);
                break;
            case 'q':
                break;
            default:
                printf("Invalid vote.\n");
                break;
        }
    }

    printf("Results:");
    for (Candidate* candidate = candidates; candidate; candidate = candidate->next)
    {
        printf(" %s: %d votes\n", candidate->name, candidate->votes);
    }

    return 0;
}