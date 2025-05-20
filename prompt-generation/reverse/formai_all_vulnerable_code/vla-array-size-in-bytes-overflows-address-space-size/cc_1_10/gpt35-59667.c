//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int candidate_id;
  char candidate_name[50];
  int candidate_votes;
} candidate;

// Function to display the list of candidates
void display_candidates(candidate c[], int num_candidates) {
  printf("List of Candidates:\n");

  for (int i = 0; i < num_candidates; i++) {
    printf("Candidate ID: %d\n", c[i].candidate_id);
    printf("Candidate Name: %s\n", c[i].candidate_name);
    printf("Number of Votes: %d\n\n", c[i].candidate_votes);
  }
}

// Function to cast a vote
void cast_vote(candidate c[], int num_candidates) {
  int choice;

  printf("Enter the Candidate ID to cast your vote: ");
  scanf("%d", &choice);

  // Increment the vote count for the chosen candidate
  for (int i = 0; i < num_candidates; i++) {
    if (c[i].candidate_id == choice) {
      c[i].candidate_votes++;
      printf("Thank you for casting your vote for %s!\n\n", c[i].candidate_name);
      return;
    }
  }

  // If candidate id is not found
  printf("Invalid Candidate ID. Please try again.\n\n");
}

// Function to determine the winner based on the number of votes
void determine_winner(candidate c[], int num_candidates) {
  int max_votes = -1, winner_index = -1;

  for (int i = 0; i < num_candidates; i++) {
    if (c[i].candidate_votes > max_votes) {
      max_votes = c[i].candidate_votes;
      winner_index = i;
    }
  }

  printf("%s wins the election with %d votes!\n\n", c[winner_index].candidate_name, max_votes);
}

int main() {
  int num_candidates;

  printf("Welcome to the Electronic Voting System!\n\n");

  printf("Enter the number of Candidates: ");
  scanf("%d", &num_candidates);

  candidate candidates[num_candidates];

  // Get details of all the candidates
  for (int i = 0; i < num_candidates; i++) {
    printf("\nCandidate #%d Details:\n", i+1);
    printf("Enter Candidate ID: ");
    scanf("%d", &candidates[i].candidate_id);
    printf("Enter Candidate Name: ");
    scanf("%s", candidates[i].candidate_name);
    candidates[i].candidate_votes = 0;
  }

  // Display the list of candidates
  display_candidates(candidates, num_candidates);

  // Allow users to cast votes
  int num_votes;
  printf("\nEnter the number of Votes to be cast: ");
  scanf("%d", &num_votes);

  for (int i = 0; i < num_votes; i++) {
    cast_vote(candidates, num_candidates);
  }

  // Determine the winner based on the number of votes
  determine_winner(candidates, num_candidates);

  return 0;
}