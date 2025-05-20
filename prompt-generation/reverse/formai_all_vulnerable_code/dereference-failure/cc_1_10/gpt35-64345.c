//FormAI DATASET v1.0 Category: Graph representation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

char *funnyGreetings[] = {"Hey there, graph enthusiasts!", "What's up, nodes and edges?", "Howdy, graphaholics!"};
char *funnyGoodbyes[] = {"Catch ya later, vertices!", "See you later, alligatorgraphs!", "Peace out, edges!"};

// Function to display a random greeting from our array of funny greetings
void displayGreeting() {
    int randomIndex = rand() % 3;
    printf("%s\n", funnyGreetings[randomIndex]);
}

// Function to display a random goodbye from our array of funny goodbyes
void displayGoodbye() {
    int randomIndex = rand() % 3;
    printf("%s\n", funnyGoodbyes[randomIndex]);
}

// Our main function where all the graph magic happens
int main() {
    int numVertices, numEdges;
    printf("Welcome to the Graph-o-Matic 5000!\n");
    displayGreeting();
    printf("Please enter the number of vertices in your graph: ");
    scanf("%d", &numVertices);
    printf("Please enter the number of edges in your graph: ");
    scanf("%d", &numEdges);

    int **adjMatrix = (int **) malloc(sizeof(int *) * numVertices);
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = (int *) malloc(sizeof(int) * numVertices);
    }

    // Let's fill our matrix with some random edge weights
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = rand() % 10;
        }
    }

    // Time to display our graph matrix
    printf("\nYour graph matrix is:\n\n  ");
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", i+1);
    }
    printf("\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    // Clean up our memory
    for(int i = 0; i < numVertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    printf("\n");
    displayGoodbye();
    printf("Thanks for using the Graph-o-Matic 5000!\n");

    return 0;
}