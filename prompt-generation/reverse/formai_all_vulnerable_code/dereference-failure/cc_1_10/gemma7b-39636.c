//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CANDIDATES 3
#define NUM_VOTES 100

typedef struct Voter {
    char name[20];
    int vote;
    struct Voter* next;
} Voter;

Voter* createVoter(char* name, int vote) {
    Voter* newVoter = (Voter*)malloc(sizeof(Voter));
    strcpy(newVoter->name, name);
    newVoter->vote = vote;
    newVoter->next = NULL;
    return newVoter;
}

void addVoter(Voter* head, char* name, int vote) {
    Voter* newVoter = createVoter(name, vote);
    if (head == NULL) {
        head = newVoter;
    } else {
        head->next = newVoter;
    }
}

void vote(Voter* head) {
    printf("Please vote for a candidate:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%d. %s\n", i + 1, head->name);
    }
    int voteNumber;
    scanf("%d", &voteNumber);
    head->vote = voteNumber;
}

int main() {
    Voter* head = NULL;
    addVoter(head, "Romeo", 1);
    addVoter(head, "Juliet", 2);
    addVoter(head, "Benvolio", 3);

    vote(head);

    printf("Results:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s won %d votes\n", head->name, head->vote);
    }

    return 0;
}