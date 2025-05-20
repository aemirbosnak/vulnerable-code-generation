//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
  char name[20];
  int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void init_candidates() {
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    candidates[i].name[0] = '\0';
    candidates[i].votes = 0;
  }
}

void add_vote(char candidate) {
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    if (strcmp(candidates[i].name, candidate) == 0) {
      candidates[i].votes++;
      return;
    }
  }

  // Candidate not found, error
  printf("Error: Invalid candidate name.\n");
}

void print_results() {
  printf("E-Voting Results:\n");
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    if (candidates[i].votes > 0) {
      printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
  }

  printf("Total Votes: %d\n", total_votes());
}

int total_votes() {
  int total = 0;
  for (int i = 0; i < MAX_CANDIDATES; i++) {
    total += candidates[i].votes;
  }
  return total;
}

int main() {
  init_candidates();

  // Voting loop
  for (int i = 0; i < MAX_VOTES; i++) {
    char candidate;
    printf("Enter candidate name: ");
    scanf("%s", &candidate);
    add_vote(candidate);
  }

  print_results();

  return 0;
}