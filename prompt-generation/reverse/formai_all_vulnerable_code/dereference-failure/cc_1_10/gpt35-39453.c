//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidate {
    char name[50];
    int votes;
} candidate;

void vote(candidate *candidates, int n);
void print_results(candidate *candidates, int n);

int main() {
    int n;
    printf("How many candidates are running?\n");
    scanf("%d", &n);
    candidate *candidates = malloc(n * sizeof(candidate));
    printf("Enter the names of the candidates:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    printf("\nWelcome to the Electronic Voting System!\n");
    printf("To vote, enter the number next to the candidate's name.\n");
    printf("To end the voting, enter '-1'.\n");
    vote(candidates, n);
    print_results(candidates, n);
    free(candidates);
    return 0;
}

void vote(candidate *candidates, int n) {
    int choice;
    while (1) {
        for (int i = 0; i < n; i++) {
            printf("%d. %s\n", i + 1, candidates[i].name);
        }
        scanf("%d", &choice);
        if (choice == -1) {
            break;
        }
        if (choice < 1 || choice > n) {
            printf("Invalid choice. Please enter a number between 1 and %d.\n", n);
            continue;
        }
        candidates[choice - 1].votes++;
        printf("Your vote has been recorded!\n");
    }
}

void print_results(candidate *candidates, int n) {
    candidate winner = {"", 0};
    printf("\nVoting Results:\n");
    for (int i = 0; i < n; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        if (candidates[i].votes > winner.votes) {
            winner = candidates[i];
        }
    }
    printf("\nThe winner is %s with %d votes!", winner.name, winner.votes);
}