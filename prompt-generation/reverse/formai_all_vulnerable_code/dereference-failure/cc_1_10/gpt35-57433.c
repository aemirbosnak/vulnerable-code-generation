//FormAI DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[20];
    char phone_number[15];
} Contact;

void add_contact(Contact** address_book, int* num_contacts);
void search_contact(Contact* address_book, int num_contacts);
void delete_contact(Contact** address_book, int* num_contacts);

int main() {
    Contact* address_book = NULL;
    int num_contacts = 0;
    int choice;
    
    while (1) {
        printf("Select an option: \n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Delete contact\n");
        
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_contact(&address_book, &num_contacts);
                break;
            case 2:
                search_contact(address_book, num_contacts);
                break;
            case 3:
                delete_contact(&address_book, &num_contacts);
                break;
            default:
                printf("Invalid option.\n");
                continue;
        }
    }
    
    return 0;
}

void add_contact(Contact** address_book, int* num_contacts) {
    Contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter phone number: ");
    scanf("%s", new_contact.phone_number);
    
    *num_contacts += 1;
    *address_book = (Contact*)realloc(*address_book, *num_contacts * sizeof(Contact));
    (*address_book)[*num_contacts - 1] = new_contact;
    
    printf("Contact added.\n");
}

void search_contact(Contact* address_book, int num_contacts) {
    char name[20];
    printf("Enter name to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, address_book[i].name) == 0) {
            printf("Name: %s\nPhone number: %s\n", address_book[i].name, address_book[i].phone_number);
            return;
        }
    }
    
    printf("Contact not found.\n");
}

void delete_contact(Contact** address_book, int* num_contacts) {
    char name[20];
    printf("Enter name to delete: ");
    scanf("%s", name);
    
    int index;
    int found = 0;
    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(name, (*address_book)[i].name) == 0) {
            index = i;
            found = 1;
            break;
        }
    }
    
    if (found) {
        for (int i = index; i < *num_contacts - 1; i++) {
            (*address_book)[i] = (*address_book)[i+1];
        }
        *num_contacts -= 1;
        *address_book = (Contact*)realloc(*address_book, *num_contacts * sizeof(Contact));
        printf("Contact deleted.\n");
    }
    else {
        printf("Contact not found.\n");
    }
}