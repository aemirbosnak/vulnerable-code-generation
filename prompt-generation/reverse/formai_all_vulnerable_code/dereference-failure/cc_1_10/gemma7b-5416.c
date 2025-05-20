//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate
{
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

Candidate* createCandidate(char* name)
{
    Candidate* candidate = (Candidate*)malloc(sizeof(Candidate));
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
    time_t t = time(NULL);

    // Create candidates
    candidates = createCandidate("John Doe");
    candidates = createCandidate("Jane Doe");
    candidates = createCandidate("Peter Pan");
    candidates = createCandidate("Mary Poppins");
    candidates = createCandidate("The Wizard of Oz");

    // Simulate votes
    addVote(candidates->next);
    addVote(candidates->next->next);
    addVote(candidates->next->next->next);
    addVote(candidates->next->next->next->next);

    // Print results
    printf("Election Results:\n");
    for (Candidate* candidate = candidates; candidate; candidate = candidate->next)
    {
        printf("%s: %d votes\n", candidate->name, candidate->votes);
    }

    // Print time
    printf("Time: %s",ctime(&t));

    return 0;
}