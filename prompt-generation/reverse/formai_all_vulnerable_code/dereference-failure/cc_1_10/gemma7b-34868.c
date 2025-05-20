//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 1000

typedef struct Voter {
  char name[50];
  int vote_count;
  struct Voter* next;
} Voter;

typedef struct Ballot {
  char candidate_name[50];
  int votes;
  struct Ballot* next;
} Ballot;

void initialize_voting_system(Ballot** ballot_head) {
  *ballot_head = NULL;
}

void add_candidate(Ballot** ballot_head, char* candidate_name) {
  Ballot* new_ballot = malloc(sizeof(Ballot));
  strcpy(new_ballot->candidate_name, candidate_name);
  new_ballot->votes = 0;
  new_ballot->next = NULL;

  if (*ballot_head == NULL) {
    *ballot_head = new_ballot;
  } else {
    (*ballot_head)->next = new_ballot;
  }
}

void vote(Voter** voter_head, char* candidate_name) {
  Voter* new_voter = malloc(sizeof(Voter));
  strcpy(new_voter->name, candidate_name);
  new_voter->vote_count = 1;
  new_voter->next = NULL;

  if (*voter_head == NULL) {
    *voter_head = new_voter;
  } else {
    (*voter_head)->next = new_voter;
  }

  (*voter_head)->vote_count++;
}

void display_results(Ballot* ballot_head) {
  printf("Election Results:\n");
  for (Ballot* current = ballot_head; current; current = current->next) {
    printf("%s: %d votes\n", current->candidate_name, current->votes);
  }
}

int main() {
  Ballot* ballot_head = NULL;
  initialize_voting_system(&ballot_head);

  add_candidate(&ballot_head, "John Doe");
  add_candidate(&ballot_head, "Jane Doe");
  add_candidate(&ballot_head, "Bill Smith");
  add_candidate(&ballot_head, "Mary Jones");
  add_candidate(&ballot_head, "Tom Brown");

  Voter* voter_head = NULL;
  vote(&voter_head, "John Doe");
  vote(&voter_head, "Jane Doe");
  vote(&voter_head, "Bill Smith");
  vote(&voter_head, "Mary Jones");
  vote(&voter_head, "Tom Brown");

  display_results(ballot_head);

  return 0;
}