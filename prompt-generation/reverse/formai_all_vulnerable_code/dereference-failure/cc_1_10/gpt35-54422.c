//FormAI DATASET v1.0 Category: Data structures visualization ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct for each node in the linked list
struct Node{
    int data;
    struct Node* next;
};

// Function to create a new node with a random value
struct Node* createNode(){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = rand()%100;
    newNode->next = NULL;
    return newNode;
}

int main(){
    // Initialize the head of the linked list
    struct Node* head = createNode();

    // Generate 10 more random nodes and connect them to the linked list
    for(int i = 0; i < 10; i++){
        struct Node* newNode = createNode();
        newNode->next = head;
        head = newNode;
    }

    // Print the linked list with arrows pointing to the next node
    struct Node* currNode = head;
    printf("Linked List:\n");
    while(currNode != NULL){
        printf("%d -> ", currNode->data);
        currNode = currNode->next;
    }
    printf("NULL\n");

    // Create an array of 5 random integers
    int arr[5];
    for(int i = 0; i < 5; i++){
        arr[i] = rand()%100;
    }

    // Print the array in a spiral pattern
    printf("\nArray:\n");
    int x = 0, y = -1, flag = 1, count = 5;
    while(count > 0){
        for(int i = 0; i < count; i++){
            y += flag;
            printf("%d ",arr[x*5 + y]);
        }
        count--;
        if(count == 0) break;
        for(int i = 0; i < count; i++){
            x += flag;
            printf("%d ",arr[x*5 + y]);
        }
        flag *= -1;
    }
    printf("\n");

    return 0;
}