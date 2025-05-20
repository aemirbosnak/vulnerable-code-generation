//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a candidate
typedef struct candidate {
  char *name;
  int votes;
} candidate;

// Structure to represent the voting system
typedef struct voting_system {
  candidate *candidates;
  int num_candidates;
  int num_voters;
} voting_system;

// Function to create a new voting system
voting_system *create_voting_system(int num_candidates, int num_voters) {
  voting_system *system = malloc(sizeof(voting_system));
  system->candidates = malloc(sizeof(candidate) * num_candidates);
  system->num_candidates = num_candidates;
  system->num_voters = num_voters;
  return system;
}

// Function to add a candidate to the voting system
void add_candidate(voting_system *system, char *name) {
  candidate *candidate = &system->candidates[system->num_candidates];
  candidate->name = malloc(strlen(name) + 1);
  strcpy(candidate->name, name);
  candidate->votes = 0;
  system->num_candidates++;
}

// Function to allow a voter to vote for a candidate
void vote(voting_system *system, int voter_id, int candidate_id) {
  candidate *candidate = &system->candidates[candidate_id];
  candidate->votes++;
}

// Function to print the results of the election
void print_results(voting_system *system) {
  for (int i = 0; i < system->num_candidates; i++) {
    candidate *candidate = &system->candidates[i];
    printf("%s: %d votes\n", candidate->name, candidate->votes);
  }
}

// Main function
int main() {
  // Create a new voting system
  voting_system *system = create_voting_system(3, 100);

  // Add candidates to the voting system
  add_candidate(system, "Alice");
  add_candidate(system, "Bob");
  add_candidate(system, "Carol");

  // Simulate voters voting
  srand(time(NULL));
  for (int i = 0; i < system->num_voters; i++) {
    int candidate_id = rand() % system->num_candidates;
    vote(system, i, candidate_id);
  }

  // Print the results of the election
  print_results(system);

  return 0;
}