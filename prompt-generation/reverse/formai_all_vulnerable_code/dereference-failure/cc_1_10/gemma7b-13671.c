//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

void vote(Candidate* head) {
    char vote[20];
    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", vote);

    Candidate* current = head;
    while (current) {
        if (strcmp(current->name, vote) == 0) {
            current->votes++;
            printf("Your vote has been cast for %s.\n", current->name);
            return;
        }
        current = current->next;
    }

    printf("Error: invalid vote.\n");
}

int main() {
    Candidate* head = NULL;

    // Create a list of candidates
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        Candidate* newCandidate = malloc(sizeof(Candidate));
        newCandidate->name[0] = '\0';
        newCandidate->votes = 0;
        newCandidate->next = head;
        head = newCandidate;
    }

    // Print the candidates
    printf("Candidates:");
    for (Candidate* current = head; current; current = current->next) {
        printf(" %s", current->name);
    }

    // Vote
    vote(head);

    // Print the results
    printf("Results:");
    for (Candidate* current = head; current; current = current->next) {
        printf(" %s: %d votes", current->name, current->votes);
    }

    return 0;
}