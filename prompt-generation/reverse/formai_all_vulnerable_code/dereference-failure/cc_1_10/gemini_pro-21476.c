//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Cryptic
#include <stdlib.h>
#include <stdio.h>

typedef struct ballot_box_t {
  unsigned int candidate_count;
  unsigned int *candidate_votes;
} ballot_box_t;

ballot_box_t *ballot_box_new(unsigned int candidate_count) {
  ballot_box_t *ballot_box = malloc(sizeof(ballot_box_t));
  ballot_box->candidate_count = candidate_count;
  ballot_box->candidate_votes = calloc(candidate_count, sizeof(unsigned int));
  return ballot_box;
}

void ballot_box_free(ballot_box_t *ballot_box) {
  free(ballot_box->candidate_votes);
  free(ballot_box);
}

void ballot_box_vote(ballot_box_t *ballot_box, unsigned int candidate_id) {
  if (candidate_id < ballot_box->candidate_count) {
    ballot_box->candidate_votes[candidate_id]++;
  }
}

unsigned int ballot_box_get_winner(ballot_box_t *ballot_box) {
  unsigned int winner_id = 0;
  unsigned int max_votes = 0;
  for (unsigned int i = 0; i < ballot_box->candidate_count; i++) {
    if (ballot_box->candidate_votes[i] > max_votes) {
      max_votes = ballot_box->candidate_votes[i];
      winner_id = i;
    }
  }
  return winner_id;
}

int main(void) {
  unsigned int candidate_count;
  printf("Enter the number of candidates: ");
  scanf("%u", &candidate_count);

  ballot_box_t *ballot_box = ballot_box_new(candidate_count);

  unsigned int voter_id;
  printf("Enter the voter ID: ");
  scanf("%u", &voter_id);

  unsigned int candidate_id;
  printf("Enter the candidate ID: ");
  scanf("%u", &candidate_id);

  ballot_box_vote(ballot_box, candidate_id);

  unsigned int winner_id = ballot_box_get_winner(ballot_box);
  printf("The winner is candidate %u\n", winner_id);

  ballot_box_free(ballot_box);
  return 0;
}