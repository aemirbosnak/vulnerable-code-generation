//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
  char name[50];
  int vote;
  struct Voter* next;
} Voter;

void vote(Voter* voter, int candidate) {
  if (voter->vote == -1) {
    voter->vote = candidate;
  } else {
    printf("You have already voted.\n");
  }
}

void print_results(Voter* voters) {
  int candidate_votes[MAX_CANDIDATES];
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    candidate_votes[i] = 0;
  }

  for (Voter* voter = voters; voter; voter = voter->next) {
    candidate_votes[voter->vote]++;
  }

  for (int i = 0; i < MAX_CANDIDATES; i++) {
    printf("Candidate %d: %d votes\n", i, candidate_votes[i]);
  }
}

int main() {
  Voter* voters = NULL;
  time_t t = time(NULL);

  // Simulate voter registration and voting
  for (int i = 0; i < MAX_VOTES; i++) {
    Voter* new_voter = malloc(sizeof(Voter));
    strcpy(new_voter->name, "Voter " + i);
    new_voter->vote = -1;
    new_voter->next = voters;
    voters = new_voter;
  }

  for (int i = 0; i < MAX_VOTES; i++) {
    vote(voters, rand() % MAX_CANDIDATES);
  }

  // Print results
  print_results(voters);

  // Calculate time taken for voting
  t = time(NULL) - t;
  printf("Time taken for voting: %d seconds\n", t);

  return 0;
}