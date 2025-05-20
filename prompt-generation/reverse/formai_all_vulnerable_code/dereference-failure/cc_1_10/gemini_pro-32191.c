//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct voter {
  int id;
  char *name;
  int *votes;
  int num_votes;
} voter;

typedef struct election {
  int num_voters;
  voter *voters;
} election;

election *create_election(int num_voters) {
  election *e = malloc(sizeof(election));
  e->num_voters = num_voters;
  e->voters = malloc(num_voters * sizeof(voter));
  for (int i = 0; i < num_voters; i++) {
    e->voters[i].id = i;
    e->voters[i].name = malloc(20 * sizeof(char));
    sprintf(e->voters[i].name, "Voter %d", i);
    e->voters[i].num_votes = 0;
    e->voters[i].votes = malloc(10 * sizeof(int));
  }
  return e;
}

void destroy_election(election *e) {
  for (int i = 0; i < e->num_voters; i++) {
    free(e->voters[i].name);
    free(e->voters[i].votes);
  }
  free(e->voters);
  free(e);
}

void vote(election *e, int voter_id, int candidate_id) {
  if (voter_id < 0 || voter_id >= e->num_voters) {
    printf("Invalid voter ID\n");
    return;
  }
  if (candidate_id < 0 || candidate_id >= 10) {
    printf("Invalid candidate ID\n");
    return;
  }
  e->voters[voter_id].votes[e->voters[voter_id].num_votes++] = candidate_id;
}

int count_votes(election *e, int candidate_id) {
  int count = 0;
  for (int i = 0; i < e->num_voters; i++) {
    for (int j = 0; j < e->voters[i].num_votes; j++) {
      if (e->voters[i].votes[j] == candidate_id) {
        count++;
      }
    }
  }
  return count;
}

int find_winner(election *e) {
  int max_votes = 0;
  int winner_id = -1;
  for (int i = 0; i < 10; i++) {
    int votes = count_votes(e, i);
    if (votes > max_votes) {
      max_votes = votes;
      winner_id = i;
    }
  }
  return winner_id;
}

int main() {
  election *e = create_election(100);
  vote(e, 0, 0);
  vote(e, 1, 1);
  vote(e, 2, 2);
  vote(e, 3, 3);
  vote(e, 4, 4);
  vote(e, 5, 5);
  vote(e, 6, 6);
  vote(e, 7, 7);
  vote(e, 8, 8);
  vote(e, 9, 9);
  int winner_id = find_winner(e);
  printf("The winner is: %s\n", e->voters[winner_id].name);
  destroy_election(e);
  return 0;
}