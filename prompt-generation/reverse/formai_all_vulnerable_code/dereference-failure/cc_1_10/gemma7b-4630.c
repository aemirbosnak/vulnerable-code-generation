//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
  char name[20];
  int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(Candidate *c) {
  c->votes++;
}

int main() {
  int i, j, votes, candidate_index;
  char vote_choice[20];

  // Initialize candidates
  for (i = 0; i < MAX_CANDIDATES; i++) {
    candidates[i].votes = 0;
  }

  // Get the number of votes
  printf("Enter the number of votes: ");
  scanf("%d", &votes);

  // Allocate votes
  for (i = 0; i < votes; i++) {
    printf("Enter the candidate's name: ");
    scanf("%s", vote_choice);

    // Find the candidate index
    for (j = 0; j < MAX_CANDIDATES; j++) {
      if (strcmp(vote_choice, candidates[j].name) == 0) {
        candidate_index = j;
      }
    }

    // Vote the candidate
    vote(&candidates[candidate_index]);
  }

  // Print the results
  for (i = 0; i < MAX_CANDIDATES; i++) {
    printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
  }

  return 0;
}