//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate { // creating a structure for candidate information
    int id;
    char name[50];
    int votes;
};

void cast_vote(struct candidate *candidates); // function for casting vote
void print_result(struct candidate *candidates, int num_candidates); // function for printing result

int main() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    struct candidate *candidates = malloc(num_candidates * sizeof(struct candidate)); // dynamic allocation for candidate structure array

    // getting information for each candidate
    for (int i = 0; i < num_candidates; i++) {
        printf("\nEnter information for Candidate %d:\n", i+1);
        candidates[i].id = i+1;
        printf("Name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // display the first menu
    printf("\n************* Welcome to Electronic Voting System *************\n\n");
    printf("1. Cast Vote\n");
    printf("2. Exit\n");
    printf("\nEnter your choice: ");

    int choice;
    scanf("%d", &choice);

    while (choice == 1) { // repeat the loop until the user selects exit option
        cast_vote(candidates); // call the cast_vote function
        printf("\n1. Cast Vote\n");
        printf("2. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    }

    print_result(candidates, num_candidates); // call the print_result function

    free(candidates); // free up the memory allocation for candidates

    return 0;
}

void cast_vote(struct candidate *candidates) {
    int id;
    printf("\nEnter candidate ID to cast vote: ");
    scanf("%d", &id);

    for (int i = 0; i < candidates[i].id; i++) {
        if (candidates[i].id == id) {
            candidates[i].votes++;
            printf("\nYou have cast a vote for %s.\n", candidates[i].name);
            break;
        }
    }
}

void print_result(struct candidate *candidates, int num_candidates) {
    // sort the candidates array in descending order based on votes
    for (int i = 0; i < num_candidates; i++) {
        for (int j = i + 1; j < num_candidates; j++) {
            if (candidates[i].votes < candidates[j].votes) {
                struct candidate temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }

    printf("\n\n************* Voting Results *************\n\n");
    printf("ID       Name        Votes\n\n");

    // display the voting results
    for (int i = 0; i < num_candidates; i++) {
        printf("%-8d %-18s %d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}