//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: introspective
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

void insertVoter(Voter** head) {
    Voter* newVoter = malloc(sizeof(Voter));
    printf("Enter your name: ");
    scanf("%s", newVoter->name);
    newVoter->vote = 0;
    newVoter->next = NULL;

    if (*head == NULL) {
        *head = newVoter;
    } else {
        (*head)->next = newVoter;
    }
}

void vote(Voter** head) {
    printf("Enter the candidate number you want to vote for: ");
    int candidateNumber;
    scanf("%d", &candidateNumber);

    Voter* currentVoter = *head;
    while (currentVoter) {
        if (strcmp(currentVoter->name, (*head)->name) == 0) {
            currentVoter->vote = candidateNumber;
            break;
        }
        currentVoter = currentVoter->next;
    }

    if (currentVoter == NULL) {
        printf("Error: voter not found.\n");
    } else {
        printf("Thank you for voting, %s.\n", currentVoter->name);
    }
}

void displayResults(Voter** head) {
    int candidateVotes[MAX_CANDIDATES] = {0};
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidateVotes[i] = 0;
    }

    for (Voter* currentVoter = *head; currentVoter; currentVoter = currentVoter->next) {
        candidateVotes[currentVoter->vote]++;
    }

    printf("Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidateVotes[i] > 0) {
            printf("Candidate %d: %d votes\n", i, candidateVotes[i]);
        }
    }
}

int main() {
    Voter* head = NULL;
    insertVoter(&head);
    insertVoter(&head);
    insertVoter(&head);
    vote(&head);
    vote(&head);
    displayResults(&head);

    return 0;
}