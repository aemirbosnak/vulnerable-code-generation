//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5

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

void vote(Candidate* candidate)
{
    candidate->votes++;
}

int main()
{
    Candidate* head = createCandidate("John Doe");
    head->next = createCandidate("Jane Doe");
    head->next->next = createCandidate("Bill Smith");
    head->next->next->next = createCandidate("Alice White");
    head->next->next->next->next = createCandidate("Bob Green");

    time_t t = time(NULL);

    printf("Please vote for your candidate: ");
    char vote_for_candidate[20];
    scanf("%s", vote_for_candidate);

    for (Candidate* candidate = head; candidate; candidate = candidate->next)
    {
        if (strcmp(candidate->name, vote_for_candidate) == 0)
        {
            vote(candidate);
        }
    }

    printf("Results:");
    for (Candidate* candidate = head; candidate; candidate = candidate->next)
    {
        printf(" %s: %d votes", candidate->name, candidate->votes);
    }

    printf("\nTime taken: %ld seconds", time(NULL) - t);

    return 0;
}