//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of voters
#define MAX_VOTERS 1000

// Define the maximum number of votes per voter
#define MAX_VOTES 5

// Define the structure of a voter
typedef struct Voter {
    char name[255];
    int votes[MAX_VOTES];
    int vote_count;
} Voter;

// Function to add a voter to the system
void add_voter(Voter **voters, int *num_voters) {
    *voters = (Voter *)realloc(*voters, (*num_voters + 1) * sizeof(Voter));
    (*num_voters)++;
    (*voters)[*num_voters - 1].vote_count = 0;
}

// Function to cast a vote
void cast_vote(Voter *voters, int num_voters, char vote) {
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].name, vote) == 0) {
            if (voters[i].vote_count < MAX_VOTES) {
                voters[i].votes[voters[i].vote_count] = vote;
                voters[i].vote_count++;
            } else {
                printf("Error: voter has already cast their vote.\n");
            }
        }
    }
}

int main() {
    // Create an array of voters
    Voter *voters = NULL;
    int num_voters = 0;

    // Add some voters to the system
    add_voter(&voters, &num_voters);
    add_voter(&voters, &num_voters);
    add_voter(&voters, &num_voters);

    // Cast some votes
    cast_vote(voters, num_voters, "John");
    cast_vote(voters, num_voters, "Mary");
    cast_vote(voters, num_voters, "Bob");

    // Print the results
    for (int i = 0; i < num_voters; i++) {
        printf("%s has voted %d times:\n", voters[i].name, voters[i].vote_count);
        for (int j = 0; j < voters[i].vote_count; j++) {
            printf("  Vote: %c\n", voters[i].votes[j]);
        }
    }

    return 0;
}