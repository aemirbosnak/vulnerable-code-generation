//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of voters
#define MAX_VOTERS 100

// Define the structure of a voter
typedef struct voter {
    char name[50];
    int vote;
    struct voter* next;
} voter;

// Function to create a new voter
voter* create_voter() {
    voter* new_voter = (voter*)malloc(sizeof(voter));
    new_voter->vote = 0;
    new_voter->next = NULL;
    return new_voter;
}

// Function to add a voter to the list
void add_voter(voter* head, char* name) {
    voter* new_voter = create_voter();
    strcpy(new_voter->name, name);
    if (head == NULL) {
        head = new_voter;
    } else {
        head->next = new_voter;
        head = new_voter;
    }
}

// Function to vote
void vote(voter* head, int choice) {
    while (head) {
        if (strcmp(head->name, "John Doe") == 0) {
            head->vote = choice;
            break;
        }
        head = head->next;
    }
}

// Function to display the results
void display_results(voter* head) {
    int total_votes = 0;
    for (voter* current_voter = head; current_voter; current_voter = current_voter->next) {
        total_votes++;
        printf("%s voted for %d\n", current_voter->name, current_voter->vote);
    }
    printf("Total number of votes: %d\n", total_votes);
}

int main() {
    // Create a list of voters
    voter* head = NULL;

    // Add some voters to the list
    add_voter(head, "John Doe");
    add_voter(head, "Jane Doe");
    add_voter(head, "Bill Smith");

    // Vote
    vote(head, 2);

    // Display the results
    display_results(head);

    return 0;
}