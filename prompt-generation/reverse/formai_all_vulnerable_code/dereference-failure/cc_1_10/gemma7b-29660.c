//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of voters
#define MAX_VOTERS 100

// Define the structure of a voter
typedef struct voter {
    char name[50];
    int vote;
    struct voter* next;
} voter;

// Function to insert a voter into the list
void insert_voter(voter** head, char* name, int vote) {
    voter* new_voter = malloc(sizeof(voter));
    strcpy(new_voter->name, name);
    new_voter->vote = vote;
    new_voter->next = NULL;

    if (*head == NULL) {
        *head = new_voter;
    } else {
        (*head)->next = new_voter;
    }
}

// Function to vote
void vote(voter* head, char* name, int vote) {
    voter* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            current->vote = vote;
            break;
        }
        current = current->next;
    }
}

// Function to print the results
void print_results(voter* head) {
    int total_votes = 0;
    for (voter* current = head; current; current = current->next) {
        total_votes++;
        printf("%s voted for %d\n", current->name, current->vote);
    }
    printf("Total votes: %d\n", total_votes);
}

int main() {
    // Create a list of voters
    voter* head = NULL;

    // Insert some voters
    insert_voter(&head, "John Doe", 1);
    insert_voter(&head, "Jane Doe", 2);
    insert_voter(&head, "Bill Smith", 3);

    // Vote
    vote(head, "Jane Doe", 4);

    // Print the results
    print_results(head);

    return 0;
}