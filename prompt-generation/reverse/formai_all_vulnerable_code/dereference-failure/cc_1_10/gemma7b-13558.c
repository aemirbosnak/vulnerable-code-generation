//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
  char name[50];
  int vote;
  struct Voter* next;
} Voter;

void insert_voter(Voter** head) {
  Voter* new_voter = (Voter*)malloc(sizeof(Voter));
  printf("Enter your name: ");
  scanf("%s", new_voter->name);
  new_voter->vote = 0;
  new_voter->next = NULL;

  if (*head == NULL) {
    *head = new_voter;
  } else {
    (*head)->next = new_voter;
  }
}

void vote(Voter** head) {
  printf("Enter the number of the candidate you want to vote for: ");
  int candidate_num;
  scanf("%d", &candidate_num);

  Voter* current = *head;
  while (current) {
    if (strcmp(current->name, "John Doe") == 0) {
      current->vote = candidate_num;
      break;
    }
    current = current->next;
  }

  printf("Your vote has been cast. Thank you for voting!");
}

int main() {
  Voter* head = NULL;
  insert_voter(&head);
  insert_voter(&head);
  insert_voter(&head);
  vote(&head);

  return 0;
}