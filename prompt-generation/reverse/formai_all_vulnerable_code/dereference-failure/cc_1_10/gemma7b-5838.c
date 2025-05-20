//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Candidate {
  char name[20];
  int votes;
  struct Candidate* next;
} Candidate;

typedef struct Ballot {
  Candidate* candidates;
  int votes_cast;
  struct Ballot* next;
} Ballot;

Ballot* create_ballot() {
  Ballot* ballot = malloc(sizeof(Ballot));
  ballot->candidates = NULL;
  ballot->votes_cast = 0;
  ballot->next = NULL;
  return ballot;
}

void add_candidate(Ballot* ballot, char* name) {
  Candidate* candidate = malloc(sizeof(Candidate));
  strcpy(candidate->name, name);
  candidate->votes = 0;
  candidate->next = ballot->candidates;
  ballot->candidates = candidate;
}

void vote(Ballot* ballot, char* candidate) {
  Candidate* current_candidate = ballot->candidates;
  while (current_candidate) {
    if (strcmp(current_candidate->name, candidate) == 0) {
      current_candidate->votes++;
      ballot->votes_cast++;
      break;
    }
    current_candidate = current_candidate->next;
  }
}

int main() {
  Ballot* ballot = create_ballot();
  add_candidate(ballot, "Alice");
  add_candidate(ballot, "Bob");
  add_candidate(ballot, "Charlie");
  add_candidate(ballot, "Dave");
  add_candidate(ballot, "Eve");

  vote(ballot, "Alice");
  vote(ballot, "Bob");
  vote(ballot, "Charlie");
  vote(ballot, "Dave");

  printf("Results:");
  Candidate* current_candidate = ballot->candidates;
  while (current_candidate) {
    printf(" %s: %d votes", current_candidate->name, current_candidate->votes);
  }

  printf("\nTotal votes cast: %d", ballot->votes_cast);

  return 0;
}