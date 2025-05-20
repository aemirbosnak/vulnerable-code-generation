//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char* name;
    char* party;
    char* platform;
} Candidate;

typedef struct {
    int id;
    char* name;
    char* city;
    char* state;
    int age;
} Voter;

int main() {
    // Initialize voter and candidate arrays
    Voter* voters = (Voter*)malloc(10 * sizeof(Voter));
    Candidate* candidates = (Candidate*)malloc(3 * sizeof(Candidate));

    // Populate voter array with random names and locations
    for (int i = 0; i < 10; i++) {
        voters[i].id = i;
        sprintf(voters[i].name, "Voter %d", i + 1);
        sprintf(voters[i].city, "City %d", rand() % 100);
        sprintf(voters[i].state, "State %d", rand() % 50);
        voters[i].age = rand() % 100;
    }

    // Populate candidate array with random names and platforms
    for (int i = 0; i < 3; i++) {
        candidates[i].id = i;
        sprintf(candidates[i].name, "Candidate %d", i + 1);
        sprintf(candidates[i].party, "Party %d", rand() % 10);
        sprintf(candidates[i].platform, "Platform %d", rand() % 100);
    }

    // Print voter and candidate arrays
    printf("Voter IDs:\n");
    for (int i = 0; i < 10; i++) {
        printf("Voter %d: %s %s %d\n", voters[i].id, voters[i].name, voters[i].city, voters[i].age);
    }
    printf("\n");

    printf("Candidate IDs:\n");
    for (int i = 0; i < 3; i++) {
        printf("Candidate %d: %s %s %s\n", candidates[i].id, candidates[i].name, candidates[i].party, candidates[i].platform);
    }
    printf("\n");

    // Simulate voting process
    printf("Voting has begun!\n");
    for (int i = 0; i < 10; i++) {
        int candidate_id = rand() % 3;
        printf("Voter %d has voted for candidate %d!\n", voters[i].id, candidate_id);
    }
    printf("Voting has ended.\n");

    // Print results
    printf("Results:\n");
    for (int i = 0; i < 10; i++) {
        int candidate_id = rand() % 3;
        printf("Voter %d has voted for candidate %d (%d%%)!\n", voters[i].id, candidate_id, (int)(voters[i].age * 100 / 100));
    }
    printf("\n");

    // Free memory
    free(voters);
    free(candidates);

    return 0;
}