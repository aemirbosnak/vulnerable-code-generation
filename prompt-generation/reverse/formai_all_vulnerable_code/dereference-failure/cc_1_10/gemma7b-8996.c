//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
  char name[50];
  char address[100];
  int vote;
  struct Voter* next;
} Voter;

typedef struct Ballot {
  char candidate[MAX_CANDIDATES][50];
  int votes[MAX_CANDIDATES];
  struct Ballot* next;
} Ballot;

Voter* insertVoter(Voter* head) {
  Voter* newVoter = (Voter*)malloc(sizeof(Voter));
  scanf("Enter your name: ", newVoter->name);
  scanf("Enter your address: ", newVoter->address);
  newVoter->vote = -1;
  newVoter->next = head;
  return newVoter;
}

Ballot* insertBallot(Ballot* head) {
  Ballot* newBallot = (Ballot*)malloc(sizeof(Ballot));
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    scanf("Enter candidate name: ", newBallot->candidate[i]);
  }
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    scanf("Enter number of votes: ", &newBallot->votes[i]);
  }
  newBallot->next = head;
  return newBallot;
}

void vote(Voter* head, Ballot* head2) {
  printf("Enter your name: ");
  char name[50];
  scanf("%s", name);

  Voter* currentVoter = head;
  while (currentVoter) {
    if (strcmp(name, currentVoter->name) == 0) {
      printf("Enter your vote: ");
      int vote = -1;
      scanf("%d", &vote);

      Ballot* currentBallot = head2;
      while (currentBallot) {
        for (int i = 0; i < MAX_CANDIDATES; i++) {
          if (strcmp(currentBallot->candidate[i], currentVoter->name) == 0) {
            currentVoter->vote = currentBallot->votes[i];
          }
        }
      }
      break;
    }
    currentVoter = currentVoter->next;
  }

  if (currentVoter == NULL) {
    printf("Voter not found.\n");
  } else {
    printf("Your vote has been cast.\n");
  }
}

int main() {
  Voter* head = NULL;
  Ballot* head2 = NULL;

  insertVoter(&head);
  insertVoter(&head);
  insertBallot(&head2);
  insertBallot(&head2);

  vote(head, head2);

  return 0;
}