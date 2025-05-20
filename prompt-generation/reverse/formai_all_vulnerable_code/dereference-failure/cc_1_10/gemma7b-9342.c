//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store voter information
typedef struct voter {
    char name[50];
    int vote;
    struct voter* next;
} voter;

// Function to insert a voter into the linked list
void insertVoter(voter** head, char* name, int vote) {
    voter* newNode = (voter*)malloc(sizeof(voter));
    strcpy(newNode->name, name);
    newNode->vote = vote;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to vote for a candidate
void vote(voter* head, int candidate) {
    while (head) {
        if (strcmp(head->name, "John Doe") == 0) {
            head->vote = candidate;
            break;
        }
        head = head->next;
    }
}

// Function to tally votes
int tallyVotes(voter* head) {
    int totalVotes = 0;
    while (head) {
        totalVotes += head->vote;
        head = head->next;
    }
    return totalVotes;
}

// Main function
int main() {
    // Create a linked list of voters
    voter* head = NULL;

    // Insert some voters
    insertVoter(&head, "John Doe", 1);
    insertVoter(&head, "Jane Doe", 2);
    insertVoter(&head, "Bill Smith", 3);

    // Vote for a candidate
    vote(head, 2);

    // Tally votes
    int totalVotes = tallyVotes(head);

    // Print the total votes
    printf("Total votes: %d", totalVotes);

    return 0;
}