//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int vote_count;
} Candidate;

typedef struct {
    int voter_id;
    int candidate_id;
} Vote;

Candidate candidates[MAX_CANDIDATES];
Vote votes[MAX_VOTERS];
int total_voters = 0;
pthread_mutex_t vote_mutex;

void initialize_candidates() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        snprintf(candidates[i].name, sizeof(candidates[i].name), "Candidate %d", i + 1);
        candidates[i].vote_count = 0;
    }
}

void* cast_vote(void* arg) {
    int voter_id = *(int*)arg;

    if (voter_id < 0 || voter_id >= MAX_VOTERS) {
        printf("Invalid voter ID: %d\n", voter_id);
        return NULL;
    }

    printf("Voter %d, please vote for a candidate (1-%d): ", voter_id + 1, MAX_CANDIDATES);
    int candidate_id;
    scanf("%d", &candidate_id);

    if (candidate_id < 1 || candidate_id > MAX_CANDIDATES) {
        printf("Invalid candidate ID. Voter %d did not vote.\n", voter_id + 1);
        return NULL;
    }

    pthread_mutex_lock(&vote_mutex);
    votes[voter_id].voter_id = voter_id;
    votes[voter_id].candidate_id = candidate_id - 1;    // Store index
    candidates[candidate_id - 1].vote_count++;
    pthread_mutex_unlock(&vote_mutex);

    printf("Voter %d voted for %s\n", voter_id + 1, candidates[candidate_id - 1].name);
    return NULL;
}

void display_results() {
    printf("\nVoting results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
}

int main() {
    pthread_mutex_init(&vote_mutex, NULL);
    initialize_candidates();

    printf("Welcome to the Decentralized Electronic Voting System!\n");
    printf("A total of %d voters can cast their votes.\n", MAX_VOTERS);

    pthread_t threads[MAX_VOTERS];

    for (int i = 0; i < MAX_VOTERS; i++) {
        int* voter_id = malloc(sizeof(int));
        *voter_id = i;
        pthread_create(&threads[i], NULL, cast_vote, voter_id);
        sleep(1);  // Simulate delay for interactive voting
        total_voters++;
    }

    for (int i = 0; i < MAX_VOTERS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    display_results();

    pthread_mutex_destroy(&vote_mutex);
    return 0;
}