//FormAI DATASET v1.0 Category: Linked list operations ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

/* Defining our linked list structure */
struct node{
    int data;
    struct node *next;
};

/* Initialize the linked list by assigning the head pointer to NULL */
struct node *head = NULL;

/* Function to add a new node at the end of the linked list */
void addNode(int value) {
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("\nNode inserted successfully!\n");
}

/* Function to delete a node at a given position from the linked list */
void deleteNode(int position) {
    if (head == NULL) {
        printf("\nLinked list is empty!\n");
    }
    else {
        struct node *temp1 = head;
        if (position == 1) {
            head = temp1->next;
            free(temp1);
        }
        else {
            struct node *temp2 = NULL;
            for (int i = 1; i < position && temp1 != NULL; i++) {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            if (temp1 == NULL) {
                printf("\nInvalid position!\n");
            }
            else {
                temp2->next = temp1->next;
                free(temp1);
                printf("\nNode deleted successfully!\n");
            }
        }
    }
}

/* Function to display the linked list */
void displayList() {
    if (head == NULL) {
        printf("\nLinked list is empty!\n");
    }
    else {
        printf("\nLinked list elements:\n");
        struct node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    int option;
    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Display the linked list\n");
        printf("4. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                int element;
                printf("\nEnter element to insert: ");
                scanf("%d", &element);
                addNode(element);
                break;
            }
            case 2: {
                int position;
                printf("\nEnter position of node to delete: ");
                scanf("%d", &position);
                deleteNode(position);
                break;
            }
            case 3: {
                displayList();
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("\nInvalid option!\n");
                break;
            }
        }
    }
    return 0;
}