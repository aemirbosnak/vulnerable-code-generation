//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
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
  char name[50];
  int has_voted;
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
  if (election->num_candidates < MAX_CANDIDATES) {
    strcpy(election->candidates[election->num_candidates].name, name);
    election->candidates[election->num_candidates].votes = 0;
    election->num_candidates++;
  }
}

// Add a voter to the election
void add_voter(Election* election, char* name) {
  if (election->num_voters < MAX_VOTERS) {
    strcpy(election->voters[election->num_voters].name, name);
    election->voters[election->num_voters].has_voted = 0;
    election->num_voters++;
  }
}

// Vote for a candidate
void vote(Election* election, char* voter_name, char* candidate_name) {
  for (int i = 0; i < election->num_candidates; i++) {
    if (strcmp(election->candidates[i].name, candidate_name) == 0) {
      for (int j = 0; j < election->num_voters; j++) {
        if (strcmp(election->voters[j].name, voter_name) == 0) {
          if (!election->voters[j].has_voted) {
            election->candidates[i].votes++;
            election->voters[j].has_voted = 1;
          }
        }
      }
    }
  }
}

// Get the winner of the election
char* get_winner(Election* election) {
  char* winner = NULL;
  int max_votes = 0;
  for (int i = 0; i < election->num_candidates; i++) {
    if (election->candidates[i].votes > max_votes) {
      max_votes = election->candidates[i].votes;
      winner = election->candidates[i].name;
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
  printf("Winner: %s\n", get_winner(election));
}

// Main function
int main() {
  // Create a new election
  Election* election = create_election();

  // Add candidates to the election
  add_candidate(election, "John Smith");
  add_candidate(election, "Jane Doe");
  add_candidate(election, "Bob Jones");

  // Add voters to the election
  add_voter(election, "Alice");
  add_voter(election, "Bob");
  add_voter(election, "Carol");

  // Vote for a candidate
  vote(election, "Alice", "John Smith");
  vote(election, "Bob", "Jane Doe");
  vote(election, "Carol", "Bob Jones");

  // Print the results of the election
  print_results(election);

  return 0;
}