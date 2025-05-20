//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate
{
  char name[20];
  int votes;
  struct Candidate* next;
} Candidate;

Candidate* createCandidate(char* name)
{
  Candidate* candidate = malloc(sizeof(Candidate));
  strcpy(candidate->name, name);
  candidate->votes = 0;
  candidate->next = NULL;
  return candidate;
}

void addVote(Candidate* candidate)
{
  candidate->votes++;
}

int main()
{
  Candidate* candidates[MAX_CANDIDATES];
  int i, vote, candidateIndex;

  // Create candidates
  for (i = 0; i < MAX_CANDIDATES; i++)
  {
    candidates[i] = createCandidate("Candidate");
  }

  // Simulate voting
  for (i = 0; i < MAX_VOTES; i++)
  {
    printf("Enter candidate index: ");
    scanf("%d", &candidateIndex);

    if (candidateIndex >= 0 && candidateIndex < MAX_CANDIDATES)
    {
      addVote(candidates[candidateIndex]);
    }
  }

  // Print results
  for (i = 0; i < MAX_CANDIDATES; i++)
  {
    printf("%s has %d votes.\n", candidates[i]->name, candidates[i]->votes);
  }

  return 0;
}