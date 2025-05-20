//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the vote structure
typedef struct {
    int candidate_id;
} Vote;

// Define the candidate structure
typedef struct {
    int id;
    char name[50];
    int vote_count;
} Candidate;

// Define the list of candidates and number of candidates
Candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;

// Define the list of votes and number of votes
Vote votes[MAX_VOTERS];
int num_votes = 0;

// Function to add a candidate to the list of candidates
void add_candidate(int id, char name[]) {
    candidates[num_candidates].id = id;
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].vote_count = 0;
    num_candidates++;
}

// Function to print the list of candidates and their vote count
void print_results() {
    printf("Candidate\tVote Count\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s\t%d\n", candidates[i].name, candidates[i].vote_count);
    }
}

// Function to get a vote from a voter
void get_vote(int voter_id) {
    int candidate_id;
    printf("Enter the candidate id you want to vote for: ");
    scanf("%d", &candidate_id);
    votes[num_votes].candidate_id = candidate_id;
    num_votes++;
}

// Main function
int main() {
    int num_voters, voter_id;
    char candidate_name[50];

    printf("Welcome to the Electronic Voting System\n");

    // Get the number of candidates and add to the candidate list
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidate_name);
        add_candidate(i+1, candidate_name);
    }

    // Get the number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Get the votes of each voter
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the voter id: ");
        scanf("%d", &voter_id);
        get_vote(voter_id);
    }

    // Count the votes for each candidate
    for (int i = 0; i < num_votes; i++) {
        int candidate_id = votes[i].candidate_id;
        for (int j = 0; j < num_candidates; j++) {
            if (candidates[j].id == candidate_id) {
                candidates[j].vote_count++;
                break;
            }
        }
    }

    // Print the results
    print_results();

    return 0;
}