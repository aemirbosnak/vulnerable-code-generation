//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include<stdio.h>
#include<string.h>

//structure for storing voter information
struct Voter
{
    char name[50];
    int age;
    char address[200];
    int vote;
};

//function for casting vote
void castVote(struct Voter v[], int n)
{
    int id, i;
    printf("Enter your voter ID: ");
    scanf("%d", &id);
    for(i=0;i<n;i++)
    {
        if(v[i].vote==0)
        {
            if(i+1==id)
            {
                printf("Enter your vote (1 for candidate A, 2 for candidate B, 3 for candidate C): ");
                scanf("%d", &v[i].vote);
                printf("Thank you for casting your vote!\n");
                return;
            }
        }
    }
    printf("Invalid voter ID or you have already casted your vote.\n");
}

//function for displaying result
void displayResult(struct Voter v[], int n)
{
    int i, c1=0, c2=0, c3=0, invalid=0;
    for(i=0;i<n;i++)
    {
        if(v[i].vote==1)
            c1++;
        else if(v[i].vote==2)
            c2++;
        else if(v[i].vote==3)
            c3++;
        else
            invalid++;
    }
    printf("Candidate A: %d votes\nCandidate B: %d votes\nCandidate C: %d votes\nInvalid votes: %d\n", c1, c2, c3, invalid);
    if(c1>c2 && c1>c3)
        printf("Candidate A wins the election!\n");
    else if(c2>c1 && c2>c3)
        printf("Candidate B wins the election!\n");
    else if(c3>c1 && c3>c2)
        printf("Candidate C wins the election!\n");
    else
        printf("The election is a tie!\n");
}

//main function
int main()
{
    int n, i, choice;
    printf("Enter the number of voters: ");
    scanf("%d", &n);
    struct Voter v[n];
    for(i=0;i<n;i++)
    {
        printf("Enter details for voter %d:\n", i+1);
        printf("Name: ");
        scanf("%s", v[i].name);
        printf("Age: ");
        scanf("%d", &v[i].age);
        printf("Address: ");
        scanf("%s", v[i].address);
        v[i].vote=0;
        printf("\n");
    }
    do
    {
        printf("Menu:\n1. Cast Vote\n2. Display Result\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                castVote(v, n);
                break;
            case 2:
                displayResult(v, n);
                break;
            case 3:
                printf("Thank you for using the electronic voting system.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=3);
    return 0;
}