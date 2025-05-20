//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Voter {
    char name[50];
    int vote;
    struct Voter *next;
} Voter;

Voter *head = NULL;
Voter *current = NULL;

void add_voter(char *name) {
    Voter *new_voter = (Voter *)malloc(sizeof(Voter));
    strcpy(new_voter->name, name);
    new_voter->vote = 0;
    new_voter->next = NULL;

    if (head == NULL) {
        head = new_voter;
    } else {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_voter;
    }
}

bool voter_exists(char *name) {
    current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void vote(char *name, int candidate) {
    if (!voter_exists(name)) {
        add_voter(name);
    }

    current = head;
    while (strcmp(current->name, name) != 0) {
        current = current->next;
    }

    current->vote = candidate;
}

void print_results() {
    int candidate_1 = 0;
    int candidate_2 = 0;
    int total_votes = 0;

    current = head;
    while (current != NULL) {
        if (current->vote == 1) {
            candidate_1++;
        } else if (current->vote == 2) {
            candidate_2++;
        }
        total_votes++;
        current = current->next;
    }

    printf("Results:\n");
    printf("Candidate 1: %d votes\n", candidate_1);
    printf("Candidate 2: %d votes\n", candidate_2);
    printf("Total votes: %d\n", total_votes);
}

int main() {
    add_voter("Alice");
    add_voter("Bob");
    add_voter("Charlie");

    vote("Alice", 1);
    vote("Bob", 2);
    vote("Alice", 1); // This should not be allowed
    vote("Charlie", 1);

    print_results();

    return 0;
}