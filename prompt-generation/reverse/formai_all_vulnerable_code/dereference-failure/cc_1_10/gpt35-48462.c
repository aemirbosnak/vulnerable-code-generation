//FormAI DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Defining LinkedList struct
struct LinkedList{
    int value;
    struct LinkedList* next;
};

// Function to create a LinkedList node
struct LinkedList* createNode(int value){
    struct LinkedList* node = malloc(sizeof(struct LinkedList));
    node->value = value;
    node->next = NULL;
    return node;
}

// Function to add node to LinkedList
void addNode(struct LinkedList** head, int value){
    struct LinkedList* newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
    }
    else{
        struct LinkedList* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for value in LinkedList
int searchLinkedList(struct LinkedList* head, int value){
    int index = 1;
    while(head != NULL){
        if(head->value == value){
            return index;
        }
        head = head->next;
        index++;
    }
    return -1;
}

// Main function
int main(){
    struct LinkedList* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    int value = 4;
    int index = searchLinkedList(head, value);
    if(index == -1){
        printf("Value not found in LinkedList.\n");
    }
    else{
        printf("Value found at index %d in LinkedList.\n", index);
    }

    return 0;
}