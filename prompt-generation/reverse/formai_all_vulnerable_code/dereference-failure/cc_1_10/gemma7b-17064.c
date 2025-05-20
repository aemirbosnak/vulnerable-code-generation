//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
  char name[20];
  int votes;
  struct Candidate* next;
} Candidate;

typedef struct VotingSystem {
  Candidate* candidates;
  int votesCast;
  int totalVotes;
  struct VotingSystem* next;
} VotingSystem;

VotingSystem* createVotingSystem() {
  VotingSystem* system = malloc(sizeof(VotingSystem));
  system->candidates = NULL;
  system->votesCast = 0;
  system->totalVotes = 0;
  system->next = NULL;
  return system;
}

void addCandidate(VotingSystem* system, char* name) {
  Candidate* candidate = malloc(sizeof(Candidate));
  strcpy(candidate->name, name);
  candidate->votes = 0;
  candidate->next = system->candidates;
  system->candidates = candidate;
}

void castVote(VotingSystem* system, char* candidateName) {
  Candidate* candidate = system->candidates;
  while (candidate) {
    if (strcmp(candidate->name, candidateName) == 0) {
      candidate->votes++;
      system->votesCast++;
      system->totalVotes++;
      return;
    }
    candidate = candidate->next;
  }
  printf("Error: Candidate not found.\n");
}

void printResults(VotingSystem* system) {
  Candidate* candidate = system->candidates;
  printf("Results:\n");
  while (candidate) {
    printf("%s: %d votes\n", candidate->name, candidate->votes);
  }
  printf("Total votes cast: %d\n", system->votesCast);
  printf("Total votes: %d\n", system->totalVotes);
}

int main() {
  VotingSystem* system = createVotingSystem();
  addCandidate(system, "John Doe");
  addCandidate(system, "Jane Doe");
  addCandidate(system, "Bill Smith");
  addCandidate(system, "Mary Johnson");
  addCandidate(system, "Tom Jones");

  castVote(system, "John Doe");
  castVote(system, "Jane Doe");
  castVote(system, "Bill Smith");
  castVote(system, "Mary Johnson");

  printResults(system);

  return 0;
}