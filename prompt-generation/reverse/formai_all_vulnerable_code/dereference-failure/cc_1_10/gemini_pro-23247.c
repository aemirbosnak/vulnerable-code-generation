//GEMINI-pro DATASET v1.0 Category: Educational ; Style: brave
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#pragma clang diagnostic ignored "-Wconversion"
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wshadow"
#pragma clang diagnostic ignored "-Wunused-value"
#pragma clang diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wenum-conversion"
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#pragma clang diagnostic ignored "-Wtautological-compare"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wdouble-promotion"
#pragma clang diagnostic ignored "-Wfloat-conversion"
#pragma clang diagnostic ignored "-Wint-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wold-style-definition"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wshift-count-overflow"
#pragma clang diagnostic ignored "-Wshift-negative-value"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_ADDRESS_LENGTH 255

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
} Contact;

Contact *createContact(char *name, char *email, char *phoneNumber, char *address) {
    Contact *contact = malloc(sizeof(Contact));
    strcpy(contact->name, name);
    strcpy(contact->email, email);
    strcpy(contact->phoneNumber, phoneNumber);
    strcpy(contact->address, address);
    return contact;
}

void printContact(Contact *contact) {
    printf("Name: %s\n", contact->name);
    printf("Email: %s\n", contact->email);
    printf("Phone Number: %s\n", contact->phoneNumber);
    printf("Address: %s\n", contact->address);
}

int main() {
    Contact *john = createContact("John Doe", "john.doe@example.com", "555-123-4567", "123 Main Street");
    Contact *jane = createContact("Jane Doe", "jane.doe@example.com", "555-234-5678", "456 Elm Street");
    printContact(john);
    printf("\n");
    printContact(jane);
    return 0;
}

#pragma clang diagnostic pop