//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct to represent a contact
struct contact {
    char name[50];
    char number[20];
    int age;
};

// Define an array to store all contacts
struct contact contacts[10];

// Function to add a new contact
void add_contact(struct contact *c) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(contacts[i].name, c->name) == 0) {
            // Contact already exists, update the existing one
            contacts[i].age = c->age;
            break;
        }
    }
    if (i == 10) {
        // Contact does not exist, add a new one
        memcpy(&contacts[i], c, sizeof(struct contact));
        i++;
    }
}

// Function to print all contacts
void print_contacts() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%s %d\n", contacts[i].name, contacts[i].age);
    }
}

int main() {
    // Add some contacts
    struct contact c1 = {"Alice", "555-1234", 25};
    struct contact c2 = {"Bob", "555-5678", 30};
    struct contact c3 = {"Charlie", "555-9012", 35};
    add_contact(&c1);
    add_contact(&c2);
    add_contact(&c3);

    // Print all contacts
    print_contacts();

    // Add a new contact and print again
    struct contact c4 = {"David", "555-1111", 20};
    add_contact(&c4);
    print_contacts();

    return 0;
}