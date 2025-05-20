//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5

typedef struct Voter {
    char name[50];
    int vote_cast;
    struct Voter* next;
} Voter;

void insert_voter(Voter** head) {
    Voter* new_voter = malloc(sizeof(Voter));
    scanf("%s", new_voter->name);
    new_voter->vote_cast = 0;
    new_voter->next = NULL;

    if (*head == NULL) {
        *head = new_voter;
    } else {
        (*head)->next = new_voter;
    }
}

void vote(Voter** head) {
    printf("Enter the candidate number you want to vote for: ");
    int candidate_num;
    scanf("%d", &candidate_num);

    Voter* current_voter = *head;
    while (current_voter) {
        if (strcmp(current_voter->name, "John Doe") == 0) {
            current_voter->vote_cast = candidate_num;
            break;
        }
        current_voter = current_voter->next;
    }

    if (current_voter == NULL) {
        printf("Error: voter not found.\n");
    } else {
        printf("Your vote has been cast.\n");
    }
}

void print_results(Voter** head) {
    int candidate_votes[MAX_CANDIDATES];
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidate_votes[i] = 0;
    }

    Voter* current_voter = *head;
    while (current_voter) {
        candidate_votes[current_voter->vote_cast]++;
        current_voter = current_voter->next;
    }

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("Candidate %d: %d votes\n", i, candidate_votes[i]);
    }
}

int main() {
    Voter* head = NULL;
    insert_voter(&head);
    insert_voter(&head);
    insert_voter(&head);
    vote(&head);
    print_results(&head);

    return 0;
}