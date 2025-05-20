//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

struct voter
{
    int id;
    char name[50];
    int age;
};

struct candidate
{
    int id;
    char name[50];
    int votes;
};

struct ballot
{
    int id;
    struct voter* voters;
    struct candidate* candidates;
};

int main()
{
    struct ballot* ballot = (struct ballot*)malloc(sizeof(struct ballot));
    
    struct voter* voters = (struct voter*)malloc(sizeof(struct voter));
    voters->id = 1;
    strcpy(voters->name, "John Doe");
    voters->age = 35;
    
    struct candidate* candidates = (struct candidate*)malloc(sizeof(struct candidate));
    candidates->id = 1;
    strcpy(candidates->name, "John Doe");
    candidates->votes = 0;
    
    ballot->id = 1;
    ballot->voters = voters;
    ballot->candidates = candidates;
    
    printf("Voter ID: %d\n", ballot->voters->id);
    printf("Voter Name: %s\n", ballot->voters->name);
    printf("Voter Age: %d\n", ballot->voters->age);
    
    printf("Candidate ID: %d\n", ballot->candidates->id);
    printf("Candidate Name: %s\n", ballot->candidates->name);
    printf("Candidate Votes: %d\n", ballot->candidates->votes);
    
    return 0;
}