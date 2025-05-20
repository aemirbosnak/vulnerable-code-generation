//FormAI DATASET v1.0 Category: Mailing list manager ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declare struct for storing contact info
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
} Contact;

// function prototypes
void addContact(Contact* contacts, int index);
void removeContact(Contact* contacts, int index);
void printList(Contact* contacts, int size);

int main() {
    int choice, size = 0, index;
    Contact* contacts = malloc(sizeof(Contact) * 10); // allocate memory for 10 contacts
    
    do {
        printf("\nMenu:\n1. Add contact\n2. Remove contact\n3. Print list\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (size < 10)
                    addContact(contacts, size++);
                else
                    printf("List is full.\n");
                break;
            case 2:
                printf("Enter index of contact to remove: ");
                scanf("%d", &index);
                if (index >= 0 && index < size)
                    removeContact(contacts, index);
                else
                    printf("Invalid index.\n");
                break;
            case 3:
                printList(contacts, size);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);
    
    free(contacts); // free allocated memory
    
    return 0;
}

void addContact(Contact* contacts, int index) {
    Contact newContact;
    
    printf("Enter name: ");
    scanf("%s", newContact.name);
    printf("Enter email: ");
    scanf("%s", newContact.email);
    printf("Enter phone: ");
    scanf("%s", newContact.phone);
    
    contacts[index] = newContact;
    
    printf("Contact added.\n");
}

void removeContact(Contact* contacts, int index) {
    int i;
    
    for (i = index; i < 9; i++) { // shift all contacts after index left by 1
        strcpy(contacts[i].name, contacts[i+1].name);
        strcpy(contacts[i].email, contacts[i+1].email);
        strcpy(contacts[i].phone, contacts[i+1].phone);
    }
    
    printf("Contact removed.\n");
}

void printList(Contact* contacts, int size) {
    int i;
    
    printf("Contacts:\n");
    for (i = 0; i < size; i++) {
        printf("%d. %s, %s, %s\n", i, contacts[i].name, contacts[i].email, contacts[i].phone);
    }
}