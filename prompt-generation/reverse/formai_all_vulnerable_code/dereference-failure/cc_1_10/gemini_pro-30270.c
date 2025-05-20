//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Linus Torvalds
// Linus Torvalds-style C Electronic Voting System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the candidate structure
typedef struct candidate {
  char name[50];
  int votes;
} candidate_t;

// Define the voter structure
typedef struct voter {
  char name[50];
  int voted;
  int candidate_id;
} voter_t;

// Define the voting system structure
typedef struct voting_system {
  candidate_t candidates[MAX_CANDIDATES];
  voter_t voters[MAX_VOTERS];
  int num_candidates;
  int num_voters;
} voting_system_t;

// Create a new voting system
voting_system_t *voting_system_new() {
  voting_system_t *vs = malloc(sizeof(voting_system_t));
  vs->num_candidates = 0;
  vs->num_voters = 0;
  return vs;
}

// Destroy a voting system
void voting_system_destroy(voting_system_t *vs) {
  free(vs);
}

// Add a candidate to the voting system
void voting_system_add_candidate(voting_system_t *vs, char *name) {
  if (vs->num_candidates < MAX_CANDIDATES) {
    strcpy(vs->candidates[vs->num_candidates].name, name);
    vs->candidates[vs->num_candidates].votes = 0;
    vs->num_candidates++;
  }
}

// Add a voter to the voting system
void voting_system_add_voter(voting_system_t *vs, char *name) {
  if (vs->num_voters < MAX_VOTERS) {
    strcpy(vs->voters[vs->num_voters].name, name);
    vs->voters[vs->num_voters].voted = 0;
    vs->voters[vs->num_voters].candidate_id = -1;
    vs->num_voters++;
  }
}

// Vote for a candidate
void voting_system_vote(voting_system_t *vs, int voter_id, int candidate_id) {
  if (voter_id < vs->num_voters && candidate_id < vs->num_candidates && !vs->voters[voter_id].voted) {
    vs->voters[voter_id].voted = 1;
    vs->voters[voter_id].candidate_id = candidate_id;
    vs->candidates[candidate_id].votes++;
  }
}

// Get the winner of the election
candidate_t *voting_system_get_winner(voting_system_t *vs) {
  int max_votes = 0;
  candidate_t *winner = NULL;
  for (int i = 0; i < vs->num_candidates; i++) {
    if (vs->candidates[i].votes > max_votes) {
      max_votes = vs->candidates[i].votes;
      winner = &vs->candidates[i];
    }
  }
  return winner;
}

// Print the results of the election
void voting_system_print_results(voting_system_t *vs) {
  printf("Election Results:\n");
  for (int i = 0; i < vs->num_candidates; i++) {
    printf("%s: %d votes\n", vs->candidates[i].name, vs->candidates[i].votes);
  }
  candidate_t *winner = voting_system_get_winner(vs);
  printf("Winner: %s\n", winner->name);
}

// Main function
int main() {
  // Create a new voting system
  voting_system_t *vs = voting_system_new();

  // Add candidates to the voting system
  voting_system_add_candidate(vs, "Linus Torvalds");
  voting_system_add_candidate(vs, "Donald Trump");
  voting_system_add_candidate(vs, "Vladimir Putin");

  // Add voters to the voting system
  voting_system_add_voter(vs, "Alice");
  voting_system_add_voter(vs, "Bob");
  voting_system_add_voter(vs, "Carol");

  // Vote for candidates
  voting_system_vote(vs, 0, 0);
  voting_system_vote(vs, 1, 1);
  voting_system_vote(vs, 2, 2);

  // Print the results of the election
  voting_system_print_results(vs);

  // Destroy the voting system
  voting_system_destroy(vs);

  return 0;
}