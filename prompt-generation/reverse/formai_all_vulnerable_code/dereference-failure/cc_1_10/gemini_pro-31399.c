//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the candidate structures
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Define the voter structure
typedef struct {
    char name[50];
    int voted;
} Voter;

// Define the ballot structure
typedef struct {
    Candidate candidates[5];
    int num_candidates;
    Voter voters[100];
    int num_voters;
} Ballot;

// Create a new ballot
Ballot* create_ballot() {
    Ballot* ballot = malloc(sizeof(Ballot));
    ballot->num_candidates = 0;
    ballot->num_voters = 0;
    return ballot;
}

// Add a candidate to the ballot
void add_candidate(Ballot* ballot, Candidate candidate) {
    ballot->candidates[ballot->num_candidates] = candidate;
    ballot->num_candidates++;
}

// Add a voter to the ballot
void add_voter(Ballot* ballot, Voter voter) {
    ballot->voters[ballot->num_voters] = voter;
    ballot->num_voters++;
}

// Cast a vote for a candidate
void cast_vote(Ballot* ballot, char* candidate_name) {
    for (int i = 0; i < ballot->num_candidates; i++) {
        if (strcmp(ballot->candidates[i].name, candidate_name) == 0) {
            ballot->candidates[i].votes++;
            break;
        }
    }
}

// Print the results of the election
void print_results(Ballot* ballot) {
    printf("Election Results:\n");
    for (int i = 0; i < ballot->num_candidates; i++) {
        printf("%s: %d votes\n", ballot->candidates[i].name, ballot->candidates[i].votes);
    }
}

// Main function
int main() {
    // Create a new ballot
    Ballot* ballot = create_ballot();

    // Add candidates to the ballot
    Candidate candidate1 = {"Alice", 0};
    add_candidate(ballot, candidate1);
    Candidate candidate2 = {"Bob", 0};
    add_candidate(ballot, candidate2);
    Candidate candidate3 = {"Charlie", 0};
    add_candidate(ballot, candidate3);

    // Add voters to the ballot
    Voter voter1 = {"John", 0};
    add_voter(ballot, voter1);
    Voter voter2 = {"Mary", 0};
    add_voter(ballot, voter2);
    Voter voter3 = {"Bob", 0};
    add_voter(ballot, voter3);

    // Cast votes
    cast_vote(ballot, "Alice");
    cast_vote(ballot, "Bob");
    cast_vote(ballot, "Charlie");

    // Print the results of the election
    print_results(ballot);

    return 0;
}