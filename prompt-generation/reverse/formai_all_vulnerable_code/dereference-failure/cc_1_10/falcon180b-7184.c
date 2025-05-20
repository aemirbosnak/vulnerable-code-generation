//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_candidates, num_voters;
    char **candidate_names;
    int *votes;

    // Prompt the user for the number of candidates and voters
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Allocate memory for the candidate names and votes
    candidate_names = (char **)malloc(num_candidates * sizeof(char *));
    votes = (int *)malloc(num_candidates * sizeof(int));

    // Prompt the user for the candidate names
    printf("Enter the names of the candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        candidate_names[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", candidate_names[i]);
    }

    // Initialize the vote counts to zero
    for (int i = 0; i < num_candidates; i++) {
        votes[i] = 0;
    }

    // Prompt each voter for their choice
    printf("Enter the choices of the voters:\n");
    for (int i = 0; i < num_voters; i++) {
        int choice;
        scanf("%d", &choice);
        votes[choice - 1]++; // Subtract 1 because arrays are zero-indexed
    }

    // Print the results
    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidate_names[i], votes[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < num_candidates; i++) {
        free(candidate_names[i]);
    }
    free(candidate_names);
    free(votes);

    return 0;
}