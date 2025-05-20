//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
  char name[20];
  int votes;
} Candidate;

void initializeCandidates(Candidate *candidates) {
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    candidates[i].name[0] = '\0';
    candidates[i].votes = 0;
  }
}

void addVote(Candidate *candidates, char voterName) {
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    if (strcmp(candidates[i].name, voterName) == 0) {
      candidates[i].votes++;
      return;
    }
  }

  // Voter not found, add new candidate
  Candidate newCandidate;
  strcpy(newCandidate.name, voterName);
  newCandidate.votes = 1;
  candidates = (Candidate *)realloc(candidates, (MAX_CANDIDATES + 1) * sizeof(Candidate));
  candidates[MAX_CANDIDATES - 1] = newCandidate;
}

int main() {
  Candidate candidates[MAX_CANDIDATES];
  initializeCandidates(candidates);

  // Register voters and add votes
  addVote(candidates, "John Doe");
  addVote(candidates, "Jane Doe");
  addVote(candidates, "Peter Pan");
  addVote(candidates, "Mary Poppins");

  // Print results
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    printf("%s has %d votes.\n", candidates[i].name, candidates[i].votes);
  }

  return 0;
}