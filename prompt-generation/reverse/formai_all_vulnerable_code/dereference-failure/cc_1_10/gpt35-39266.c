//FormAI DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

//Defining a single node in a linked list
typedef struct node{
    int data;
    struct node* next;
} node_t;

//Creating a new linked list
void createList(node_t** head, int data){
    *head = (node_t*)malloc(sizeof(node_t));
    (*head)->data = data;
    (*head)->next = NULL;
}

//Adding a new node to the end of the linked list
void append(node_t* head, int data){
    node_t* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = (node_t*)malloc(sizeof(node_t));
    current->next->data = data;
    current->next->next = NULL;
}

//Deleting a node in the linked list
void deleteNode(node_t** head, int data){
    node_t* current = *head;
    node_t* previous = NULL;

    while(current != NULL){
        if(current->data == data){
            if(previous == NULL){
                *head = current->next;
            }
            else{
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

//Displaying the elements of the linked list
void displayList(node_t* head){
    node_t* current = head;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    node_t* head = NULL;

    printf("Initializing Cyberpunk Linked List operations....\n\n");

    int option, val;
    do{
        printf("Choose an option:\n");
        printf("1. Create a new Linked List\n");
        printf("2. Append an element to the Linked List\n");
        printf("3. Delete an element from the Linked List\n");
        printf("4. Display the elements of the Linked List\n");
        printf("5. Exit\n");

        scanf("%d", &option);

        switch(option){
            case 1: 
                printf("Enter the first element of the list: ");
                scanf("%d", &val);
                createList(&head, val);
                printf("Linked List Created!\n\n");
                break;
            case 2: 
                printf("Enter the element to be appended: ");
                scanf("%d", &val);
                append(head, val);
                printf("Element Appended!\n\n");
                break;
            case 3: 
                printf("Enter the value of the element to be deleted: ");
                scanf("%d", &val);
                deleteNode(&head, val);
                printf("Element Deleted!\n\n");
                break;
            case 4:
                displayList(head);
                printf("\n");
                break;
            case 5:
                printf("Cyberpunk Linked List operations terminated...\n");
                break;
            default:
                printf("Invalid option!\n\n");
                break;
        }

    }while(option != 5);

    return 0;
}