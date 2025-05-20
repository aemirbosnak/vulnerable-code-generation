//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Voter
{
    char name[50];
    int vote_id;
    int vote_cast;
} Voter;

typedef struct Candidate
{
    char name[50];
    int vote_count;
} Candidate;

void initialize_system(Candidate *candidates, Voter *voters)
{
    // Initialize candidates
    candidates->vote_count = 0;
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].name[0] = '\0';
    }

    // Initialize voters
    voters->vote_cast = 0;
    for (int i = 0; i < MAX_VOTES; i++)
    {
        voters[i].name[0] = '\0';
        voters[i].vote_id = -1;
    }
}

void cast_vote(Voter *voter, Candidate *candidates)
{
    // Validate voter
    if (voter->vote_cast)
    {
        printf("Error: You have already voted.\n");
        return;
    }

    // Get candidate choice
    char candidate_choice;
    printf("Enter the candidate's choice (A-Z): ");
    scanf("%c", &candidate_choice);

    // Validate candidate choice
    if (candidate_choice < 'A' || candidate_choice > 'Z')
    {
        printf("Error: Invalid candidate choice.\n");
        return;
    }

    // Cast vote
    voter->vote_cast = 1;
    candidates[candidate_choice - 'A'].vote_count++;
}

void display_results(Candidate *candidates)
{
    // Print results
    printf("Election Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }

    // Declare winner
    int winner = 0;
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        if (candidates[i].vote_count > candidates[winner].vote_count)
        {
            winner = i;
        }
    }

    printf("Winner: %s\n", candidates[winner].name);
}

int main()
{
    // Allocate memory for candidates and voters
    Candidate *candidates = (Candidate *)malloc(MAX_CANDIDATES * sizeof(Candidate));
    Voter *voters = (Voter *)malloc(MAX_VOTES * sizeof(Voter));

    // Initialize the system
    initialize_system(candidates, voters);

    // Cast votes
    cast_vote(voters, candidates);

    // Display results
    display_results(candidates);

    // Free memory
    free(candidates);
    free(voters);

    return 0;
}