//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

// Structure to store contact information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
} Contact;

// Function to read contact information from file
Contact readContact(const char* filePath) {
    // Open file in read mode
    FILE* file = fopen(filePath, "r");

    // Check if file is empty
    if (feof(file)) {
        // File is empty, return empty contact struct
        Contact contact;
        return contact;
    }

    // Read name and phone number from file
    char line[100];
    fgets(line, 100, file);
    char* name = strtok(line, " ");
    char* phoneNumber = strtok(NULL, "\n");

    // Create contact struct and fill in name and phone number
    Contact contact;
    strcpy(contact.name, name);
    strcpy(contact.phoneNumber, phoneNumber);

    // Return contact struct
    return contact;
}

// Function to write contact information to file
void writeContact(const char* filePath, const Contact* contact) {
    // Open file in write mode
    FILE* file = fopen(filePath, "w");

    // Check if file is empty
    if (feof(file)) {
        // File is empty, write contact struct
        fprintf(file, "%s %s\n", contact->name, contact->phoneNumber);
    } else {
        // Append contact struct to existing file
        fprintf(file, "%s %s\n", contact->name, contact->phoneNumber);
    }

    // Close file
    fclose(file);
}

int main() {
    // Define file paths
    const char* romanticFilePath = "romantic_contacts.txt";
    const char* practicalFilePath = "practical_contacts.txt";

    // Read romantic contact information
    Contact romanticContact = readContact(romanticFilePath);

    // Print romantic contact information
    printf("Romantic Contact:\n");
    printf("Name: %s\n", romanticContact.name);
    printf("Phone Number: %s\n", romanticContact.phoneNumber);

    // Write practical contact information
    Contact practicalContact = {
        .name = "Sarah",
        .phoneNumber = "555-1234"
    };
    writeContact(practicalFilePath, &practicalContact);

    // Print practical contact information
    printf("Practical Contact:\n");
    printf("Name: %s\n", practicalContact.name);
    printf("Phone Number: %s\n", practicalContact.phoneNumber);

    return 0;
}