//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max_size 100

int adj_matrix[max_size][max_size], color_assignment[max_size];
int num_vertex, num_color = 0;

void graph_coloring()
{
    int i,j, color;
    srand(time(NULL));
    
    for(i=0; i<num_vertex; i++)
    {
        color_assignment[i] = -1;
    }
    
    color_assignment[0] = rand() % num_color; //Assign random color to first vertex
    
    for(i=1; i<num_vertex; i++)
    {
        for(color=0; color<num_color; color++)
        {
            int flag = 1;
            
            for(j=0; j<num_vertex; j++)
            {
                if(adj_matrix[i][j] == 1 && color_assignment[j] == color)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
            {
                color_assignment[i] = color;
                break;
            }
        }
        
        if(color_assignment[i] == -1)
        {
            printf("Not possible to coloring.\n");
            break;
        }
    }
}

void print_coloring()
{
    int i;
    printf("\nNode and its color:\n");
    for(i=0; i<num_vertex; i++)
        printf("%d : %d\n",i+1,color_assignment[i] + 1);
}

int main()
{
    int i,j;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertex);
    
    printf("\nEnter adjacency matrix(1 if connected 0 otherwise):\n");
    for(i=0; i<num_vertex; i++)
    {
        for(j=0; j<num_vertex; j++)
        {
            scanf("%d",&adj_matrix[i][j]);
        }
    }
    
    printf("\nEnter number of colors: ");
    scanf("%d",&num_color);
    
    graph_coloring();
    print_coloring();
    
    return 0;
}