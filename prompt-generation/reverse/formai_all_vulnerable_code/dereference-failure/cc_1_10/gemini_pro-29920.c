//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: artistic
// A symphony of democracy, where electrons dance to shape our fate

#include <stdio.h>
#include <stdlib.h>

// The tapestry of choices, each thread a voter's voice
char **candidates;
int numCandidates;

// The ebb and flow of votes, shaping the destiny of our nation
int *votes;

// Prelude: Initialize our electoral canvas
void init(char **cand, int num) {
    candidates = cand;
    numCandidates = num;
    votes = malloc(sizeof(int) * numCandidates);
    memset(votes, 0, sizeof(int) * numCandidates);
}

// Interlude: Capture the voice of the electorate
void castVote(int candidate) {
    votes[candidate-1]++;
}

// Crescendo: Tally the symphony of voices, revealing the victor
void tallyVotes(void) {
    int maxVotes = 0;
    int winner = -1;
    for (int i = 0; i < numCandidates; i++) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winner = i+1;
        }
    }
    printf("The triumphant melody of democracy declares candidate %d victorious!\n", winner);
}

int main(int argc, char *argv[]) {
    
    // Overture: The cast of candidates unfolds
    init(argv+1, argc-1);
    
    // Intermezzo: The electorate speaks, their voices shaping the outcome
    printf("Enter your choice (candidate number): ");
    int choice;
    while (scanf("%d", &choice) != EOF) {
        castVote(choice);
        printf("Enter your choice (candidate number): ");
    }
    
    // Finale: The grand crescendo, the voice of the people revealed
    tallyVotes();
    
    return 0;
}