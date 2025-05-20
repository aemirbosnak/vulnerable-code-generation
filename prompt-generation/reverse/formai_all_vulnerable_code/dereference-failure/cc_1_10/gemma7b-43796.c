//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the number of voters
int num_voters = 100;

// Define the list of voters
struct voter {
    char name[50];
    int vote;
    struct voter* next;
};

// Create the first voter
struct voter* create_voter(char* name, int vote) {
    struct voter* new_voter = malloc(sizeof(struct voter));
    strcpy(new_voter->name, name);
    new_voter->vote = vote;
    new_voter->next = NULL;
    return new_voter;
}

// Add a voter to the list
void add_voter(struct voter* head, char* name, int vote) {
    struct voter* new_voter = create_voter(name, vote);
    if (head == NULL) {
        head = new_voter;
    } else {
        struct voter* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_voter;
    }
}

// Vote for a candidate
void vote(struct voter* head, int candidate) {
    struct voter* temp = head;
    while (temp) {
        if (strcmp(temp->name, "John Doe") == 0) {
            temp->vote = candidate;
            break;
        }
        temp = temp->next;
    }
}

// Print the results
void print_results(struct voter* head) {
    struct voter* temp = head;
    int total_votes = 0;
    while (temp) {
        total_votes++;
        printf("%s voted for candidate %d\n", temp->name, temp->vote);
        temp = temp->next;
    }
    printf("Total number of votes: %d\n", total_votes);
}

int main() {
    // Create the list of voters
    struct voter* head = NULL;
    add_voter(head, "John Doe", 1);
    add_voter(head, "Jane Doe", 2);
    add_voter(head, "Peter Pan", 3);

    // Vote for a candidate
    vote(head, 1);

    // Print the results
    print_results(head);

    return 0;
}