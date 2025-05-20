//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

typedef struct Voter {
  char name[20];
  int vote;
  struct Voter* next;
} Voter;

void vote(Voter* voter, int candidate) {
  if (voter->vote == -1) {
    voter->vote = candidate;
  } else {
    printf("You have already voted!\n");
  }
}

void displayResults(Voter* voters) {
  int candidateVotes[MAX_CANDIDATES];
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    candidateVotes[i] = 0;
  }

  for (Voter* voter = voters; voter; voter = voter->next) {
    candidateVotes[voter->vote]++;
  }

  printf("The results are:\n");
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    printf("Candidate %d: %d votes\n", i, candidateVotes[i]);
  }
}

int main() {
  Voter* voters = NULL;
  int numVoters = 0;

  // Register voters
  for (int i = 0; i < 10; i++) {
    Voter* newVoter = malloc(sizeof(Voter));
    strcpy(newVoter->name, "Voter");
    newVoter->vote = -1;
    newVoter->next = voters;
    voters = newVoter;
    numVoters++;
  }

  // Vote
  vote(voters, 2);
  vote(voters, 1);
  vote(voters, 3);

  // Display results
  displayResults(voters);

  return 0;
}