//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Structure to store candidate details
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Function to create a new candidate
candidate *create_candidate(char *name) {
    candidate *new_candidate = (candidate *)malloc(sizeof(candidate));
    strcpy(new_candidate->name, name);
    new_candidate->votes = 0;
    return new_candidate;
}

// Function to add a candidate to the list of candidates
void add_candidate(candidate **candidates, int *num_candidates, char *name) {
    candidates[*num_candidates] = create_candidate(name);
    (*num_candidates)++;
}

// Function to print the list of candidates
void print_candidates(candidate **candidates, int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i]->name);
    }
}

// Function to get the vote for a candidate
int get_vote(candidate **candidates, int num_candidates) {
    int vote;
    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &vote);
    if (vote < 1 || vote > num_candidates) {
        printf("Invalid vote. Please enter a number between 1 and %d.\n", num_candidates);
        return -1;
    }
    return vote - 1;
}

// Function to count the votes for each candidate
void count_votes(candidate **candidates, int num_candidates, int *num_votes) {
    for (int i = 0; i < num_candidates; i++) {
        candidates[i]->votes += num_votes[i];
    }
}

// Function to print the results of the election
void print_results(candidate **candidates, int num_candidates) {
    printf("The results of the election are:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i]->name, candidates[i]->votes);
    }
}

// Main function
int main() {
    // Create an array of candidates
    candidate *candidates[10];
    int num_candidates = 0;

    // Add candidates to the array
    add_candidate(candidates, &num_candidates, "Candidate 1");
    add_candidate(candidates, &num_candidates, "Candidate 2");
    add_candidate(candidates, &num_candidates, "Candidate 3");

    // Print the list of candidates
    print_candidates(candidates, num_candidates);

    // Get the votes for each candidate
    int num_votes[num_candidates];
    for (int i = 0; i < num_candidates; i++) {
        num_votes[i] = get_vote(candidates, num_candidates);
        while (num_votes[i] == -1) {
            num_votes[i] = get_vote(candidates, num_candidates);
        }
    }

    // Count the votes for each candidate
    count_votes(candidates, num_candidates, num_votes);

    // Print the results of the election
    print_results(candidates, num_candidates);

    return 0;
}