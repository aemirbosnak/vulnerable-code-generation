//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of voters
#define MAX_VOTERS 100

// Define the maximum number of votes for each voter
#define MAX_VOTES 5

// Create a structure to store voter information
typedef struct voter {
    char name[50];
    int votes[MAX_VOTES];
    int vote_status;
} voter;

// Function to add a voter to the system
void add_voter(voter *v) {
    printf("Enter voter name: ");
    scanf("%s", v->name);

    // Initialize the number of votes for each voter
    for (int i = 0; i < MAX_VOTES; i++) {
        v->votes[i] = 0;
    }

    // Set the voter's status to active
    v->vote_status = 1;
}

// Function to cast a vote
void cast_vote(voter *v) {
    int vote_choice;

    // Check if the voter has already voted
    if (v->vote_status == 0) {
        printf("You have not yet voted.\n");
    } else {
        printf("Enter your vote choice (1-5): ");
        scanf("%d", &vote_choice);

        // Validate the vote choice
        if (vote_choice < 1 || vote_choice > 5) {
            printf("Invalid vote choice.\n");
        } else {
            // Record the vote
            v->votes[vote_choice - 1]++;

            // Set the voter's status to have voted
            v->vote_status = 0;

            // Print a confirmation message
            printf("Your vote has been cast.\n");
        }
    }
}

// Function to display the results
void display_results(voter *v) {
    int total_votes = 0;
    int winner = -1;

    // Calculate the total number of votes
    for (int i = 0; i < MAX_VOTERS; i++) {
        total_votes += v[i].votes[0] + v[i].votes[1] + v[i].votes[2] + v[i].votes[3] + v[i].votes[4];
    }

    // Determine the winner
    for (int i = 0; i < MAX_VOTERS; i++) {
        if (v[i].votes[0] + v[i].votes[1] + v[i].votes[2] + v[i].votes[3] + v[i].votes[4] > winner) {
            winner = v[i].votes[0] + v[i].votes[1] + v[i].votes[2] + v[i].votes[3] + v[i].votes[4];
        }
    }

    // Print the results
    printf("Total number of votes: %d\n", total_votes);
    printf("Winner: %s\n", v[winner - 1].name);
}

int main() {
    // Create an array of voters
    voter *v = (voter *)malloc(MAX_VOTERS * sizeof(voter));

    // Add voters to the system
    add_voter(v);
    add_voter(v);
    add_voter(v);

    // Cast votes
    cast_vote(v);
    cast_vote(v);
    cast_vote(v);

    // Display the results
    display_results(v);

    return 0;
}