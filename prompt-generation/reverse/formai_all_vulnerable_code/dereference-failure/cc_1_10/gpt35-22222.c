//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for representing a node in a linked list
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to add a new node at the beginning of a linked list
void push(struct node** head_ref, int data) {
    struct node* temp = newNode(data);
    temp->next = (*head_ref);
    (*head_ref) = temp;
}

// Function to find the sum of all the nodes in a linked list
int sumOfNodes(struct node* head) {
    if (head == NULL)
        return 0;
    else
        return head->data + sumOfNodes(head->next);
}

// Recursive function to monitor network quality of service
void monitorQoS() {
    // Create an empty linked list
    struct node* head = NULL;

    // Generate random network traffic values and add them to the linked list
    int i;
    for (i = 0; i < 10; i++) {
        int val = rand() % 101; // Generate a random value between 0 and 100
        push(&head, val); // Add the value to the linked list
    }

    // Calculate the average network traffic value
    int sum = sumOfNodes(head);
    int count = 10;
    float average = (float)sum / count;

    // Display the average network traffic value
    printf("Average Network Traffic: %.2f\n", average);

    // Determine if network quality of service meets criteria
    bool meets_criteria = false;
    if (average > 80.0) {
        printf("Network Quality of Service: Poor\n");
        meets_criteria = false;
    } else if (average > 60.0) {
        printf("Network Quality of Service: Fair\n");
        meets_criteria = true;
    } else {
        printf("Network Quality of Service: Good\n");
        meets_criteria = true;
    }

    // If network quality of service does not meet criteria, recursively call the function again
    if (!meets_criteria) {
        printf("Monitoring Network Quality of Service...\n");
        monitorQoS();
    } else {
        printf("Network Quality of Service meets criteria.\n");
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Call the function to monitor network quality of service
    monitorQoS();

    return 0;
}