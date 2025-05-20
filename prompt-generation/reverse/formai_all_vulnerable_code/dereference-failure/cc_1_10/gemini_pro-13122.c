//GEMINI-pro DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's represent our password entries as simple structs
typedef struct PasswordEntry {
    char *website;
    char *username;
    char *password;
} PasswordEntry;

// Curious about how many entries our database holds?
int numEntries = 0;

// Let's keep our entries in a dynamic array, shall we?
PasswordEntry *entries;

// A handy function to allocate and initialize a new entry
PasswordEntry* createEntry(char *website, char *username, char *password) {
    PasswordEntry *entry = malloc(sizeof(PasswordEntry));
    entry->website = strdup(website);
    entry->username = strdup(username);
    entry->password = strdup(password);
    return entry;
}

// Oh, look! Our database has a quirky name...
char *dbName = "CuriosityDatabase";

// Time to explore our database!
void exploreDatabase() {
    printf("Welcome to %s! Let's peek into your secrets...\n", dbName);
    printf("We currently have %d entries. Intriguing, isn't it?\n", numEntries);
    for (int i = 0; i < numEntries; i++) {
        printf("Website: %s\n", entries[i].website);
        printf("Username: %s\n", entries[i].username);
        printf("Password: %s\n\n", entries[i].password);
    }
}

// Let's not forget about adding new entries...
void addEntry() {
    char website[100], username[100], password[100];
    printf("Tell us, what website are we storing a password for?\n");
    scanf("%s", website);
    printf("And your username for this website?\n");
    scanf("%s", username);
    printf("Finally, the password you wish to store (we're all ears...)\n");
    scanf("%s", password);

    // Let's grow our array to accommodate the new entry
    entries = realloc(entries, sizeof(PasswordEntry) * (numEntries + 1));
    entries[numEntries++] = *createEntry(website, username, password);
    printf("Your secret is safe with us! (%d entries now)\n", numEntries);
}

// Curious about a specific website?
void searchWebsite() {
    char website[100];
    printf("Which website's password do you seek, curious soul?\n");
    scanf("%s", website);

    for (int i = 0; i < numEntries; i++) {
        if (!strcmp(entries[i].website, website)) {
            printf("For %s, your username is %s and password is %s\n", website, entries[i].username, entries[i].password);
            return;
        }
    }
    printf("Sorry, we couldn't find that website in our database.\n");
}

// Time to bid farewell to our secrets...
void deleteEntry() {
    char website[100];
    printf("Which website's password do you wish to erase from our memory?\n");
    scanf("%s", website);

    int foundIndex = -1;
    for (int i = 0; i < numEntries; i++) {
        if (!strcmp(entries[i].website, website)) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Sorry, we couldn't find that website in our database.\n");
        return;
    }

    // Shift entries to fill the gap
    for (int i = foundIndex; i < numEntries - 1; i++) {
        entries[i] = entries[i + 1];
    }

    // Shrink the array
    entries = realloc(entries, sizeof(PasswordEntry) * (numEntries - 1));
    numEntries--;
    printf("Your secret is now forgotten. (%d entries now)\n", numEntries);
}

// The grand finale: our interactive menu!
void menu() {
    int choice;
    do {
        printf("What curious action do you have in mind?\n");
        printf("1. Explore the database\n");
        printf("2. Add a new entry\n");
        printf("3. Search for a website's password\n");
        printf("4. Delete an entry\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                exploreDatabase();
                break;
            case 2:
                addEntry();
                break;
            case 3:
                searchWebsite();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                printf("Farewell, curious soul! Your secrets remain safe with us.\n");
                break;
            default:
                printf("Sorry, that's not a valid option. Try again.\n");
        }
    } while (choice != 5);
}

int main() {
    // Initialize our database with some sample entries
    entries = malloc(sizeof(PasswordEntry) * 3);
    entries[0] = *createEntry("www.example.com", "johndoe", "password1");
    entries[1] = *createEntry("www.google.com", "janedoe", "password2");
    entries[2] = *createEntry("www.facebook.com", "johnsmith", "password3");
    numEntries = 3;

    // Let the curious exploration begin!
    menu();

    // Free the allocated memory before we say goodbye
    for (int i = 0; i < numEntries; i++) {
        free(entries[i].website);
        free(entries[i].username);
        free(entries[i].password);
    }
    free(entries);
    return 0;
}