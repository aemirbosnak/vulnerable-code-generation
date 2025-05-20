//FormAI DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

// Creating structure of node for Linked List
struct node{
    int data;
    struct node* next;
};

// Create a global variable of Linked List type
struct node* head;

// Function for creating Linked List
void create_list(int n){
    struct node *temp, *newNode;
    int data, i;

    // Creating first node
    head = (struct node*)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Memory allocation failed.\n");
        exit(0);
    }

    // User input for first node
    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;
    temp = head;

    // Creating remaining nodes
    for(i=2; i<=n; i++){
        newNode = (struct node*)malloc(sizeof(struct node));
        if(newNode == NULL){
            printf("Memory allocation failed.\n");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = temp->next;
    }
}

// Function to display all the nodes of Linked List
void display(){
    struct node *temp;

    if(head == NULL){
        printf("List is empty.\n");
    }
    else{
        temp = head;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to insert node at beginning of Linked List
void insert_at_beginning(int data){
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
    }
    else{
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        printf("Node inserted successfully at beginning.\n");
    }
}

// Function to insert node at end of Linked List
void insert_at_end(int data){
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
    }
    else{
        newNode->data = data;
        newNode->next = NULL;
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        printf("Node inserted successfully at end.\n");
    }
}

// Function to insert node at desired position in Linked List
void insert_at_position(int data, int pos){
    struct node *newNode, *temp;
    int i;

    if(pos == 1){
        insert_at_beginning(data);
    }
    else{
        newNode = (struct node*)malloc(sizeof(struct node));
        if(newNode == NULL){
            printf("Memory allocation failed.\n");
        }
        else{
            newNode->data = data;
            temp = head;
            for(i=1; i<pos-1; i++){
                temp = temp->next;
                if(temp == NULL){
                    printf("Invalid position.\n");
                    return;
                }
            }
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node inserted successfully at position %d.\n", pos);
        }
    }
}

// Function to delete node from beginning of Linked List
void delete_from_beginning(){
    struct node *temp;

    if(head == NULL){
        printf("List is empty.\n");
    }
    else{
        temp = head;
        head = head->next;
        printf("Node %d deleted from beginning.\n", temp->data);
        free(temp);
    }
}

// Function to delete node from end of Linked List
void delete_from_end(){
    struct node *temp, *prevNode;

    if(head == NULL){
        printf("List is empty.\n");
    }
    else{
        temp = head;
        while(temp->next != NULL){
            prevNode = temp;
            temp = temp->next;
        }
        prevNode->next = NULL;
        printf("Node %d deleted from end.\n", temp->data);
        free(temp);
    }
}

// Function to delete node from desired position in Linked List
void delete_from_position(int pos){
    struct node *temp, *prevNode;
    int i;

    if(head == NULL){
        printf("List is empty.\n");
    }
    else if(pos == 1){
        delete_from_beginning();
    }
    else{
        temp = head;
        for(i=1; i<pos; i++){
            prevNode = temp;
            temp = temp->next;
            if(temp == NULL){
                printf("Invalid position.\n");
                return;
            }
        }
        prevNode->next = temp->next;
        printf("Node %d deleted from position %d.\n", temp->data, pos);
        free(temp);
    }
}

int main(){
    int choice, data, n, pos;

    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);

    create_list(n);

    while(1){
        printf("Select an option:\n");
        printf("1. Display all nodes\n");
        printf("2. Insert node at beginning\n");
        printf("3. Insert node at end\n");
        printf("4. Insert node at position\n");
        printf("5. Delete node from beginning\n");
        printf("6. Delete node from end\n");
        printf("7. Delete node from position\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                display();
                break;
            case 2:
                printf("Enter the data to be inserted at beginning: ");
                scanf("%d", &data);
                insert_at_beginning(data);
                break;
            case 3:
                printf("Enter the data to be inserted at end: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 4:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position where the data is to be inserted: ");
                scanf("%d", &pos);
                insert_at_position(data, pos);
                break;
            case 5:
                delete_from_beginning();
                break;
            case 6:
                delete_from_end();
                break;
            case 7:
                printf("Enter the position of node to be deleted: ");
                scanf("%d", &pos);
                delete_from_position(pos);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}