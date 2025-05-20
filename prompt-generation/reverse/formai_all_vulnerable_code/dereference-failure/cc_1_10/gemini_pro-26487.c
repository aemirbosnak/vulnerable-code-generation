//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a candidate
struct Candidate {
  char name[50];
  int votes;
};

// Structure to represent the election
struct Election {
  struct Candidate candidates[10];
  int num_candidates;
  char winning_candidate[50];
};

// Function to create a new election
struct Election *create_election() {
  struct Election *election = malloc(sizeof(struct Election));
  election->num_candidates = 0;
  return election;
}

// Function to add a candidate to the election
void add_candidate(struct Election *election, char *name) {
  strcpy(election->candidates[election->num_candidates].name, name);
  election->candidates[election->num_candidates].votes = 0;
  election->num_candidates++;
}

// Function to cast a vote for a candidate
void cast_vote(struct Election *election, char *name) {
  for (int i = 0; i < election->num_candidates; i++) {
    if (strcmp(election->candidates[i].name, name) == 0) {
      election->candidates[i].votes++;
      break;
    }
  }
}

// Function to determine the winner of the election
void determine_winner(struct Election *election) {
  int max_votes = 0;
  for (int i = 0; i < election->num_candidates; i++) {
    if (election->candidates[i].votes > max_votes) {
      max_votes = election->candidates[i].votes;
      strcpy(election->winning_candidate, election->candidates[i].name);
    }
  }
}

// Function to print the results of the election
void print_results(struct Election *election) {
  printf("Election Results:\n");
  for (int i = 0; i < election->num_candidates; i++) {
    printf("%s: %d votes\n", election->candidates[i].name, election->candidates[i].votes);
  }
  printf("Winner: %s\n", election->winning_candidate);
}

int main() {
  // Create a new election
  struct Election *election = create_election();

  // Add candidates to the election
  add_candidate(election, "Candidate A");
  add_candidate(election, "Candidate B");
  add_candidate(election, "Candidate C");

  // Cast votes for the candidates
  cast_vote(election, "Candidate A");
  cast_vote(election, "Candidate A");
  cast_vote(election, "Candidate B");
  cast_vote(election, "Candidate C");
  cast_vote(election, "Candidate C");

  // Determine the winner of the election
  determine_winner(election);

  // Print the results of the election
  print_results(election);

  return 0;
}