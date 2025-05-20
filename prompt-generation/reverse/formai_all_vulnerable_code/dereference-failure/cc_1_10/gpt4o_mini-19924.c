//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for each character in the love story
typedef struct Character {
    char name[50];
    struct Character *next;
} Character;

// Define a structure for the graph
typedef struct Graph {
    int numCharacters;
    Character **adjacencyList;
} Graph;

// Function to create a new character
Character* createCharacter(const char *name) {
    Character *newCharacter = (Character *)malloc(sizeof(Character));
    strcpy(newCharacter->name, name);
    newCharacter->next = NULL;
    return newCharacter;
}

// Function to create a graph
Graph* createGraph(int numCharacters) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numCharacters = numCharacters;
    graph->adjacencyList = (Character **)malloc(numCharacters * sizeof(Character *));
    for (int i = 0; i < numCharacters; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

// Function to add a connection between two characters
void addConnection(Graph *graph, int src, int dest) {
    Character *newCharacter = createCharacter(graph->adjacencyList[dest]->name);
    newCharacter->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newCharacter;
}

// Function to add a character to the graph
void addCharacter(Graph *graph, const char *name, int index) {
    graph->adjacencyList[index] = createCharacter(name);
}

// Function to display all characters and their connections
void displayGraph(Graph *graph) {
    for (int i = 0; i < graph->numCharacters; i++) {
        Character *temp = graph->adjacencyList[i];
        printf("%s is connected to: ", temp->name);
        temp = temp->next;
        while (temp) {
            printf("%s ", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to bring the love story to life
int main() {
    printf("In the romantic city of CodeVille, where every character yearns for connection...\n\n");

    // Create the graph of characters
    int numberOfCharacters = 5;
    Graph *loveGraph = createGraph(numberOfCharacters);

    // Adding charming characters
    addCharacter(loveGraph, "Luna", 0);
    addCharacter(loveGraph, "Orion", 1);
    addCharacter(loveGraph, "Stella", 2);
    addCharacter(loveGraph, "Leo", 3);
    addCharacter(loveGraph, "Nora", 4);

    // Creating love connections
    addConnection(loveGraph, 0, 1); // Luna -> Orion
    addConnection(loveGraph, 0, 2); // Luna -> Stella
    addConnection(loveGraph, 1, 3); // Orion -> Leo
    addConnection(loveGraph, 2, 4); // Stella -> Nora
    addConnection(loveGraph, 3, 0); // Leo -> Luna
    addConnection(loveGraph, 4, 1); // Nora -> Orion

    // Display the romantic connections in the graph
    printf("The connections between characters in CodeVille:\n");
    displayGraph(loveGraph);

    // Clean up the memory
    for (int i = 0; i < numberOfCharacters; i++) {
        Character *current = loveGraph->adjacencyList[i];
        while (current) {
            Character *toFree = current;
            current = current->next;
            free(toFree);
        }
    }
    free(loveGraph->adjacencyList);
    free(loveGraph);
    
    printf("\nThe love story lives on...\n");
    return 0;
}