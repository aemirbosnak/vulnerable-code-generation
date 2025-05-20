//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter
{
  char name[50];
  int vote;
  struct Voter* next;
} Voter;

typedef struct Ballot
{
  char candidate[MAX_CANDIDATES][50];
  int votes[MAX_VOTES];
  struct Ballot* next;
} Ballot;

Ballot* createBallot()
{
  Ballot* ballot = (Ballot*)malloc(sizeof(Ballot));
  ballot->next = NULL;

  for (int i = 0; i < MAX_CANDIDATES; i++)
  {
    ballot->candidate[i][0] = '\0';
  }

  for (int i = 0; i < MAX_VOTES; i++)
  {
    ballot->votes[i] = 0;
  }

  return ballot;
}

void addVoter(Ballot* ballot)
{
  Voter* voter = (Voter*)malloc(sizeof(Voter));
  voter->next = NULL;

  printf("Enter your name: ");
  scanf("%s", voter->name);

  printf("Enter your vote: ");
  scanf("%d", &voter->vote);

  ballot->votes[voter->vote]++;
  ballot->candidate[voter->vote][0] = voter->name[0];

  free(voter);
}

void printResults(Ballot* ballot)
{
  int totalVotes = 0;
  for (int i = 0; i < MAX_VOTES; i++)
  {
    totalVotes += ballot->votes[i];
  }

  printf("\nTotal Votes: %d", totalVotes);

  for (int i = 0; i < MAX_CANDIDATES; i++)
  {
    if (ballot->candidate[i][0] != '\0')
    {
      printf("\nCandidate: %s, Votes: %d", ballot->candidate[i], ballot->votes[i]);
    }
  }

  printf("\nWinner: %s", ballot->candidate[0]);
}

int main()
{
  Ballot* ballot = createBallot();

  addVoter(ballot);
  addVoter(ballot);
  addVoter(ballot);

  printResults(ballot);

  return 0;
}