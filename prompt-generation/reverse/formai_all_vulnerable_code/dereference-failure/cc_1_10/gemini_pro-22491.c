//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store candidate details
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Function to compare two candidates based on their votes
int compare_candidates(const void *a, const void *b) {
    candidate *c1 = (candidate *)a;
    candidate *c2 = (candidate *)b;
    return c2->votes - c1->votes;
}

// Function to print the results of the election
void print_results(candidate *candidates, int num_candidates) {
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main(int argc, char *argv[]) {
    // Check if the number of arguments is valid
    if (argc != 3) {
        printf("Usage: %s <num_candidates> <num_voters>\n", argv[0]);
        return 1;
    }

    // Get the number of candidates and voters from the command line arguments
    int num_candidates = atoi(argv[1]);
    int num_voters = atoi(argv[2]);

    // Check if the number of candidates and voters is valid
    if (num_candidates < 2 || num_voters < 1) {
        printf("Invalid input: The number of candidates must be at least 2 and the number of voters must be at least 1.\n");
        return 1;
    }

    // Allocate memory for the candidates
    candidate *candidates = (candidate *)malloc(num_candidates * sizeof(candidate));

    // Get the details of each candidate
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Get the votes for each candidate
    for (int i = 0; i < num_voters; i++) {
        int vote;
        printf("Enter the vote for voter %d: ", i + 1);
        scanf("%d", &vote);

        // Check if the vote is valid
        if (vote < 1 || vote > num_candidates) {
            printf("Invalid vote: The vote must be between 1 and %d.\n", num_candidates);
            i--;
            continue;
        }

        // Increment the vote count for the candidate
        candidates[vote - 1].votes++;
    }

    // Sort the candidates based on their votes
    qsort(candidates, num_candidates, sizeof(candidate), compare_candidates);

    // Print the results of the election
    print_results(candidates, num_candidates);

    // Free the memory allocated for the candidates
    free(candidates);

    return 0;
}