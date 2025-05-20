//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int num_voters = 100;
    char **voters_list = (char **)malloc(num_voters * sizeof(char *));

    for (int i = 0; i < num_voters; i++)
    {
        voters_list[i] = (char *)malloc(20 * sizeof(char));
    }

    // Get voters' information
    for (int i = 0; i < num_voters; i++)
    {
        printf("Enter your name: ");
        scanf("%s", voters_list[i]);

        printf("Enter your vote: ");
        scanf("%s", voters_list[i]);
    }

    // Count votes
    int vote_count = 0;
    char vote_choice;
    for (int i = 0; i < num_voters; i++)
    {
        vote_choice = voters_list[i][0];
        switch (vote_choice)
        {
            case 'A':
                vote_count++;
                break;
            case 'B':
                vote_count++;
                break;
            case 'C':
                vote_count++;
                break;
            default:
                break;
        }
    }

    // Display results
    printf("\n");
    printf("The results of the election are:");
    printf("\n");
    printf("Candidate A received %d votes.", vote_count);
    printf("\n");
    printf("Candidate B received %d votes.", vote_count);
    printf("\n");
    printf("Candidate C received %d votes.", vote_count);

    free(voters_list);
    return;
}