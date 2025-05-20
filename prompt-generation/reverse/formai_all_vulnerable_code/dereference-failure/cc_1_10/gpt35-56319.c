//FormAI DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[30];
    char number[15];
    struct contact *next;
};

void insert_contact(struct contact **list, char name[], char number[]) {
    // Create a new node
    struct contact *new_contact = (struct contact*) malloc(sizeof(struct contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->number, number);
    new_contact->next = NULL;

    // Base case: if the list is empty, set the new node as the head and return
    if (*list == NULL) {
        *list = new_contact;
        return;
    }
    
    // Recursive case: find the last node, and insert the new node after it
    insert_contact(&((*list)->next), name, number);
}

struct contact* search_contact(struct contact *list, char name[]) {
    // Base case: the list is empty or we have reached the end of the list
    if (list == NULL) {
        printf("Contact not found.\n");
        return NULL;
    }
    
    // If the current node's name matches the search name, return it
    if (strcmp(list->name, name) == 0) {
        printf("Name : %s \n Phone Number : %s\n", list->name, list->number);
        return list;
    }
    
    // Recursive case: continue searching in the next node
    return search_contact(list->next, name);
}

void display_contacts(struct contact *list) {
    if (list == NULL) {
        printf("Phone book is empty.\n");
        return;
    }
    printf("List of contacts:\n");
    while (list != NULL) {
        printf("Name : %s \n Phone Number : %s\n", list->name, list->number);
        list = list->next;
    }
}

void remove_contact(struct contact **list, char name[]) {
    if (*list == NULL) {
        printf("Contact not found.\n");
        return;
    }
    
    if (strcmp((*list)->name, name) == 0) {
        // Remove the first node
        struct contact *temp = *list;
        *list = (*list)->next;
        free(temp);
        printf("Contact removed.\n");
        return;
    }
    
    remove_contact(&((*list)->next), name);
}

void menu() {
    printf("\nPhone Book Menu\n");
    printf("1. Add contact\n");
    printf("2. Search contact\n");
    printf("3. Display all contacts\n");
    printf("4. Remove contact\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5):\n");
}

int main() {
    struct contact *phone_book = NULL;
    int choice;
    char name[30], number[15];
    struct contact *result;
    do {
        menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter Name:\n");
                scanf("%s", name);
                printf("Enter Phone Number:\n");
                scanf("%s", number);
                insert_contact(&phone_book, name, number);
                printf("Contact added.\n");
                break;
            case 2:
                printf("Enter Name to search:\n");
                scanf("%s", name);
                result = search_contact(phone_book, name);
                if (result == NULL) {
                    printf("Contact not found.\n");
                }
                break;
            case 3:
                display_contacts(phone_book);
                break;
            case 4:
                printf("Enter Name to remove:\n");
                scanf("%s", name);
                remove_contact(&phone_book, name);
                break;
            case 5:
                printf("Exiting..");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}