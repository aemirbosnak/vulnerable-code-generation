//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10

typedef struct Candidate
{
    char name[50];
    int votes;
    struct Candidate* next;
} Candidate;

void vote(Candidate** head, char* candidate_name)
{
    Candidate* new_candidate = malloc(sizeof(Candidate));
    strcpy(new_candidate->name, candidate_name);
    new_candidate->votes = 0;
    new_candidate->next = NULL;

    if (*head == NULL)
    {
        *head = new_candidate;
    }
    else
    {
        (*head)->next = new_candidate;
    }

    (*head)->votes++;
}

int main()
{
    Candidate* head = NULL;

    // Register candidates
    vote(&head, "John Doe");
    vote(&head, "Jane Doe");
    vote(&head, "Bob Smith");

    // Vote for a candidate
    vote(&head, "John Doe");

    // Print candidates and their votes
    Candidate* current = head;
    while (current)
    {
        printf("%s: %d votes\n", current->name, current->votes);
        current = current->next;
    }

    return 0;
}