//FormAI DATASET v1.0 Category: Mailing list manager ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
    char name[50];
    char email[50];
    struct node* next;
};

struct node* start = NULL;

void insert_node(char name[], char email[]) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if (start == NULL) {
        start = new_node;
    }
    else {
        struct node* temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void display() {
    if (start == NULL) {
        printf("Mailing list is empty!\n");
    }
    else {
        struct node* temp = start;
        while (temp != NULL) {
            printf("Name: %s\nEmail: %s\n", temp->name, temp->email);
            temp = temp->next;
        }
    }
}

bool search(char email[]) {
    struct node* temp = start;
    while (temp != NULL) {
        if (strcmp(temp->email, email) == 0) {
            printf("Email already exists in the mailing list!\n");
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void delete(char email[]) {
    struct node* temp = start;
    struct node* prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->email, email) == 0) {
            if (prev == NULL) {
                start = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Email removed from mailing list!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Email not found in mailing list!\n");
}

int main() {
    char name[50], email[50], choice;
    bool done = false;
    while (!done) {
        printf("Enter your choice:\n1. Insert an email into the mailing list\n2. Display all emails in mailing list\n3. Search for an email in the mailing list\n4. Delete an email from the mailing list\n5. Exit\n");
        scanf(" %c", &choice);
        switch (choice) {
        case '1':
            printf("Enter name: ");
            scanf(" %[^\n]s", name);
            printf("Enter email: ");
            scanf(" %[^\n]s", email);
            if (!search(email)) {
                insert_node(name, email);
                printf("Email added to mailing list!\n");
            }
            break;
        case '2':
            display();
            break;
        case '3':
            printf("Enter email to search: ");
            scanf(" %[^\n]s", email);
            search(email);
            break;
        case '4':
            printf("Enter email to delete: ");
            scanf(" %[^\n]s", email);
            delete(email);
            break;
        case '5':
            done = true;
            printf("Exiting mailing list manager...\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}