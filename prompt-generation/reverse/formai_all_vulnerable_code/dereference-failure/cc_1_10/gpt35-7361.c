//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multi-threaded
//Multi-threaded Electronic Voting System Example

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//structure to hold candidate information
struct Candidate {
    int id;
    char* name;
    int votes;
};

//global variables
int NUM_CANDIDATES = 3;
int NUM_VOTERS = 5;
int* voteList; //keep track of each voter's vote (-1 = not voted yet)
struct Candidate* candidateList; //array of candidates
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //initialize mutex

//initialize candidate list
void initCandidateList() {
    candidateList = (struct Candidate*) malloc(NUM_CANDIDATES * sizeof(struct Candidate));
    candidateList[0].id = 1;
    candidateList[0].name = "John Doe";
    candidateList[0].votes = 0;
    candidateList[1].id = 2;
    candidateList[1].name = "Jane Smith";
    candidateList[1].votes = 0;
    candidateList[2].id = 3;
    candidateList[2].name = "Bob Johnson";
    candidateList[2].votes = 0;
}

//initialize vote list
void initVoteList() {
    voteList = (int*) malloc(NUM_VOTERS * sizeof(int));
    for (int i = 0; i < NUM_VOTERS; i++) {
        voteList[i] = -1; //not voted yet
    }
}

//cast a vote
void castVote(int voterId, int candidateId) {
    pthread_mutex_lock(&mutex); //lock mutex
    if (voteList[voterId] == -1) { //if voter has not voted yet
        candidateList[candidateId - 1].votes++; //increment candidate's vote count
        voteList[voterId] = candidateId; //mark voter as voted for candidate
        printf("Voter %d cast their vote for candidate %d (%s)\n", voterId, candidateId, candidateList[candidateId - 1].name);
    } else {
        printf("Voter %d has already cast their vote for candidate %d (%s)\n", voterId, voteList[voterId], candidateList[voteList[voterId] - 1].name);
    }
    pthread_mutex_unlock(&mutex); //unlock mutex
}

//determine winner
void determineWinner() {
    int winnerIndex = 0;
    for (int i = 1; i < NUM_CANDIDATES; i++) {
        if (candidateList[i].votes > candidateList[winnerIndex].votes) {
            winnerIndex = i; //update winner index
        }
    }
    printf("\nThe winner is %s with %d votes!\n", candidateList[winnerIndex].name, candidateList[winnerIndex].votes);
}

//voter thread function
void* voterThread(void* arg) {
    int voterId = *(int*) arg; //extract voter id from argument
    int candidateId = rand() % NUM_CANDIDATES + 1; //generate random candidate id
    castVote(voterId, candidateId); //cast vote
    pthread_exit(NULL); //exit thread
}

//main function
int main() {
    //initialize candidate list and vote list
    initCandidateList();
    initVoteList();

    //create voter threads
    pthread_t voterThreads[NUM_VOTERS];
    int voterIds[NUM_VOTERS];
    for (int i = 0; i < NUM_VOTERS; i++) {
        voterIds[i] = i;
        pthread_create(&voterThreads[i], NULL, voterThread, &voterIds[i]);
    }

    //wait for voter threads to complete
    for (int i = 0; i < NUM_VOTERS; i++) {
        pthread_join(voterThreads[i], NULL);
    }

    //determine winner
    determineWinner();

    //free memory and exit program
    free(candidateList);
    free(voteList);
    pthread_mutex_destroy(&mutex);
    return 0;
}