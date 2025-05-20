//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the happiest electronic voting system ever!\n");

  // Initialize the candidates and their vote counts
  char *candidates[] = {"Alice", "Bob", "Charlie", "Dora", "Eve"};
  int votes[] = {0, 0, 0, 0, 0};

  // Get the number of voters
  int num_voters;
  printf("How many happy voters are there? ");
  scanf("%d", &num_voters);

  // Get the votes from the voters
  for (int i = 0; i < num_voters; i++) {
    printf("Happy voter %d, who do you want to vote for? ", i + 1);
    char *vote;
    scanf("%s", vote);

    // Find the index of the candidate in the candidates array
    int index = -1;
    for (int j = 0; j < 5; j++) {
      if (strcmp(vote, candidates[j]) == 0) {
        index = j;
        break;
      }
    }

    // If the candidate is not found, print an error message
    if (index == -1) {
      printf("Invalid candidate. Please try again.\n");
      i--;
      continue;
    }

    // Increment the vote count for the candidate
    votes[index]++;
  }

  // Find the winner
  int max_votes = 0;
  int winner_index = -1;
  for (int i = 0; i < 5; i++) {
    if (votes[i] > max_votes) {
      max_votes = votes[i];
      winner_index = i;
    }
  }

  // Print the winner
  printf("The winner is %s with %d votes. Congratulations!\n", candidates[winner_index], max_votes);

  return 0;
}