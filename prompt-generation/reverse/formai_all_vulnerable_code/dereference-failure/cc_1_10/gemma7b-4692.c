//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the voter structure
typedef struct Voter {
    char name[50];
    int vote;
    struct Voter* next;
} Voter;

// Define the ballot structure
typedef struct Ballot {
    char candidate[50];
    int votes;
    struct Ballot* next;
} Ballot;

// Function to insert a voter into the voter list
void insertVoter(Voter** head, char* name, int vote) {
    Voter* newVoter = (Voter*)malloc(sizeof(Voter));
    strcpy(newVoter->name, name);
    newVoter->vote = vote;
    newVoter->next = NULL;

    if (*head == NULL) {
        *head = newVoter;
    } else {
        (*head)->next = newVoter;
    }
}

// Function to insert a ballot into the ballot list
void insertBallot(Ballot** head, char* candidate, int votes) {
    Ballot* newBallot = (Ballot*)malloc(sizeof(Ballot));
    strcpy(newBallot->candidate, candidate);
    newBallot->votes = votes;
    newBallot->next = NULL;

    if (*head == NULL) {
        *head = newBallot;
    } else {
        (*head)->next = newBallot;
    }
}

// Function to vote
void vote(Voter* head, Ballot** headBallot) {
    char* voterName;
    printf("Enter your name: ");
    scanf("%s", voterName);

    Voter* currentVoter = head;
    while (currentVoter) {
        if (strcmp(currentVoter->name, voterName) == 0) {
            printf("You have already voted.\n");
            return;
        }
        currentVoter = currentVoter->next;
    }

    char* candidate;
    printf("Enter the candidate you want to vote for: ");
    scanf("%s", candidate);

    Ballot* currentBallot = *headBallot;
    while (currentBallot) {
        if (strcmp(currentBallot->candidate, candidate) == 0) {
            currentBallot->votes++;
            printf("Your vote has been recorded.\n");
            return;
        }
        currentBallot = currentBallot->next;
    }

    printf("Error: invalid vote.\n");
}

// Main function
int main() {
    Voter* head = NULL;
    Ballot* headBallot = NULL;

    insertVoter(&head, "John Doe", 1);
    insertVoter(&head, "Jane Doe", 2);
    insertBallot(&headBallot, "Candidate A", 50);
    insertBallot(&headBallot, "Candidate B", 30);

    vote(head, &headBallot);

    return 0;
}