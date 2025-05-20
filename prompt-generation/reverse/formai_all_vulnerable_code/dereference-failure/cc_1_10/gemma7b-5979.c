//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Candidate {
  char name[50];
  int votes;
  struct Candidate* next;
} Candidate;

typedef struct VotingBooth {
  Candidate* candidates;
  int votesCast;
  struct VotingBooth* next;
} VotingBooth;

VotingBooth* createVotingBooth() {
  VotingBooth* booth = (VotingBooth*)malloc(sizeof(VotingBooth));
  booth->candidates = NULL;
  booth->votesCast = 0;
  booth->next = NULL;
  return booth;
}

void addCandidate(VotingBooth* booth, char* name) {
  Candidate* candidate = (Candidate*)malloc(sizeof(Candidate));
  strcpy(candidate->name, name);
  candidate->votes = 0;
  candidate->next = NULL;

  if (booth->candidates == NULL) {
    booth->candidates = candidate;
  } else {
    Candidate* current = booth->candidates;
    while (current->next) {
      current = current->next;
    }
    current->next = candidate;
  }
}

void vote(VotingBooth* booth, char* candidate) {
  Candidate* current = booth->candidates;
  while (current) {
    if (strcmp(current->name, candidate) == 0) {
      current->votes++;
      booth->votesCast++;
      return;
    }
    current = current->next;
  }
  printf("Error: Candidate not found.\n");
}

int main() {
  VotingBooth* booth = createVotingBooth();

  addCandidate(booth, "John Doe");
  addCandidate(booth, "Jane Doe");
  addCandidate(booth, "Bill Smith");

  vote(booth, "John Doe");
  vote(booth, "Jane Doe");
  vote(booth, "Bill Smith");

  printf("Results:\n");
  Candidate* current = booth->candidates;
  while (current) {
    printf("%s: %d votes\n", current->name, current->votes);
  }

  printf("Total votes cast: %d\n", booth->votesCast);

  return 0;
}