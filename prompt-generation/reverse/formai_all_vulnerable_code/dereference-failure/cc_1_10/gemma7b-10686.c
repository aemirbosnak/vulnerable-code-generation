//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CANDIDATES 5

typedef struct Candidate {
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

void addCandidate(Candidate** head, char* name) {
    Candidate* newCandidate = malloc(sizeof(Candidate));
    strcpy(newCandidate->name, name);
    newCandidate->votes = 0;
    newCandidate->next = NULL;

    if (*head == NULL) {
        *head = newCandidate;
    } else {
        (*head)->next = newCandidate;
    }
}

void vote(Candidate** head, char* candidate) {
    Candidate* currentCandidate = *head;
    while (currentCandidate) {
        if (strcmp(currentCandidate->name, candidate) == 0) {
            currentCandidate->votes++;
            return;
        }
        currentCandidate = currentCandidate->next;
    }

    printf("Error: Candidate not found.\n");
}

int main() {
    Candidate* head = NULL;
    addCandidate(&head, "John Doe");
    addCandidate(&head, "Jane Doe");
    addCandidate(&head, "Bill Smith");
    addCandidate(&head, "Mary Jones");
    addCandidate(&head, "Tom Anderson");

    vote(&head, "John Doe");
    vote(&head, "Jane Doe");
    vote(&head, "Bill Smith");

    printf("Results:");
    Candidate* currentCandidate = head;
    while (currentCandidate) {
        printf("\n%s: %d votes", currentCandidate->name, currentCandidate->votes);
        currentCandidate = currentCandidate->next;
    }

    return 0;
}