//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
  char name[20];
  int vote;
  struct Voter* next;
} Voter;

Voter* createVoter() {
  Voter* newVoter = (Voter*)malloc(sizeof(Voter));
  newVoter->vote = 0;
  newVoter->next = NULL;
  return newVoter;
}

void addVoter(Voter* head, char* name) {
  Voter* newVoter = createVoter();
  strcpy(newVoter->name, name);
  if (head == NULL) {
    head = newVoter;
  } else {
    newVoter->next = head;
    head = newVoter;
  }
}

void vote(Voter* head, int candidate) {
  while (head) {
    if (strcmp(head->name, "John") == 0) {
      head->vote = candidate;
    }
    head = head->next;
  }
}

int main() {
  Voter* head = NULL;
  addVoter(head, "Alice");
  addVoter(head, "Bob");
  addVoter(head, "Charlie");
  addVoter(head, "Dave");
  addVoter(head, "John");

  vote(head, 2);
  vote(head, 1);
  vote(head, 3);

  for (head = head; head; head = head->next) {
    printf("%s voted for candidate %d\n", head->name, head->vote);
  }

  return 0;
}