//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int check_if_voted(int id);

struct Candidate 
{
    char name[20];
    int vote_count;
};

int main()
{
    int num_candidates, num_voters, num_votes;
    int id_num, voter_count = 0;
    
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    
    struct Candidate candidates[num_candidates];
    
    for(int i = 0; i < num_candidates; i++)
    {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].vote_count = 0;
    }
    
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    
    int voter_ids[num_voters];
    
    for(int i = 0; i < num_voters; i++)
    {
        printf("Enter the ID number for voter %d: ", i+1);
        scanf("%d", &id_num);
        
        if(check_if_voted(id_num))
        {
            printf("Voter with ID number %d already voted!\n", id_num);
            i--;
        }
        else
        {
            voter_ids[i] = id_num;
            voter_count++;
        }
    }

    srand((unsigned) time(NULL));

    for(int i = 0; i < voter_count; i++)
    {
        printf("Voter %d, choose a candidate:\n", i+1);
        
        for(int j = 0; j < num_candidates; j++) 
        {
            printf("%d. %s\n", j+1, candidates[j].name);
        }
        
        scanf("%d", &num_votes);
        
        while(num_votes < 1 || num_votes > num_candidates) 
        {
            printf("Error: Invalid entry. Please enter number between 1 and %d\n", num_candidates);
            scanf("%d", &num_votes);
        }
        
        candidates[num_votes - 1].vote_count++;
    }
    
    printf("RESULTS: \n");
    printf("-------------------------------------------------\n");
    for(int i = 0; i < num_candidates; i++)
    {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
    printf("-------------------------------------------------\n");
    
    return 0;
}

int check_if_voted(int id)
{
    // This function should check a database or file for previously voted ids.
    // In this example I will use a random boolean to simulate if the voter already voted
    return rand() % 2; 
}