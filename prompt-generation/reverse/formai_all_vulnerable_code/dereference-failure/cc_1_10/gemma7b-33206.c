//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VOTES 10

typedef struct Voter {
  char name[20];
  int vote;
  struct Voter* next;
} Voter;

void vote(Voter* head) {
  int vote_choice;
  printf("Enter your vote (1-10): ");
  scanf("%d", &vote_choice);

  if (vote_choice > MAX_VOTES || vote_choice < 1) {
    printf("Invalid vote. Please try again.\n");
    return;
  }

  head->vote = vote_choice;
  printf("Your vote has been cast.\n");
}

void print_results(Voter* head) {
  int total_votes = 0;
  int candidate_votes[MAX_VOTES] = {0};

  for (Voter* voter = head; voter; voter = voter->next) {
    candidate_votes[voter->vote - 1]++;
    total_votes++;
  }

  printf("Total votes: %d\n", total_votes);

  for (int i = 0; i < MAX_VOTES; i++) {
    if (candidate_votes[i] > 0) {
      printf("Candidate %d: %d votes\n", i + 1, candidate_votes[i]);
    }
  }

  printf("The winner is: Candidate %d\n", winner(candidate_votes));
}

int winner(int* votes) {
  int max_votes = votes[0];
  int winner = 1;

  for (int i = 1; i < MAX_VOTES; i++) {
    if (votes[i] > max_votes) {
      max_votes = votes[i];
      winner = i + 1;
    }
  }

  return winner;
}

int main() {
  Voter* head = NULL;

  // Create a voter list
  for (int i = 0; i < 10; i++) {
    Voter* new_voter = malloc(sizeof(Voter));
    new_voter->name[0] = 'A' + i;
    new_voter->vote = 0;
    new_voter->next = head;
    head = new_voter;
  }

  // Vote
  vote(head);

  // Print results
  print_results(head);

  return 0;
}