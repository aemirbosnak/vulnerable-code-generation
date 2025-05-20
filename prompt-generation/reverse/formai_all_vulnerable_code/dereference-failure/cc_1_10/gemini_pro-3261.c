//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phoneNumber {
    char *name;
    char *number;
};

struct phoneNumberBook {
    struct phoneNumber *contacts;
    int numContacts;
};

struct phoneNumberBook *createPhoneBook() {
    struct phoneNumberBook *phoneBook = malloc(sizeof(struct phoneNumberBook));
    phoneBook->contacts = malloc(sizeof(struct phoneNumber) * 100);
    phoneBook->numContacts = 0;
    return phoneBook;
}

void addContact(struct phoneNumberBook *phoneBook, char *name, char *number) {
    struct phoneNumber *contact = &phoneBook->contacts[phoneBook->numContacts++];
    contact->name = malloc(strlen(name) + 1);
    strcpy(contact->name, name);
    contact->number = malloc(strlen(number) + 1);
    strcpy(contact->number, number);
}

char *findContactNumber(struct phoneNumberBook *phoneBook, char *name) {
    for (int i = 0; i < phoneBook->numContacts; i++) {
        if (strcmp(phoneBook->contacts[i].name, name) == 0) {
            return phoneBook->contacts[i].number;
        }
    }
    return NULL;
}

void printPhoneBook(struct phoneNumberBook *phoneBook) {
    for (int i = 0; i < phoneBook->numContacts; i++) {
        printf("%s: %s\n", phoneBook->contacts[i].name, phoneBook->contacts[i].number);
    }
}

int main() {
    struct phoneNumberBook *phoneBook = createPhoneBook();

    // Let's add some wacky contacts to our phone book!

    addContact(phoneBook, "Mr. Bean", "555-123-4567");
    addContact(phoneBook, "Mr. Magoo", "555-234-5678");
    addContact(phoneBook, "The Pink Panther", "555-345-6789");
    addContact(phoneBook, "Bugs Bunny", "555-456-7890");
    addContact(phoneBook, "Daffy Duck", "555-567-8901");
    addContact(phoneBook, "Tweety Bird", "555-678-9012");
    addContact(phoneBook, "Sylvester the Cat", "555-789-0123");
    addContact(phoneBook, "Tom and Jerry", "555-890-1234");
    addContact(phoneBook, "SpongeBob SquarePants", "555-901-2345");
    addContact(phoneBook, "Patrick Star", "555-012-3456");

    // Let's try finding the number of our favorite wacky character!

    char *number = findContactNumber(phoneBook, "Bugs Bunny");
    if (number != NULL) {
        printf("Bugs Bunny's number is: %s\n", number);
    } else {
        printf("Sorry, Bugs Bunny's number is not in the phone book.\n");
    }

    // And finally, let's print out our entire phone book for reference!

    printf("\nHere is the entire phone book:\n");
    printPhoneBook(phoneBook);

    return 0;
}