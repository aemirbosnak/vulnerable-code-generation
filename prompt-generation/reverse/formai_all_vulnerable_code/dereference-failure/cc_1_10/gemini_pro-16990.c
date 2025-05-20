//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the candidate struct
typedef struct candidate {
    char name[50];
    int votes;
} candidate_t;

// Define the voter struct
typedef struct voter {
    char name[50];
    int voted;
} voter_t;

// Define the election struct
typedef struct election {
    candidate_t candidates[MAX_CANDIDATES];
    voter_t voters[MAX_VOTERS];
    int num_candidates;
    int num_voters;
} election_t;

// Function to create a new election
election_t* create_election() {
    election_t* election = malloc(sizeof(election_t));
    election->num_candidates = 0;
    election->num_voters = 0;
    return election;
}

// Function to add a candidate to an election
void add_candidate(election_t* election, char* name) {
    strcpy(election->candidates[election->num_candidates].name, name);
    election->candidates[election->num_candidates].votes = 0;
    election->num_candidates++;
}

// Function to add a voter to an election
void add_voter(election_t* election, char* name) {
    strcpy(election->voters[election->num_voters].name, name);
    election->voters[election->num_voters].voted = 0;
    election->num_voters++;
}

// Function to vote for a candidate in an election
void vote(election_t* election, char* voter_name, char* candidate_name) {
    for (int i = 0; i < election->num_candidates; i++) {
        if (strcmp(election->candidates[i].name, candidate_name) == 0) {
            election->candidates[i].votes++;
            for (int j = 0; j < election->num_voters; j++) {
                if (strcmp(election->voters[j].name, voter_name) == 0) {
                    election->voters[j].voted = 1;
                    break;
                }
            }
            break;
        }
    }
}

// Function to get the winner of an election
char* get_winner(election_t* election) {
    int max_votes = 0;
    char* winner = NULL;
    for (int i = 0; i < election->num_candidates; i++) {
        if (election->candidates[i].votes > max_votes) {
            max_votes = election->candidates[i].votes;
            winner = election->candidates[i].name;
        }
    }
    return winner;
}

// Function to print the results of an election
void print_results(election_t* election) {
    printf("Election Results:\n");
    for (int i = 0; i < election->num_candidates; i++) {
        printf("%s: %d votes\n", election->candidates[i].name, election->candidates[i].votes);
    }
    printf("Winner: %s\n", get_winner(election));
}

// Main function
int main() {
    // Create a new election
    election_t* election = create_election();

    // Add candidates to the election
    add_candidate(election, "Candidate 1");
    add_candidate(election, "Candidate 2");
    add_candidate(election, "Candidate 3");

    // Add voters to the election
    add_voter(election, "Voter 1");
    add_voter(election, "Voter 2");
    add_voter(election, "Voter 3");

    // Vote for candidates in the election
 
    srand(time(NULL));
    for (int i = 0; i < election->num_voters; i++) {
        //If the voter already voted skip the vote activity
        if(!election->voters[i].voted){
            vote(election, election->voters[i].name, election->candidates[rand() % election->num_candidates].name);
        }
    }

    // Print the results of the election
    print_results(election);

    // Free the memory allocated for the election
    free(election);

    return 0;
}