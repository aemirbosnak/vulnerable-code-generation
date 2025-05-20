//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the structure of a candidate
typedef struct {
  char name[50];
  int votes;
} Candidate;

// Define the structure of a voter
typedef struct {
  int id;
  int voted;
} Voter;

// Define the structure of the election
typedef struct {
  Candidate candidates[MAX_CANDIDATES];
  Voter voters[MAX_VOTERS];
  int num_candidates;
  int num_voters;
} Election;

// Create a new election
Election* create_election() {
  Election* election = malloc(sizeof(Election));
  election->num_candidates = 0;
  election->num_voters = 0;
  return election;
}

// Add a candidate to the election
void add_candidate(Election* election, char* name) {
  strcpy(election->candidates[election->num_candidates].name, name);
  election->candidates[election->num_candidates].votes = 0;
  election->num_candidates++;
}

// Add a voter to the election
void add_voter(Election* election, int id) {
  election->voters[election->num_voters].id = id;
  election->voters[election->num_voters].voted = 0;
  election->num_voters++;
}

// Vote for a candidate
void vote(Election* election, int voter_id, int candidate_id) {
  if (election->voters[voter_id].voted == 0) {
    election->candidates[candidate_id].votes++;
    election->voters[voter_id].voted = 1;
  }
}

// Get the winner of the election
Candidate* get_winner(Election* election) {
  Candidate* winner = NULL;
  int max_votes = 0;
  for (int i = 0; i < election->num_candidates; i++) {
    if (election->candidates[i].votes > max_votes) {
      winner = &election->candidates[i];
      max_votes = election->candidates[i].votes;
    }
  }
  return winner;
}

// Print the results of the election
void print_results(Election* election) {
  printf("Election Results:\n");
  for (int i = 0; i < election->num_candidates; i++) {
    printf("%s: %d votes\n", election->candidates[i].name, election->candidates[i].votes);
  }
  Candidate* winner = get_winner(election);
  printf("Winner: %s\n", winner->name);
}

// Free the memory allocated for the election
void free_election(Election* election) {
  free(election);
}

// Main function
int main() {
  // Create a new election
  Election* election = create_election();

  // Add candidates to the election
  add_candidate(election, "Alice");
  add_candidate(election, "Bob");
  add_candidate(election, "Carol");

  // Add voters to the election
  add_voter(election, 1);
  add_voter(election, 2);
  add_voter(election, 3);

  // Vote for candidates
  vote(election, 1, 0);
  vote(election, 2, 1);
  vote(election, 3, 2);

  // Print the results of the election
  print_results(election);

  // Free the memory allocated for the election
  free_election(election);

  return 0;
}