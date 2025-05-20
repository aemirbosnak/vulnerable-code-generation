//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a contact to the phone book
void add_contact(char* name, char* number) {
    FILE* file = fopen("phonebook.txt", "a");
    if (file!= NULL) {
        fprintf(file, "%s %s\n", name, number);
        fclose(file);
    } else {
        printf("Error opening file.\n");
    }
}

// Function to search for a contact in the phone book
char* search_contact(char* name) {
    FILE* file = fopen("phonebook.txt", "r");
    if (file!= NULL) {
        char buffer[100];
        char* result = fgets(buffer, sizeof(buffer), file);
        if (result!= NULL) {
            result[strcspn(result, "\n")] = '\0'; // remove the newline character
            return result;
        } else {
            return NULL;
        }
    } else {
        printf("Error opening file.\n");
        return NULL;
    }
}

int main() {
    char name[100];
    char number[100];

    while (1) {
        printf("1. Add contact\n2. Search contact\n3. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter contact name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove the newline character
                printf("Enter contact number: ");
                fgets(number, sizeof(number), stdin);
                number[strcspn(number, "\n")] = '\0'; // remove the newline character
                add_contact(name, number);
                break;
            case 2:
                printf("Enter contact name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove the newline character
                char* result = search_contact(name);
                if (result!= NULL) {
                    printf("Contact found: %s\n", result);
                    free(result);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}