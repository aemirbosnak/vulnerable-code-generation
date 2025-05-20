//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[20];
    struct Contact *next;
};

struct Contact *head = NULL;
struct Contact *tail = NULL;

void addContact(char *name, char *phone) {
    struct Contact *newContact = (struct Contact *)malloc(sizeof(struct Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;
    
    if (head == NULL) {
        head = newContact;
        tail = newContact;
    } else {
        tail->next = newContact;
        tail = newContact;
    }
}

void deleteContact(char *name) {
    struct Contact *current = head;
    struct Contact *previous = NULL;
    
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current == head) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            
            if (current == tail) {
                tail = previous;
            }
            
            free(current);
            
            return;
        }
        
        previous = current;
        current = current->next;
    }
    
    printf("Contact not found.\n");
}

void searchContact(char *name) {
    struct Contact *current = head;
    
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", current->name, current->phone);
            
            return;
        }
        
        current = current->next;
    }
    
    printf("Contact not found.\n");
}

void printContacts() {
    struct Contact *current = head;
    
    while (current != NULL) {
        printf("Name: %s\nPhone: %s\n", current->name, current->phone);
        
        current = current->next;
    }
}

int main() {
    int choice;
    char name[50];
    char phone[20];
    
    while (1) {
        printf("\n1. Add contact\n2. Delete contact\n3. Search contact\n4. Print contacts\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                
                addContact(name, phone);
                
                break;
                
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                
                deleteContact(name);
                
                break;
                
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                
                searchContact(name);
                
                break;
                
            case 4:
                printContacts();
                
                break;
                
            case 5:
                exit(0);
                
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}