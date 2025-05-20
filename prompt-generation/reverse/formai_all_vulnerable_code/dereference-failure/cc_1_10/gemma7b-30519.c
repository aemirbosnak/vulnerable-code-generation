//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
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

void printCandidates(Candidate* head)
{
    while (head)
    {
        printf("%s: %d votes\n", head->name, head->votes);
        head = head->next;
    }
}

int main()
{
    Candidate* head = createCandidate("Alice");
    addVote(head);
    addVote(head);
    addVote(head);
    addVote(createCandidate("Bob"));
    addVote(createCandidate("Charlie"));

    printCandidates(head);

    return 0;
}