//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/sha.h>

#define MAX_VOTES 10

typedef struct voter {
    char name[50];
    int vote;
    struct voter* next;
} voter;

void vote(voter** head, char* name, int vote) {
    voter* new_voter = malloc(sizeof(voter));
    strcpy(new_voter->name, name);
    new_voter->vote = vote;
    new_voter->next = NULL;

    if (*head == NULL) {
        *head = new_voter;
    } else {
        (*head)->next = new_voter;
    }
}

int verify_vote(voter* head, char* name, int vote) {
    while (head) {
        if (strcmp(head->name, name) == 0 && head->vote == vote) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

int main() {
    voter* head = NULL;

    // Register voters
    vote(&head, "John Doe", 1);
    vote(&head, "Jane Doe", 2);
    vote(&head, "Peter Pan", 3);

    // Cast votes
    vote(&head, "John Doe", 2);
    vote(&head, "Jane Doe", 1);

    // Verify votes
    if (verify_vote(head, "John Doe", 2)) {
        printf("John Doe's vote is verified.\n");
    } else {
        printf("John Doe's vote is not verified.\n");
    }

    return 0;
}