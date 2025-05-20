//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialize_ballot(char **ballot, int size) {
  *ballot = malloc(size * sizeof(char));
  for (int i = 0; i < size; i++) {
    ballot[i] = '\0';
  }
}

int validate_ballot(char **ballot, int size, char *candidate) {
  for (int i = 0; i < size; i++) {
    if (ballot[i] == candidate[0]) {
      return 1;
    }
  }
  return 0;
}

void record_ballot(char **ballot, int size, char *candidate) {
  for (int i = 0; i < size; i++) {
    if (ballot[i] == '\0') {
      ballot[i] = candidate[0];
      return;
    }
  }
  return;
}

int main() {
  int num_voters = 100;
  char **ballot = NULL;
  initialize_ballot(&ballot, num_voters);

  char candidate_a[] = "A";
  char candidate_b[] = "B";
  char candidate_c[] = "C";

  char voter_choice;

  for (int i = 0; i < num_voters; i++) {
    printf("Enter your vote: ");
    scanf("%c", &voter_choice);

    if (validate_ballot(ballot, num_voters, candidate_a) ||
        validate_ballot(ballot, num_voters, candidate_b) ||
        validate_ballot(ballot, num_voters, candidate_c)) {
      record_ballot(ballot, num_voters, candidate_a);
    } else {
      printf("Invalid vote.\n");
    }
  }

  int votes_a = 0;
  int votes_b = 0;
  int votes_c = 0;

  for (int i = 0; i < num_voters; i++) {
    if (ballot[i] == candidate_a[0]) {
      votes_a++;
    } else if (ballot[i] == candidate_b[0]) {
      votes_b++;
    } else if (ballot[i] == candidate_c[0]) {
      votes_c++;
    }
  }

  printf("Results:\n");
  printf("Candidate A: %d votes\n", votes_a);
  printf("Candidate B: %d votes\n", votes_b);
  printf("Candidate C: %d votes\n", votes_c);

  return 0;
}