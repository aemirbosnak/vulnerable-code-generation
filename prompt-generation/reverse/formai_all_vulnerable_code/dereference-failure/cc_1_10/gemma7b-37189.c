//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

typedef struct Candidate {
  char name[20];
  int votes;
  struct Candidate* next;
} Candidate;

Candidate* insertCandidate(Candidate* head, char* name) {
  Candidate* newNode = (Candidate*)malloc(sizeof(Candidate));
  strcpy(newNode->name, name);
  newNode->votes = 0;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void vote(Candidate* head, char* name) {
  Candidate* current = head;
  while (current) {
    if (strcmp(current->name, name) == 0) {
      current->votes++;
    }
    current = current->next;
  }
}

int main() {
  Candidate* head = NULL;
  head = insertCandidate(head, "John Doe");
  head = insertCandidate(head, "Jane Doe");
  head = insertCandidate(head, "Bill Smith");

  vote(head, "John Doe");
  vote(head, "Jane Doe");
  vote(head, "Bill Smith");

  Candidate* current = head;
  while (current) {
    printf("%s has %d votes\n", current->name, current->votes);
    current = current->next;
  }

  return 0;
}