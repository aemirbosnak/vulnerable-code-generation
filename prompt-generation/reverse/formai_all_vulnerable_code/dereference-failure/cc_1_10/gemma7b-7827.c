//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define PIN_LENGTH 4
#define BALLOT_LENGTH 20
#define MAX_CANDIDATES 5

typedef struct Voter
{
    char pin[PIN_LENGTH];
    char ballot[BALLOT_LENGTH];
    int candidate_choice;
} Voter;

Voter voters[MAX_CANDIDATES];

void initialize_voters()
{
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        voters[i].pin[0] = '\0';
        voters[i].ballot[0] = '\0';
        voters[i].candidate_choice = -1;
    }
}

void cast_vote(char pin, int candidate_choice)
{
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        if (strcmp(pin, voters[i].pin) == 0)
        {
            if (voters[i].candidate_choice == -1)
            {
                voters[i].candidate_choice = candidate_choice;
                printf("Vote cast for candidate %d.\n", candidate_choice);
            }
            else
            {
                printf("Error: you have already voted.");
            }
        }
    }
}

int main()
{
    initialize_voters();

    char pin;
    int candidate_choice;

    printf("Enter your PIN:");
    scanf("%s", pin);

    printf("Enter your candidate choice (1-5):");
    scanf("%d", &candidate_choice);

    cast_vote(pin, candidate_choice);

    return 0;
}