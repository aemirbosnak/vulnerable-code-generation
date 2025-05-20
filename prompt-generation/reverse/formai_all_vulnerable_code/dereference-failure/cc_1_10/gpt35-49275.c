//FormAI DATASET v1.0 Category: Data structures visualization ; Style: visionary
#include<stdio.h>

// Defining structure for a node of the Linked List
struct Node{
    int data;
    struct Node* next;
};

// Function to create a new node and return its pointer
struct Node* createNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the Linked List
void insertAtBeginning(struct Node** head, int data){
    struct Node* node = createNode(data);
    node->next = *head;
    *head = node;
}

// Function to insert a node after a given node in the Linked List
void insertAfter(struct Node* node, int data){
    if(node == NULL){
        printf("Cannot perform this operation as the given node is NULL\n");
        return;
    }
    
    struct Node* newNode = createNode(data);
    newNode->next = node->next;
    node->next = newNode;
}

// Function to insert a node at the end of the Linked List
void insertAtEnd(struct Node** head, int data){
    struct Node* node = createNode(data);
    if(*head == NULL){
        *head = node;
        return;
    }
    
    struct Node* current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = node;
}

// Function to delete the node with given value from the Linked List
void deleteNode(struct Node** head, int value){
    if(*head == NULL){
        printf("Linked List is already empty\n");
        return;
    }
    
    struct Node* current = *head;
    struct Node* prev = NULL;
    while(current != NULL){
        if(current->data == value){
            if(prev == NULL){
                *head = current->next;
            }
            else{
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Node with given value not found in the Linked List\n");
}

// Function to display the Linked List
void display(struct Node* head){
    if(head == NULL){
        printf("Linked List is empty\n");
        return;
    }
    
    printf("Linked List: ");
    struct Node* current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 10);
    insertAfter(head, 7);
    deleteNode(&head, 5);
    display(head);
    return 0;
}