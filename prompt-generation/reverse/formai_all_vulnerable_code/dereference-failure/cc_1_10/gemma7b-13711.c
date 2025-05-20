//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
  char name[20];
  int votes;
  struct Candidate* next;
} Candidate;

Candidate* createCandidate(char* name) {
  Candidate* newCandidate = (Candidate*)malloc(sizeof(Candidate));
  strcpy(newCandidate->name, name);
  newCandidate->votes = 0;
  newCandidate->next = NULL;
  return newCandidate;
}

void addVote(Candidate* candidate) {
  candidate->votes++;
}

int main() {
  time_t t = time(NULL);

  Candidate* candidates = createCandidate("John Doe");
  candidates = createCandidate("Jane Doe");
  candidates = createCandidate("Bill Smith");
  candidates = createCandidate("Mary Johnson");
  candidates = createCandidate("Bob Green");

  // Simulate voting
  addVote(candidates->next);
  addVote(candidates);
  addVote(candidates->next->next);
  addVote(candidates->next->next->next);

  // Print results
  printf("Results:");
  for (Candidate* candidate = candidates; candidate; candidate = candidate->next) {
    printf(" %s: %d votes", candidate->name, candidate->votes);
  }

  printf("\nTime taken: %.2f seconds", time(NULL) - t);

  return 0;
}