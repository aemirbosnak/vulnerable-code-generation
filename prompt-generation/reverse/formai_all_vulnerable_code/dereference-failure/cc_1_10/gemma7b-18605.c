//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
  char name[20];
  int votes;
  struct Candidate* next;
};

struct Ballot {
  struct Candidate* head;
  struct Ballot* next;
};

void vote(struct Ballot* ballot, char* candidate) {
  struct Candidate* current = ballot->head;
  while (current) {
    if (strcmp(current->name, candidate) == 0) {
      current->votes++;
      return;
    }
    current = current->next;
  }

  // Candidate not found, add new candidate
  struct Candidate* new_candidate = malloc(sizeof(struct Candidate));
  strcpy(new_candidate->name, candidate);
  new_candidate->votes = 1;
  new_candidate->next = NULL;

  ballot->head = new_candidate;
}

int main() {
  struct Ballot* ballot = malloc(sizeof(struct Ballot));
  ballot->head = NULL;
  ballot->next = NULL;

  vote(ballot, "John Doe");
  vote(ballot, "Jane Doe");
  vote(ballot, "Bob Smith");

  struct Candidate* current = ballot->head;
  while (current) {
    printf("%s has %d votes\n", current->name, current->votes);
    current = current->next;
  }

  return 0;
}