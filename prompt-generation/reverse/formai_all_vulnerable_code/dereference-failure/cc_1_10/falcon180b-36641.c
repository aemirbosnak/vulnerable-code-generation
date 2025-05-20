//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voter_id;
    int choice;
} voter;

int main() {
    int num_candidates, num_voters;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    candidate *candidates = (candidate*)malloc(num_candidates * sizeof(candidate));
    voter *voters = (voter*)malloc(num_voters * sizeof(voter));

    printf("Enter the names of the candidates:\n");
    for(int i=0; i<num_candidates; i++) {
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter the names of the voters:\n");
    for(int i=0; i<num_voters; i++) {
        scanf("%s", voters[i].name);
        voters[i].voter_id = i+1;
    }

    printf("Enter the choices of the voters:\n");
    for(int i=0; i<num_voters; i++) {
        scanf("%d", &voters[i].choice);
    }

    int total_votes = 0;
    for(int i=0; i<num_voters; i++) {
        int choice = voters[i].choice;
        strcpy(candidates[choice-1].name, candidates[choice-1].name);
        candidates[choice-1].votes++;
        total_votes++;
    }

    printf("Total votes cast: %d\n", total_votes);

    for(int i=0; i<num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    free(candidates);
    free(voters);
    return 0;
}