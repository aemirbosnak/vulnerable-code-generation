//FormAI DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_NUM_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone_num[MAX_PHONE_NUM_LENGTH];
} Contact;

typedef struct node_t {
    Contact contact;
    struct node_t *next;
} Node;

Node *head = NULL;

void add_contact() {
    Contact new_contact;

    printf("Enter name: ");
    fgets(new_contact.name, MAX_NAME_LENGTH, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0; //remove newline character
    
    printf("Enter email: ");
    fgets(new_contact.email, MAX_EMAIL_LENGTH, stdin);
    new_contact.email[strcspn(new_contact.email, "\n")] = 0; //remove newline character
    
    printf("Enter phone number: ");
    fgets(new_contact.phone_num, MAX_PHONE_NUM_LENGTH, stdin);
    new_contact.phone_num[strcspn(new_contact.phone_num, "\n")] = 0; //remove newline character
    
    //Add new contact to the beginning of the linked list
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->contact = new_contact;
    new_node->next = head;
    head = new_node;
}

void delete_contact() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name of contact to delete: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; //remove newline character
    
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL) {
        if (strcmp(curr->contact.name, name) == 0) {
            if (prev == NULL) { //If deleting the head node
                head = head->next;
            } else {
                prev->next = curr->next;
            }

            free(curr);
            printf("Contact '%s' deleted.\n", name);
            return;
        }

        prev = curr;
        curr = curr->next;
    }
    
    printf("Contact '%s' not found.\n", name);
}

void print_contacts() {
    if (head == NULL) {
        printf("No contacts found.\n");
    } else {
        printf("%-30s %-50s %-20s\n", "Name", "Email", "Phone Number");

        Node *curr = head;

        while (curr != NULL) {
            printf("%-30s %-50s %-20s\n", curr->contact.name, curr->contact.email, curr->contact.phone_num);
            curr = curr->next;
        }
    }
}

int main() {
    char choice;
    do {
        printf("\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Print contacts\n");
        printf("4. Quit\n");
        printf("Enter choice (1-4): ");
        choice = getchar();
        getchar(); // Consume newline character

        switch (choice) {
            case '1':
                add_contact();
                break;
            case '2':
                delete_contact();
                break;
            case '3':
                print_contacts();
                break;
        }
    } while (choice != '4');

    return 0;
}