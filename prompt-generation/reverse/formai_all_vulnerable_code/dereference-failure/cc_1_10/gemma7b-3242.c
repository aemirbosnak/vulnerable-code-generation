//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter
{
  char name[20];
  int vote;
} Voter;

void vote(Voter **voters, int *numVoters, int candidate)
{
  (*voters) = realloc((*voters), (*numVoters) * sizeof(Voter));
  (*voters)[*numVoters].name[0] = '\0';
  scanf("Enter your name: ", (*voters)[*numVoters].name);
  (*voters)[*numVoters].vote = candidate;
  (*numVoters)++;
}

int main()
{
  int numVoters = 0;
  Voter *voters = NULL;

  int candidates[MAX_CANDIDATES] = {0, 1, 2, 3, 4};
  int votes[MAX_VOTES] = {0, 0, 0, 0, 0};

  printf("Welcome to the Electronic Voting System!\n");

  while (1)
  {
    char choice;

    printf("Please select an option:\n");
    printf("a) Register to vote\n");
    printf("b) Vote\n");
    printf("c) Exit\n");

    scanf("Enter your choice: ", &choice);

    switch (choice)
    {
      case 'a':
        vote(&voters, &numVoters, 0);
        break;
      case 'b':
        vote(&voters, &numVoters, 0);
        break;
      case 'c':
        exit(0);
    }
  }

  return 0;
}