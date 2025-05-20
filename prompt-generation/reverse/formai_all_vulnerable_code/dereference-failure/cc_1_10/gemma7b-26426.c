//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <string.h>

// Define a structure to store phone book data
typedef struct phoneBook {
    char name[20];
    char number[20];
    struct phoneBook* next;
} phoneBook;

// Function to insert a new entry into the phone book
void insert(phoneBook* head, char* name, char* number) {
    phoneBook* newNode = (phoneBook*)malloc(sizeof(phoneBook));
    strcpy(newNode->name, name);
    strcpy(newNode->number, number);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        phoneBook* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for a name in the phone book
phoneBook* search(phoneBook* head, char* name) {
    phoneBook* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the phone book
void printPhoneBook(phoneBook* head) {
    phoneBook* temp = head;
    while (temp) {
        printf("%s: %s\n", temp->name, temp->number);
        temp = temp->next;
    }
}

int main() {
    phoneBook* head = NULL;

    // Insert some entries
    insert(head, "John Doe", "123-456-7890");
    insert(head, "Jane Doe", "456-789-0123");
    insert(head, "Peter Pan", "543-214-8901");

    // Search for a name
    phoneBook* found = search(head, "Jane Doe");

    // Print the phone book
    if (found) {
        printf("%s: %s\n", found->name, found->number);
    } else {
        printf("Name not found\n");
    }

    printPhoneBook(head);

    return 0;
}