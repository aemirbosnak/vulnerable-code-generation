//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/* Global variables */
int num_of_candidates;
char **candidates_name;
int *candidates_votes;

void display_candidates()
{
    printf("\nList of Candidates:");
    for(int i=0; i<num_of_candidates; i++)
    {
        printf("\n%d. %s", i+1, candidates_name[i]);
    }
    printf("\n");
}

void cast_vote(int selection)
{
    if(selection > 0 && selection <= num_of_candidates)
    {
        candidates_votes[selection-1]++;
        printf("\nVote casted for %s\n", candidates_name[selection-1]);
    }
    else
    {
        printf("\nInvalid candidate selection.\n");
    }
}

void display_results()
{
    int max_votes_index = 0;
    printf("\nResults:\n");
    for(int i=0; i<num_of_candidates; i++)
    {
        printf("%d. %s - %d votes\n", i+1, candidates_name[i], candidates_votes[i]);
        if(candidates_votes[i] > candidates_votes[max_votes_index])
        {
            max_votes_index = i;
        }
    }
    printf("\nWinner: %s\n", candidates_name[max_votes_index]);
}

int main()
{
    printf("Welcome to the Shape-Shifting Electronic Voting System!");

    printf("\nEnter the number of candidates: ");
    scanf("%d", &num_of_candidates);

    candidates_name = (char**) malloc(num_of_candidates * sizeof(char*));
    candidates_votes = (int*) malloc(num_of_candidates * sizeof(int));

    for(int i=0; i<num_of_candidates; i++)
    {
        char buffer[100];
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", buffer);
        candidates_name[i] = strdup(buffer);
        candidates_votes[i] = 0;
    }

    int is_voting_active = 1;
    while(is_voting_active)
    {
        int selection;
        printf("\n");
        display_candidates();
        printf("Enter the number of the candidate you want to cast your vote to (or enter 0 to exit): ");
        scanf("%d", &selection);
        if(selection == 0)
        {
            is_voting_active = 0;
            printf("\nExiting...");
        }
        else
        {
            cast_vote(selection);
        }
    }

    display_results();

    // Freeing allocated memory
    for(int i=0; i<num_of_candidates; i++)
    {
        free(candidates_name[i]);
    }
    free(candidates_name);
    free(candidates_votes);

    return 0;
}