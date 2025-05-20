//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define the number of candidates and voters
#define NUM_CANDIDATES 3
#define NUM_VOTERS 10

// Define the candidate names
char *candidateNames[] = {"Ada Lovelace", "Charles Babbage", "Alan Turing"};

// Define the voter names
char *voterNames[] = {"Grace Hopper", "Margaret Hamilton", "Edsger Dijkstra", "Niklaus Wirth", "Dennis Ritchie", "Bjarne Stroustrup", "Guido van Rossum", "Linus Torvalds", "Tim Berners-Lee", "Larry Page"};

// Define the vote structure
typedef struct {
    int candidateID;
    int voterID;
} Vote;

// Define the voting system structure
typedef struct {
    Vote votes[NUM_VOTERS];
    int numVotes[NUM_CANDIDATES];
} VotingSystem;

// Create a new voting system
VotingSystem* createVotingSystem() {
    VotingSystem *votingSystem = malloc(sizeof(VotingSystem));
    for (int i = 0; i < NUM_VOTERS; i++) {
        votingSystem->votes[i].candidateID = -1;
        votingSystem->votes[i].voterID = -1;
    }
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        votingSystem->numVotes[i] = 0;
    }
    return votingSystem;
}

// Cast a vote
void castVote(VotingSystem *votingSystem, int voterID, int candidateID) {
    if (voterID < 0 || voterID >= NUM_VOTERS) {
        printf("Invalid voter ID\n");
        return;
    }
    if (candidateID < 0 || candidateID >= NUM_CANDIDATES) {
        printf("Invalid candidate ID\n");
        return;
    }
    votingSystem->votes[voterID].candidateID = candidateID;
    votingSystem->votes[voterID].voterID = voterID;
    votingSystem->numVotes[candidateID]++;
}

// Get the number of votes for a candidate
int getNumVotes(VotingSystem *votingSystem, int candidateID) {
    if (candidateID < 0 || candidateID >= NUM_CANDIDATES) {
        printf("Invalid candidate ID\n");
        return -1;
    }
    return votingSystem->numVotes[candidateID];
}

// Get the winner of the election
int getWinner(VotingSystem *votingSystem) {
    int maxVotes = 0;
    int winnerID = -1;
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        if (votingSystem->numVotes[i] > maxVotes) {
            maxVotes = votingSystem->numVotes[i];
            winnerID = i;
        }
    }
    return winnerID;
}

// Print the voting system
void printVotingSystem(VotingSystem *votingSystem) {
    printf("Voting System\n\n");
    printf("Candidates:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%d. %s\n", i+1, candidateNames[i]);
    }
    printf("\nVoters:\n");
    for (int i = 0; i < NUM_VOTERS; i++) {
        printf("%d. %s\n", i+1, voterNames[i]);
    }
    printf("\nVotes:\n");
    for (int i = 0; i < NUM_VOTERS; i++) {
        printf("Voter %d: %s\n", votingSystem->votes[i].voterID+1, candidateNames[votingSystem->votes[i].candidateID]);
    }
    printf("\nResults:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidateNames[i], votingSystem->numVotes[i]);
    }
    int winnerID = getWinner(votingSystem);
    printf("\nWinner: %s\n", candidateNames[winnerID]);
}

// Main function
int main() {
    // Create a new voting system
    VotingSystem *votingSystem = createVotingSystem();

    // Cast some votes
    castVote(votingSystem, 0, 0);
    castVote(votingSystem, 1, 1);
    castVote(votingSystem, 2, 2);
    castVote(votingSystem, 3, 0);
    castVote(votingSystem, 4, 1);
    castVote(votingSystem, 5, 2);
    castVote(votingSystem, 6, 0);
    castVote(votingSystem, 7, 1);
    castVote(votingSystem, 8, 2);
    castVote(votingSystem, 9, 0);

    // Print the voting system
    printVotingSystem(votingSystem);

    // Free the voting system
    free(votingSystem);

    return 0;
}