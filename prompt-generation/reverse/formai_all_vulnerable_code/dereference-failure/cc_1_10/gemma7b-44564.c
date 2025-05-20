//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5

typedef struct Voter {
  char name[20];
  int vote;
  struct Voter* next;
} Voter;

void insertVoter(Voter** head, char* name, int vote) {
  Voter* newNode = malloc(sizeof(Voter));
  strcpy(newNode->name, name);
  newNode->vote = vote;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void vote(Voter** head, char* candidate) {
  Voter* current = *head;
  while (current) {
    if (strcmp(current->name, candidate) == 0) {
      current->vote++;
    }
    current = current->next;
  }
}

int main() {
  Voter* head = NULL;
  insertVoter(&head, "John Doe", 1);
  insertVoter(&head, "Jane Doe", 2);
  insertVoter(&head, "Peter Pan", 3);
  insertVoter(&head, "Mary Poppins", 4);
  insertVoter(&head, "The Wizard of Oz", 5);

  vote(&head, "Jane Doe");
  vote(&head, "Peter Pan");
  vote(&head, "Mary Poppins");

  int totalVotes = 0;
  for (Voter* current = head; current; current = current->next) {
    totalVotes += current->vote;
  }

  printf("Total Votes: %d", totalVotes);

  return 0;
}