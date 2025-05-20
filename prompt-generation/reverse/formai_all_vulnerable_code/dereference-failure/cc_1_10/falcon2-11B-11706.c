//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char* name;
    char* party;
    int votes;
} Candidate;

void addCandidate(Candidate* candidates, int numCandidates, char* name, char* party) {
    Candidate newCandidate;
    strcpy(newCandidate.name, name);
    strcpy(newCandidate.party, party);
    newCandidate.id = numCandidates;
    candidates[numCandidates] = newCandidate;
    numCandidates++;
}

void printCandidates(Candidate* candidates, int numCandidates) {
    printf("ID | Name | Party | Votes\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%3d | %-20s | %-20s | %3d\n", i + 1, candidates[i].name, candidates[i].party, candidates[i].votes);
    }
    printf("\n");
}

void printResults(Candidate* candidates, int numCandidates) {
    int maxVotes = 0;
    int winnerIndex = -1;
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }
    if (winnerIndex!= -1) {
        printf("Winner: %s (%s)\n", candidates[winnerIndex].name, candidates[winnerIndex].party);
    } else {
        printf("No winner found.\n");
    }
}

int main() {
    Candidate candidates[5];
    int numCandidates = 0;

    addCandidate(candidates, numCandidates, "John Smith", "Democrat");
    addCandidate(candidates, numCandidates, "Jane Doe", "Republican");
    addCandidate(candidates, numCandidates, "Bob Johnson", "Democrat");
    addCandidate(candidates, numCandidates, "Alice Brown", "Republican");
    addCandidate(candidates, numCandidates, "Charlie Davis", "Democrat");

    printf("Election Results\n");
    printCandidates(candidates, numCandidates);
    printf("\n");
    printResults(candidates, numCandidates);

    return 0;
}