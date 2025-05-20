//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for a vertex in the graph
struct vertex {
    int color;
    struct vertex *next;
};

// Function to print the graph
void printGraph(struct vertex *head) {
    while (head!= NULL) {
        printf("%d->", head->color);
        head = head->next;
    }
    printf("\n");
}

// Function to perform a DFS on the graph
void dfs(struct vertex *head, int color) {
    // Mark the vertex as visited
    head->color = color;

    // Traverse the adjacency list
    struct vertex *current = head->next;
    while (current!= NULL) {
        if (current->color == -1) {
            // If the vertex is not colored yet, color it
            current->color = color;
            dfs(current, color);
        }
        current = current->next;
    }
}

// Function to color the graph using DFS
void colorGraph(struct vertex *head) {
    int colorCount = 0;
    int colors[3] = {0, 1, 2};

    while (head!= NULL) {
        if (head->color == -1) {
            dfs(head, colors[colorCount]);
            colorCount++;
        }
        head = head->next;
    }
}

// Function to add a vertex to the graph
void addVertex(struct vertex **head, int color) {
    struct vertex *newVertex = (struct vertex *)malloc(sizeof(struct vertex));
    newVertex->color = color;
    newVertex->next = NULL;

    // If the graph is empty, make the new vertex the head
    if (*head == NULL) {
        *head = newVertex;
    } else {
        // Otherwise, traverse the adjacency list and add the new vertex at the end
        struct vertex *current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newVertex;
    }
}

// Function to remove a vertex from the graph
void removeVertex(struct vertex **head, int color) {
    struct vertex *current = *head;
    struct vertex *previous = NULL;

    // Traverse the adjacency list and remove the vertex
    while (current->next!= NULL) {
        if (current->next->color == color) {
            if (previous == NULL) {
                // If the vertex is the head, update the head pointer
                *head = current->next;
            } else {
                // If the vertex is not the head, update the previous pointer
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to check if the graph is properly colored
int isColored(struct vertex *head) {
    int colorCount = 0;
    int colors[3] = {0, 1, 2};

    while (head!= NULL) {
        if (head->color!= colors[colorCount]) {
            return 0;
        }
        colorCount++;
        head = head->next;
    }
    return 1;
}

// Main function
int main() {
    // Create the graph
    struct vertex *head = NULL;
    addVertex(&head, 1);
    addVertex(&head, 2);
    addVertex(&head, 3);
    addVertex(&head, 4);
    addVertex(&head, 5);

    // Color the graph using DFS
    colorGraph(head);

    // Check if the graph is properly colored
    if (isColored(head)) {
        printf("The graph is properly colored.\n");
    } else {
        printf("The graph is not properly colored.\n");
    }

    // Remove the vertex with color 2
    removeVertex(&head, 2);

    // Check if the graph is properly colored again
    if (isColored(head)) {
        printf("The graph is properly colored after removing the vertex.\n");
    } else {
        printf("The graph is not properly colored after removing the vertex.\n");
    }

    return 0;
}