//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int vote_id;
    char* name;
    int age;
} Candidate;

int main() {
    // Initialize candidates
    Candidate candidate1 = {0, "John Doe", 25};
    Candidate candidate2 = {1, "Jane Smith", 30};
    Candidate candidate3 = {2, "Bob Johnson", 35};

    // Create a voter
    char voter_name[100];
    printf("Enter your name: ");
    fgets(voter_name, sizeof(voter_name), stdin);
    strcpy(voter_name, voter_name);

    // Create a ballot
    int ballot_id = rand() % 3;
    Candidate* ballot = (Candidate*)malloc(sizeof(Candidate));
    *ballot = candidate1;

    // Vote
    printf("Vote for candidate %s (%d)\n", ballot->name, ballot->vote_id);
    printf("Vote for candidate %s (%d)\n", candidate2.name, candidate2.vote_id);
    printf("Vote for candidate %s (%d)\n", candidate3.name, candidate3.vote_id);
    printf("Enter your vote: ");
    int vote = atoi(fgets(NULL, 0, stdin));
    printf("You have voted for candidate %s (%d)\n", ballot->name, ballot->vote_id);

    // Count votes
    int max_votes = 0;
    int winner = 0;
    for (int i = 0; i < 3; i++) {
        int votes = 0;
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                votes++;
            }
        }
        if (votes > max_votes) {
            max_votes = votes;
            winner = i;
        }
    }

    // Announce winner
    printf("The winner is %s (%d) with %d votes\n", ballot->name, ballot->vote_id, max_votes);

    return 0;
}