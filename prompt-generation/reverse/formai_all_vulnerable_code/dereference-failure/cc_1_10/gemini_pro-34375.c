//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Candidate struct
struct candidate {
    char name[50];
    int votes;
};

// Initialize candidates
struct candidate candidates[] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Charlie", 0},
    {"Dave", 0}
};

// Number of candidates
int num_candidates = sizeof(candidates) / sizeof(candidates[0]);

int main(int argc, char* argv[]) {
    // Check if a candidate name was provided
    if (argc != 2) {
        printf("Usage: %s <candidate name>\n", argv[0]);
        return 1;
    }

    // Find the candidate by name
    int candidate_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(argv[1], candidates[i].name) == 0) {
            candidate_index = i;
            break;
        }
    }

    // If the candidate was not found, print an error message
    if (candidate_index == -1) {
        printf("Candidate %s not found\n", argv[1]);
        return 1;
    }

    // Increment the candidate's vote count
    candidates[candidate_index].votes++;

    // Print the updated vote counts
    printf("Vote counts:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}