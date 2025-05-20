//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX 100

struct candidate{
    char name[20];
    int votes;
};

void swap(struct candidate* a, struct candidate* b){
    struct candidate temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b){
    struct candidate* c1 = (struct candidate*)a;
    struct candidate* c2 = (struct candidate*)b;
    return strcmp(c1->name, c2->name);
}

void print_candidates(struct candidate candidates[], int n){
    printf("Candidate Name\tVotes\n");
    for(int i=0; i<n; i++){
        printf("%s\t%d\n", candidates[i].name, candidates[i].votes);
    }
}

int main(){
    int n;
    printf("Enter the number of candidates: ");
    scanf("%d", &n);

    struct candidate candidates[n];

    for(int i=0; i<n; i++){
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int m;
    printf("Enter the number of voters: ");
    scanf("%d", &m);

    int votes[m][n];

    for(int i=0; i<m; i++){
        printf("Enter the votes for candidate 1: ");
        for(int j=0; j<n; j++){
            scanf("%d", &votes[i][j]);
        }
    }

    for(int i=0; i<m-1; i++){
        for(int j=0; j<n-1; j++){
            if(votes[i][j] < votes[i][j+1]){
                swap(candidates+j, candidates+j+1);
            }
        }
    }

    qsort(candidates, n, sizeof(struct candidate), compare);

    printf("Sorted candidates:\n");
    print_candidates(candidates, n);

    return 0;
}