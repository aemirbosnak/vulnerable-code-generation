//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

// Radiation Hardened Phone Book

// Bunker structure containing the individual contacts' data.
typedef struct Bunker {
    char* name;
    char* number;
    int  radiation_level;
    int  health;
} Bunker;

// Global array to hold the phone book
Bunker* phonebook[100];
int num_contacts = 0;

// Function to add a new contact to the phone book.
void add_contact(char* name, char* number, int radiation_level, int health) {
    if (num_contacts == 100) {
        printf("Phone book is full!\n");
        return;
    }

    phonebook[num_contacts++] = malloc(sizeof(Bunker));
    phonebook[num_contacts-1]->name = strdup(name);
    phonebook[num_contacts-1]->number = strdup(number);
    phonebook[num_contacts-1]->radiation_level = radiation_level;
    phonebook[num_contacts-1]->health = health;
}

// Function to search for a contact in the phone book.
Bunker* find_contact(char* name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i]->name, name) == 0) {
            return phonebook[i];
        }
    }

    return NULL;
}

// Function to print the details of a contact.
void print_contact(Bunker* contact) {
    printf("Name: %s\n", contact->name);
    printf("Number: %s\n", contact->number);
    printf("Radiation Level: %d\n", contact->radiation_level);
    printf("Health: %d\n", contact->health);
}

// Main function.
int main(int argc, char** argv) {
    // Add some contacts to the phone book.
    add_contact("Scavenger", "123-456-7890", 10, 75);
    add_contact("Medic", "098-765-4321", 5, 90);
    add_contact("Engineer", "234-567-8901", 15, 60);

    // Search for a contact.
    Bunker* contact = find_contact("Scavenger");
    if (contact == NULL) {
        printf("Contact not found!\n");
    } else {
        // Print the contact's details.
        print_contact(contact);
    }

    return 0;
}