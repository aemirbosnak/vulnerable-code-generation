//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for candidate data
struct Candidate {
  char name[50];
  int votes;
};

int main() {

  // Define number of candidates and total votes
  int numCandidates = 3;
  int totalVotes = 0;

  // Allocate memory for array of candidates and initialize with default values
  struct Candidate *candidates = malloc(numCandidates * sizeof(struct Candidate));
  for (int i = 0; i < numCandidates; i++) {
    strcpy(candidates[i].name, "Candidate");
    candidates[i].votes = 0;
  }

  // Display welcome message and list of candidates
  printf("Welcome to the Electronic Voting System!\n\n");
  for (int i = 0; i < numCandidates; i++) {
    printf("%d. %s\n", i+1, candidates[i].name);
  }
  printf("\n");

  // Loop over voters and record their votes
  int numVoters = 10;
  for (int i = 0; i < numVoters; i++) {
    printf("Voter %d, please enter your vote (1-%d): ", i+1, numCandidates);
    int vote;
    scanf("%d", &vote);
    if (vote < 1 || vote > numCandidates) {
      printf("Invalid vote!\n");
    } else {
      candidates[vote-1].votes++;
      totalVotes++;
    }
  }

  // Display results
  printf("\nTotal votes: %d\n\n", totalVotes);
  for (int i = 0; i < numCandidates; i++) {
    printf("%s: %d votes (%.2f%%)\n", candidates[i].name, candidates[i].votes, (float)candidates[i].votes/totalVotes*100);
  }

  // Free memory and exit
  free(candidates);
  return 0;
}