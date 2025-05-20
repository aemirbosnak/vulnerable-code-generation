//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

typedef struct{
    int **coins;
    int n;
    int m;
    int *dp;
}Greed;

Greed* createGreed(int n,int m){
    Greed *g = (Greed*)malloc(sizeof(Greed));
    g->n = n;
    g->m = m;
    g->coins = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        g->coins[i] = (int*)malloc(m*sizeof(int));
        for(int j=0;j<m;j++){
            scanf("%d",&(g->coins[i][j]));
        }
    }
    g->dp = (int*)malloc(m*sizeof(int));
    for(int i=0;i<m;i++){
        g->dp[i] = INT_MAX;
    }
    return g;
}

int minCoins(Greed *g,int i,int j){
    if(i==j){
        return 0;
    }
    if(i>j){
        return INT_MAX;
    }
    if(g->dp[i]!=INT_MAX){
        return g->dp[i];
    }
    int min = INT_MAX;
    for(int k=i;k<=j;k++){
        int temp = minCoins(g,i,k-1) + minCoins(g,k+1,j);
        if(temp<min){
            min = temp;
        }
    }
    g->dp[i] = min + g->coins[i][j];
    return min + g->coins[i][j];
}

void printSolution(Greed *g){
    printf("Minimum number of coins required: %d\n",minCoins(g,0,g->n-1));
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    Greed *g = createGreed(n,m);
    printSolution(g);
    return 0;
}