//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the number of voters
#define NUM_VOTERS 100

// Define the list of voters
struct voter {
    char name[50];
    int vote;
    struct voter* next;
};

// Define the ballot box
struct ballot_box {
    struct voter* head;
    int total_votes;
    struct ballot_box* next;
};

// Create a new voter
struct voter* create_voter(char* name, int vote) {
    struct voter* new_voter = (struct voter*)malloc(sizeof(struct voter));
    strcpy(new_voter->name, name);
    new_voter->vote = vote;
    new_voter->next = NULL;
    return new_voter;
}

// Create a new ballot box
struct ballot_box* create_ballot_box() {
    struct ballot_box* new_ballot_box = (struct ballot_box*)malloc(sizeof(struct ballot_box));
    new_ballot_box->head = NULL;
    new_ballot_box->total_votes = 0;
    new_ballot_box->next = NULL;
    return new_ballot_box;
}

// Add a voter to the ballot box
void add_voter(struct ballot_box* ballot_box, struct voter* new_voter) {
    if (ballot_box->head == NULL) {
        ballot_box->head = new_voter;
    } else {
        ballot_box->head->next = new_voter;
        ballot_box->head = new_voter;
    }
    ballot_box->total_votes++;
}

// Vote for a candidate
void vote(struct ballot_box* ballot_box, char* candidate) {
    struct voter* current_voter = ballot_box->head;
    while (current_voter) {
        if (strcmp(current_voter->name, candidate) == 0) {
            current_voter->vote++;
            break;
        }
        current_voter = current_voter->next;
    }
}

// Print the results of the election
void print_results(struct ballot_box* ballot_box) {
    int total_votes = ballot_box->total_votes;
    printf("Total votes: %d\n", total_votes);
    struct voter* current_voter = ballot_box->head;
    while (current_voter) {
        printf("%s: %d votes\n", current_voter->name, current_voter->vote);
    }
}

int main() {
    // Create a list of voters
    struct voter* voters = create_voter("John Doe", 1);
    add_voter(voters, create_voter("Jane Doe", 2));
    add_voter(voters, create_voter("Peter Pan", 3));

    // Create a ballot box
    struct ballot_box* ballot_box = create_ballot_box();

    // Add voters to the ballot box
    add_voter(ballot_box, voters);

    // Vote for a candidate
    vote(ballot_box, "Jane Doe");
    vote(ballot_box, "Peter Pan");

    // Print the results of the election
    print_results(ballot_box);

    return 0;
}