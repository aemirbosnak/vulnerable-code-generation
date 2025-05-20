//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct Candidate
{
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

void vote(Candidate** head)
{
    char vote_choice;
    printf("Enter your vote for: ");
    scanf(" %c", &vote_choice);

    switch (vote_choice)
    {
        case 'a':
            (*head)->votes++;
            break;
        case 'b':
            ((*head)->next)->votes++;
            break;
        case 'c':
            ((*head)->next->next)->votes++;
            break;
        case 'd':
            ((*head)->next->next->next)->votes++;
            break;
        default:
            printf("Invalid vote.\n");
    }
}

int main()
{
    Candidate* head = NULL;
    Candidate* tail = NULL;

    // Create a list of candidates
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        Candidate* new_candidate = (Candidate*)malloc(sizeof(Candidate));
        new_candidate->name[0] = 'a' + i;
        new_candidate->votes = 0;
        new_candidate->next = NULL;

        if (head == NULL)
        {
            head = new_candidate;
            tail = new_candidate;
        }
        else
        {
            tail->next = new_candidate;
            tail = new_candidate;
        }
    }

    // Vote for a candidate
    vote(&head);

    // Print the results
    printf("Results:\n");
    for (Candidate* candidate = head; candidate; candidate = candidate->next)
    {
        printf("%s: %d votes\n", candidate->name, candidate->votes);
    }

    return 0;
}