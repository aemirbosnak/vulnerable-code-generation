//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
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

typedef struct Poll {
  char candidate[MAX_CANDIDATES][50];
  int votes[MAX_CANDIDATES];
  struct Voter* head;
} Poll;

Poll* createPoll() {
  Poll* poll = (Poll*)malloc(sizeof(Poll));
  poll->head = NULL;
  return poll;
}

void addVoter(Poll* poll) {
  Voter* voter = (Voter*)malloc(sizeof(Voter));
  printf("Enter your name: ");
  scanf("%s", voter->name);
  printf("Enter your vote for candidate: ");
  scanf("%d", &voter->vote);
  voter->next = poll->head;
  poll->head = voter;
}

void vote(Poll* poll) {
  printf("Enter the name of the candidate you want to vote for: ");
  char candidateName[50];
  scanf("%s", candidateName);
  int candidateIndex = -1;
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    if (strcmp(candidateName, poll->candidate[i]) == 0) {
      candidateIndex = i;
      break;
    }
  }
  if (candidateIndex == -1) {
    printf("Candidate not found.\n");
  } else {
    poll->votes[candidateIndex]++;
  }
}

void printResults(Poll* poll) {
  printf("Results:\n");
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    printf("%s: %d votes\n", poll->candidate[i], poll->votes[i]);
  }
}

int main() {
  Poll* poll = createPoll();
  addVoter(poll);
  addVoter(poll);
  vote(poll);
  printResults(poll);
  return 0;
}