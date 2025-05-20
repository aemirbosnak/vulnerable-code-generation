//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of voters
#define MAX_VOTERS 1000

// Define the structure of a voter
typedef struct Voter {
    char name[50];
    int vote;
    struct Voter* next;
} Voter;

// Create a linked list of voters
Voter* createVoterList() {
    Voter* head = NULL;
    head = malloc(sizeof(Voter));
    head->name[0] = '\0';
    head->vote = -1;
    head->next = NULL;
    return head;
}

// Add a voter to the list
void addVoter(Voter* head, char* name, int vote) {
    Voter* newVoter = malloc(sizeof(Voter));
    newVoter->name[0] = '\0';
    strcpy(newVoter->name, name);
    newVoter->vote = vote;
    newVoter->next = NULL;

    if (head->next == NULL) {
        head->next = newVoter;
    } else {
        head->next->next = newVoter;
    }
}

// Vote for a candidate
void vote(Voter* head, int candidate) {
    for (Voter* currentVoter = head; currentVoter->next != NULL; currentVoter = currentVoter->next) {
        if (strcmp(currentVoter->name, "John Doe") == 0) {
            currentVoter->vote = candidate;
            break;
        }
    }
}

// Print the results of the election
void printResults(Voter* head) {
    int totalVotes = 0;
    for (Voter* currentVoter = head; currentVoter->next != NULL; currentVoter = currentVoter->next) {
        totalVotes++;
    }

    printf("Total votes: %d\n", totalVotes);

    int candidateVotes[5] = {0};
    for (Voter* currentVoter = head; currentVoter->next != NULL; currentVoter = currentVoter->next) {
        candidateVotes[currentVoter->vote]++;
    }

    printf("Candidate votes:\n");
    for (int i = 0; i < 5; i++) {
        printf("Candidate %d: %d votes\n", i, candidateVotes[i]);
    }

    int winner = -1;
    for (int i = 0; i < 5; i++) {
        if (candidateVotes[i] > candidateVotes[winner]) {
            winner = i;
        }
    }

    printf("Winner: Candidate %d\n", winner);
}

int main() {
    Voter* head = createVoterList();
    addVoter(head, "John Doe", 1);
    addVoter(head, "Jane Doe", 2);
    addVoter(head, "Bob Smith", 3);
    addVoter(head, "Alice White", 4);

    vote(head, 2);
    vote(head, 1);
    vote(head, 3);

    printResults(head);

    return 0;
}