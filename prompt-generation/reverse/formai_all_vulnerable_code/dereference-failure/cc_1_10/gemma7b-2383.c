//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to store voter information
typedef struct Voter
{
    char name[20];
    int vote;
    struct Voter* next;
} Voter;

// Define a function to insert a voter into the list
void insertVoter(Voter** head, char* name, int vote)
{
    Voter* newVoter = (Voter*)malloc(sizeof(Voter));
    strcpy(newVoter->name, name);
    newVoter->vote = vote;
    newVoter->next = NULL;

    if (*head == NULL)
    {
        *head = newVoter;
    }
    else
    {
        (*head)->next = newVoter;
    }
}

// Define a function to vote
void vote(Voter** head, char* name, int vote)
{
    Voter* currentVoter = *head;

    while (currentVoter)
    {
        if (strcmp(currentVoter->name, name) == 0)
        {
            currentVoter->vote = vote;
            break;
        }
        currentVoter = currentVoter->next;
    }

    if (currentVoter == NULL)
    {
        printf("Error: Voter not found.\n");
    }
}

int main()
{
    // Create a linked list of voters
    Voter* head = NULL;

    // Insert some voters
    insertVoter(&head, "Romeo", 1);
    insertVoter(&head, "Juliet", 2);
    insertVoter(&head, "Benvolio", 3);
    insertVoter(&head, "Mercutio", 4);
    insertVoter(&head, "Tybalt", 5);

    // Vote
    vote(&head, "Romeo", 2);
    vote(&head, "Tybalt", 3);

    // Print the voters
    Voter* currentVoter = head;

    while (currentVoter)
    {
        printf("%s: %d\n", currentVoter->name, currentVoter->vote);
        currentVoter = currentVoter->next;
    }

    return 0;
}