//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the candidate struct
typedef struct candidate {
  char name[50];
  int votes;
} candidate;

// Define the voter struct
typedef struct voter {
  char name[50];
  int voted;
} voter;

// Define the election struct
typedef struct election {
  candidate candidates[MAX_CANDIDATES];
  voter voters[MAX_VOTERS];
  int num_candidates;
  int num_voters;
} election;

// Create a new election
election *new_election() {
  election *e = malloc(sizeof(election));
  e->num_candidates = 0;
  e->num_voters = 0;
  return e;
}

// Add a candidate to the election
void add_candidate(election *e, char *name) {
  strcpy(e->candidates[e->num_candidates].name, name);
  e->candidates[e->num_candidates].votes = 0;
  e->num_candidates++;
}

// Add a voter to the election
void add_voter(election *e, char *name) {
  strcpy(e->voters[e->num_voters].name, name);
  e->voters[e->num_voters].voted = 0;
  e->num_voters++;
}

// Vote for a candidate
void vote(election *e, char *voter_name, char *candidate_name) {
  int i, j;

  // Find the voter
  for (i = 0; i < e->num_voters; i++) {
    if (strcmp(e->voters[i].name, voter_name) == 0) {
      break;
    }
  }

  // If the voter was not found, return
  if (i == e->num_voters) {
    printf("Voter not found\n");
    return;
  }

  // Find the candidate
  for (j = 0; j < e->num_candidates; j++) {
    if (strcmp(e->candidates[j].name, candidate_name) == 0) {
      break;
    }
  }

  // If the candidate was not found, return
  if (j == e->num_candidates) {
    printf("Candidate not found\n");
    return;
  }

  // If the voter has already voted, return
  if (e->voters[i].voted) {
    printf("Voter has already voted\n");
    return;
  }

  // Increment the candidate's vote count
  e->candidates[j].votes++;

  // Mark the voter as having voted
  e->voters[i].voted = 1;
}

// Get the winner of the election
char *get_winner(election *e) {
  int i, max_votes = 0;
  char *winner = NULL;

  // Find the candidate with the most votes
  for (i = 0; i < e->num_candidates; i++) {
    if (e->candidates[i].votes > max_votes) {
      max_votes = e->candidates[i].votes;
      winner = e->candidates[i].name;
    }
  }

  return winner;
}

// Print the election results
void print_results(election *e) {
  int i;

  // Print the winner
  printf("The winner is %s\n", get_winner(e));

  // Print the candidate's names and vote counts
  printf("Candidate\tVotes\n");
  for (i = 0; i < e->num_candidates; i++) {
    printf("%s\t%d\n", e->candidates[i].name, e->candidates[i].votes);
  }
}

// Free the memory allocated for the election
void free_election(election *e) {
  free(e);
}

int main() {
  election *e = new_election();

  // Add candidates to the election
  add_candidate(e, "Alice");
  add_candidate(e, "Bob");
  add_candidate(e, "Charlie");

  // Add voters to the election
  add_voter(e, "John");
  add_voter(e, "Mary");
  add_voter(e, "Tom");

  // Vote for candidates
  vote(e, "John", "Alice");
  vote(e, "Mary", "Bob");
  vote(e, "Tom", "Charlie");

  // Print the election results
  print_results(e);

  // Free the memory allocated for the election
  free_election(e);

  return 0;
}