//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int number_of_voters, number_of_candidates;

  printf("Enter the number of voters: ");
  scanf("%d", &number_of_voters);

  printf("Enter the number of candidates: ");
  scanf("%d", &number_of_candidates);

  int **votes = malloc(sizeof(int*) * number_of_voters);

  for (int i = 0; i < number_of_voters; i++) {
    votes[i] = malloc(sizeof(int) * number_of_candidates);
  }

  printf("Enter the votes:\n");

  for (int i = 0; i < number_of_voters; i++) {
    printf("Voter %d\n", i + 1);

    for (int j = 0; j < number_of_candidates; j++) {
      printf("Candidate %d: ", j + 1);
      scanf("%d", &votes[i][j]);
    }
  }

  int *candidate_votes = calloc(number_of_candidates, sizeof(int));

  for (int i = 0; i < number_of_voters; i++) {
    for (int j = 0; j < number_of_candidates; j++) {
      candidate_votes[votes[i][j] - 1]++;
      break;
    }
  }

  printf("Candidate\tVotes\n");

  for (int i = 0; i < number_of_candidates; i++) {
    printf("%d\t\t%d\n", i + 1, candidate_votes[i]);
  }

  int max_votes = candidate_votes[0];
  int winner = 1;

  for (int i = 1; i < number_of_candidates; i++) {
    if (candidate_votes[i] > max_votes) {
      max_votes = candidate_votes[i];
      winner = i + 1;
    }
  }

  printf("The winner is candidate %d with %d votes.\n", winner, max_votes);

  for (int i = 0; i < number_of_voters; i++) {
    free(votes[i]);
  }
  free(votes);
  free(candidate_votes);

  return 0;
}