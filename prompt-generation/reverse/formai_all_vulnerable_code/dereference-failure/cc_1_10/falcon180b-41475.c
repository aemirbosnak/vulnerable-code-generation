//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME 50
#define MAX_BALLOT 100

typedef struct {
    char name[MAX_NAME];
    int id;
} candidate;

typedef struct {
    int voter_id;
    int candidate_id;
} ballot;

candidate candidates[MAX_CANDIDATES];
ballot ballots[MAX_VOTERS][MAX_BALLOT];
int num_candidates = 0;
int num_voters = 0;
int num_ballots = 0;

void rand_string(char *str, int len) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < len; ++i) {
        str[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    str[len] = '\0';
}

void init_candidates() {
    for (int i = 0; i < MAX_CANDIDATES; ++i) {
        rand_string(candidates[i].name, rand() % (MAX_NAME - 1) + 1);
        candidates[i].id = i;
    }
    num_candidates = MAX_CANDIDATES;
}

void init_voters() {
    for (int i = 0; i < MAX_VOTERS; ++i) {
        rand_string(ballots[i][0].voter_id, 10);
        for (int j = 0; j < MAX_BALLOT; ++j) {
            rand_string(ballots[i][j].candidate_id, 10);
        }
        ++num_voters;
    }
}

int main() {
    srand(time(NULL));
    init_candidates();
    init_voters();
    FILE *fp = fopen("votes.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open votes.txt\n");
        exit(1);
    }
    for (int i = 0; i < num_voters; ++i) {
        fprintf(fp, "Voter ID: %s\n", ballots[i][0].voter_id);
        for (int j = 0; j < num_ballots; ++j) {
            fprintf(fp, "Candidate ID: %s\n", ballots[i][j].candidate_id);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;
}