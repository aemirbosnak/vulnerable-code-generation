//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a candidate
typedef struct candidate {
    char* name;
    int votes;
} candidate_t;

// Function to create a new candidate
candidate_t* create_candidate(char* name) {
    candidate_t* candidate = malloc(sizeof(candidate_t));
    candidate->name = malloc(strlen(name) + 1);
    strcpy(candidate->name, name);
    candidate->votes = 0;
    return candidate;
}

// Function to free a candidate
void free_candidate(candidate_t* candidate) {
    free(candidate->name);
    free(candidate);
}

// Function to add a vote to a candidate
void add_vote(candidate_t* candidate) {
    candidate->votes++;
}

// Function to print a candidate
void print_candidate(candidate_t* candidate) {
    printf("%s: %d votes\n", candidate->name, candidate->votes);
}

// Function to compare two candidates by name
int compare_candidates(const void* a, const void* b) {
    const candidate_t* candidate_a = a;
    const candidate_t* candidate_b = b;
    return strcmp(candidate_a->name, candidate_b->name);
}

// Function to sort an array of candidates by name
void sort_candidates(candidate_t** candidates, int num_candidates) {
    qsort(candidates, num_candidates, sizeof(candidate_t*), compare_candidates);
}

// Function to print the results of an election
void print_results(candidate_t** candidates, int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        print_candidate(candidates[i]);
    }
}

// Main function
int main() {
    // Create an array of candidates
    candidate_t* candidates[] = {
        create_candidate("Alice"),
        create_candidate("Bob"),
        create_candidate("Carol"),
        create_candidate("Dave"),
        create_candidate("Eve"),
    };
    const int num_candidates = sizeof(candidates) / sizeof(candidates[0]);

    // Simulate an election
    for (int i = 0; i < 1000; i++) {
        add_vote(candidates[rand() % num_candidates]);
    }

    // Sort the candidates by name
    sort_candidates(candidates, num_candidates);

    // Print the results of the election
    print_results(candidates, num_candidates);

    // Free the candidates
    for (int i = 0; i < num_candidates; i++) {
        free_candidate(candidates[i]);
    }

    return 0;
}