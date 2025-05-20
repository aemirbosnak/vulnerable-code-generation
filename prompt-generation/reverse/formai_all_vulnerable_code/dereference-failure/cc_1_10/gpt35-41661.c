//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold information about each person on the mailing list
typedef struct {
    char *name;
    char *email;
    int age;
} Person;

// Define a struct to hold information about the mailing list
typedef struct {
    Person **people;
    int length;
} MailingList;

// Create a new Person with the given name, email, and age
Person *createPerson(char *name, char *email, int age) {
    Person *person = (Person *) malloc(sizeof(Person));
    person->name = (char *) malloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->email = (char *) malloc(strlen(email) + 1);
    strcpy(person->email, email);
    person->age = age;
    return person;
}

// Free the memory allocated for a Person
void freePerson(Person *person) {
    free(person->name);
    free(person->email);
    free(person);
}

// Add a Person to the given MailingList
void addPersonToMailingList(MailingList *list, Person *person) {
    list->length++;
    list->people = (Person **) realloc(list->people, list->length * sizeof(Person *));
    list->people[list->length - 1] = person;
}

// Remove a Person from the given MailingList
void removePersonFromMailingList(MailingList *list, int index) {
    freePerson(list->people[index]);
    for (int i = index; i < list->length - 1; i++) {
        list->people[i] = list->people[i + 1];
    }
    list->length--;
    list->people = (Person **) realloc(list->people, list->length * sizeof(Person *));
}

// Print out a Person's information
void printPerson(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Email: %s\n", person->email);
    printf("Age: %d\n", person->age);
    printf("\n");
}

// Print out the entire mailing list
void printMailingList(MailingList *list) {
    for (int i = 0; i < list->length; i++) {
        printPerson(list->people[i]);
    }
}

int main() {
    // Create a new empty MailingList
    MailingList *list = (MailingList *) malloc(sizeof(MailingList));
    list->people = NULL;
    list->length = 0;

    // Add some people to the mailing list
    addPersonToMailingList(list, createPerson("John Smith", "jsmith@example.com", 30));
    addPersonToMailingList(list, createPerson("Jane Doe", "jdoe@example.com", 25));
    addPersonToMailingList(list, createPerson("Bob Johnson", "bjohnson@example.com", 40));

    // Print out the mailing list
    printf("Mailing List:\n");
    printMailingList(list);

    // Remove a person from the mailing list
    printf("Removing John Smith from the mailing list.\n");
    removePersonFromMailingList(list, 0);

    // Print out the updated mailing list
    printf("Updated Mailing List:\n");
    printMailingList(list);

    // Free the memory allocated for the mailing list and its people
    for (int i = 0; i < list->length; i++) {
        freePerson(list->people[i]);
    }
    free(list->people);
    free(list);

    return 0;
}