//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

struct candidate {
   char name[20];
   int vote_count;
};

void cast_vote(struct candidate *candidates, int num_candidates) {
   int choice;
   printf("\nChoose a candidate:\n");
   for(int i=0; i<num_candidates; i++) {
      printf("%d. %s\n", i+1, candidates[i].name);
   }
   scanf("%d", &choice);
   candidates[choice-1].vote_count++;
   printf("\nThank you for casting your vote.\n");
}

void display_results(struct candidate *candidates, int num_candidates) {
   printf("\nVote count results:\n");
   for(int i=0; i<num_candidates; i++) {
      printf("%s: %d\n", candidates[i].name, candidates[i].vote_count);
   }
}

int main() {
   int num_candidates;
   printf("Enter the number of candidates: ");
   scanf("%d", &num_candidates);

   struct candidate *candidates = malloc(sizeof(struct candidate)*num_candidates);
   for(int i=0; i<num_candidates; i++) {
      printf("Enter the name of candidate %d: ", i+1);
      scanf("%s", candidates[i].name);
      candidates[i].vote_count = 0;
   }

   int num_votes;
   printf("\nEnter the number of votes: ");
   scanf("%d", &num_votes);
   for(int i=0; i<num_votes; i++) {
      printf("\nVoter %d: ", i+1);
      cast_vote(candidates, num_candidates);
   }

   display_results(candidates, num_candidates);
   free(candidates);
   return 0;
}