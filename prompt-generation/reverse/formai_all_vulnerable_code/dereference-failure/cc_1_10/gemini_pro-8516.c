//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates
#define MAX_CANDIDATES 10

// Define the maximum number of voters
#define MAX_VOTERS 100

// Define the data structure for a candidate
typedef struct candidate {
  char name[100];
  int votes;
} candidate;

// Define the data structure for a voter
typedef struct voter {
  char name[100];
  int voted;
} voter;

// Define the data structure for the election
typedef struct election {
  candidate candidates[MAX_CANDIDATES];
  int num_candidates;
  voter voters[MAX_VOTERS];
  int num_voters;
} election;

// Function to create a new election
election* create_election() {
  election* e = malloc(sizeof(election));
  e->num_candidates = 0;
  e->num_voters = 0;
  return e;
}

// Function to add a candidate to an election
void add_candidate(election* e, char* name) {
  strcpy(e->candidates[e->num_candidates].name, name);
  e->candidates[e->num_candidates].votes = 0;
  e->num_candidates++;
}

// Function to add a voter to an election
void add_voter(election* e, char* name) {
  strcpy(e->voters[e->num_voters].name, name);
  e->voters[e->num_voters].voted = 0;
  e->num_voters++;
}

// Function to vote for a candidate
void vote(election* e, char* voter_name, char* candidate_name) {
  for (int i = 0; i < e->num_candidates; i++) {
    if (strcmp(e->candidates[i].name, candidate_name) == 0) {
      e->candidates[i].votes++;
      for (int j = 0; j < e->num_voters; j++) {
        if (strcmp(e->voters[j].name, voter_name) == 0) {
          e->voters[j].voted = 1;
          break;
        }
      }
      break;
    }
  }
}

// Function to print the results of an election
void print_results(election* e) {
  printf("Election Results:\n");
  for (int i = 0; i < e->num_candidates; i++) {
    printf("%s: %d votes\n", e->candidates[i].name, e->candidates[i].votes);
  }
}

// Function to run an election
void run_election(election* e) {
  char voter_name[100];
  char candidate_name[100];
  int voted;

  // Get the voter's name
  printf("Enter your name: ");
  scanf("%s", voter_name);

  // Check if the voter has already voted
  for (int i = 0; i < e->num_voters; i++) {
    if (strcmp(e->voters[i].name, voter_name) == 0) {
      voted = e->voters[i].voted;
      break;
    }
  }

  // If the voter has not already voted, get the candidate's name and vote
  if (!voted) {
    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", candidate_name);
    vote(e, voter_name, candidate_name);
  } else {
    printf("You have already voted.\n");
  }

  // Recursively call the run_election function until all voters have voted
  if (e->num_voters > 0) {
    run_election(e);
  } else {
    print_results(e);
  }
}

int main() {
  // Create a new election
  election* e = create_election();

  // Add candidates to the election
  add_candidate(e, "Alice");
  add_candidate(e, "Bob");
  add_candidate(e, "Charlie");

  // Add voters to the election
  add_voter(e, "John");
  add_voter(e, "Mary");
  add_voter(e, "Tom");

  // Run the election
  run_election(e);

  return 0;
}