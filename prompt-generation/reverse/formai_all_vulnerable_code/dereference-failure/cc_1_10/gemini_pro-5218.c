//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Constants
#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

// Candidate struct
typedef struct {
  char name[50];
  int votes;
} Candidate;

// Voter struct
typedef struct {
  char name[50];
  int voted;
} Voter;

// Function to create a new candidate
Candidate *create_candidate(char *name) {
  Candidate *candidate = malloc(sizeof(Candidate));
  strcpy(candidate->name, name);
  candidate->votes = 0;
  return candidate;
}

// Function to create a new voter
Voter *create_voter(char *name) {
  Voter *voter = malloc(sizeof(Voter));
  strcpy(voter->name, name);
  voter->voted = 0;
  return voter;
}

// Function to add a candidate to the list of candidates
void add_candidate(Candidate **candidates, int *num_candidates, char *name) {
  candidates[*num_candidates] = create_candidate(name);
  (*num_candidates)++;
}

// Function to add a voter to the list of voters
void add_voter(Voter **voters, int *num_voters, char *name) {
  voters[*num_voters] = create_voter(name);
  (*num_voters)++;
}

// Function to print the list of candidates
void print_candidates(Candidate **candidates, int num_candidates) {
  for (int i = 0; i < num_candidates; i++) {
    printf("%s\n", candidates[i]->name);
  }
}

// Function to print the list of voters
void print_voters(Voter **voters, int num_voters) {
  for (int i = 0; i < num_voters; i++) {
    printf("%s\n", voters[i]->name);
  }
}

// Function to get the index of a candidate by name
int get_candidate_index(Candidate **candidates, int num_candidates, char *name) {
  for (int i = 0; i < num_candidates; i++) {
    if (strcmp(candidates[i]->name, name) == 0) {
      return i;
    }
  }
  return -1;
}

// Function to get the index of a voter by name
int get_voter_index(Voter **voters, int num_voters, char *name) {
  for (int i = 0; i < num_voters; i++) {
    if (strcmp(voters[i]->name, name) == 0) {
      return i;
    }
  }
  return -1;
}

// Function to handle the voting process
void vote(Candidate **candidates, int num_candidates, Voter **voters, int num_voters) {
  char voter_name[50];
  char candidate_name[50];

  // Get the voter's name
  printf("Enter your name: ");
  gets(voter_name);

  // Check if the voter has already voted
  int voter_index = get_voter_index(voters, num_voters, voter_name);
  if (voter_index == -1) {
    printf("Voter not found.\n");
    return;
  }
  if (voters[voter_index]->voted) {
    printf("You have already voted.\n");
    return;
  }

  // Get the candidate's name
  printf("Enter the candidate you want to vote for: ");
  gets(candidate_name);

  // Check if the candidate is valid
  int candidate_index = get_candidate_index(candidates, num_candidates, candidate_name);
  if (candidate_index == -1) {
    printf("Candidate not found.\n");
    return;
  }

  // Increment the candidate's vote count
  candidates[candidate_index]->votes++;

  // Mark the voter as having voted
  voters[voter_index]->voted = 1;

  printf("Thank you for voting!\n");
}

// Function to get the winner of the election
Candidate *get_winner(Candidate **candidates, int num_candidates) {
  int max_votes = 0;
  Candidate *winner = NULL;

  for (int i = 0; i < num_candidates; i++) {
    if (candidates[i]->votes > max_votes) {
      max_votes = candidates[i]->votes;
      winner = candidates[i];
    }
  }

  return winner;
}

// Function to print the results of the election
void print_results(Candidate **candidates, int num_candidates) {
  Candidate *winner = get_winner(candidates, num_candidates);

  printf("\nElection results:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("%s: %d votes\n", candidates[i]->name, candidates[i]->votes);
  }

  printf("\nWinner:\n");
  printf("%s\n", winner->name);
}

// Main function
int main() {
  // Create the list of candidates
  Candidate *candidates[MAX_CANDIDATES];
  int num_candidates = 0;

  // Add candidates to the list
  add_candidate(candidates, &num_candidates, "John Smith");
  add_candidate(candidates, &num_candidates, "Jane Doe");
  add_candidate(candidates, &num_candidates, "Bob Jones");

  // Create the list of voters
  Voter *voters[MAX_VOTERS];
  int num_voters = 0;

  // Add voters to the list
  add_voter(voters, &num_voters, "Alice");
  add_voter(voters, &num_voters, "Bob");
  add_voter(voters, &num_voters, "Carol");

  // Handle the voting process
  while (1) {
    char choice;

    // Display the menu
    printf("\nElectronic Voting System\n");
    printf("-------------------------\n");
    printf("1. Vote\n");
    printf("2. Print candidates\n");
    printf("3. Print voters\n");
    printf("4. Print results\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");

    // Get the user's choice
    scanf(" %c", &choice);

    // Process the user's choice
    switch (choice) {
      case '1':
        vote(candidates, num_candidates, voters, num_voters);
        break;
      case '2':
        print_candidates(candidates, num_candidates);
        break;
      case '3':
        print_voters(voters, num_voters);
        break;
      case '4':
        print_results(candidates, num_candidates);
        break;
      case '5':
        return 0;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}