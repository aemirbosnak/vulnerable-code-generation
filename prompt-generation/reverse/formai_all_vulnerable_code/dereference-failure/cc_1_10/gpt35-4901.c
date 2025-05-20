//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
// It was a dark and stormy night. Detective Holmes was pondering over the case of a missing data structure. 
// He knew that he had to visualize the data structure in order to solve the case. 
// Thus, he came up with a plan to create a C code that could do just that. 
// As he sat down to write the code, lightning struck, illuminating the room.

#include <stdio.h>
#include <stdlib.h>

// The data structure to be visualized
struct node {
    int data;
    struct node* next;
};

// Function to add a node to the data structure
void addNode(struct node** head, int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to display the data structure visually
void display(struct node* head) {
    // Initialize the variables needed for visualization
    int nodeLength = 4; // Length of each node block
    int arrowLength = 4; // Length of each arrow
    int spacesBeforeData = (nodeLength - 1) / 2; // Spaces needed before data
    int spacesAfterData = nodeLength - spacesBeforeData - 1; // Spaces needed after data

    // Print the top of the visualization
    printf("┌");
    for (int i = 0; i < nodeLength + arrowLength; i++) {
        printf("─");
    }
    printf("┐\n");

    // Print the nodes and arrows
    while (head != NULL) {
        // Print spaces before the data
        printf("│");
        for (int i = 0; i < spacesBeforeData; i++) {
            printf(" ");
        }

        // Print the data
        printf("%d", head->data);

        // Print spaces after the data
        for (int i = 0; i < spacesAfterData; i++) {
            printf(" ");
        }

        // Print the arrow
        if (head->next != NULL) {
            printf("┤");
            for (int i = 0; i < arrowLength; i++) {
                printf("─");
            }
        }
        else {
            printf("┐");
        }

        // Move to the next node
        head = head->next;

        // Print a new line
        printf("\n");

        // Print the bottom of the node
        if (head != NULL) {
            printf("├");
            for (int i = 0; i < nodeLength; i++) {
                printf("─");
            }
        }
        else {
            printf("└");
            for (int i = 0; i < nodeLength; i++) {
                printf("─");
            }
        }
    }

    // Print a new line
    printf("\n");
}

int main() {
    // Initialize the data structure
    struct node* head = NULL;

    // Add some nodes to the data structure
    addNode(&head, 5);
    addNode(&head, 7);
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 9);
    addNode(&head, 1);
    addNode(&head, 6);

    // Display the data structure visually
    display(head);

    return 0;
}