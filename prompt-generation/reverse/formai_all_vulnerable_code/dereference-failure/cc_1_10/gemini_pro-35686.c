//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A structure to represent a candidate
typedef struct Candidate {
    char* name;
    int votes;
} Candidate;

// A structure to represent an election
typedef struct Election {
    Candidate** candidates;
    int numCandidates;
    int numVoters;
} Election;

// Function to create a new candidate
Candidate* createCandidate(char* name) {
    Candidate* candidate = malloc(sizeof(Candidate));
    candidate->name = name;
    candidate->votes = 0;
    return candidate;
}

// Function to create a new election
Election* createElection(int numCandidates) {
    Election* election = malloc(sizeof(Election));
    election->candidates = malloc(sizeof(Candidate*) * numCandidates);
    election->numCandidates = numCandidates;
    election->numVoters = 0;
    return election;
}

// Function to add a candidate to an election
void addCandidate(Election* election, Candidate* candidate) {
    election->candidates[election->numCandidates++] = candidate;
}

// Function to vote for a candidate in an election
void vote(Election* election, Candidate* candidate) {
    candidate->votes++;
    election->numVoters++;
}

// Function to print the results of an election
void printResults(Election* election) {
    printf("Election Results:\n");
    for (int i = 0; i < election->numCandidates; i++) {
        printf("%s: %d votes\n", election->candidates[i]->name, election->candidates[i]->votes);
    }
    printf("Total number of votes: %d\n", election->numVoters);
}

// Function to free the memory allocated for an election
void freeElection(Election* election) {
    for (int i = 0; i < election->numCandidates; i++) {
        free(election->candidates[i]);
    }
    free(election->candidates);
    free(election);
}

// Main function
int main() {
    // Create a new election with 3 candidates
    Election* election = createElection(3);

    // Add candidates to the election
    addCandidate(election, createCandidate("John Doe"));
    addCandidate(election, createCandidate("Jane Doe"));
    addCandidate(election, createCandidate("Bob Smith"));

    // Simulate 100 voters voting for the candidates
    for (int i = 0; i < 100; i++) {
        switch (rand() % 3) {
            case 0:
                vote(election, election->candidates[0]);
                break;
            case 1:
                vote(election, election->candidates[1]);
                break;
            case 2:
                vote(election, election->candidates[2]);
                break;
        }
    }

    // Print the results of the election
    printResults(election);

    // Free the memory allocated for the election
    freeElection(election);

    return 0;
}