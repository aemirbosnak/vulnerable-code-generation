//FormAI DATASET v1.0 Category: Phone Book ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone_no[15];
} PhoneBook;

void AddNewContact(PhoneBook **phone_book, int *num_contacts);
void SearchContact(PhoneBook *phone_book, int num_contacts);
void DisplayAllContacts(PhoneBook *phone_book, int num_contacts);
void DeleteContact(PhoneBook **phone_book, int *num_contacts);

int main() {
    PhoneBook *phone_book = NULL;
    int num_contacts = 0;
    int choice;

    printf("Welcome to the Phone Book!\n");

    while(1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add new contact\n");
        printf("2. Search for a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Delete a contact\n");
        printf("5. Quit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                AddNewContact(&phone_book, &num_contacts);
                break;
            case 2:
                SearchContact(phone_book, num_contacts);
                break;
            case 3:
                DisplayAllContacts(phone_book, num_contacts);
                break;
            case 4:
                DeleteContact(&phone_book, &num_contacts);
                break;
            case 5:
                printf("\nThank you for using the Phone Book, goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}

void AddNewContact(PhoneBook **phone_book, int *num_contacts) {
    char name[50], phone_no[15];

    printf("\nPlease enter the name of the new contact: ");
    scanf("%s", name);

    while(getchar() != '\n'); // clear input buffer

    printf("Please enter the phone number of the new contact: ");
    scanf("%s", phone_no);

    (*num_contacts)++;
    *phone_book = realloc(*phone_book, (*num_contacts) * sizeof(PhoneBook));

    strcpy((*phone_book)[*num_contacts - 1].name, name);
    strcpy((*phone_book)[*num_contacts - 1].phone_no, phone_no);

    printf("\nNew contact added successfully!\n");
}

void SearchContact(PhoneBook *phone_book, int num_contacts) {
    char name[50];
    int found_contact = 0;

    printf("\nPlease enter the name of the contact you wish to search for: ");
    scanf("%s", name);

    for(int i = 0; i < num_contacts; i++) {
        if(strcmp(phone_book[i].name, name) == 0) {
            printf("\n%s: %s\n", phone_book[i].name, phone_book[i].phone_no);
            found_contact = 1;
            break;
        }
    }

    if(!found_contact) {
        printf("\nContact not found.\n");
    }
}

void DisplayAllContacts(PhoneBook *phone_book, int num_contacts) {
    printf("\nAll contacts in the Phone Book:\n");

    for(int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].phone_no);
    }
}

void DeleteContact(PhoneBook **phone_book, int *num_contacts) {
    char name[50];
    int found_contact = 0;
    int index_to_delete;

    printf("\nPlease enter the name of the contact you wish to delete: ");
    scanf("%s", name);

    for(int i = 0; i < *num_contacts; i++) {
        if(strcmp((*phone_book)[i].name, name) == 0) {
            found_contact = 1;
            index_to_delete = i;
            break;
        }
    }

    if(!found_contact) {
        printf("\nContact not found.\n");
    } else {
        for(int i = index_to_delete; i < (*num_contacts) - 1; i++) {
            strcpy((*phone_book)[i].name, (*phone_book)[i+1].name);
            strcpy((*phone_book)[i].phone_no, (*phone_book)[i+1].phone_no);
        }

        (*num_contacts)--;
        *phone_book = realloc(*phone_book, (*num_contacts) * sizeof(PhoneBook));

        printf("\nContact deleted successfully!\n");
    }
}