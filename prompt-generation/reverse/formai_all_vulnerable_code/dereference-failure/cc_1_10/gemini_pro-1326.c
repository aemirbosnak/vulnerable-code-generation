//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: happy
// This is a cheerful C program that models a graph of happy faces :)

#include <stdio.h>
#include <stdlib.h>

// Define a happy face struct to represent each node in the graph
typedef struct happy_face {
    char expression;  // The expression of the face, such as ':)' or ':('
    struct happy_face *next;  // A pointer to the next happy face in the list
} happy_face;

// Create a new happy face with the given expression
happy_face *create_face(char expression) {
    happy_face *new_face = (happy_face *)malloc(sizeof(happy_face));
    new_face->expression = expression;
    new_face->next = NULL;
    return new_face;
}

// Add a new happy face to the end of the graph
void add_face(happy_face **graph, char expression) {
    happy_face *new_face = create_face(expression);
    if (*graph == NULL) {  // If the graph is empty, set the first face to the new face
        *graph = new_face;
    } else {  // Otherwise, traverse the graph until we reach the last face
        happy_face *current_face = *graph;
        while (current_face->next != NULL) {
            current_face = current_face->next;
        }
        current_face->next = new_face;  // Add the new face to the end of the graph
    }
}

// Print the happy faces in the graph
void print_faces(happy_face *graph) {
    happy_face *current_face = graph;
    while (current_face != NULL) {  // Traverse the graph and print each face's expression
        printf("%c ", current_face->expression);
        current_face = current_face->next;
    }
    printf("\n");
}

// Free the memory allocated for the graph
void free_faces(happy_face *graph) {
    happy_face *current_face = graph;
    while (current_face != NULL) {  // Traverse the graph and free each face
        happy_face *next_face = current_face->next;
        free(current_face);
        current_face = next_face;
    }
}

int main() {
    happy_face *graph = NULL;  // Initialize the graph to be empty

    // Add some happy faces to the graph
    add_face(&graph, ':)');
    add_face(&graph, ':D');
    add_face(&graph, ';)');
    add_face(&graph, ':P');

    // Print the happy faces in the graph
    print_faces(graph);

    // Free the memory allocated for the graph
    free_faces(graph);

    return 0;  // Spread happiness everywhere!
}