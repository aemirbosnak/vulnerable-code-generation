//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct candidate {
   char name[50];
   int votes;
};

struct voter {
   char name[50];
   int vote;
};

int main() {
   int num_voters = 0;
   int num_candidates = 0;
   printf("Welcome to the Electronic Voting System!\n");

   // Get the number of voters and candidates
   printf("Enter the number of voters: ");
   scanf("%d", &num_voters);
   printf("Enter the number of candidates: ");
   scanf("%d", &num_candidates);

   // Allocate memory for the candidates and voters
   struct candidate* candidates = malloc(sizeof(struct candidate) * num_candidates);
   struct voter* voters = malloc(sizeof(struct voter) * num_voters);

   // Get the name of each candidate
   for (int i = 0; i < num_candidates; i++) {
      printf("Enter candidate %d's name: ", i + 1);
      scanf("%s", candidates[i].name);
      candidates[i].votes = 0;
   }

   // Get the name of each voter and their vote
   for (int i = 0; i < num_voters; i++) {
      printf("Enter your name, voter %d: ", i + 1);
      scanf("%s", voters[i].name);
      printf("Enter your vote (1-%d): ", num_candidates);
      scanf("%d", &voters[i].vote);
      candidates[voters[i].vote - 1].votes++;
   }

   // Print out the results
   printf("Results:\n\n");
   for (int i = 0; i < num_candidates; i++) {
      printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
   }

   // Free the memory
   free(candidates);
   free(voters);
   return 0;
}