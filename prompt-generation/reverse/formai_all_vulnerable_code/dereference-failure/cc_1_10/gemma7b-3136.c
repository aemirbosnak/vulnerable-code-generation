//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5

typedef struct Candidate {
    char name[50];
    int votes;
    struct Candidate* next;
} Candidate;

void vote(Candidate** head) {
    char vote_choice;
    printf("Please select a candidate: ");
    scanf(" %c", &vote_choice);

    Candidate* current = *head;
    while (current) {
        if (vote_choice == current->name[0]) {
            current->votes++;
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid vote.\n");
    }
}

int main() {
    time_t t = time(NULL);
    srand(t);

    Candidate* head = NULL;
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        Candidate* new_candidate = (Candidate*)malloc(sizeof(Candidate));
        new_candidate->name[0] = 'A' + i;
        new_candidate->votes = rand() % 100;
        new_candidate->next = head;
        head = new_candidate;
    }

    vote(&head);

    Candidate* winner = head;
    while (winner->next) {
        if (winner->votes < winner->next->votes) {
            winner = winner->next;
        }
    }

    printf("The winner is: %s with %d votes.\n", winner->name, winner->votes);

    return 0;
}