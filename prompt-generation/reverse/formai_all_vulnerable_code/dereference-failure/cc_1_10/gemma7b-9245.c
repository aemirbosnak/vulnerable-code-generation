//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100

typedef struct Voter {
  char name[50];
  int vote;
  struct Voter* next;
} Voter;

void addVoter(Voter** head) {
  Voter* newVoter = (Voter*)malloc(sizeof(Voter));
  scanf("Enter your name: ", newVoter->name);
  newVoter->vote = 0;
  newVoter->next = NULL;

  if (*head == NULL) {
    *head = newVoter;
  } else {
    (*head)->next = newVoter;
  }
}

void vote(Voter* head) {
  printf("Please select a candidate: ");
  int candidate;
  scanf("%d", &candidate);

  Voter* current = head;
  while (current) {
    if (strcmp(current->name, "Candidate") == 0) {
      current->vote++;
      printf("Your vote has been cast.\n");
      break;
    }
    current = current->next;
  }

  if (current == NULL) {
    printf("Error: Invalid candidate.\n");
  }
}

void displayResults(Voter* head) {
  printf("Election Results:\n");
  int totalVotes = 0;
  for (Voter* current = head; current; current = current->next) {
    printf("%s: %d votes\n", current->name, current->vote);
    totalVotes += current->vote;
  }

  printf("Total Votes: %d\n", totalVotes);
}

int main() {
  Voter* head = NULL;
  addVoter(&head);
  addVoter(&head);
  addVoter(&head);
  vote(head);
  vote(head);
  displayResults(head);

  return 0;
}