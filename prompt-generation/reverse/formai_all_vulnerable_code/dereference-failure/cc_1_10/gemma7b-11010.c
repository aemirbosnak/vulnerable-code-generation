//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
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

void vote(Candidate* head)
{
    char vote_for[20];
    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", vote_for);

    Candidate* current = head;
    while (current)
    {
        if (strcmp(vote_for, current->name) == 0)
        {
            current->votes++;
            printf("Your vote has been cast for %s.\n", current->name);
            break;
        }
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Error: candidate not found.\n");
    }
}

int main()
{
    time_t t = time(NULL);
    srand(t);

    Candidate* head = NULL;
    Candidate* tail = NULL;

    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        Candidate* new_candidate = (Candidate*)malloc(sizeof(Candidate));
        new_candidate->name[0] = 'A' + i;
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

    vote(head);

    return 0;
}