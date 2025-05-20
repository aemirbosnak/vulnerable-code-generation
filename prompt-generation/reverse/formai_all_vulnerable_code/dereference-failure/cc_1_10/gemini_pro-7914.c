//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Candidate structure
typedef struct candidate {
  char *name;
  int votes;
} candidate;

// Array of candidates
candidate candidates[] = {
  {"Alice", 0},
  {"Bob", 0},
  {"Carol", 0},
  {"Dave", 0},
  {"Eve", 0},
};

// Number of candidates
int num_candidates = sizeof(candidates) / sizeof(candidate);

// Get the vote for a candidate
int get_vote(char *name) {
  for (int i = 0; i < num_candidates; i++) {
    if (strcmp(name, candidates[i].name) == 0) {
      return candidates[i].votes;
    }
  }
  return -1;
}

// Increment the vote for a candidate
void increment_vote(char *name) {
  for (int i = 0; i < num_candidates; i++) {
    if (strcmp(name, candidates[i].name) == 0) {
      candidates[i].votes++;
    }
  }
}

// Print the results of the election
void print_results() {
  printf("Election results:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }
}

// Main function
int main() {
  // Get the user's vote
  char *vote;
  printf("Enter your vote: ");
  scanf("%s", vote);

  // Increment the vote for the user's candidate
  increment_vote(vote);

  // Print the results of the election
  print_results();

  return 0;
}