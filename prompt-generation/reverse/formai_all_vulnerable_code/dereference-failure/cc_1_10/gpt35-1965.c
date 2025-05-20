//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the candidate structure
typedef struct candidate {
    char name[20];                 // name of the candidate
    int votes;                     // number of votes received
} candidate;

// Define the election structure
typedef struct election {
    char name[20];                 // name of the election
    candidate* candidates;         // array of candidates
    int num_candidates;            // number of candidates
} election;

// Function to initialize the election
void init_election(election* e) {
    printf("Enter the name of the election: ");
    scanf("%s", e->name);

    printf("Enter the number of candidates: ");
    scanf("%d", &e->num_candidates);

    e->candidates = (candidate*) malloc(e->num_candidates * sizeof(candidate));

    for (int i = 0; i < e->num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", e->candidates[i].name);
        e->candidates[i].votes = 0;
    }
}

// Function to display the election information
void display_election(election* e) {
    printf("Election: %s\n", e->name);
    printf("Number of candidates: %d\n", e->num_candidates);
    for (int i = 0; i < e->num_candidates; i++) {
        printf("Candidate %d: %s\n", i+1, e->candidates[i].name);
    }
}

// Function to vote for a candidate
void vote(election* e, char* name) {
    int found = 0;
    for (int i = 0; i < e->num_candidates; i++) {
        if (strcmp(e->candidates[i].name, name) == 0) {
            e->candidates[i].votes++;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Invalid candidate name.\n");
    }
}

// Function to display the results of the election
void display_results(election* e) {
    printf("Results of election: %s\n", e->name);
    for (int i = 0; i < e->num_candidates; i++) {
        printf("%s: %d votes\n", e->candidates[i].name, e->candidates[i].votes);
    }
}

int main() {
    election e;
    init_election(&e);
    display_election(&e);

    printf("Enter the name of the candidate you want to vote for: ");
    char name[20];
    scanf("%s", name);
    vote(&e, name);

    display_results(&e);

    return 0;
}