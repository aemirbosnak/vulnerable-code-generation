//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct candidate{
        char name[50];
        int votes;
};

struct voter{
        char name[50];
        int id;
};

int main(){
        int i,j,n,m;
        
        printf("\nEnter the number of candidates: ");
        scanf("%d",&n);
        getchar();

        struct candidate c[n];
        for(i=0;i<n;i++){
                printf("\nEnter the name of candidate %d: ",i+1);
                fgets(c[i].name,sizeof(c[i].name),stdin);
                c[i].votes=0;
        }

        printf("\nEnter the number of voters: ");
        scanf("%d",&m);
        getchar();

        struct voter v[m];
        for(i=0;i<m;i++){
                printf("\nEnter the name of voter %d: ",i+1);
                fgets(v[i].name,sizeof(v[i].name),stdin);
                printf("Enter the voter ID: ");
                scanf("%d",&v[i].id);
                getchar();
        }

        int id;
        char c_name[50];
        printf("\nVoting Section: \n");
        for(i=0;i<m;i++){
                printf("\nHi %s, Enter your candidate name to vote: ",v[i].name);
                fgets(c_name,sizeof(c_name),stdin);
                for(j=0;j<n;j++){
                        if(strcmp(c_name,c[j].name)==0){
                                c[j].votes++;
                                printf("\nYour vote has been cast.\n");
                                break;
                        }
                }
                if(j==n) printf("\nInvalid Candidate Name.\n");
        }

        printf("\nVote Summary: \n");
        for(i=0;i<n;i++){
                printf("%s - %d votes\n",c[i].name,c[i].votes);
        }

        return 0;
}