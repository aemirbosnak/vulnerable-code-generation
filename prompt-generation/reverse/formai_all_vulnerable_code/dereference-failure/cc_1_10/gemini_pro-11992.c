//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a phone book entry
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} PhoneBookEntry;

// Function to create a new phone book entry
PhoneBookEntry* createEntry(char *name, char *phone, char *email) {
    PhoneBookEntry *entry = malloc(sizeof(PhoneBookEntry));
    strcpy(entry->name, name);
    strcpy(entry->phone, phone);
    strcpy(entry->email, email);
    return entry;
}

// Function to print a phone book entry
void printEntry(PhoneBookEntry *entry) {
    printf("%s\t%s\t%s\n", entry->name, entry->phone, entry->email);
}

// Function to add a new entry to the phone book
void addEntry(PhoneBookEntry **phoneBook, int *numEntries, PhoneBookEntry *entry) {
    phoneBook[*numEntries] = entry;
    (*numEntries)++;
}

// Function to search for an entry in the phone book by name
PhoneBookEntry* searchByName(PhoneBookEntry **phoneBook, int numEntries, char *name) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i]->name, name) == 0) {
            return phoneBook[i];
        }
    }
    return NULL;
}

// Function to search for an entry in the phone book by phone number
PhoneBookEntry* searchByPhone(PhoneBookEntry **phoneBook, int numEntries, char *phone) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i]->phone, phone) == 0) {
            return phoneBook[i];
        }
    }
    return NULL;
}

// Function to search for an entry in the phone book by email
PhoneBookEntry* searchByEmail(PhoneBookEntry **phoneBook, int numEntries, char *email) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i]->email, email) == 0) {
            return phoneBook[i];
        }
    }
    return NULL;
}

// Function to delete an entry from the phone book by name
void deleteByName(PhoneBookEntry **phoneBook, int *numEntries, char *name) {
    for (int i = 0; i < *numEntries; i++) {
        if (strcmp(phoneBook[i]->name, name) == 0) {
            free(phoneBook[i]);
            for (int j = i + 1; j < *numEntries; j++) {
                phoneBook[j - 1] = phoneBook[j];
            }
            (*numEntries)--;
            break;
        }
    }
}

// Function to delete an entry from the phone book by phone number
void deleteByPhone(PhoneBookEntry **phoneBook, int *numEntries, char *phone) {
    for (int i = 0; i < *numEntries; i++) {
        if (strcmp(phoneBook[i]->phone, phone) == 0) {
            free(phoneBook[i]);
            for (int j = i + 1; j < *numEntries; j++) {
                phoneBook[j - 1] = phoneBook[j];
            }
            (*numEntries)--;
            break;
        }
    }
}

// Function to delete an entry from the phone book by email
void deleteByEmail(PhoneBookEntry **phoneBook, int *numEntries, char *email) {
    for (int i = 0; i < *numEntries; i++) {
        if (strcmp(phoneBook[i]->email, email) == 0) {
            free(phoneBook[i]);
            for (int j = i + 1; j < *numEntries; j++) {
                phoneBook[j - 1] = phoneBook[j];
            }
            (*numEntries)--;
            break;
        }
    }
}

// Main function
int main() {
    // Create a phone book
    PhoneBookEntry *phoneBook[100];
    int numEntries = 0;

    // Add some entries to the phone book
    addEntry(phoneBook, &numEntries, createEntry("John Doe", "555-555-5555", "john.doe@example.com"));
    addEntry(phoneBook, &numEntries, createEntry("Jane Doe", "555-555-5556", "jane.doe@example.com"));
    addEntry(phoneBook, &numEntries, createEntry("John Smith", "555-555-5557", "john.smith@example.com"));
    addEntry(phoneBook, &numEntries, createEntry("Jane Smith", "555-555-5558", "jane.smith@example.com"));

    // Print the phone book
    printf("Phone Book:\n");
    for (int i = 0; i < numEntries; i++) {
        printEntry(phoneBook[i]);
    }

    // Search for an entry by name
    char name[] = "John Doe";
    PhoneBookEntry *entry = searchByName(phoneBook, numEntries, name);
    if (entry != NULL) {
        printf("Found entry by name: %s\n", name);
        printEntry(entry);
    } else {
        printf("Entry not found by name: %s\n", name);
    }

    // Search for an entry by phone number
    char phone[] = "555-555-5557";
    entry = searchByPhone(phoneBook, numEntries, phone);
    if (entry != NULL) {
        printf("Found entry by phone: %s\n", phone);
        printEntry(entry);
    } else {
        printf("Entry not found by phone: %s\n", phone);
    }

    // Search for an entry by email
    char email[] = "john.smith@example.com";
    entry = searchByEmail(phoneBook, numEntries, email);
    if (entry != NULL) {
        printf("Found entry by email: %s\n", email);
        printEntry(entry);
    } else {
        printf("Entry not found by email: %s\n", email);
    }

    // Delete an entry by name
    deleteByName(phoneBook, &numEntries, name);
    printf("Deleted entry by name: %s\n", name);

    // Delete an entry by phone number
    deleteByPhone(phoneBook, &numEntries, phone);
    printf("Deleted entry by phone: %s\n", phone);

    // Delete an entry by email
    deleteByEmail(phoneBook, &numEntries, email);
    printf("Deleted entry by email: %s\n", email);

    // Print the remaining entries in the phone book
    printf("Remaining entries in the phone book:\n");
    for (int i = 0; i < numEntries; i++) {
        printEntry(phoneBook[i]);
    }

    return 0;
}