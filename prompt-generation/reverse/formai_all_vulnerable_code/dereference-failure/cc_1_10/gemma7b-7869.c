//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: complete
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
    Candidate* current = head;
    while (current)
    {
        printf("%s: %d votes\n", current->name, current->votes);
        current = current->next;
    }
}

int main()
{
    time_t t = time(NULL);
    srand(t);

    // Create a list of candidates
    Candidate* head = createCandidate("John Doe");
    head->next = createCandidate("Jane Doe");
    head->next->next = createCandidate("Bob Smith");
    head->next->next->next = createCandidate("Alice White");

    // Simulate voting
    for (int i = 0; i < MAX_VOTES; i++)
    {
        addVote(head->next);
        addVote(head);
    }

    // Print the candidates
    printCandidates(head);

    return 0;
}