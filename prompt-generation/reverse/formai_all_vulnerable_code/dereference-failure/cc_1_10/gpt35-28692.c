//FormAI DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to hold contact information */
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

/* Function prototypes */
void printMenu();
void addContact(Contact phoneBook[], int *numContacts);
void deleteContact(Contact phoneBook[], int *numContacts);
void searchContacts(Contact phoneBook[], int numContacts);
void saveToFile(Contact phoneBook[], int numContacts);
void loadFromFile(Contact phoneBook[], int *numContacts);

/* Main function */
int main() {
    Contact phoneBook[100];  // create an array of contacts
    int numContacts = 0;     // set initial number of contacts to 0
    
    int choice;
    do {
        printMenu();                // display menu
        scanf("%d", &choice);       // get user choice
        
        switch(choice) {
            case 1:
                addContact(phoneBook, &numContacts);
                break;
            case 2:
                deleteContact(phoneBook, &numContacts);
                break;
            case 3:
                searchContacts(phoneBook, numContacts);
                break;
            case 4:
                saveToFile(phoneBook, numContacts);
                break;
            case 5:
                loadFromFile(phoneBook, &numContacts);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);  // loop until user chooses to quit
    
    return 0;
}

/* Function to display menu */
void printMenu() {
    printf("*** C PHONE BOOK ***\n");
    printf("1. Add contact\n");
    printf("2. Delete contact\n");
    printf("3. Search contacts\n");
    printf("4. Save to file\n");
    printf("5. Load from file\n");
    printf("6. Quit\n");
    printf("Enter your choice: ");
}

/* Function to add a contact */
void addContact(Contact phoneBook[], int *numContacts) {
    if (*numContacts == 100) {  // check if phone book is full
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }
    
    Contact newContact;
    printf("Enter name: ");
    scanf("%s", newContact.name);
    printf("Enter phone number: ");
    scanf("%s", newContact.phone);
    printf("Enter email: ");
    scanf("%s", newContact.email);
    
    phoneBook[*numContacts] = newContact;
    (*numContacts)++;
    printf("Contact added successfully.\n");
}

/* Function to delete a contact */
void deleteContact(Contact phoneBook[], int *numContacts) {
    if (*numContacts == 0) {  // check if phone book is empty
        printf("Phone book is empty. Nothing to delete.\n");
        return;
    }
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(name, phoneBook[i].name) == 0) {
            found = 1;
            for (int j = i; j < *numContacts - 1; j++) {
                phoneBook[j] = phoneBook[j+1];
            }
            (*numContacts)--;
            printf("Contact deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

/* Function to search for contacts */
void searchContacts(Contact phoneBook[], int numContacts) {
    if (numContacts == 0) {  // check if phone book is empty
        printf("Phone book is empty. Nothing to search for.\n");
        return;
    }
    char name[50];
    printf("Enter name to search for: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strstr(phoneBook[i].name, name) != NULL) {
            printf("Name: %s\nPhone: %s\nEmail: %s\n", phoneBook[i].name, phoneBook[i].phone, phoneBook[i].email);
            found = 1;
        }
    }
    if (!found) {
        printf("No contacts found.\n");
    }
}

/* Function to save contacts to file */
void saveToFile(Contact phoneBook[], int numContacts) {
    if (numContacts == 0) {  // check if phone book is empty
        printf("Phone book is empty. Nothing to save.\n");
        return;
    }
    char filename[50];
    printf("Enter filename to save to (include extension): ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "w");  // open file for writing
    for (int i = 0; i < numContacts; i++) {
        fprintf(file, "%s,%s,%s\n", phoneBook[i].name, phoneBook[i].phone, phoneBook[i].email);
    }
    fclose(file);  // close file
    printf("Contacts saved to file successfully.\n");
}

/* Function to load contacts from file */
void loadFromFile(Contact phoneBook[], int *numContacts) {
    char filename[50];
    printf("Enter filename to load from (include extension): ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "r");  // open file for reading
    if (file == NULL) {
        printf("File not found.\n");
        return;
    }
    
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *name = strtok(line, ",\n");
        char *phone = strtok(NULL, ",\n");
        char *email = strtok(NULL, ",\n");
        Contact newContact;
        strcpy(newContact.name, name);
        strcpy(newContact.phone, phone);
        strcpy(newContact.email, email);
        phoneBook[*numContacts] = newContact;
        (*numContacts)++;
    }
    fclose(file);  // close file
    printf("Contacts loaded from file successfully.\n");
}