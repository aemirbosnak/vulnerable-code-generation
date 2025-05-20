//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 10

typedef struct {
    int id;
    char name[50];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int totalVotes = 0;
pthread_mutex_t voteLock;

void* vote(void* args) {
    int voterId = *(int*)args;
    for (int i = 0; i < 3; i++) { // Each voter votes 3 times
        int candidateId = rand() % MAX_CANDIDATES;

        pthread_mutex_lock(&voteLock);
        candidates[candidateId].votes++;
        totalVotes++;
        printf("Voter %d voted for Candidate %d (%s)\n", voterId, candidates[candidateId].id, candidates[candidateId].name);
        pthread_mutex_unlock(&voteLock);
        
        sleep(1); // Simulate time taken to cast a vote
    }
    pthread_exit(NULL);
}

void displayResults() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("Candidate %d (%s) has %d votes.\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
    printf("Total Votes Cast: %d\n", totalVotes);
}

int main() {
    // Initialize candidates
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].id = i;
        snprintf(candidates[i].name, sizeof(candidates[i].name), "Candidate %d", i + 1);
        candidates[i].votes = 0;
    }

    pthread_t voters[MAX_VOTERS];
    pthread_mutex_init(&voteLock, NULL);
    srand(time(NULL));

    printf("Welcome to the Electronic Voting System\n");
    
    // Create voter threads
    for (int i = 0; i < MAX_VOTERS; i++) {
        int* voterId = malloc(sizeof(int));
        *voterId = i + 1; // Assign unique ID to each voter
        pthread_create(&voters[i], NULL, vote, voterId);
    }

    // Wait for all votes to be cast
    for (int i = 0; i < MAX_VOTERS; i++) {
        pthread_join(voters[i], NULL);
    }

    // Display results
    displayResults();

    // Clean up
    pthread_mutex_destroy(&voteLock);
    return 0;
}