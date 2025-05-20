//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a voter
typedef struct Voter {
    char name[50];
    int vote;
} Voter;

// Define the function to add a voter
void addVoter(Voter **v, int *n) {
    *v = malloc((*n) * sizeof(Voter));
    (*v)->vote = 0;
    printf("Enter voter name: ");
    scanf((*v)->name, 50);
    (*n)++;
}

// Define the function to vote
void vote(Voter **v, int *n) {
    int i;
    printf("Enter vote for candidate 1-3: ");
    scanf(&i);
    for (i = 0; i < *n; i++) {
        if ((*v)[i].name == "John Doe") {
            ((*v)[i].vote)++;
        }
    }
}

// Define the function to tally votes
void tallyVotes(Voter **v, int *n) {
    int i, totalVotes = 0;
    for (i = 0; i < *n; i++) {
        totalVotes += (*v)[i].vote;
    }
    printf("Total votes: %d", totalVotes);
}

int main() {
    Voter *v = NULL;
    int n = 0;
    addVoter(&v, &n);
    addVoter(&v, &n);
    vote(&v, &n);
    vote(&v, &n);
    tallyVotes(&v, &n);
    return 0;
}