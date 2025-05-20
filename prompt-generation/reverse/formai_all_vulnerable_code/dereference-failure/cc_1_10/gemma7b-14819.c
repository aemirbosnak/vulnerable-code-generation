//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store voter information
typedef struct Voter
{
    char name[50];
    int vote;
    struct Voter* next;
} Voter;

// Function to insert a voter into the linked list
void insertVoter(Voter** head, char* name, int vote)
{
    Voter* newNode = (Voter*)malloc(sizeof(Voter));
    strcpy(newNode->name, name);
    newNode->vote = vote;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

// Function to vote for a candidate
void voteCandidate(Voter* head, char* candidate)
{
    while (head)
    {
        if (strcmp(head->name, candidate) == 0)
        {
            head->vote++;
            break;
        }
        head = head->next;
    }
}

// Function to display the results of the election
void displayResults(Voter* head)
{
    int totalVotes = 0;
    printf("Election Results:\n");
    while (head)
    {
        printf("%s: %d votes\n", head->name, head->vote);
        totalVotes++;
        head = head->next;
    }
    printf("Total Votes: %d\n", totalVotes);
}

int main()
{
    // Create a linked list of voters
    Voter* head = NULL;

    // Insert voters into the list
    insertVoter(&head, "John Doe", 1);
    insertVoter(&head, "Jane Doe", 2);
    insertVoter(&head, "Bill Smith", 3);

    // Vote for a candidate
    voteCandidate(head, "John Doe");
    voteCandidate(head, "Jane Doe");

    // Display the results of the election
    displayResults(head);

    return 0;
}