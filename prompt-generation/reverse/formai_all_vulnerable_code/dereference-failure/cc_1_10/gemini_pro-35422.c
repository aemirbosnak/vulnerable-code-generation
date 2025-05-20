//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The Baker Street Irregulars' Phone Book

// The Irregulars' Registry
struct Irregular {
    char *name;
    char *phone_number;
    struct Irregular *next;
};

// The Baker Street Irregulars' Headquarters
struct Directory {
    struct Irregular *head;
};

// The Great Detective's Inquiries
void inquire(struct Directory *directory, char *name) {
    struct Irregular *irregular = directory->head;
    while (irregular != NULL) {
        if (strcmp(irregular->name, name) == 0) {
            printf("Elementary, my dear Watson! %s's phone number is %s.\n", name, irregular->phone_number);
            return;
        }
        irregular = irregular->next;
    }
    printf("Alas, my dear Watson, %s's name is not in my registry.\n", name);
}

// The Irregulars' Registry Clerk
struct Irregular *create_irregular(char *name, char *phone_number) {
    struct Irregular *irregular = malloc(sizeof(struct Irregular));
    irregular->name = strdup(name);
    irregular->phone_number = strdup(phone_number);
    irregular->next = NULL;
    return irregular;
}

// The Irregulars' Registry Keeper
void add_irregular(struct Directory *directory, struct Irregular *irregular) {
    if (directory->head == NULL) {
        directory->head = irregular;
    } else {
        irregular->next = directory->head;
        directory->head = irregular;
    }
}

// The Irregulars' Registry Maintenance
void remove_irregular(struct Directory *directory, char *name) {
    struct Irregular *irregular = directory->head;
    struct Irregular *previous = NULL;
    while (irregular != NULL) {
        if (strcmp(irregular->name, name) == 0) {
            if (previous == NULL) {
                directory->head = irregular->next;
            } else {
                previous->next = irregular->next;
            }
            free(irregular->name);
            free(irregular->phone_number);
            free(irregular);
            return;
        }
        previous = irregular;
        irregular = irregular->next;
    }
}

// The Irregulars' Phone Book Interface
int main() {
    // The Baker Street Irregulars' Directory
    struct Directory directory;
    directory.head = NULL;

    // The Irregulars' Registry
    add_irregular(&directory, create_irregular("John Watson", "0123456789"));
    add_irregular(&directory, create_irregular("Mycroft Holmes", "0987654321"));
    add_irregular(&directory, create_irregular("Sherlock Holmes", "1234567890"));
    add_irregular(&directory, create_irregular("Irene Adler", "2345678901"));

    // The Great Detective's Inquiries
    inquire(&directory, "John Watson");
    inquire(&directory, "Mycroft Holmes");
    inquire(&directory, "Sherlock Holmes");
    inquire(&directory, "Irene Adler");
    inquire(&directory, "Dr. Mortimer");

    // The Irregulars' Registry Maintenance
    remove_irregular(&directory, "Mycroft Holmes");

    // The Great Detective's Inquiries
    inquire(&directory, "Mycroft Holmes");

    return 0;
}