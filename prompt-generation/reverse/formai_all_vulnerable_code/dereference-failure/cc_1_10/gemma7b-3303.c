//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CANDIDATES 5
#define NUM_VOTERS 100

typedef struct Voter {
  char name[50];
  int vote_cast;
  struct Voter* next;
} Voter;

typedef struct Candidate {
  char name[50];
  int votes_received;
  struct Candidate* next;
} Candidate;

void vote(Voter* voter, Candidate* candidate) {
  if (voter->vote_cast) {
    return;
  }
  voter->vote_cast = 1;
  candidate->votes_received++;
}

int main() {
  Voter* head_voter = NULL;
  Candidate* head_candidate = NULL;

  // Initialize voters
  for (int i = 0; i < NUM_VOTERS; i++) {
    Voter* new_voter = malloc(sizeof(Voter));
    strcpy(new_voter->name, "Voter");
    new_voter->vote_cast = 0;
    new_voter->next = head_voter;
    head_voter = new_voter;
  }

  // Initialize candidates
  for (int i = 0; i < NUM_CANDIDATES; i++) {
    Candidate* new_candidate = malloc(sizeof(Candidate));
    strcpy(new_candidate->name, "Candidate");
    new_candidate->votes_received = 0;
    new_candidate->next = head_candidate;
    head_candidate = new_candidate;
  }

  // Simulate voting
  time_t t = time(NULL);
  for (int i = 0; i < NUM_VOTERS; i++) {
    Voter* voter = head_voter;
    for (int j = 0; j < NUM_CANDIDATES; j++) {
      Candidate* candidate = head_candidate;
      if (rand() % 2) {
        vote(voter, candidate);
      }
    }
  }

  // Print results
  for (Candidate* candidate = head_candidate; candidate; candidate++) {
    printf("%s received %d votes\n", candidate->name, candidate->votes_received);
  }

  return 0;
}