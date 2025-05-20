//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* struct to hold information about a candidate */
typedef struct candidate {
    int id;
    char name[50];
    int vote_count;
    struct candidate *next;
} candidate_t;

/* struct to hold information about a voter */
typedef struct voter {
    int id;
    int voted;
    struct voter *next;
} voter_t;

/* function to add a new candidate */
void add_candidate(candidate_t **head, int id, char *name) {
    candidate_t *new_candidate = calloc(1, sizeof(candidate_t));
    new_candidate->id = id;
    strncpy(new_candidate->name, name, sizeof(new_candidate->name) - 1);

    candidate_t *current = *head;

    if (*head == NULL) {
        *head = new_candidate;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_candidate;
    }
}

/* function to add a new voter */
void add_voter(voter_t **head, int id) {
    voter_t *new_voter = calloc(1, sizeof(voter_t));
    new_voter->id = id;
    new_voter->voted = 0;

    voter_t *current = *head;

    if (*head == NULL) {
        *head = new_voter;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_voter;
    }
}

/* function to check if a voter has already voted */
int has_voted(voter_t *head, int id) {
    voter_t *current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current->voted;
        }
        current = current->next;
    }
    return 0;
}

/* function to get a candidate by ID */
candidate_t *get_candidate_by_id(candidate_t *head, int id) {
    candidate_t *current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/* function to vote for a candidate */
void vote(candidate_t **head, voter_t **voter_head, int voter_id, int candidate_id) {
    voter_t *voter = *voter_head;
    candidate_t *candidate = get_candidate_by_id(*head, candidate_id);

    if (voter == NULL) {
        printf("Invalid voter ID\n");
        return;
    } else if (has_voted(*voter_head, voter_id) == 1) {
        printf("This voter has already voted\n");
        return;
    } 

    if (candidate == NULL) {
        printf("Invalid candidate ID\n");
        return;
    } 

    candidate->vote_count++;
    voter->voted = 1;

    printf("%s has received a vote\n", candidate->name);
}

/* function to display the results */
void display_results(candidate_t *head) {
    candidate_t *current = head;
    printf("Results:\n");
    while (current != NULL) {
        printf("%s: %d votes\n", current->name, current->vote_count);
        current = current->next;
    }
}

/* main function */
int main() {
    candidate_t *candidates = NULL;
    voter_t *voters = NULL;

    /* adding candidates */
    add_candidate(&candidates, 1, "John Doe");
    add_candidate(&candidates, 2, "Jane Smith");

    /* adding voters */
    add_voter(&voters, 1);
    add_voter(&voters, 2);

    /* voting */
    vote(&candidates, &voters, 1, 1);
    vote(&candidates, &voters, 2, 2);
    vote(&candidates, &voters, 1, 2);

    /* displaying results */
    display_results(candidates);

    return 0;
}