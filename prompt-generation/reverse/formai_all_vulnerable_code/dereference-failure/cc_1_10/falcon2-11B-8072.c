//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the number of vertices in the graph
#define VERTICES 5

// Define the maximum number of colors used in the graph
#define MAX_COLORS 5

// Define a structure to store each vertex in the graph
typedef struct vertex {
    int color;
    struct vertex *next;
} vertex;

// Define a function to print the graph
void print_graph(vertex *head) {
    vertex *current = head;
    while (current!= NULL) {
        printf("%d ", current->color);
        current = current->next;
    }
    printf("\n");
}

// Define a function to find a valid coloring of the graph
bool color_graph(vertex *head, int *colors) {
    int i;
    vertex *current = head;
    
    // Find a valid coloring of the graph
    while (current!= NULL) {
        for (i = 0; i < MAX_COLORS; i++) {
            if (colors[i] == 0 && current->color == i) {
                colors[i] = 1;
                break;
            }
        }
        current = current->next;
    }
    
    // Return true if a valid coloring was found, false otherwise
    return (bool) (colors[0] == 1);
}

int main() {
    // Create the graph
    vertex *head = (vertex *) malloc(sizeof(vertex));
    vertex *second = (vertex *) malloc(sizeof(vertex));
    vertex *third = (vertex *) malloc(sizeof(vertex));
    vertex *fourth = (vertex *) malloc(sizeof(vertex));
    vertex *fifth = (vertex *) malloc(sizeof(vertex));
    
    // Initialize the vertices
    head->color = 0;
    head->next = second;
    second->color = 1;
    second->next = third;
    third->color = 2;
    third->next = fourth;
    fourth->color = 3;
    fourth->next = fifth;
    fifth->color = 4;
    fifth->next = NULL;
    
    // Find a valid coloring of the graph
    int colors[MAX_COLORS];
    if (color_graph(head, colors) == true) {
        printf("Graph is %s colorable\n", (colors[0] == 1)? "not" : " ");
    } else {
        printf("Graph is not colorable\n");
    }
    
    // Print the graph
    printf("Graph:\n");
    print_graph(head);
    
    // Free the memory used by the graph
    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    
    return 0;
}