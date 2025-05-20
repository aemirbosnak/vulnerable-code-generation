//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the data structure
#define MAX_SIZE 100

// Define the structure of each node in the data structure
typedef struct {
    int data;
    struct node* next;
} Node;

// Define the structure of the data structure
typedef struct {
    Node* head;
    int size;
} DataStructure;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new data structure
DataStructure* newDataStructure() {
    DataStructure* dataStructure = (DataStructure*)malloc(sizeof(DataStructure));
    dataStructure->head = NULL;
    dataStructure->size = 0;
    return dataStructure;
}

// Function to add a node to the data structure
void addNode(DataStructure* dataStructure, int data) {
    Node* node = newNode(data);
    if (dataStructure->head == NULL) {
        dataStructure->head = node;
    } else {
        Node* temp = dataStructure->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    dataStructure->size++;
}

// Function to display the data structure
void displayDataStructure(DataStructure* dataStructure) {
    if (dataStructure->head == NULL) {
        printf("Data structure is empty.\n");
    } else {
        printf("Data structure contains the following nodes:\n");
        Node* temp = dataStructure->head;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to check if the data structure is empty
bool isEmpty(DataStructure* dataStructure) {
    return (dataStructure->head == NULL);
}

// Function to get the size of the data structure
int getSize(DataStructure* dataStructure) {
    return dataStructure->size;
}

int main() {
    // Create a new data structure
    DataStructure* dataStructure = newDataStructure();

    // Add some nodes to the data structure
    addNode(dataStructure, 10);
    addNode(dataStructure, 20);
    addNode(dataStructure, 30);
    addNode(dataStructure, 40);

    // Display the data structure
    displayDataStructure(dataStructure);

    // Check if the data structure is empty
    printf("Is the data structure empty? %s\n", isEmpty(dataStructure)? "Yes" : "No");

    // Get the size of the data structure
    printf("Size of the data structure: %d\n", getSize(dataStructure));

    // Free the memory used by the data structure
    free(dataStructure->head);
    free(dataStructure);

    return 0;
}