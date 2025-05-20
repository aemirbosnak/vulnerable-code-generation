//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
    char name[50];
    int vote;
    struct Voter* next;
} Voter;

typedef struct Poll {
    char candidate[MAX_CANDIDATES][50];
    int votes[MAX_CANDIDATES];
    struct Poll* next;
} Poll;

Voter* createVoter(char* name, int vote) {
    Voter* newVoter = malloc(sizeof(Voter));
    strcpy(newVoter->name, name);
    newVoter->vote = vote;
    newVoter->next = NULL;
    return newVoter;
}

Poll* createPoll(char* candidate, int votes) {
    Poll* newPoll = malloc(sizeof(Poll));
    strcpy(newPoll->candidate, candidate);
    newPoll->votes[0] = votes;
    newPoll->next = NULL;
    return newPoll;
}

void vote(Poll* poll, Voter* voter) {
    int i = 0;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (strcmp(voter->name, poll->candidate[i]) == 0) {
            poll->votes[i]++;
            break;
        }
    }
}

void displayResults(Poll* poll) {
    int i = 0;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s received %d votes\n", poll->candidate[i], poll->votes[i]);
    }
}

int main() {
    Voter* head = createVoter("John Doe", 1);
    Voter* tail = head;
    tail = createVoter("Jane Doe", 2);
    tail->next = head;
    tail = createVoter("Peter Pan", 3);
    tail->next = head;

    Poll* poll = createPoll("Mr. A", 50);
    Poll* pollTail = poll;
    pollTail = createPoll("Ms. B", 30);
    pollTail->next = poll;
    pollTail = createPoll("Mr. C", 20);
    pollTail->next = poll;

    vote(poll, head);
    vote(poll, tail);

    displayResults(poll);

    return 0;
}