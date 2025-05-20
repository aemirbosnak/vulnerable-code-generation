//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate
{
    char name[20];
    int votes;
    struct Candidate* next;
};

typedef struct Candidate Candidate;

Candidate* createCandidate(char* name)
{
    Candidate* newCandidate = (Candidate*)malloc(sizeof(Candidate));
    strcpy(newCandidate->name, name);
    newCandidate->votes = 0;
    newCandidate->next = NULL;
    return newCandidate;
}

void addVote(Candidate* candidate)
{
    candidate->votes++;
}

void printCandidates(Candidate* head)
{
    Candidate* current = head;
    while (current)
    {
        printf("%s: %d votes\n", current->name, current->votes);
        current = current->next;
    }
}

int main()
{
    Candidate* head = createCandidate("John Doe");
    addVote(head);
    addVote(head);
    addVote(head);
    addVote(head);

    Candidate* second = createCandidate("Jane Doe");
    addVote(second);
    addVote(second);

    printCandidates(head);

    return 0;
}