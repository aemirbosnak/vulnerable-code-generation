//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store candidate information
typedef struct Candidate {
    char name[50];
    int votes;
} Candidate;

// Function to display main menu
void displayMenu() {
    printf("Electronic Voting System\n");
    printf("1. Add Candidate\n");
    printf("2. Cast Vote\n");
    printf("3. Display Results\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int numCandidates = 0;
    Candidate* candidates = NULL;
    int numVotes = 0;
    int choice = 0;

    while (choice != 4) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add Candidate
                numCandidates++;

                if (candidates == NULL) {
                    candidates = (Candidate*) malloc(sizeof(Candidate));
                } else {
                    candidates = (Candidate*) realloc(candidates, numCandidates * sizeof(Candidate));
                }

                printf("Enter candidate name: ");
                scanf("%s", candidates[numCandidates - 1].name);

                candidates[numCandidates - 1].votes = 0;

                printf("Candidate added successfully!\n\n");
                break;

            case 2:
                // Cast Vote
                if (numCandidates == 0) {
                    printf("No candidates added yet!\n\n");
                } else {
                    char candidateName[50];
                    int candidateIndex = -1;

                    printf("Enter candidate name: ");
                    scanf("%s", candidateName);

                    for (int i = 0; i < numCandidates; i++) {
                        if (strcmp(candidates[i].name, candidateName) == 0) {
                            candidateIndex = i;
                            break;
                        }
                    }

                    if (candidateIndex == -1) {
                        printf("Invalid candidate name!\n\n");
                    } else {
                        candidates[candidateIndex].votes++;

                        printf("Vote cast successfully!\n\n");
                        numVotes++;
                    }
                }
                break;

            case 3:
                // Display Results
                if (numCandidates == 0) {
                    printf("No candidates added yet!\n\n");
                } else {
                    printf("Candidate\tVotes\n");

                    for (int i = 0; i < numCandidates; i++) {
                        printf("%s\t%d\n", candidates[i].name, candidates[i].votes);
                    }

                    printf("Total Votes: %d\n\n", numVotes);
                }
                break;

            case 4:
                // Exit
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n\n");
                break;
        }
    }

    // Free memory allocated for candidates array
    free(candidates);

    return 0;
}