//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a romantic character in our love story graph
typedef struct Character {
    char name[50];
    struct Character* next; // Pointer to the next character in love
} Character;

// Structure to represent the love graph
typedef struct LoveGraph {
    int numOfCharacters;
    Character** adjacencyList;
} LoveGraph;

// Function to create a new character
Character* createCharacter(char* name) {
    Character* newCharacter = (Character*)malloc(sizeof(Character));
    strcpy(newCharacter->name, name);
    newCharacter->next = NULL;
    return newCharacter;
}

// Function to create a love graph
LoveGraph* createLoveGraph(int numOfCharacters) {
    LoveGraph* graph = (LoveGraph*)malloc(sizeof(LoveGraph));
    graph->numOfCharacters = numOfCharacters;
    graph->adjacencyList = (Character**)malloc(numOfCharacters * sizeof(Character*));

    for (int i = 0; i < numOfCharacters; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Function to add a love connection between two characters
void addLoveConnection(LoveGraph* graph, char* loverA, char* loverB) {
    int indexA = (int)(loverA[0] - 'A');  // Using the first letter for simple indexing
    int indexB = (int)(loverB[0] - 'A');

    Character* newConnection = createCharacter(loverB);
    newConnection->next = graph->adjacencyList[indexA];
    graph->adjacencyList[indexA] = newConnection;

    // For a two-way love connection, uncomment the next two lines
    // newConnection = createCharacter(loverA);
    // newConnection->next = graph->adjacencyList[indexB]; 
    // graph->adjacencyList[indexB] = newConnection; 
}

// Function to display the love connections of the characters
void displayLoveGraph(LoveGraph* graph) {
    for (int i = 0; i < graph->numOfCharacters; i++) {
        Character* temp = graph->adjacencyList[i];
        if (temp != NULL) {
            printf("%c's loves: ", 'A' + i);
            while (temp != NULL) {
                printf("%s ", temp->name);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

// Function to free the memory allocated for the love graph
void freeLoveGraph(LoveGraph* graph) {
    for (int i = 0; i < graph->numOfCharacters; i++) {
        Character* current = graph->adjacencyList[i];
        while (current != NULL) {
            Character* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjacencyList);
    free(graph);
}

// Main function to execute the romantic love graph
int main() {
    printf("Welcome to the Romantic Love Graph!\n");

    // Number of lovers represented by letters A to Z
    int numberOfLovers = 26;
    LoveGraph* loveGraph = createLoveGraph(numberOfLovers);

    // Let's create some love connections in this romantic journey:
    addLoveConnection(loveGraph, "A", "B"); // A loves B
    addLoveConnection(loveGraph, "A", "C"); // A loves C
    addLoveConnection(loveGraph, "B", "D"); // B loves D
    addLoveConnection(loveGraph, "C", "D"); // C loves D
    addLoveConnection(loveGraph, "D", "E"); // D loves E
    addLoveConnection(loveGraph, "E", "A"); // E loves A - a beautiful cycle

    // Display all love connections
    displayLoveGraph(loveGraph);

    // Free the memory
    freeLoveGraph(loveGraph);
    
    printf("Thank you for joining us in this tale of love!\n");

    return 0;
}