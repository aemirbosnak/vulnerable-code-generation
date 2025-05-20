//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate;

typedef struct {
    char voter_id[10];
    int selected_candidate;
} voter;

candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

void add_candidate(char *name) {
    if (num_candidates == MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates reached.\n");
        return;
    }
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void add_voter(char *id) {
    if (num_voters == MAX_VOTERS) {
        printf("Error: Maximum number of voters reached.\n");
        return;
    }
    strcpy(voters[num_voters].voter_id, id);
    num_voters++;
}

void vote(int voter_id, int selected_candidate) {
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].voter_id, voter_id) == 0) {
            voters[i].selected_candidate = selected_candidate;
            break;
        }
    }
}

void count_votes() {
    for (int i = 0; i < num_candidates; i++) {
        candidates[i].votes = 0;
    }
    for (int i = 0; i < num_voters; i++) {
        for (int j = 0; j < num_candidates; j++) {
            if (voters[i].selected_candidate == j) {
                candidates[j].votes++;
            }
        }
    }
}

void print_results() {
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    add_candidate("John");
    add_candidate("Jane");
    add_candidate("Bob");
    add_candidate("Alice");
    add_candidate("Charlie");

    add_voter("1234");
    add_voter("5678");
    vote(1, 0);
    vote(2, 1);
    vote(3, 1);
    vote(4, 2);
    vote(5, 3);

    count_votes();
    print_results();

    return 0;
}