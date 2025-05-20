//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES] = {
    {"King John", 0},
    {"Queen Mary", 0},
    {"Prince William", 0},
    {"Princess Sophia", 0},
    {"The Evil Baron", 0}
};

void vote(char candidate)
{
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        if (strcmp(candidates[i].name, candidate) == 0)
        {
            candidates[i].votes++;
            break;
        }
    }
}

int main()
{
    char vote_choice;

    printf("Welcome to the Grand Assembly!\n");
    printf("Please select a candidate to vote for:\n");

    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    scanf("Enter your choice: ", &vote_choice);

    vote(vote_choice);

    printf("Thank you for voting, %c!\n", vote_choice);

    return 0;
}