//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CANDIDATES 5

struct Candidate {
  char name[20];
  int votes;
  struct Candidate* next;
};

void vote(struct Candidate* candidate) {
  candidate->votes++;
  printf("Thank you for voting for %s.\n", candidate->name);
}

int main() {
  struct Candidate* candidates = NULL;
  int i;

  // Initialize candidates
  for (i = 0; i < NUM_CANDIDATES; i++) {
    candidates = (struct Candidate*)malloc(sizeof(struct Candidate));
    strcpy(candidates->name, "Candidate " + i);
    candidates->votes = 0;
    candidates->next = NULL;

    if (candidates != NULL) {
      if (candidates->next == NULL) {
        candidates->next = candidates;
      }
    }
  }

  // Voting loop
  printf("Please select a candidate: ");
  char choice[20];
  scanf("%s", choice);

  // Find and vote for candidate
  struct Candidate* candidate = candidates;
  while (candidate) {
    if (strcmp(candidate->name, choice) == 0) {
      vote(candidate);
      break;
    }
    candidate = candidate->next;
  }

  // Print results
  printf("The results are:");
  candidate = candidates;
  while (candidate) {
    printf(" %s: %d votes", candidate->name, candidate->votes);
    candidate = candidate->next;
  }

  return 0;
}