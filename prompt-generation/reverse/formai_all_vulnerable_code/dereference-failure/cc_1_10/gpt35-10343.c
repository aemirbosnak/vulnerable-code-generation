//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

// number of candidates
#define NUM_CANDIDATES 4

// number of voting stations
#define NUM_STATIONS 3

// structure for storing candidate information
typedef struct {
    int id; // unique identifier
    char name[20]; // name of candidate
    int num_votes; // number of votes
} candidate_t;

// array of candidates
candidate_t candidates[NUM_CANDIDATES] = {
    {1, "John Smith", 0},
    {2, "Mary Johnson", 0},
    {3, "Bob Williams", 0},
    {4, "Lisa Davis", 0}
};

// function to initialize candidate array
void init_candidates() {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        candidates[i].num_votes = 0;
    }
}

// structure for storing station information
typedef struct {
    int id; // unique identifier
    int votes[NUM_CANDIDATES]; // number of votes for each candidate
} station_t;

// array of stations
station_t stations[NUM_STATIONS];

// function to initialize station array
void init_stations() {
    for (int i = 0; i < NUM_STATIONS; i++) {
        stations[i].id = i;
        for (int j = 0; j < NUM_CANDIDATES; j++) {
            stations[i].votes[j] = 0;
        }
    }
}

// function for voting process
void cast_vote(int candidate_id, int station_id) {
    stations[station_id].votes[candidate_id - 1]++;
    candidates[candidate_id - 1].num_votes++;
}

// function to print candidate information
void print_candidates() {
    printf("Candidate Information:\n");
    printf("ID\tName\t\tVotes\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%d\t%s\t\t%d\n", candidates[i].id, candidates[i].name, candidates[i].num_votes);
    }
}

// function to print station information
void print_stations() {
    printf("Station Information:\n");
    printf("ID\tCandidate 1\tCandidate 2\tCandidate 3\tCandidate 4\n");
    for (int i = 0; i < NUM_STATIONS; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", stations[i].id, stations[i].votes[0], stations[i].votes[1], stations[i].votes[2], stations[i].votes[3]);
    }
}

// structure for storing thread arguments
typedef struct {
    int candidate_id;
    int station_id;
} thread_args_t;

// function for voting thread
void *vote_thread(void *args) {
    thread_args_t *thread_args = (thread_args_t *) args;
    cast_vote(thread_args->candidate_id, thread_args->station_id);
    free(thread_args);
    return NULL;
}

// function to run simulation
void run_sim() {
    // initialize arrays
    init_candidates();
    init_stations();

    // create threads for each vote
    pthread_t threads[NUM_CANDIDATES][NUM_STATIONS];
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        for (int j = 0; j < NUM_STATIONS; j++) {
            thread_args_t *args = malloc(sizeof(thread_args_t));
            args->candidate_id = i + 1;
            args->station_id = j;
            pthread_create(&threads[i][j], NULL, vote_thread, (void *) args);
        }
    }

    // join threads
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        for (int j = 0; j < NUM_STATIONS; j++) {
            pthread_join(threads[i][j], NULL);
        }
    }

    // print results
    print_candidates();
    print_stations();
}

int main() {
    run_sim();
    return 0;
}