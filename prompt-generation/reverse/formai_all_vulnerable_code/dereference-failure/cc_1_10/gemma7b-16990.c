//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Voter {
  char name[50];
  int vote;
  struct Voter* next;
} Voter;

typedef struct Poll {
  char candidate[MAX_CANDIDATES][50];
  int votes[MAX_CANDIDATES];
  struct Poll* next;
} Poll;

void vote(Poll* poll, Voter* voter) {
  int i;
  for (i = 0; i < MAX_CANDIDATES; i++) {
    if (strcmp(voter->name, poll->candidate[i]) == 0) {
      poll->votes[i]++;
      break;
    }
  }
}

void displayResults(Poll* poll) {
  int i;
  for (i = 0; i < MAX_CANDIDATES; i++) {
    printf("%s received %d votes.\n", poll->candidate[i], poll->votes[i]);
  }
}

int main() {
  Voter* head = NULL;
  Poll* tail = NULL;

  // Create a voter
  Voter* newVoter = malloc(sizeof(Voter));
  strcpy(newVoter->name, "John Doe");
  newVoter->vote = 1;
  newVoter->next = NULL;

  // Insert the voter into the head of the list
  if (head == NULL) {
    head = newVoter;
  } else {
    tail->next = newVoter;
    tail = newVoter;
  }

  // Create a poll
  Poll* newPoll = malloc(sizeof(Poll));
  strcpy(newPoll->candidate[0], "Alice");
  strcpy(newPoll->candidate[1], "Bob");
  strcpy(newPoll->candidate[2], "Charlie");
  newPoll->votes[0] = 20;
  newPoll->votes[1] = 30;
  newPoll->votes[2] = 10;
  newPoll->next = NULL;

  // Insert the poll into the tail of the list
  if (tail == NULL) {
    tail = newPoll;
  } else {
    tail->next = newPoll;
    tail = newPoll;
  }

  // Vote
  vote(tail, head);

  // Display the results
  displayResults(tail);

  return 0;
}