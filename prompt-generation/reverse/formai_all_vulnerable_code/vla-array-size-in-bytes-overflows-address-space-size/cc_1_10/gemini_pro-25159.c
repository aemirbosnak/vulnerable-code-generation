//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int votes;
} Candidate;

int main() {
  // Create an array of candidates
  Candidate candidates[] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Carol", 0},
    {"Dave", 0},
    {"Eve", 0},
  };

  // Get the number of candidates
  int num_candidates = sizeof(candidates) / sizeof(candidates[0]);

  // Get the number of voters
  int num_voters;
  printf("Enter the number of voters: ");
  scanf("%d", &num_voters);

  // Create an array of votes
  int votes[num_voters];

  // Get the votes for each voter
  for (int i = 0; i < num_voters; i++) {
    printf("Enter the vote for voter %d: ", i + 1);
    scanf("%d", &votes[i]);
  }

  // Count the votes for each candidate
  for (int i = 0; i < num_candidates; i++) {
    for (int j = 0; j < num_voters; j++) {
      if (votes[j] == i) {
        candidates[i].votes++;
      }
    }
  }

  // Find the winner
  int max_votes = 0;
  int winner_index = -1;
  for (int i = 0; i < num_candidates; i++) {
    if (candidates[i].votes > max_votes) {
      max_votes = candidates[i].votes;
      winner_index = i;
    }
  }

  // Print the winner
  printf("The winner is %s with %d votes.\n", candidates[winner_index].name,
         candidates[winner_index].votes);

  return 0;
}