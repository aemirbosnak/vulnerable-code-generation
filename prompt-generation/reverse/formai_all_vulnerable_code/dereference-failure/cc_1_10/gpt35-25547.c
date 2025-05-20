//FormAI DATASET v1.0 Category: Memory management ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

typedef struct abc {  /* defining a structure */
    int data;
    struct abc *next;
}node;

void display(node*);
node *create_node();
void insert(node**, int);
void delete(node**, int);

int main() {
    node *head = NULL;
    int choice, input, flag = 1;
    while(flag) {  /* wrapping it in a loop until user exits */
        printf("Enter your choice:\n1. Create a new node\n2. Insert node\n3. Delete node\n4. Display list\n5. Exit\n");
        scanf("%d",&choice);
        switch(choice) {  /* switch-case implementation */
            case 1: 
                if(head == NULL) {  /* if list is empty */
                    head = create_node();
                }
                else {
                    printf("Head node is already present. Use insertion option instead.\n");
                }
                break;
            case 2: 
                printf("Enter data to insert: ");
                scanf("%d",&input);
                insert(&head,input);
                break;
            case 3: 
                printf("Enter data to delete: ");
                scanf("%d",&input);
                delete(&head,input);
                break;
            case 4: 
                if(head == NULL) {  /* if list is empty */
                    printf("List is empty\n");
                }
                else {
                    printf("The list is:\n");
                    display(head);
                }
                break;
            case 5:  
                flag = 0; 
                printf("Thank you for using. Bye!\n");
                break;
            default:
                printf("Invalid Input. Try Again.\n");
                break;
        }
    }
    return 0;
}

node* create_node() {  /* function to create a new node */
    node *temp = (node*) malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    printf("New node created successfully.\n");
    return temp;
}

void insert(node **head, int data) {  /* function to insert a node */
    node *temp = create_node();
    temp -> data = data;
    temp -> next = *head;
    *head = temp;
    printf("Node inserted successfully.\n");
}

void delete(node **head, int data) {  /* function to delete a node */
    node *temp = *head, *prev;
    if(temp != NULL && temp->data == data) {  /* if node to be deleted is head node */
        *head = temp->next;
        free(temp);
        printf("Node deleted successfully.\n");
        return;
    }
    while(temp != NULL && temp->data != data) {  /* finding the node to be deleted */
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {  /* if node to be deleted is not found */
        printf("Element not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully.\n");
}

void display(node *head) {  /* function to display all the nodes */
    while(head!=NULL) {  
        printf("%d->",head->data);  
        head=head->next;  
    } 
    printf("NULL\n");
}