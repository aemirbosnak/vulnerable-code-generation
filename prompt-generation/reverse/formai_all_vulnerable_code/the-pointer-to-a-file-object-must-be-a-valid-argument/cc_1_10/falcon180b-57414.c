//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTE_LENGTH 50

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int vote[MAX_CANDIDATES];
} Voter;

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int votes;
} Candidate;

Voter voters[MAX_VOTERS];
Candidate candidates[MAX_CANDIDATES];
int num_voters = 0;
int num_candidates = 0;

void read_voters() {
    FILE *file = fopen("voters.txt", "r");
    char line[MAX_VOTE_LENGTH];
    while (fgets(line, MAX_VOTE_LENGTH, file)!= NULL) {
        Voter *voter = &voters[num_voters];
        strcpy(voter->name, line);
        num_voters++;
    }
    fclose(file);
}

int compare_names(const void *a, const void *b) {
    Voter *voter_a = (Voter *)a;
    Voter *voter_b = (Voter *)b;
    return strcmp(voter_a->name, voter_b->name);
}

void read_candidates() {
    FILE *file = fopen("candidates.txt", "r");
    char line[MAX_VOTE_LENGTH];
    while (fgets(line, MAX_VOTE_LENGTH, file)!= NULL) {
        Candidate *candidate = &candidates[num_candidates];
        strcpy(candidate->name, line);
        num_candidates++;
    }
    fclose(file);
}

void count_votes() {
    qsort(voters, num_voters, sizeof(Voter), compare_names);
    int i;
    for (i = 0; i < num_voters; i++) {
        Voter *voter = &voters[i];
        int j;
        for (j = 0; j < num_candidates; j++) {
            Candidate *candidate = &candidates[j];
            if (strcasecmp(candidate->name, voter->name) == 0) {
                voter->vote[j] = 1;
                break;
            }
        }
    }
}

void print_results() {
    int i, j;
    for (i = 0; i < num_candidates; i++) {
        Candidate *candidate = &candidates[i];
        printf("%s: %d votes\n", candidate->name, candidate->votes);
    }
}

int main() {
    read_voters();
    read_candidates();
    count_votes();
    print_results();
    return 0;
}