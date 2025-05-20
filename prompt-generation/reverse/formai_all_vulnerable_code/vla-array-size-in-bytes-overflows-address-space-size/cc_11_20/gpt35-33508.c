//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

int main() {
  int num_voters, num_candidates;

  printf("Enter the number of voters: ");
  scanf("%d", &num_voters);

  printf("Enter the number of candidates: ");
  scanf("%d", &num_candidates);

  // initialize candidate names
  char candidate_names[MAX_CANDIDATES][20];
  for (int i = 0; i < num_candidates; i++) {
    printf("Enter the name of candidate %d: ", (i+1));
    scanf("%s", candidate_names[i]);
  }

  // initialize votes
  int votes[MAX_VOTERS][MAX_CANDIDATES];
  for (int i = 0; i < num_voters; i++) {
    printf("Voter %d, enter your vote (enter candidate number 1 through %d): ", (i+1), num_candidates);
    int candidate_choice;
    scanf("%d", &candidate_choice);
    for (int j = 0; j < num_candidates; j++) {
      if ((j+1) == candidate_choice) {
        votes[i][j] = 1;
      } else {
        votes[i][j] = 0;
      }
    }
  }

  // display number of votes for each candidate
  int vote_totals[num_candidates];
  for (int i = 0; i < num_candidates; i++) {
    vote_totals[i] = 0;
  }

  for (int i = 0; i < num_voters; i++) {
    for (int j = 0; j < num_candidates; j++) {
      if (votes[i][j] == 1) {
        vote_totals[j]++;
      }
    }
  }

  printf("\nVote totals:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("%s: %d\n", candidate_names[i], vote_totals[i]);
  }

  // determine winner
  int max_votes = vote_totals[0], winner = 0;
  for (int i = 1; i < num_candidates; i++) {
    if (vote_totals[i] > max_votes) {
      max_votes = vote_totals[i];
      winner = i;
    }
  }

  printf("\nThe winner is %s with %d votes!\n", candidate_names[winner], max_votes);

  return 0;
}