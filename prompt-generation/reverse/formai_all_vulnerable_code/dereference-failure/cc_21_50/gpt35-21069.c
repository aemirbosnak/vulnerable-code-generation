//FormAI DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Shape-shifting C Graph Representation Example
int main(){
    int size = 5, i, j, option;
    int **graph;

    // Initial Graph as a 5x5 Matrix
    graph = (int **) malloc(size*sizeof(int *));
    for(i=0; i<size; i++)
        graph[i] = (int *) malloc(size*sizeof(int));

    // Filling initial graph matrix with 1's and 0's
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            if(i == j || abs(i-j) == 1)
                graph[i][j] = 1;
            else
                graph[i][j] = 0;
        }
    }

    // Printing initial graph matrix
    printf("\nInitial Graph Matrix:\n");
    for(i=0; i<size; i++){
        for(j=0; j<size; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    // Shape-shifting options loop
    while(1){
        // Prompt user for shape-shifting option
        printf("\nSelect a shape-shifting option:\n");
        printf("1. Double the size of the Graph\n");
        printf("2. Add an additional row and column to the Graph\n");
        printf("3. Add an additional column and delete the last row from the Graph\n");
        printf("4. Exit program\n");
        printf("Option: ");
        scanf("%d", &option);

        // Shape-shifting based on user option
        if(option == 1){
            // Double the size of the Graph
            int **new_graph;
            size = size * 2;

            // Create a new graph matrix with double size
            new_graph = (int **) malloc(size*sizeof(int *));
            for(i=0; i<size; i++)
                new_graph[i] = (int *) malloc(size*sizeof(int));

            // Copy elements from old graph matrix to new graph matrix
            for(i=0; i<size/2; i++){
                for(j=0; j<size/2; j++){
                    new_graph[i][j] = graph[i][j];
                    new_graph[i+size/2][j+size/2] = graph[i][j];
                    new_graph[i][j+size/2] = 0;
                    new_graph[i+size/2][j] = 0;
                }
            }
            free(graph);
            graph = new_graph;

            // Printing new graph matrix
            printf("\nGraph Matrix after doubling the size:\n");
            for(i=0; i<size; i++){
                for(j=0; j<size; j++)
                    printf("%d ", graph[i][j]);
                printf("\n");
            }
        }
        else if(option == 2){
            // Add an additional row and column to the Graph
            int **new_graph;
            size = size + 1;

            // Create a new graph matrix with addition of a row and column
            new_graph = (int **) malloc(size*sizeof(int *));
            for(i=0; i<size; i++)
                new_graph[i] = (int *) malloc(size*sizeof(int));

            // Copy elements from old graph matrix to new graph matrix
            for(i=0; i<size-1; i++){
                for(j=0; j<size-1; j++)
                    new_graph[i][j] = graph[i][j];
                new_graph[i][j] = 0;
                new_graph[j][i] = 0;
            }
            free(graph);
            graph = new_graph;

            // Printing new graph matrix
            printf("\nGraph Matrix after adding an additional row and column:\n");
            for(i=0; i<size; i++){
                for(j=0; j<size; j++)
                    printf("%d ", graph[i][j]);
                printf("\n");
            }
        }
        else if(option == 3){
            // Add an additional column and delete the last row from the Graph
            int **new_graph;
            size = size;

            // Create a new graph matrix with addition of a column and deletion of the last row
            new_graph = (int **) malloc(size*sizeof(int *));
            for(i=0; i<size; i++)
                new_graph[i] = (int *) malloc(size*sizeof(int));

            // Copy elements from old graph matrix to new graph matrix
            for(i=0; i<size-1; i++){
                for(j=0; j<size-1; j++)
                    new_graph[i][j] = graph[i][j];
                new_graph[i][j] = 0;
                new_graph[j][i] = 0;
            }
            free(graph);
            graph = new_graph;

            // Printing new graph matrix
            printf("\nGraph Matrix after adding an additional column and deleting the last row:\n");
            for(i=0; i<size; i++){
                for(j=0; j<size; j++)
                    printf("%d ", graph[i][j]);
                printf("\n");
            }
        }
        else if(option == 4){
            // Exit program
            break;
        }
        else{
            printf("\nInvalid Option! Try Again.\n");
        }
    }

    return 0;
}