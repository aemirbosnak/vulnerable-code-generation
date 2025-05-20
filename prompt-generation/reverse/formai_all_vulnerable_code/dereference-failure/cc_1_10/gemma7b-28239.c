//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
    char name[50];
    int vote_count;
    struct Voter* next;
} Voter;

typedef struct Poll {
    char candidate_names[MAX_CANDIDATES][50];
    int candidate_votes[MAX_CANDIDATES];
    struct Voter* head;
} Poll;

void add_voter(Poll* poll, char* name) {
    Voter* new_voter = malloc(sizeof(Voter));
    strcpy(new_voter->name, name);
    new_voter->vote_count = 0;
    new_voter->next = NULL;

    if (poll->head == NULL) {
        poll->head = new_voter;
    } else {
        poll->head->next = new_voter;
    }
}

void cast_vote(Poll* poll, char* candidate_name) {
    Voter* current_voter = poll->head;

    while (current_voter) {
        if (strcmp(current_voter->name, candidate_name) == 0) {
            current_voter->vote_count++;
            break;
        }
        current_voter = current_voter->next;
    }
}

int main() {
    Poll* poll = malloc(sizeof(Poll));
    poll->head = NULL;

    add_voter(poll, "John Doe");
    add_voter(poll, "Jane Doe");
    add_voter(poll, "Peter Pan");

    cast_vote(poll, "John Doe");
    cast_vote(poll, "Jane Doe");
    cast_vote(poll, "Peter Pan");

    int total_votes = 0;
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        total_votes += poll->candidate_votes[i];
    }

    printf("Total votes: %d", total_votes);

    return 0;
}