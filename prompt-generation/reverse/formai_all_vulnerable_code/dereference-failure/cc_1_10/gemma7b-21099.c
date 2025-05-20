//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialize_ballot(char **ballot, int index);
void cast_vote(char **ballot, int index, char vote);
void display_results(char **ballot);

int main()
{
  int num_voters = 10;
  char **ballot = (char **)malloc(num_voters * sizeof(char *));

  for (int i = 0; i < num_voters; i++)
  {
    ballot[i] = (char *)malloc(20 * sizeof(char));
    initialize_ballot(ballot[i], i);
  }

  cast_vote(ballot, 2, 'A');
  cast_vote(ballot, 4, 'B');
  cast_vote(ballot, 6, 'C');

  display_results(ballot);

  free(ballot);

  return 0;
}

void initialize_ballot(char **ballot, int index)
{
  ballot[index] = (char *)malloc(20 * sizeof(char));
  ballot[index][0] = '\0';
}

void cast_vote(char **ballot, int index, char vote)
{
  ballot[index][0] = vote;
}

void display_results(char **ballot)
{
  int total_votes = 0;
  for (int i = 0; i < 10; i++)
  {
    if (ballot[i][0] != '\0')
    {
      total_votes++;
    }
  }

  printf("Total votes: %d\n", total_votes);

  for (int i = 0; i < 10; i++)
  {
    if (ballot[i][0] != '\0')
    {
      printf("Voter %d voted for: %c\n", i, ballot[i][0]);
    }
  }
}