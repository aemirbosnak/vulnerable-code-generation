//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: post-apocalyptic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Initialize the candidate list
char *candidates[] = {"Caesar", "Brutus", "Cassius", "Antony", "Lepidus"};
int num_candidates = 5;

// Initialize the voter list
char *voters[] = {"Marius", "Sulla", "Pompey", "Crassus", "Cicero", "Cato"};
int num_voters = 6;

// Initialize the blockchain
struct Block {
  int block_number;
  char *candidate;
  char *voter;
  time_t timestamp;
  struct Block *next;
};

struct Block *blockchain = NULL;

// Create a new block
struct Block *create_block(char *candidate, char *voter) {
  struct Block *new_block = malloc(sizeof(struct Block));
  new_block->block_number = blockchain ? blockchain->block_number + 1 : 1;
  new_block->candidate = candidate;
  new_block->voter = voter;
  new_block->timestamp = time(NULL);
  new_block->next = NULL;
  return new_block;
}

// Add a block to the blockchain
void add_block(struct Block *new_block) {
  if (!blockchain) {
    blockchain = new_block;
  } else {
    new_block->next = blockchain;
    blockchain = new_block;
  }
}

// Cast a vote
void cast_vote(char *candidate, char *voter) {
  struct Block *new_block = create_block(candidate, voter);
  add_block(new_block);
  printf("Vote cast for %s by %s\n", candidate, voter);
}

// Print the blockchain
void print_blockchain() {
  struct Block *current_block = blockchain;
  while (current_block) {
    printf("Block %d: %s -> %s (%ld)\n", current_block->block_number, current_block->candidate, current_block->voter, current_block->timestamp);
    current_block = current_block->next;
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Register a random voter
  char *voter = voters[rand() % num_voters];
  printf("Voter: %s\n", voter);

  // Get the list of candidates
  printf("Candidates:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("  %d. %s\n", i + 1, candidates[i]);
  }

  // Get the voter's choice
  int choice;
  do {
    printf("Enter your choice (1-%d): ", num_candidates);
    scanf("%d", &choice);
  } while (choice < 1 || choice > num_candidates);

  // Cast the vote
  cast_vote(candidates[choice - 1], voter);

  // Print the blockchain
  printf("\nBlockchain:\n");
  print_blockchain();

  return 0;
}