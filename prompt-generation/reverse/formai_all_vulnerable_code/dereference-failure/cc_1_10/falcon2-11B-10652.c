//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct definition
struct PhoneBook {
    char name[50];
    char phoneNumber[20];
    struct PhoneBook *next;
};

// function declarations
struct PhoneBook *addToPhoneBook(struct PhoneBook *head, char *name, char *phoneNumber);
struct PhoneBook *findInPhoneBook(struct PhoneBook *head, char *name);
void printPhoneBook(struct PhoneBook *head);
void freePhoneBook(struct PhoneBook *head);

int main()
{
    // create a new phone book
    struct PhoneBook *phoneBook = NULL;
    
    // add entries to the phone book
    phoneBook = addToPhoneBook(phoneBook, "John Doe", "555-1234");
    phoneBook = addToPhoneBook(phoneBook, "Jane Doe", "555-5678");
    phoneBook = addToPhoneBook(phoneBook, "Bob Smith", "555-9012");
    
    // print the phone book
    printf("Phone Book:\n");
    printPhoneBook(phoneBook);
    
    // free memory
    freePhoneBook(phoneBook);
    
    return 0;
}

// add entry to phone book
struct PhoneBook *addToPhoneBook(struct PhoneBook *head, char *name, char *phoneNumber)
{
    // create a new entry
    struct PhoneBook *entry = (struct PhoneBook *)malloc(sizeof(struct PhoneBook));
    
    // set the name and phone number
    strcpy(entry->name, name);
    strcpy(entry->phoneNumber, phoneNumber);
    
    // set the next entry
    entry->next = NULL;
    
    // if head is NULL, set it to the new entry
    if (head == NULL) {
        head = entry;
    } else {
        // otherwise, add the new entry to the end of the list
        entry->next = head;
        head = entry;
    }
    
    return head;
}

// find entry in phone book
struct PhoneBook *findInPhoneBook(struct PhoneBook *head, char *name)
{
    // find the entry in the phone book
    while (head!= NULL) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    
    return NULL;
}

// print phone book
void printPhoneBook(struct PhoneBook *head)
{
    // print the name and phone number for each entry
    while (head!= NULL) {
        printf("%s - %s\n", head->name, head->phoneNumber);
        head = head->next;
    }
}

// free memory
void freePhoneBook(struct PhoneBook *head)
{
    // free each entry in the phone book
    while (head!= NULL) {
        struct PhoneBook *nextEntry = head->next;
        free(head);
        head = nextEntry;
    }
}