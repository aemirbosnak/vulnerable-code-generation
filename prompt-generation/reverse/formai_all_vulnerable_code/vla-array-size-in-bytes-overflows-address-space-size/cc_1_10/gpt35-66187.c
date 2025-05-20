//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidate{
    int cid;
    char name[50];
    int votes;
} Candidate;

typedef struct voter{
    int vid;
    char name[50];
    int voted; //0=not voted, 1=voted
} Voter;

int main(){
    int n; //number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &n);

    Candidate candidates[n];

    for(int i=0; i<n; i++){
        candidates[i].cid = i;
        printf("\nEnter details for candidate %d:\n", i+1);
        printf("Name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int m; //number of voters
    printf("\nEnter the number of voters: ");
    scanf("%d", &m);

    Voter voters[m];

    for(int i=0; i<m; i++){
        voters[i].vid = i;
        printf("\nEnter details for voter %d:\n", i+1);
        printf("Name: ");
        scanf("%s", voters[i].name);
        voters[i].voted = 0; //not voted yet
    }

    //Voting starts now!
    int choice;
    do{
        printf("\n\n---------VOTING MENU---------\n");
        printf("1. Cast your vote\n");
        printf("2. View candidate's vote count\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter your voter ID: ");
                int vid;
                scanf("%d", &vid);
                if(voters[vid].voted == 1){ //already voted
                    printf("You have already voted!\n");
                    break;
                }
                printf("\nEnter the ID of your chosen candidate: ");
                int cid;
                scanf("%d", &cid);
                if(cid >= n){ //invalid candidate ID
                    printf("Invalid candidate ID!\n");
                }else{ //vote cast successfully
                    candidates[cid].votes++;
                    voters[vid].voted = 1;
                    printf("Thank you for voting!\n");
                }
                break;

            case 2:
                printf("\n---------VOTE COUNT---------\n");
                for(int i=0; i<n; i++){
                    printf("%d. %s: %d\n", candidates[i].cid, candidates[i].name, candidates[i].votes);
                }
                break;

            case 3:
                printf("Thank you for using the Electronic Voting System!\n");
                exit(0);
                break;
            
            default:
                printf("Invalid choice!\n");
        }

    }while(choice!=3);

    return 0;
}