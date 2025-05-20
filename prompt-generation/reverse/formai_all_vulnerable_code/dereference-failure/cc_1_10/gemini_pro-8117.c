//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates
#define MAX_CANDIDATES 10

// Define the maximum length of a candidate's name
#define MAX_NAME_LENGTH 50

// Define the structure of a candidate
typedef struct {
  char name[MAX_NAME_LENGTH];
  int votes;
} candidate;

// Define the structure of the election
typedef struct {
  candidate candidates[MAX_CANDIDATES];
  int num_candidates;
  int num_votes;
} election;

// Create a new election
election* create_election() {
  election* e = malloc(sizeof(election));
  e->num_candidates = 0;
  e->num_votes = 0;
  return e;
}

// Add a candidate to the election
void add_candidate(election* e, char* name) {
  strcpy(e->candidates[e->num_candidates].name, name);
  e->candidates[e->num_candidates].votes = 0;
  e->num_candidates++;
}

// Vote for a candidate
void vote_for_candidate(election* e, char* name) {
  for (int i = 0; i < e->num_candidates; i++) {
    if (strcmp(e->candidates[i].name, name) == 0) {
      e->candidates[i].votes++;
      e->num_votes++;
      return;
    }
  }
  printf("Invalid candidate name: %s\n", name);
}

// Print the results of the election
void print_results(election* e) {
  printf("Election Results:\n");
  for (int i = 0; i < e->num_candidates; i++) {
    printf("%s: %d votes (%.2f%%)\n", e->candidates[i].name, e->candidates[i].votes,
           (float)e->candidates[i].votes / e->num_votes * 100);
  }
}

// Destroy the election
void destroy_election(election* e) {
  free(e);
}

int main() {
  // Create a new election
  election* e = create_election();

  // Add some candidates to the election
  add_candidate(e, "Alice");
  add_candidate(e, "Bob");
  add_candidate(e, "Charlie");

  // Simulate some votes
  vote_for_candidate(e, "Alice");
  vote_for_candidate(e, "Bob");
  vote_for_candidate(e, "Charlie");
  vote_for_candidate(e, "Alice");
  vote_for_candidate(e, "Bob");

  // Print the results of the election
  print_results(e);

  // Destroy the election
  destroy_election(e);

  return 0;
}