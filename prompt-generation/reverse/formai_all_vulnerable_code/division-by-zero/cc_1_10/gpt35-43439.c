//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for maximum values
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 20

// Define candidate and voter structures
typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voted_for;
} Voter;

// Declare global variables
Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

// Function to add a candidate to the list
void addCandidate(char *name) {
    // Check that we haven't reached the maximum number of candidates
    if (num_candidates == MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates reached.\n");
        return;
    }

    // Check if the name already exists
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            printf("Error: Candidate already exists.\n");
            return;
        }
    }

    // Create the new candidate and add to the list
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;

    printf("Candidate added successfully!\n");
}

// Function to display the list of candidates
void displayCandidates() {
    printf("List of candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s (Votes: %d)\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

// Function to add a voter to the list
void addVoter(char *name) {
    // Check that we haven't reached the maximum number of voters
    if (num_voters == MAX_VOTERS) {
        printf("Error: Maximum number of voters reached.\n");
        return;
    }

    // Check if the name already exists
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            printf("Error: Voter already exists.\n");
            return;
        }
    }

    // Create the new voter and add to the list
    strcpy(voters[num_voters].name, name);
    voters[num_voters].voted_for = -1;
    num_voters++;

    printf("Voter added successfully!\n");
}

// Function to get a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

// Function to simulate the voting process
void simulateVoting() {
    printf("Simulating voting process...\n");
    for (int i = 0; i < num_voters; i++) {
        // Check if the voter has already cast a vote
        if (voters[i].voted_for != -1) {
            printf("%s has already cast a vote.\n", voters[i].name);
            continue;
        }

        // Choose a random candidate to vote for
        int candidate_index = getRandomNumber(0, num_candidates-1);
        candidates[candidate_index].votes++;
        voters[i].voted_for = candidate_index;
        printf("%s has cast a vote for %s.\n", voters[i].name, candidates[candidate_index].name);
    }
}

// Function to display the winner of the election
void displayWinner() {
    Candidate *winner = &candidates[0];

    for (int i = 1; i < num_candidates; i++) {
        if (candidates[i].votes > winner->votes) {
            winner = &candidates[i];
        }
    }

    printf("The winner of the election is: %s (with %d votes)\n", winner->name, winner->votes);
}

// Main function
int main() {
    // Display welcome message
    printf("Welcome to the Electronic Voting System!\n");

    // Read user input in a loop
    while (1) {
        // Display menu options
        printf("\nPlease choose an option:\n");
        printf("1. Add candidate\n");
        printf("2. Display candidates\n");
        printf("3. Add voter\n");
        printf("4. Simulate voting\n");
        printf("5. Display winner\n");
        printf("6. Exit\n");

        // Read user input and perform action
        char input[MAX_NAME_LENGTH];
        fgets(input, MAX_NAME_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;

        switch (atoi(input)) {
            case 1:
                printf("Enter candidate name: ");
                fgets(input, MAX_NAME_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0;
                addCandidate(input);
                break;

            case 2:
                displayCandidates();
                break;

            case 3:
                printf("Enter voter name: ");
                fgets(input, MAX_NAME_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0;
                addVoter(input);
                break;

            case 4:
                simulateVoting();
                break;

            case 5:
                displayWinner();
                break;

            case 6:
                printf("Thank you for using the Electronic Voting System!\n");
                return 0;

            default:
                printf("Invalid option. Please enter a number between 1 and 6.\n");
                break;
        }
    }
}