//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
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

void insertVoter(Voter** head, char* name, int vote) {
    Voter* newVoter = malloc(sizeof(Voter));
    strcpy(newVoter->name, name);
    newVoter->vote = vote;
    newVoter->next = NULL;

    if (*head == NULL) {
        *head = newVoter;
    } else {
        (*head)->next = newVoter;
    }
}

void insertPoll(Poll** head, char* candidate, int votes) {
    Poll* newPoll = malloc(sizeof(Poll));
    strcpy(newPoll->candidate[0], candidate);
    newPoll->votes[0] = votes;
    newPoll->next = NULL;

    if (*head == NULL) {
        *head = newPoll;
    } else {
        (*head)->next = newPoll;
    }
}

void vote(Voter* head, char* candidate) {
    for (Voter* voter = head; voter; voter = voter->next) {
        if (strcmp(voter->name, candidate) == 0) {
            voter->vote++;
        }
    }
}

int main() {
    Voter* head = NULL;
    Poll* headPoll = NULL;

    insertVoter(&head, "John Doe", 10);
    insertVoter(&head, "Jane Doe", 8);
    insertVoter(&head, "Peter Pan", 6);

    insertPoll(&headPoll, "Mr. A", 50);
    insertPoll(&headPoll, "Ms. B", 20);
    insertPoll(&headPoll, "Mr. C", 30);

    vote(head, "Mr. A");
    vote(head, "Ms. B");

    for (Voter* voter = head; voter; voter = voter->next) {
        printf("%s has voted %d times.\n", voter->name, voter->vote);
    }

    for (Poll* poll = headPoll; poll; poll = poll->next) {
        printf("%s has received %d votes.\n", poll->candidate[0], poll->votes[0]);
    }

    return 0;
}