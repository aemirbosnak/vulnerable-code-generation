//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10

typedef struct Candidate {
  char name[20];
  int votes;
  struct Candidate* next;
} Candidate;

Candidate* createCandidate(char* name) {
  Candidate* candidate = malloc(sizeof(Candidate));
  strcpy(candidate->name, name);
  candidate->votes = 0;
  candidate->next = NULL;
  return candidate;
}

void vote(Candidate* candidate) {
  candidate->votes++;
}

int main() {
  Candidate* candidates = NULL;
  char vote_choice;
  time_t t;

  // Create candidates
  candidates = createCandidate("John Doe");
  candidates = createCandidate("Jane Doe");
  candidates = createCandidate("Bill Smith");

  // Start timer
  t = time(NULL);

  // Vote
  printf("Enter your vote (a, b, c): ");
  scanf("%c", &vote_choice);

  switch (vote_choice) {
    case 'a':
      vote(candidates);
      printf("Thank you for voting, %s!\n", candidates->name);
      break;
    case 'b':
      vote(candidates->next);
      printf("Thank you for voting, %s!\n", candidates->next->name);
      break;
    case 'c':
      vote(candidates->next->next);
      printf("Thank you for voting, %s!\n", candidates->next->next->name);
      break;
    default:
      printf("Invalid vote.\n");
  }

  // End timer
  t = time(NULL) - t;

  // Print results
  printf("Total time: %d seconds\n", t);
  printf("Winner: %s\n", candidates->votes > candidates->next->votes ? candidates->name : candidates->next->name);

  return 0;
}