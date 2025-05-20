//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to add a new contact to the phone book
void add_contact(char *name, char *number) {
    char *line = NULL;
    size_t len = 0;
    int count = 0;

    // Open the phone book file
    FILE *fp = fopen("phonebook.txt", "a");

    // Check if the file was opened successfully
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Loop until a valid line is found
    while ((line = fgets(line, sizeof(line), fp))!= NULL) {
        // Check if the line is empty or starts with a '#'
        if (strlen(line) == 0 || line[0] == '#') {
            break;
        }

        // Check if the line is already a contact
        if (isdigit(line[0])) {
            // Increment the count
            count++;
        } else {
            // The line is a contact
            printf("Contact added: %s (%s)\n", line, line+strlen(line)-1);
            break;
        }
    }

    // Add the new contact to the file
    fprintf(fp, "%s (%s)\n", name, number);

    // Close the file
    fclose(fp);

    // Print the count of contacts in the phone book
    printf("Number of contacts: %d\n", count);
}

// Function to display all contacts in the phone book
void display_contacts() {
    char *line = NULL;
    size_t len = 0;
    int count = 0;

    // Open the phone book file
    FILE *fp = fopen("phonebook.txt", "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Loop until a valid line is found
    while ((line = fgets(line, sizeof(line), fp))!= NULL) {
        // Check if the line is empty or starts with a '#'
        if (strlen(line) == 0 || line[0] == '#') {
            break;
        }

        // Check if the line is already a contact
        if (isdigit(line[0])) {
            // Increment the count
            count++;
        } else {
            // The line is a contact
            printf("Contact: %s (%s)\n", line, line+strlen(line)-1);
        }
    }

    // Close the file
    fclose(fp);

    // Print the count of contacts in the phone book
    printf("Number of contacts: %d\n", count);
}

int main() {
    // Add a new contact to the phone book
    add_contact("John Smith", "123-456-7890");

    // Display all contacts in the phone book
    display_contacts();

    return 0;
}