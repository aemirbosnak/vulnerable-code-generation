//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
  char name[255];
  int vote_count;
  struct Voter* next;
} Voter;

typedef struct Ballot {
  char candidate_name[255];
  int votes;
  struct Ballot* next;
} Ballot;

Voter* create_voter(char* name) {
  Voter* new_voter = malloc(sizeof(Voter));
  strcpy(new_voter->name, name);
  new_voter->vote_count = 0;
  new_voter->next = NULL;
  return new_voter;
}

Ballot* create_ballot(char* candidate_name) {
  Ballot* new_ballot = malloc(sizeof(Ballot));
  strcpy(new_ballot->candidate_name, candidate_name);
  new_ballot->votes = 0;
  new_ballot->next = NULL;
  return new_ballot;
}

void vote(Voter* voter, Ballot* ballot) {
  if (voter->vote_count < MAX_VOTES) {
    voter->vote_count++;
    ballot->votes++;
  } else {
    printf("Error: voter has already voted.");
  }
}

void print_results(Ballot* ballot) {
  Ballot* current_ballot = ballot;
  while (current_ballot) {
    printf("%s: %d votes\n", current_ballot->candidate_name, current_ballot->votes);
    current_ballot = current_ballot->next;
  }
}

int main() {
  // Create a list of voters
  Voter* head = create_voter("Alice");
  head->next = create_voter("Bob");
  head->next->next = create_voter("Charlie");

  // Create a list of ballots
  Ballot* tail = create_ballot("John Doe");
  tail->next = create_ballot("Jane Doe");
  tail->next->next = create_ballot("Bill Smith");

  // Vote
  vote(head, tail);
  vote(head, tail);
  vote(head->next, tail);

  // Print results
  print_results(tail);

  return 0;
}