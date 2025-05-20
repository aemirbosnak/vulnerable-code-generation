//FormAI DATASET v1.0 Category: Mailing list manager ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 20

typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

typedef struct Node {
    Contact contact;
    struct Node* next;
} Node;

Node* list_head = NULL;

void add_contact() {
    Node* new_node = (Node*) malloc(sizeof(Node));
    printf("Enter name: ");
    scanf("%s", new_node->contact.name);
    printf("Enter email: ");
    scanf("%s", new_node->contact.email);
    printf("Enter phone: ");
    scanf("%s", new_node->contact.phone);
    new_node->next = list_head;
    list_head = new_node;
    printf("Contact added successfully!\n");
}

void display_contacts() {
    if (list_head == NULL) {
        printf("No contacts to display.\n");
        return;
    }
    printf("Name\tEmail\t\t\tPhone\n");
    Node* current = list_head;
    while (current != NULL) {
        printf("%s\t%s\t%s\n", current->contact.name, current->contact.email, current->contact.phone);
        current = current->next;
    }
}

void search_contact() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    Node* current = list_head;
    while (current != NULL) {
        if (strcmp(current->contact.name, search_name) == 0) {
            printf("Name\tEmail\t\t\tPhone\n");
            printf("%s\t%s\t%s\n", current->contact.name, current->contact.email, current->contact.phone);
            return;
        }
        current = current->next;
    }
    printf("Contact not found.\n");
}

void delete_contact() {
    char delete_name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", delete_name);
    Node* previous = NULL;
    Node* current = list_head;
    while (current != NULL) {
        if (strcmp(current->contact.name, delete_name) == 0) {
            if (previous == NULL) {
                list_head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Contact deleted successfully!\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Contact not found.\n");
}

void save_contacts() {
    char filename[MAX_NAME_LENGTH];
    FILE *fp;
    printf("Enter file name to save: ");
    scanf("%s", filename);
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error saving contacts.\n");
        return;
    }
    Node* current = list_head;
    while (current != NULL) {
        fprintf(fp, "%s,%s,%s\n", current->contact.name, current->contact.email, current->contact.phone);
        current = current->next;
    }
    fclose(fp);
    printf("Contacts saved successfully!\n");
}

void load_contacts() {
    char filename[MAX_NAME_LENGTH];
    FILE *fp;
    printf("Enter file name to load: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error loading contacts.\n");
        return;
    }
    char line[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + MAX_PHONE_LENGTH + 2];
    while (fgets(line, MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + MAX_PHONE_LENGTH + 2, fp) != NULL) {
        Node* new_node = (Node*) malloc(sizeof(Node));
        sscanf(line, "%[^,],%[^,],%s", new_node->contact.name, new_node->contact.email, new_node->contact.phone);
        new_node->next = list_head;
        list_head = new_node;
    }
    fclose(fp);
    printf("Contacts loaded successfully!\n");
}

int main() {
    while (1) {
        printf("\n");
        printf("Mailing List Manager\n");
        printf("====================\n");
        printf("1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Save contacts\n");
        printf("6. Load contacts\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                save_contacts();
                break;
            case 6:
                load_contacts();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}