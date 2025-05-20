//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include<stdio.h>  
#include<stdlib.h>  
int G[50][50], x[50];  
int n, e, m;  
void next_value(int k)  
{  
    int j;  
    while(1)  
    {  
        x[k]=(x[k]+1)%(m+1);  
        if(x[k]==0)   
        return;  
        for(j=1;j<=n;j++)  
        if(G[k][j]!=0 && x[k]==x[j])  
        break;  
        if(j==n+1)  
        return;  
    }  
}  
void mcoloring(int k)  
{  
    int i;  
    while(1)  
    {  
        next_value(k);  
        if(x[k]==0)  
        return;  
        if(k==n)  
        {  
            printf("\n\n\tColouring of Graph:\n\n");  
            for(i=1;i<=n;i++)  
            printf("\n\t\tVertex %d: Colour %d", i, x[i]);  
            return;  
        }  
        mcoloring(k+1);  
    }  
}  
void main()  
{  
    int i, j, v1, v2;  
    printf("\n\tEnter the number of vertices in Graph: ");  
    scanf("%d",&n);  
    printf("\n\tEnter the number of edges in Graph: ");  
    scanf("%d",&e);  
    for(i=1;i<=n;i++)  
    for(j=1;j<=n;j++)  
    G[i][j]=0;  
    printf("\n\tEnter the edges [u(v1) v(v2)]:\n");  
    for(i=1;i<=e;i++)  
    {  
        printf("\n\t\tEnter edge %d:",i);  
        scanf("%d%d",&v1,&v2);  
        G[v1][v2]=G[v2][v1]=1;  
    }  
    printf("\n\tEnter the max permissible colours: ");  
    scanf("%d",&m);  
    printf("\n\n");  
    for(i=1;i<=n;i++)  
    x[i]=0;  
    printf("\n\n\tColoring possibilities of graph are:\n\n");  
    mcoloring(1);  
}