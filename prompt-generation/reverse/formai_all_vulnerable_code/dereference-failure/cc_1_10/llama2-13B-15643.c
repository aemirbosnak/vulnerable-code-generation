//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME_LENGTH 256
#define MAX_PHONE_NUMBER_LENGTH 20

// Global variables
char *phoneBook[100];
int numPhones = 0;

// Function prototypes
void addPhone(char *name, char *phoneNumber);
void searchPhone(char *name);

int main() {
    // Initialize phone book
    for (int i = 0; i < 100; i++) {
        phoneBook[i] = NULL;
    }

    // Add some phones
    addPhone("John Doe", "555-1234");
    addPhone("Jane Doe", "555-5678");
    addPhone("Bob Smith", "555-9012");

    // Search for a phone number
    searchPhone("Jane Doe");

    return 0;
}

// Function to add a phone number to the phone book
void addPhone(char *name, char *phoneNumber) {
    char *newPhone = malloc(strlen(name) + strlen(phoneNumber) + 2);
    sprintf(newPhone, "%s %s", name, phoneNumber);
    phoneBook[numPhones] = newPhone;
    numPhones++;
}

// Function to search for a phone number in the phone book
void searchPhone(char *name) {
    int i;
    for (i = 0; i < numPhones; i++) {
        if (strcmp(phoneBook[i], name) == 0) {
            printf("Found phone number %s\n", phoneBook[i]);
            return;
        }
    }
    printf("Phone number not found\n");
}