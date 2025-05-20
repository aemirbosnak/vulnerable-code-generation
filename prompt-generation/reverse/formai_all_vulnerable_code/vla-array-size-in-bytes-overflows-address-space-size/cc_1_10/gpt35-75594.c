//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

int candidate_count;
char candidates[MAX_CANDIDATES][50];
int votes[MAX_VOTERS][MAX_CANDIDATES];
int num_voters;

pthread_mutex_t lock;

void *cast_vote(void *arg) {
  int *voter_id = (int*) arg;

  printf("Voter %d: Please select your candidate from below list:\n", *voter_id);
  for (int i = 0; i < candidate_count; i++) {
    printf("%d. %s\n", i+1, candidates[i]);
  }

  int choice = 0;
  scanf("%d", &choice);

  pthread_mutex_lock(&lock);
  votes[*voter_id][choice-1] = 1;
  pthread_mutex_unlock(&lock);

  printf("Voter %d: Voted for %s\n", *voter_id, candidates[choice-1]);

  return NULL;
}

void count_votes() {
  int total_votes[MAX_CANDIDATES] = {0};
  
  for (int i = 0; i < num_voters; i++) {
    for (int j = 0; j < candidate_count; j++) {
      if (votes[i][j] == 1) {
        total_votes[j]++;
      }
    }
  }

  printf("VOTES COUNTED:\n");
  for (int i = 0; i < candidate_count; i++) {
    printf("%s: %d\n", candidates[i], total_votes[i]);
  }
}

int main() {
  printf("Welcome to Electronic Voting System\n");

  //Taking candidate names as input
  printf("Please enter the number of candidates: ");
  scanf("%d", &candidate_count);

  for (int i = 0; i < candidate_count; i++) {
    printf("Enter the name of candidate %d: ", i+1);
    scanf("%s", candidates[i]);
  }

  //Taking the number of voters as input
  printf("Please enter the number of voters: ");
  scanf("%d", &num_voters);

  //Creating threads for each voter
  pthread_t threads[num_voters];

  for (int i = 0; i < num_voters; i++) {
    int *voter_id = malloc(sizeof(int));
    *voter_id = i;
    pthread_create(&threads[i], NULL, cast_vote, (void*) voter_id);
  }

  //Waiting for threads to complete
  for (int i = 0; i < num_voters; i++) {
    pthread_join(threads[i], NULL);
  }

  //Counting the votes
  count_votes();

  return 0;
}