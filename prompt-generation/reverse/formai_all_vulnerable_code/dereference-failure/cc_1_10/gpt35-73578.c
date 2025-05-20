//FormAI DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct node {
    Contact data;
    struct node* next;
} Node;

Node* head = NULL;

void add_contact() {
    Contact new_contact;
    printf("Enter the contact's name: ");
    scanf("%s", new_contact.name);
    printf("Enter the contact's email: ");
    scanf("%s", new_contact.email);
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_contact;
    new_node->next = head;
    head = new_node;
}

void display_contacts() {
    printf("Name\t\tEmail\n");
    printf("----\t\t-----\n");
    Node* temp = head;
    while (temp != NULL) {
        printf("%s\t\t%s\n", temp->data.name, temp->data.email);
        temp = temp->next;
    }
}

void remove_contact() {
    char email[MAX_EMAIL_LENGTH];
    printf("Enter the email of the contact to remove: ");
    scanf("%s", email);
    Node* temp = head;
    if (strcmp(temp->data.email, email) == 0) {
        head = head->next;
        free(temp);
        printf("Contact removed successfully.\n");
        return;
    }
    while (temp->next != NULL) {
        if (strcmp(temp->next->data.email, email) == 0) {
            Node* node_to_remove = temp->next;
            temp->next = temp->next->next;
            free(node_to_remove);
            printf("Contact removed successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Contact not found.\n");
}

void save_contacts_to_file() {
    FILE* file = fopen("contacts.txt", "w");
    Node* temp = head;
    while (temp != NULL) {
        fprintf(file, "%s,%s\n", temp->data.name, temp->data.email);
        temp = temp->next;
    }
    fclose(file);
    printf("Contacts saved to file.\n");
}

void load_contacts_from_file() {
    FILE* file = fopen("contacts.txt", "r");
    if (file != NULL) {
        char line[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2];
        while (fgets(line, sizeof(line), file) != NULL) {
            char* name = strtok(line, ",");
            char* email = strtok(NULL, ",");
            Contact contact;
            strcpy(contact.name, name);
            strcpy(contact.email, email);
            Node* new_node = (Node*) malloc(sizeof(Node));
            new_node->data = contact;
            new_node->next = head;
            head = new_node;
        }
        fclose(file);
        printf("Contacts loaded from file.\n");
    } else {
        printf("Error: could not open file.\n");
    }
}

int main() {
    load_contacts_from_file();
    while (1) {
        printf("----- Mailing List Manager -----\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Display contacts\n");
        printf("4. Save contacts to file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                remove_contact();
                break;
            case 3:
                display_contacts();
                break;
            case 4:
                save_contacts_to_file();
                break;
            case 5:
                save_contacts_to_file();
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}