//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
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

void vote(Candidate* candidate)
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
    Candidate* head = NULL;
    Candidate* tail = NULL;

    // Create candidates
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        Candidate* newCandidate = (Candidate*)malloc(sizeof(Candidate));
        strcpy(newCandidate->name, "Candidate " + i);
        newCandidate->votes = 0;
        newCandidate->next = NULL;

        if (head == NULL)
        {
            head = newCandidate;
            tail = newCandidate;
        }
        else
        {
            tail->next = newCandidate;
            tail = newCandidate;
        }
    }

    // Simulate votes
    vote(head);
    vote(head->next);
    vote(tail);

    // Print candidates
    printCandidates(head);

    return 0;
}