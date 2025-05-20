//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
    char name[20];
    int vote;
    struct Voter* next;
} Voter;

typedef struct Poll {
    char candidate[MAX_CANDIDATES][20];
    int votes[MAX_CANDIDATES];
    struct Poll* next;
} Poll;

Voter* createVoter(char* name, int vote) {
    Voter* voter = malloc(sizeof(Voter));
    strcpy(voter->name, name);
    voter->vote = vote;
    voter->next = NULL;
    return voter;
}

Poll* createPoll() {
    Poll* poll = malloc(sizeof(Poll));
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        poll->candidate[i][0] = '\0';
        poll->votes[i] = 0;
    }
    poll->next = NULL;
    return poll;
}

void vote(Poll* poll, Voter* voter) {
    int candidateVote = voter->vote - 1;
    if (candidateVote >= 0 && candidateVote < MAX_CANDIDATES) {
        poll->votes[candidateVote]++;
    }
}

int main() {
    time_t t = time(NULL);
    srand(t);

    Poll* poll = createPoll();

    // Create a bunch of voters
    Voter* head = createVoter("John Doe", rand() % MAX_VOTES);
    head->next = createVoter("Jane Doe", rand() % MAX_VOTES);
    head->next->next = createVoter("Peter Pan", rand() % MAX_VOTES);

    // Vote
    vote(poll, head);

    // Print the results
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", poll->candidate[i], poll->votes[i]);
    }

    return 0;
}