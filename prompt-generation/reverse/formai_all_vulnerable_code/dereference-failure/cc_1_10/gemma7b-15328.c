//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10

typedef struct Candidate {
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

void vote(Candidate** head) {
    char vote_for[20];
    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", vote_for);

    Candidate* current = *head;
    while (current) {
        if (strcmp(current->name, vote_for) == 0) {
            current->votes++;
            printf("Your vote has been cast.\n");
            return;
        }
        current = current->next;
    }

    printf("Error: Invalid vote.\n");
}

int main() {
    Candidate* head = NULL;

    // Create a list of candidates
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        Candidate* new_candidate = malloc(sizeof(Candidate));
        new_candidate->name[0] = '\0';
        new_candidate->votes = 0;
        new_candidate->next = head;
        head = new_candidate;
    }

    // Vote
    vote(&head);

    // Print the results
    printf("The results of the election:\n");
    Candidate* current = head;
    while (current) {
        printf("%s: %d votes\n", current->name, current->votes);
        current = current->next;
    }

    return 0;
}