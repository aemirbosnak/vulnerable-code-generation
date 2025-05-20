//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

int main() {
    FILE *file;
    contact contacts[100];
    int num_contacts = 0;
    char input[100];

    // Open the contacts file
    file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open contacts file.\n");
        return 1;
    }

    // Read in the contacts
    while (fgets(input, sizeof(input), file)!= NULL) {
        if (num_contacts >= 100) {
            printf("Error: Too many contacts.\n");
            return 1;
        }
        strcpy(contacts[num_contacts].name, strtok(input, ","));
        strcpy(contacts[num_contacts].email, strtok(NULL, ","));
        num_contacts++;
    }

    // Close the contacts file
    fclose(file);

    // Display the contacts
    printf("Name\tEmail\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t%s\n", contacts[i].name, contacts[i].email);
    }

    // Add a new contact
    printf("\nEnter name: ");
    scanf("%s", input);
    printf("Enter email: ");
    scanf("%s", input);

    if (num_contacts >= 100) {
        printf("Error: Too many contacts.\n");
        return 1;
    }

    strcpy(contacts[num_contacts].name, input);
    strcpy(contacts[num_contacts].email, input);
    num_contacts++;

    // Save the contacts
    file = fopen("contacts.txt", "w");
    for (int i = 0; i < num_contacts; i++) {
        fprintf(file, "%s,%s\n", contacts[i].name, contacts[i].email);
    }
    fclose(file);

    printf("\nContact added successfully.\n");

    return 0;
}