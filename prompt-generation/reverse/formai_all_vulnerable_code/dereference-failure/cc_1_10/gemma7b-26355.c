//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
  char name[20];
  int vote;
  struct Voter *next;
} Voter;

typedef struct Ballot {
  int candidate_votes[MAX_CANDIDATES];
  struct Ballot *next;
} Ballot;

Ballot *create_ballot() {
  Ballot *ballot = (Ballot *)malloc(sizeof(Ballot));
  ballot->candidate_votes[0] = 0;
  ballot->candidate_votes[1] = 0;
  ballot->candidate_votes[2] = 0;
  ballot->candidate_votes[3] = 0;
  ballot->candidate_votes[4] = 0;
  ballot->next = NULL;
  return ballot;
}

void add_vote(Ballot *ballot, int candidate_number) {
  ballot->candidate_votes[candidate_number - 1]++;
}

void print_ballot(Ballot *ballot) {
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    printf("Candidate %d: %d votes\n", i + 1, ballot->candidate_votes[i]);
  }
}

int main() {
  Ballot *ballot = create_ballot();
  add_vote(ballot, 2);
  add_vote(ballot, 3);
  add_vote(ballot, 1);
  add_vote(ballot, 2);
  add_vote(ballot, 4);
  print_ballot(ballot);

  return 0;
}