//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
  char name[50];
  int vote_count;
  struct Voter* next;
} Voter;

typedef struct Poll {
  char poll_name[50];
  int total_votes;
  Voter* head;
  struct Poll* next;
} Poll;

int main() {
  time_t t = time(NULL);
  srand(t);

  Poll* head = NULL;
  Poll* current_poll = NULL;

  // Create a new poll
  current_poll = malloc(sizeof(Poll));
  strcpy(current_poll->poll_name, "Romantic Election");
  current_poll->total_votes = 0;
  current_poll->head = NULL;

  // Add a few voters
  Voter* voter1 = malloc(sizeof(Voter));
  strcpy(voter1->name, "Romeo");
  voter1->vote_count = rand() % MAX_VOTES;
  current_poll->head = voter1;

  Voter* voter2 = malloc(sizeof(Voter));
  strcpy(voter2->name, "Juliet");
  voter2->vote_count = rand() % MAX_VOTES;
  current_poll->head->next = voter2;

  Voter* voter3 = malloc(sizeof(Voter));
  strcpy(voter3->name, "Ben");
  voter3->vote_count = rand() % MAX_VOTES;
  current_poll->head->next->next = voter3;

  // Vote casting
  for (int i = 0; i < MAX_VOTES; i++) {
    Voter* voter = current_poll->head;
    while (voter) {
      if (rand() % MAX_CANDIDATES == voter->vote_count) {
        voter->vote_count++;
        current_poll->total_votes++;
      }
      voter = voter->next;
    }
  }

  // Print the results
  printf("Results of the Romantic Election:\n");
  printf("------------------------\n");
  printf("Total votes: %d\n", current_poll->total_votes);
  printf("Winner: %s\n", current_poll->head->name);

  return 0;
}