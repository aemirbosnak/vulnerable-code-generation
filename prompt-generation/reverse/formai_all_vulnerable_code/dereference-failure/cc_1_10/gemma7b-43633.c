//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
  char name[20];
  int vote;
} Voter;

typedef struct Ballot {
  char candidate[MAX_CANDIDATES][20];
  int votes[MAX_CANDIDATES];
} Ballot;

Ballot ballot;

void initializeBallot() {
  ballot.candidate[0][0] = "John Doe";
  ballot.candidate[0][1] = "Jane Doe";
  ballot.candidate[0][2] = "Peter Pan";
  ballot.candidate[0][3] = "Mary Poppins";
  ballot.candidate[0][4] = "Batman";

  ballot.votes[0] = 0;
  ballot.votes[1] = 0;
  ballot.votes[2] = 0;
  ballot.votes[3] = 0;
  ballot.votes[4] = 0;
}

void castVote(char* candidate) {
  int i;
  for (i = 0; i < MAX_CANDIDATES; i++) {
    if (strcmp(candidate, ballot.candidate[i][0]) == 0) {
      ballot.votes[i]++;
    }
  }
}

void displayResults() {
  int i;
  printf("Results:\n");
  for (i = 0; i < MAX_CANDIDATES; i++) {
    printf("%s: %d votes\n", ballot.candidate[i][0], ballot.votes[i]);
  }
}

int main() {
  initializeBallot();

  Voter voter1;
  strcpy(voter1.name, "John Smith");
  voter1.vote = 2;
  castVote(voter1.name);

  Voter voter2;
  strcpy(voter2.name, "Jane Doe");
  voter2.vote = 1;
  castVote(voter2.name);

  displayResults();

  return 0;
}