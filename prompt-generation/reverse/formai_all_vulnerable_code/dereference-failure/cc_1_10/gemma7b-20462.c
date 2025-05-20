//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define the number of voters
int num_voters = 100;

// Define the list of voters
struct voter {
  char name[20];
  int vote;
  struct voter* next;
};

// Create a linked list of voters
struct voter* create_voter_list() {
  struct voter* head = NULL;
  for (int i = 0; i < num_voters; i++) {
    struct voter* new_voter = malloc(sizeof(struct voter));
    strcpy(new_voter->name, "Voter");
    new_voter->vote = 0;
    new_voter->next = head;
    head = new_voter;
  }
  return head;
}

// Print the list of voters
void print_voter_list(struct voter* head) {
  struct voter* current = head;
  while (current) {
    printf("%s, ", current->name);
    current = current->next;
  }
  printf("\n");
}

// Get the vote of a voter
int get_voter_vote(struct voter* head, char* name) {
  struct voter* current = head;
  while (current) {
    if (strcmp(current->name, name) == 0) {
      return current->vote;
    }
    current = current->next;
  }
  return -1;
}

// Set the vote of a voter
void set_voter_vote(struct voter* head, char* name, int vote) {
  struct voter* current = head;
  while (current) {
    if (strcmp(current->name, name) == 0) {
      current->vote = vote;
      return;
    }
    current = current->next;
  }
  return;
}

int main() {
  struct voter* head = create_voter_list();
  print_voter_list(head);
  set_voter_vote(head, "John Doe", 1);
  print_voter_list(head);
  int vote = get_voter_vote(head, "John Doe");
  printf("John Doe's vote is: %d\n", vote);

  return 0;
}