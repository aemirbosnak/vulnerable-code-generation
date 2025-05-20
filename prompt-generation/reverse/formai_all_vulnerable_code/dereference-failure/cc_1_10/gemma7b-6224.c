//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Voter
{
  char name[255];
  int vote;
  struct Voter* next;
} Voter;

Voter* createVoter(char* name, int vote)
{
  Voter* voter = malloc(sizeof(Voter));
  strcpy(voter->name, name);
  voter->vote = vote;
  voter->next = NULL;
  return voter;
}

void addVoter(Voter** head, char* name, int vote)
{
  Voter* voter = createVoter(name, vote);
  if (*head == NULL)
  {
    *head = voter;
  }
  else
  {
    (*head)->next = voter;
  }
}

void vote(Voter** head, int candidate)
{
  Voter* current = *head;
  while (current)
  {
    if (strcmp(current->name, "John Doe") == 0)
    {
      current->vote = candidate;
      break;
    }
    current = current->next;
  }
}

int main()
{
  Voter** head = NULL;
  addVoter(head, "Alice", 1);
  addVoter(head, "Bob", 2);
  addVoter(head, "Charlie", 3);
  addVoter(head, "Dave", 4);

  vote(head, 2);

  for (Voter* current = *head; current; current = current->next)
  {
    printf("%s voted for candidate %d\n", current->name, current->vote);
  }

  return 0;
}