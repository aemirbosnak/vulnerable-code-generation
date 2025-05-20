//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 1000

typedef struct Voter {
    char name[20];
    int vote;
    struct Voter* next;
} Voter;

void initialize_voting_system(Voter** head) {
    *head = NULL;
}

void add_voter(Voter** head, char* name, int vote) {
    Voter* new_voter = malloc(sizeof(Voter));
    strcpy(new_voter->name, name);
    new_voter->vote = vote;
    new_voter->next = NULL;

    if (*head == NULL) {
        *head = new_voter;
    } else {
        (*head)->next = new_voter;
    }
}

int get_total_votes(Voter* head) {
    int total_votes = 0;
    while (head) {
        total_votes++;
        head = head->next;
    }
    return total_votes;
}

void vote(Voter** head, char* candidate) {
    Voter* current_voter = *head;
    while (current_voter) {
        if (strcmp(current_voter->name, candidate) == 0) {
            current_voter->vote++;
            break;
        }
        current_voter = current_voter->next;
    }
}

int main() {
    Voter* head = NULL;
    initialize_voting_system(&head);

    // Add voters
    add_voter(&head, "John Doe", 1);
    add_voter(&head, "Jane Doe", 2);
    add_voter(&head, "Peter Pan", 3);
    add_voter(&head, "Mary Poppins", 4);
    add_voter(&head, "The Wizard of Oz", 5);

    // Get total votes
    int total_votes = get_total_votes(head);
    printf("Total votes: %d\n", total_votes);

    // Vote for candidate
    vote(&head, "Mary Poppins");

    // Get total votes after vote
    total_votes = get_total_votes(head);
    printf("Total votes: %d\n", total_votes);

    return 0;
}