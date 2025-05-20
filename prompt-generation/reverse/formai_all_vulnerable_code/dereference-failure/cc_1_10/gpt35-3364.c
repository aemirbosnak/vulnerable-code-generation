//FormAI DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a data structure for a phonebook entry
typedef struct phonebook_entry {
    char name[50];
    char phone_num[20];
} PhonebookEntry;

// Define a function to search for a specific phonebook entry
int search_phonebook(PhonebookEntry* phonebook, int num_entries, char* name) {
    for (int i=0; i<num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int num_entries = 0;
    PhonebookEntry* phonebook = malloc(num_entries * sizeof(PhonebookEntry));
    char input[50];
    bool running = true;

    printf("Welcome to your C Phone Book!\n");

    while (running) {
        printf("\nPlease select an option:\n1. Add new entry\n2. Search for entry\n3. Print all entries\n4. Exit program\n\nOption: ");
        fgets(input, 50, stdin);

        // Handle user input
        switch (atoi(input)) {
            case 1: {  // Add new entry
                // Create new PhonebookEntry
                PhonebookEntry new_entry;
                printf("\nEnter name: ");
                fgets(new_entry.name, 50, stdin);
                printf("Enter phone number: ");
                fgets(new_entry.phone_num, 20, stdin);

                // Add new entry to phonebook array
                num_entries++;
                phonebook = realloc(phonebook, num_entries * sizeof(PhonebookEntry));
                phonebook[num_entries-1] = new_entry;
                printf("\nAdded new entry successfully!\n");
                break;
            }
            case 2: {  // Search for entry
                char name[50];
                printf("\nEnter name: ");
                fgets(name, 50, stdin);
                int index = search_phonebook(phonebook, num_entries, name);
                if (index == -1) {
                    printf("Entry not found.\n");
                } else {
                    printf("\n%s's phone number is %s\n", phonebook[index].name, phonebook[index].phone_num);
                }
                break;
            }
            case 3: {  // Print all entries
                printf("\nPHONE BOOK ENTRIES:\n");
                for (int i=0; i<num_entries; i++) {
                    printf("%s: %s", phonebook[i].name, phonebook[i].phone_num);
                }
                break;
            }
            case 4: {  // Exit program
                running = false;
                break;
            }
            default: {
                printf("\nInvalid input, please try again.\n");
                break;
            }
        }
    }

    free(phonebook);
    printf("\nThank you for using the C Phone Book!\n");

    return 0;
}