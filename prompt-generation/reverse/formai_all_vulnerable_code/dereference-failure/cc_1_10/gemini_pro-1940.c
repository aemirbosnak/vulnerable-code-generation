//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the structure of a candidate
typedef struct {
  int id;
  char name[100];
  int votes;
} Candidate;

// Define the structure of a voter
typedef struct {
  int id;
  char name[100];
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
Election *new_election() {
  Election *election = malloc(sizeof(Election));
  election->num_candidates = 0;
  election->num_voters = 0;
  return election;
}

// Add a candidate to the election
void add_candidate(Election *election, Candidate candidate) {
  if (election->num_candidates < MAX_CANDIDATES) {
    election->candidates[election->num_candidates] = candidate;
    election->num_candidates++;
  }
}

// Add a voter to the election
void add_voter(Election *election, Voter voter) {
  if (election->num_voters < MAX_VOTERS) {
    election->voters[election->num_voters] = voter;
    election->num_voters++;
  }
}

// Vote for a candidate
void vote(Election *election, int voter_id, int candidate_id) {
  for (int i = 0; i < election->num_candidates; i++) {
    if (election->candidates[i].id == candidate_id) {
      election->candidates[i].votes++;
    }
  }
  for (int i = 0; i < election->num_voters; i++) {
    if (election->voters[i].id == voter_id) {
      election->voters[i].voted = 1;
    }
  }
}

// Get the winner of the election
Candidate *get_winner(Election *election) {
  Candidate *winner = NULL;
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
void print_results(Election *election) {
  printf("Election Results:\n");
  for (int i = 0; i < election->num_candidates; i++) {
    printf("%s: %d votes\n", election->candidates[i].name, election->candidates[i].votes);
  }
  printf("Winner: %s\n", get_winner(election)->name);
}

// Free the memory allocated for the election
void free_election(Election *election) {
  free(election);
}

// Main function
int main() {
  // Create a new election
  Election *election = new_election();

  // Add candidates to the election
  Candidate candidate1 = {1, "Candidate 1"};
  add_candidate(election, candidate1);
  Candidate candidate2 = {2, "Candidate 2"};
  add_candidate(election, candidate2);
  Candidate candidate3 = {3, "Candidate 3"};
  add_candidate(election, candidate3);

  // Add voters to the election
  Voter voter1 = {1, "Voter 1", 0};
  add_voter(election, voter1);
  Voter voter2 = {2, "Voter 2", 0};
  add_voter(election, voter2);
  Voter voter3 = {3, "Voter 3", 0};
  add_voter(election, voter3);

  // Vote for candidates
  vote(election, 1, 1);
  vote(election, 2, 2);
  vote(election, 3, 3);

  // Print the results of the election
  print_results(election);

  // Free the memory allocated for the election
  free_election(election);

  return 0;
}