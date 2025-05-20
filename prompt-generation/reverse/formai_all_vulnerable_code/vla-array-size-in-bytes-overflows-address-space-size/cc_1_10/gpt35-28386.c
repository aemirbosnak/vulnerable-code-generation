//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>

struct candidate { // candidate struct
    char name[50];
    int votes;
};

void printCandidates(struct candidate candidates[], int numCands) { // print function
    printf("Candidates:\n");
    for(int i = 0; i < numCands; i++) {
        printf("%d: %s\n", i+1, candidates[i].name);
    }
}

void castVote(struct candidate candidates[], int numCands) { // cast vote function
    int choice;
    printf("Enter candidate choice: ");
    scanf("%d", &choice);
    if(choice < 1 || choice > numCands) { // invalid input
        printf("Invalid Choice!\n");
    } else { // valid input
        candidates[choice-1].votes++;
        printf("Vote casted successfully for %s\n", candidates[choice-1].name);
    }
}

int main() {
    int numCands;
    printf("Enter number of candidates: ");
    scanf("%d", &numCands);

    struct candidate candidates[numCands];
    for(int i = 0; i < numCands; i++) {
        printf("Enter name of candidate #%d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int numVoters;
    printf("Enter number of voters: ");
    scanf("%d", &numVoters);

    for(int i = 0; i < numVoters; i++) {
        printf("\nVoter #%d\n", i+1);
        printCandidates(candidates, numCands);
        castVote(candidates, numCands);
    }

    printf("\n\nResults:\n"); // print result
    for(int i = 0; i < numCands; i++) {
        printf("%d. %s - %d vote(s)\n", i+1, candidates[i].name, candidates[i].votes);
    }

    return 0;
}