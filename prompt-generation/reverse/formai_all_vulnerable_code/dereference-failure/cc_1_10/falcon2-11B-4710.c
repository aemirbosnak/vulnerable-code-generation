//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a voter
typedef struct {
    char name[50];
    int age;
} Voter;

// Define the structure for a candidate
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Function to initialize a voter structure
void initVoter(Voter *voter) {
    strcpy(voter->name, "");
    voter->age = 0;
}

// Function to print a voter structure
void printVoter(Voter *voter) {
    printf("Name: %s\n", voter->name);
    printf("Age: %d\n", voter->age);
}

// Function to initialize a candidate structure
void initCandidate(Candidate *candidate) {
    strcpy(candidate->name, "");
    candidate->votes = 0;
}

// Function to print a candidate structure
void printCandidate(Candidate *candidate) {
    printf("Name: %s\n", candidate->name);
    printf("Votes: %d\n", candidate->votes);
}

// Function to add a vote to a candidate
void addVote(Candidate *candidate, char *name) {
    if (strlen(candidate->name) == 0) {
        strcpy(candidate->name, name);
    } else {
        candidate->votes++;
    }
}

// Function to get the winner of the election
Candidate* getWinner(Candidate candidates[5], int numCandidates) {
    Candidate* winner = malloc(sizeof(Candidate));
    int maxVotes = 0;
    int maxIndex = 0;

    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            maxIndex = i;
        }
    }

    strcpy(winner->name, candidates[maxIndex].name);
    return winner;
}

// Function to display the results of the election
void displayResults(Candidate candidates[5], int numCandidates) {
    printf("Election Results:\n");
    printf("-----------------------------\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
    }
    printf("-----------------------------\n");
    printf("Winner: %s\n", getWinner(candidates, numCandidates)->name);
}

int main() {
    Voter voters[10];
    initVoter(voters);
    Voter *voter1 = voters;
    voter1->name[0] = 'A';
    voter1->name[1] = 'l';
    voter1->name[2] = 'l';
    voter1->name[3] = 'e';
    voter1->name[4] = '\0';
    voter1->age = 18;

    Voter *voter2 = voters + 1;
    voter2->name[0] = 'B';
    voter2->name[1] = 'r';
    voter2->name[2] = 'o';
    voter2->name[3] = 'w';
    voter2->name[4] = '\0';
    voter2->age = 19;

    Voter *voter3 = voters + 2;
    voter3->name[0] = 'C';
    voter3->name[1] = 'h';
    voter3->name[2] = 'a';
    voter3->name[3] = 'r';
    voter3->name[4] = '\0';
    voter3->age = 20;

    Voter *voter4 = voters + 3;
    voter4->name[0] = 'D';
    voter4->name[1] = 'a';
    voter4->name[2] = 'n';
    voter4->name[3] = 'i';
    voter4->name[4] = '\0';
    voter4->age = 21;

    Voter *voter5 = voters + 4;
    voter5->name[0] = 'E';
    voter5->name[1] = 'f';
    voter5->name[2] = 'i';
    voter5->name[3] = 'x';
    voter5->name[4] = '\0';
    voter5->age = 22;

    Candidate candidates[5];
    initCandidate(candidates);
    addVote(candidates, "A");
    addVote(candidates, "B");
    addVote(candidates, "C");
    addVote(candidates, "D");
    addVote(candidates, "E");
    Candidate *winner = getWinner(candidates, 5);
    displayResults(candidates, 5);
    return 0;
}