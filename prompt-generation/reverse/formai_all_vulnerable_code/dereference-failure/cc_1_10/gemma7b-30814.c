//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CANDIDATES 5
#define NUM_VOTERS 100

typedef struct Voter {
  char name[20];
  int vote;
} Voter;

typedef struct Candidate {
  char name[20];
  int votes;
} Candidate;

void initializeVoters(Voter *voters, int numVoters) {
  for (int i = 0; i < numVoters; i++) {
    voters[i].name[0] = '\0';
    voters[i].vote = 0;
  }
}

void initializeCandidates(Candidate *candidates, int numCandidates) {
  for (int i = 0; i < numCandidates; i++) {
    candidates[i].name[0] = '\0';
    candidates[i].votes = 0;
  }
}

void vote(Voter *voters, Candidate *candidates) {
  printf("Enter your name: ");
  scanf("%s", voters[voters->vote].name);

  printf("Enter your vote for candidate number: ");
  scanf("%d", &candidates[voters->vote].votes);
}

void displayResults(Candidate *candidates) {
  printf("Election Results:\n");
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }
}

int main() {
  Voter *voters = malloc(NUM_VOTERS * sizeof(Voter));
  initializeVoters(voters, NUM_VOTERS);

  Candidate *candidates = malloc(NUM_CANDIDATES * sizeof(Candidate));
  initializeCandidates(candidates, NUM_CANDIDATES);

  time_t t = time(NULL);
  srand(t);

  for (int i = 0; i < NUM_VOTERS; i++) {
    voters[i].vote = rand() % NUM_CANDIDATES;
    vote(voters, candidates);
  }

  displayResults(candidates);

  free(voters);
  free(candidates);

  return 0;
}