//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 20
#define MAX_NUMBER_LENGTH 15
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_NUMBER_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

int main() {
    FILE *file;
    Contact contacts[100];
    int num_contacts = 0;
    char line[100];
    char *token;
    int i;

    // Open file
    file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file and store contacts in array
    while (fgets(line, sizeof(line), file)!= NULL) {
        token = strtok(line, ",");
        strcpy(contacts[num_contacts].name, token);
        token = strtok(NULL, ",");
        strcpy(contacts[num_contacts].phone, token);
        token = strtok(NULL, ",");
        strcpy(contacts[num_contacts].email, token);
        num_contacts++;
    }

    fclose(file);

    // Sort contacts alphabetically by name
    for (i = 0; i < num_contacts - 1; i++) {
        while (strcmp(contacts[i].name, contacts[i+1].name) > 0) {
            Contact temp = contacts[i];
            contacts[i] = contacts[i+1];
            contacts[i+1] = temp;
        }
    }

    // Print sorted contacts
    for (i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n\n", contacts[i].email);
    }

    return 0;
}