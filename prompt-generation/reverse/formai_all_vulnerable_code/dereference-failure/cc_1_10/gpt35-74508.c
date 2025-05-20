//FormAI DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    char data[50];
    struct Node* next;
}node;

node* head = NULL;

//function to create a new node and return a pointer to it
node* create_node(char* value) {
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->data, value);
    new_node->next = NULL;
    return new_node;
}

//function to add node at the end of the list
void add_node(char* value) {
    node* new_node = create_node(value);
    if(head == NULL)
        head = new_node;
    else {
        node* current = head;
        while(current->next != NULL)
            current = current->next;
        current->next = new_node;
    }
}

//function to delete a node from the list
void delete_node(char* value) {
    if(head == NULL) {
        printf("The list is empty!\n");
        return;
    }
    else {
        node* current = head;
        node* previous = NULL;
        while(current != NULL) {
            if(strcmp(current->data, value) == 0) {
                if(previous == NULL)
                    head = current->next;
                else
                    previous->next = current->next;
                free(current);
                printf("%s has been removed!", value);
                return;
            }
            previous = current;
            current = current->next;
        }
    }
}

//function to print the current mailing list
void print_list() {
    if(head == NULL) {
        printf("The list is empty!\n");
        return;
    }
    else {
        node* current = head;
        printf("The current mailing list is:\n");
        while(current != NULL) {
            printf("%s", current->data);
            current = current->next;
        }
    }
}

//main function to drive the program
int main() {
    printf("Welcome to the mailing list manager program!\n");
    printf("Enter 1 to add a new email address to the mailing list.\n");
    printf("Enter 2 to delete an email address from the mailing list.\n");
    printf("Enter 3 to print the current mailing list.\n");
    printf("Enter 4 to exit the program.\n");
    int choice = 0;
    char email[50];
    
    while(choice != 4) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the email address you want to add: ");
                scanf("%s", email);
                add_node(email);
                break;

            case 2:
                printf("Enter the email address you want to delete: ");
                scanf("%s", email);
                delete_node(email);
                break;

            case 3:
                print_list();
                break;

            case 4:
                printf("Thank you for using the mailing list manager program!\n");
                break;

            default:
                printf("Invalid choice, try again!\n");
                break;
        }
    }

    return 0;
}