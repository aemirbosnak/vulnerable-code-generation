//FormAI DATASET v1.0 Category: Linked list operations ; Style: configurable
#include <stdio.h> 

struct Node { 
    int data; 
    struct Node* next; 
}; 

struct Node* head = NULL; 

void insert(int new_data) { 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    new_node->data = new_data; 
    new_node->next = head; 
    head = new_node; 
} 

void printList(struct Node* n) { 
    while (n != NULL) { 
        printf("%d ", n->data); 
        n = n->next; 
    } 
} 

void delete(int key) {
  struct Node* temp = head; 
    struct Node* prev = NULL; 
 
    if (temp != NULL && temp->data == key) { 
        head = temp->next; 
        free(temp);           
        return; 
    } 

    while (temp != NULL && temp->data != key) { 
        prev = temp; 
        temp = temp->next; 
    } 

    if (temp == NULL) return; 
 
    prev->next = temp->next;       
    free(temp);                 
} 

int main() { 
    
    insert(1); 
    insert(2); 
    insert(3); 
    insert(4); 

    printf("Linked list: ");
    printList(head);
    printf("\n\n");

    int choice; 
    int key;
    do {
        printf("Enter an operation number:\n1. Insert an element.\n2. Delete an element.\n3. Print linked list.\n4. Exit\n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                int new_data;
                scanf("%d",&new_data);
                insert(new_data);
                printf("\nElement %d is inserted.\n\n",new_data);
                break;
            case 2:
                printf("Enter the element to be deleted: ");
                scanf("%d",&key);
                delete(key);
                printf("\nElement %d is deleted.\n\n", key);
                break;
            case 3:
                printf("Linked list: ");
                printList(head);
                printf("\n\n");
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid operation number.\n\n");
                break;
        }
    } while(choice != 4);

    return 0; 
}