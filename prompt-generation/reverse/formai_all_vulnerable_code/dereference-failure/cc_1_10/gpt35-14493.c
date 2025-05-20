//FormAI DATASET v1.0 Category: Mailing list manager ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50
#define MAX_PHONE_LEN 13

// Define a struct to represent the contact information
typedef struct{
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];
} contact_t;

// Define a linked list node that has a contact pointer
typedef struct node{
    contact_t *contact;
    struct node *next;
} node_t;

// Define a function to create a new contact
contact_t* create_contact(char *name, char *email, char *phone){
    contact_t *new_contact = (contact_t*)malloc(sizeof(contact_t));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    strcpy(new_contact->phone, phone);
    return new_contact;
}

// Define a function to add a new contact to the list
void add_contact(node_t **head, char *name, char *email, char *phone){
    // Create a new contact object
    contact_t *new_contact = create_contact(name, email, phone);
    
    // Create a new node and set its contact pointer
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->contact = new_contact;
    
    // Add the new node to the front of the list
    new_node->next = *head;
    *head = new_node;
}

// Define a function to print all contacts in the list
void print_list(node_t *head){
    node_t *curr = head;
    while(curr != NULL){
        printf("Name: %s\nEmail: %s\nPhone: %s\n\n", curr->contact->name, 
                curr->contact->email, curr->contact->phone);
        curr = curr->next;
    }
}

// Define a function to free all memory allocated for the list and contacts
void free_list(node_t **head){
    node_t *curr = *head;
    while(curr != NULL){
        node_t *temp = curr->next;
        free(curr->contact);
        free(curr);
        curr = temp;
    }
    *head = NULL;
}

int main(){
    node_t *head = NULL;
    // Add some sample contacts to the list
    add_contact(&head, "John Smith", "john@email.com", "555-555-1234");
    add_contact(&head, "Jane Doe", "jane@email.com", "555-555-5678");
    add_contact(&head, "Bob Johnson", "bob@email.com", "555-555-9999");
    
    // Print all contacts in the list
    printf("Contacts:\n");
    print_list(head);
    
    // Free all memory allocated for the list and contacts
    free_list(&head);
    
    return 0;
}