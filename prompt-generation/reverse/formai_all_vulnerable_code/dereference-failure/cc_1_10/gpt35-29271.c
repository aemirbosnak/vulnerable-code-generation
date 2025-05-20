//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing candidate
struct Candidate {
    int id;
    char name[50];
    int votes;
};

// Function declarations
int castVote(struct Candidate c[], int n);
void addNewCandidate(struct Candidate c[], int *n);
void deleteCandidate(struct Candidate c[], int *n);
void displayCandidates(struct Candidate c[], int n);
void displayWinner(struct Candidate c[], int n);

int main() {
    printf("\nWelcome to the Electronic Voting System\n");
    int n, choice;
    printf("\nEnter the number of candidates: ");
    scanf("%d", &n);
    struct Candidate c[n];
    // Initialize candidates
    for(int i = 0; i < n; i++) {
        c[i].id = i + 1;
        printf("\nEnter name of candidate %d: ", i+1);
        scanf("%s", c[i].name);
        c[i].votes = 0;
    }
    do {
        printf("\nSelect one of the following options:\n");
        printf("1. Cast vote\n");
        printf("2. Add new candidate\n");
        printf("3. Delete candidate\n");
        printf("4. Display list of candidates\n");
        printf("5. Display winner\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                castVote(c, n);
                break;
            case 2:
                addNewCandidate(c, &n);
                break;
            case 3:
                deleteCandidate(c, &n);
                break;
            case 4:
                displayCandidates(c, n);
                break;
            case 5:
                displayWinner(c, n);
                break;
            case 6:
                printf("\nThank you for using Electronic Voting System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a valid choice!\n");
        }
    } while(choice != 6);
    return 0;
}

// Function to cast vote
int castVote(struct Candidate c[], int n) {
    int id, i, flag = 0;
    printf("\nEnter the candidate ID you want to vote for: ");
    scanf("%d", &id);
    for(i = 0; i < n; i++) {
        if(c[i].id == id) {
            flag = 1;
            c[i].votes++;
            printf("\nThank you for casting your vote to %s!\n", c[i].name);
            break;
        }
    }
    if(flag == 0) {
        printf("\nInvalid candidate ID! Please enter a valid candidate ID!\n");
    }
    return 0;
}

// Function to add new candidate
void addNewCandidate(struct Candidate c[], int *n) {
    (*n)++;
    c[*n-1].id = *n;
    printf("\nEnter name of new candidate: ");
    scanf("%s", c[*n-1].name);
    c[*n-1].votes = 0;
    printf("\nNew candidate added successfully!\n");
}

// Function to delete candidate
void deleteCandidate(struct Candidate c[], int *n) {
    int id, i, flag = 0;
    printf("\nEnter the candidate ID you want to delete: ");
    scanf("%d", &id);
    for(i = 0; i < *n; i++) {
        if(c[i].id == id) {
            flag = 1;
            for(int j = i; j < *n-1; j++) {
                c[j] = c[j+1];
            }
            (*n)--;
            printf("\nCandidate deleted successfully!\n");
            break;
        }
    }
    if(flag == 0) {
        printf("\nInvalid candidate ID! Please enter a valid candidate ID!\n");
    }
}

// Function to display list of candidates
void displayCandidates(struct Candidate c[], int n) {
    printf("\nList of candidates:\n");
    printf("\nID\tName\t\tVotes\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%d\n", c[i].id, c[i].name, c[i].votes);
    }
}

// Function to display winner
void displayWinner(struct Candidate c[], int n) {
    int max_id, max_votes = -1;
    for(int i = 0; i < n; i++) {
        if(c[i].votes > max_votes) {
            max_id = c[i].id;
            max_votes = c[i].votes;
        }
    }
    printf("\nThe winner is candidate with ID: %d and name: %s with %d votes!\n", max_id, c[max_id-1].name, max_votes);
}