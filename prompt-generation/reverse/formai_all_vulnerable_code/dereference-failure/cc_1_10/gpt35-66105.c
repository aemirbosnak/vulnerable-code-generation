//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

//Function to check if the color can be assigned to the vertex
int isSafe(int v, int n, int **G, int color[], int c)
{
    for(int i=0; i<n; i++)
    {
        if(G[v][i] && c==color[i])
            return 0;
    }
    return 1;
}

//Function to color the graph recursively
int graphColor(int **G, int n, int m, int color[], int v)
{
    //Base Case: If all the vertices are assigned a color, return true
    if(v==n)
        return 1;
    
    //Check color for each vertex
    for(int c=1; c<=m; c++)
    {
        //Check if the color can be assigned to vertex v
        if(isSafe(v, n, G, color, c))
        {
            //Assign the color and move on to next vertex
            color[v] = c;
            
            //Recursive call
            if(graphColor(G, n, m, color, v+1))
                return 1;
                
            //Backtrack if no color can be assigned
            color[v] = 0;
        }
    }
    return 0;
}

int main()
{
    //Number of vertices and edges
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    
    //Adjacency matrix representation of graph
    int **G = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
        G[i] = (int*)calloc(n, sizeof(int));
    
    //Input edges
    for(int i=0; i<e; i++)
    {
        int u, v;
        printf("Enter the edge %d: ", i+1);
        scanf("%d%d", &u, &v);
        G[u][v] = G[v][u] = 1; //Undirected graph
    }
    
    //Number of colors available
    int m;
    printf("Enter the number of colors available: ");
    scanf("%d", &m);
    
    //Color array to store the color assigned to each vertex
    int *color = (int*)calloc(n, sizeof(int));
    
    //Function call to color the graph
    if(graphColor(G, n, m, color, 0))
    {
        printf("\nGraph can be colored using %d colors as follows:\n\n", m);
        for(int i=0; i<n; i++)
            printf("Vertex %d: Color %d\n", i+1, color[i]);
    }
    else
        printf("\nGraph cannot be colored using %d colors.\n", m);
    
    //Free memory
    for(int i=0; i<n; i++)
        free(G[i]);
    free(G);
    free(color);
    
    return 0;
}