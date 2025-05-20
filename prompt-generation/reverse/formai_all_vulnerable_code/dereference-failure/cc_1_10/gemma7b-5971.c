//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
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

typedef struct Ballot {
    char candidate[MAX_CANDIDATES][50];
    int votes[MAX_CANDIDATES];
    struct Ballot* next;
} Ballot;

void addVoter(Voter** head) {
    Voter* newVoter = (Voter*)malloc(sizeof(Voter));
    printf("Enter your name: ");
    scanf("%s", newVoter->name);
    newVoter->vote = 0;
    newVoter->next = *head;
    *head = newVoter;
}

void addBallot(Ballot** head) {
    Ballot* newBallot = (Ballot*)malloc(sizeof(Ballot));
    printf("Enter the name of candidate 1: ");
    scanf("%s", newBallot->candidate[0]);
    printf("Enter the name of candidate 2: ");
    scanf("%s", newBallot->candidate[1]);
    printf("Enter the name of candidate 3: ");
    scanf("%s", newBallot->candidate[2]);
    newBallot->votes[0] = 0;
    newBallot->votes[1] = 0;
    newBallot->votes[2] = 0;
    newBallot->next = *head;
    *head = newBallot;
}

void vote(Voter* head, Ballot* headB) {
    printf("Enter the number of the candidate you want to vote for: ");
    int candidateNumber = 0;
    scanf("%d", &candidateNumber);

    for (Voter* currentVoter = head; currentVoter; currentVoter = currentVoter->next) {
        if (strcmp(currentVoter->name, headB->candidate[candidateNumber - 1]) == 0) {
            currentVoter->vote = candidateNumber;
            headB->votes[candidateNumber - 1]++;
            break;
        }
    }
}

void displayResults(Ballot* head) {
    printf("The results of the election are:\n");
    for (Ballot* currentBallot = head; currentBallot; currentBallot = currentBallot->next) {
        printf("%s received %d votes.\n", currentBallot->candidate[0], currentBallot->votes[0]);
        printf("%s received %d votes.\n", currentBallot->candidate[1], currentBallot->votes[1]);
        printf("%s received %d votes.\n", currentBallot->candidate[2], currentBallot->votes[2]);
    }
}

int main() {
    Voter* head = NULL;
    Ballot* headB = NULL;

    addVoter(&head);
    addVoter(&head);
    addVoter(&head);
    addBallot(&headB);
    addBallot(&headB);
    addBallot(&headB);

    vote(head, headB);
    vote(head, headB);
    vote(head, headB);

    displayResults(headB);

    return 0;
}