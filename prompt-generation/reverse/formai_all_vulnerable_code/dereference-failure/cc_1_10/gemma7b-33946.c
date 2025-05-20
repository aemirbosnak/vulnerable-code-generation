//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: intelligent
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
    char title[50];
    Voter* head;
    int votes[MAX_CANDIDATES];
    struct Poll* next;
} Poll;

void addVoter(Poll* poll, char* name, int vote) {
    Voter* newVoter = (Voter*)malloc(sizeof(Voter));
    strcpy(newVoter->name, name);
    newVoter->vote = vote;
    newVoter->next = NULL;

    if (poll->head == NULL) {
        poll->head = newVoter;
    } else {
        poll->head->next = newVoter;
        poll->head = newVoter;
    }
}

void castVote(Poll* poll, char* voterName, int candidate) {
    Voter* voter = poll->head;
    while (voter) {
        if (strcmp(voter->name, voterName) == 0) {
            if (voter->vote == candidate) {
                printf("Error: You have already voted for this candidate.\n");
            } else {
                voter->vote = candidate;
                printf("Vote cast successfully.\n");
            }
            break;
        }
        voter = voter->next;
    }

    if (voter == NULL) {
        printf("Error: Voter not found.\n");
    }
}

void printResults(Poll* poll) {
    int i = 0;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", poll->votes[i], poll->votes[i]);
    }

    printf("Total votes: %d\n", poll->head->vote);
}

int main() {
    Poll* poll = (Poll*)malloc(sizeof(Poll));
    strcpy(poll->title, "Example Election");
    poll->head = NULL;
    poll->votes[0] = 0;
    poll->votes[1] = 0;
    poll->votes[2] = 0;
    poll->votes[3] = 0;
    poll->votes[4] = 0;

    addVoter(poll, "John Doe", 1);
    addVoter(poll, "Jane Doe", 2);
    addVoter(poll, "Peter Pan", 3);
    addVoter(poll, "Mary Poppins", 2);
    addVoter(poll, "The Wizard of Oz", 4);

    castVote(poll, "John Doe", 3);
    castVote(poll, "Jane Doe", 2);
    castVote(poll, "Peter Pan", 1);
    castVote(poll, "Mary Poppins", 2);
    castVote(poll, "The Wizard of Oz", 4);

    printResults(poll);

    return 0;
}