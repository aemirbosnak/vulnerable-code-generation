//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    char *name;
    int votes;
};

struct candidate *candidates;  // array of candidates
int num_candidates;  // number of candidates
int num_voters;  // number of voters

// function to read in the candidates and their names from a file
void read_candidates() {
    FILE *fp = fopen("candidates.txt", "r");
    if (fp == NULL) {
        perror("Error opening candidates.txt");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        char *name = strtok(line, ",");
        int votes = atoi(strtok(NULL, ","));
        struct candidate *candidate = malloc(sizeof(struct candidate));
        candidate->name = strdup(name);
        candidate->votes = votes;
        candidates = realloc(candidates, (num_candidates + 1) * sizeof(struct candidate));
        candidates[num_candidates++] = *candidate;
    }

    fclose(fp);
}

// function to read in the voters and their votes from a file
void read_voters() {
    FILE *fp = fopen("voters.txt", "r");
    if (fp == NULL) {
        perror("Error opening voters.txt");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        char *name = strtok(line, ",");
        int vote = atoi(strtok(NULL, ","));
        // TODO: check that the voter exists and that the vote is valid
        candidates[vote - 1].votes++;
        num_voters++;
    }

    fclose(fp);
}

// function to print the results of the election
void print_results() {
    printf("Election results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // find the winner
    int max_votes = 0;
    int winner = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner = i;
        }
    }

    printf("The winner is %s with %d votes.\n", candidates[winner].name, max_votes);
}

int main() {
    read_candidates();
    read_voters();
    print_results();

    return 0;
}