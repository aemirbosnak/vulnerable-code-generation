//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Candidate {
    char name[50];
    int votes;
    struct Candidate* next;
} Candidate;

typedef struct Voter {
    char name[50];
    int hasVoted;
    struct Voter* next;
} Voter;

Candidate* candidateList = NULL;
Voter* voterList = NULL;

void addCandidate();
void registerVoter();
void castVote();
void showResults();
void freeMemory();

int main() {
    int choice;
    while (1) {
        printf("\n***** Electronic Voting System *****\n");
        printf("1. Add Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Show Results\n");
        printf("5. Exit\n");
        printf("************************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addCandidate();
                break;
            case 2: 
                registerVoter();
                break;
            case 3: 
                castVote();
                break;
            case 4: 
                showResults();
                break;
            case 5: 
                freeMemory();
                printf("Exiting...\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addCandidate() {
    Candidate* newCandidate = (Candidate*)malloc(sizeof(Candidate));
    printf("Enter candidate name: ");
    scanf("%s", newCandidate->name);
    newCandidate->votes = 0;
    newCandidate->next = candidateList;
    candidateList = newCandidate;
    printf("Candidate '%s' added successfully!\n", newCandidate->name);
}

void registerVoter() {
    Voter* newVoter = (Voter*)malloc(sizeof(Voter));
    printf("Enter voter name: ");
    scanf("%s", newVoter->name);
    newVoter->hasVoted = 0;
    newVoter->next = voterList;
    voterList = newVoter;
    printf("Voter '%s' registered successfully!\n", newVoter->name);
}

void castVote() {
    char voterName[50];
    printf("Enter your name to vote: ");
    scanf("%s", voterName);

    Voter* currentVoter = voterList;
    while (currentVoter != NULL) {
        if (strcmp(currentVoter->name, voterName) == 0) {
            if (currentVoter->hasVoted) {
                printf("You have already cast your vote!\n");
                return;
            }
            break;
        }
        currentVoter = currentVoter->next;
    }

    if (currentVoter == NULL) {
        printf("Voter not found! Please register first.\n");
        return;
    }

    char candidateName[50];
    printf("Enter candidate name to vote for: ");
    scanf("%s", candidateName);

    Candidate* currentCandidate = candidateList;
    while (currentCandidate != NULL) {
        if (strcmp(currentCandidate->name, candidateName) == 0) {
            currentCandidate->votes++;
            currentVoter->hasVoted = 1;
            printf("Vote for '%s' cast successfully!\n", currentCandidate->name);
            return;
        }
        currentCandidate = currentCandidate->next;
    }
    printf("Candidate not found!\n");
}

void showResults() {
    printf("\n***** Voting Results *****\n");
    Candidate* currentCandidate = candidateList;
    if (currentCandidate == NULL) {
        printf("No candidates available.\n");
        return;
    }
    while (currentCandidate != NULL) {
        printf("Candidate: %s | Votes: %d\n", currentCandidate->name, currentCandidate->votes);
        currentCandidate = currentCandidate->next;
    }
}

void freeMemory() {
    Candidate* currentCandidate = candidateList;
    while (currentCandidate != NULL) {
        Candidate* temp = currentCandidate;
        currentCandidate = currentCandidate->next;
        free(temp);
    }

    Voter* currentVoter = voterList;
    while (currentVoter != NULL) {
        Voter* temp = currentVoter;
        currentVoter = currentVoter->next;
        free(temp);
    }
}