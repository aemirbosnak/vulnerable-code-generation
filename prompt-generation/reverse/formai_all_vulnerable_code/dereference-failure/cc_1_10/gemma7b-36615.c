//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Voter {
    char name[50];
    int vote;
    struct Voter* next;
} Voter;

typedef struct Poll {
    char poll_name[50];
    int total_votes;
    Voter* head;
    struct Poll* next;
} Poll;

void add_voter(Poll* poll, Voter* new_voter) {
    new_voter->next = poll->head;
    poll->head = new_voter;
    poll->total_votes++;
}

void vote(Poll* poll, char* candidate) {
    Voter* current_voter = poll->head;
    while (current_voter) {
        if (strcmp(current_voter->name, candidate) == 0) {
            current_voter->vote++;
            return;
        }
        current_voter = current_voter->next;
    }

    printf("Error: voter not found.\n");
}

int main() {
    Poll* polls = NULL;
    Voter* new_voter = NULL;

    // Create a new poll
    polls = malloc(sizeof(Poll));
    polls->head = NULL;
    polls->total_votes = 0;
    strcpy(polls->poll_name, "Example Poll");

    // Add some voters
    new_voter = malloc(sizeof(Voter));
    strcpy(new_voter->name, "John Doe");
    new_voter->vote = 0;
    add_voter(polls, new_voter);

    new_voter = malloc(sizeof(Voter));
    strcpy(new_voter->name, "Jane Doe");
    new_voter->vote = 0;
    add_voter(polls, new_voter);

    // Vote for a candidate
    vote(polls, "John Doe");

    // Print the results
    printf("Results:\n");
    for (new_voter = polls->head; new_voter; new_voter = new_voter->next) {
        printf("%s: %d votes\n", new_voter->name, new_voter->vote);
    }

    return 0;
}