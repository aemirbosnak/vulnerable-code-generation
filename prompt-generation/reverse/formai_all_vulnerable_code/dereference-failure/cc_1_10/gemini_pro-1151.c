//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the data structure for a candidate
typedef struct candidate {
    char name[50];
    int votes;
} candidate_t;

// Define the data structure for a voter
typedef struct voter {
    char name[50];
    int has_voted;
} voter_t;

// Define the data structure for the election
typedef struct election {
    candidate_t candidates[MAX_CANDIDATES];
    voter_t voters[MAX_VOTERS];
    int num_candidates;
    int num_voters;
} election_t;

// Create a new election
election_t* create_election() {
    election_t* election = malloc(sizeof(election_t));
    election->num_candidates = 0;
    election->num_voters = 0;
    return election;
}

// Add a candidate to the election
void add_candidate(election_t* election, char* name) {
    if (election->num_candidates < MAX_CANDIDATES) {
        strcpy(election->candidates[election->num_candidates].name, name);
        election->candidates[election->num_candidates].votes = 0;
        election->num_candidates++;
    } else {
        printf("Error: Maximum number of candidates reached.\n");
    }
}

// Add a voter to the election
void add_voter(election_t* election, char* name) {
    if (election->num_voters < MAX_VOTERS) {
        strcpy(election->voters[election->num_voters].name, name);
        election->voters[election->num_voters].has_voted = 0;
        election->num_voters++;
    } else {
        printf("Error: Maximum number of voters reached.\n");
    }
}

// Print the candidates and their votes
void print_candidates(election_t* election) {
    for (int i = 0; i < election->num_candidates; i++) {
        printf("%s: %d votes\n", election->candidates[i].name, election->candidates[i].votes);
    }
}

// Print the voters and their voting status
void print_voters(election_t* election) {
    for (int i = 0; i < election->num_voters; i++) {
        printf("%s: %s\n", election->voters[i].name, election->voters[i].has_voted ? "Voted" : "Not voted");
    }
}

// Vote for a candidate
void vote(election_t* election, char* voter_name, char* candidate_name) {
    // Find the voter
    int voter_index = -1;
    for (int i = 0; i < election->num_voters; i++) {
        if (strcmp(election->voters[i].name, voter_name) == 0) {
            voter_index = i;
            break;
        }
    }

    // Find the candidate
    int candidate_index = -1;
    for (int i = 0; i < election->num_candidates; i++) {
        if (strcmp(election->candidates[i].name, candidate_name) == 0) {
            candidate_index = i;
            break;
        }
    }

    // Check if the voter has already voted
    if (voter_index != -1 && candidate_index != -1 && !election->voters[voter_index].has_voted) {
        // Increment the candidate's vote count
        election->candidates[candidate_index].votes++;

        // Mark the voter as having voted
        election->voters[voter_index].has_voted = 1;
    } else {
        printf("Error: Invalid vote.\n");
    }
}

// Find the winner of the election
char* find_winner(election_t* election) {
    // Find the candidate with the most votes
    int max_votes = 0;
    char* winner_name = NULL;
    for (int i = 0; i < election->num_candidates; i++) {
        if (election->candidates[i].votes > max_votes) {
            max_votes = election->candidates[i].votes;
            winner_name = election->candidates[i].name;
        }
    }

    return winner_name;
}

// Main function
int main() {
    // Create a new election
    election_t* election = create_election();

    // Add some candidates
    add_candidate(election, "John Doe");
    add_candidate(election, "Jane Doe");
    add_candidate(election, "Bob Smith");

    // Add some voters
    add_voter(election, "Alice");
    add_voter(election, "Bob");
    add_voter(election, "Carol");

    // Print the candidates and their votes
    printf("Candidates:\n");
    print_candidates(election);

    // Print the voters and their voting status
    printf("\nVoters:\n");
    print_voters(election);

    // Vote for some candidates
    vote(election, "Alice", "John Doe");
    vote(election, "Bob", "Jane Doe");
    vote(election, "Carol", "Bob Smith");

    // Print the candidates and their votes
    printf("\nCandidates:\n");
    print_candidates(election);

    // Find the winner of the election
    char* winner_name = find_winner(election);

    // Print the winner
    printf("\nWinner: %s\n", winner_name);

    return 0;
}