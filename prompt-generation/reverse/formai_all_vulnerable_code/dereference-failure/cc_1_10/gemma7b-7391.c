//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of voters
int num_voters = 100;

// Define the structure of a voter
typedef struct voter {
    char name[20];
    int vote_count;
    struct voter* next;
} voter;

// Create a linked list of voters
voter* create_voter_list() {
    voter* head = NULL;
    for (int i = 0; i < num_voters; i++) {
        voter* new_voter = (voter*)malloc(sizeof(voter));
        strcpy(new_voter->name, "Voter");
        new_voter->vote_count = 0;
        new_voter->next = head;
        head = new_voter;
    }
    return head;
}

// Function to add a vote to a voter
void add_vote(voter* voter, int vote_choice) {
    voter->vote_count++;
    switch (vote_choice) {
        case 1:
            printf("You have voted for candidate A.\n");
            break;
        case 2:
            printf("You have voted for candidate B.\n");
            break;
        case 3:
            printf("You have voted for candidate C.\n");
            break;
    }
}

// Function to display the results of the election
void display_results(voter* head) {
    int total_votes = 0;
    printf("Election Results:\n");
    for (voter* voter = head; voter; voter = voter->next) {
        printf("%s has received %d votes.\n", voter->name, voter->vote_count);
        total_votes += voter->vote_count;
    }
    printf("Total Votes: %d\n", total_votes);
}

int main() {
    voter* head = create_voter_list();
    add_vote(head, 2);
    add_vote(head, 1);
    add_vote(head, 3);
    add_vote(head, 2);
    display_results(head);

    return 0;
}