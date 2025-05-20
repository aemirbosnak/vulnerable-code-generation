//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <string.h>

// Function to add a new entry to the phone book
void add_entry(char* name, char* phone_number) {
    char* new_entry = (char*)malloc(strlen(name) + strlen(phone_number) + 1);
    strcpy(new_entry, name);
    strcat(new_entry, " - ");
    strcat(new_entry, phone_number);

    FILE* file = fopen("phone_book.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
    } else {
        fprintf(file, "%s\n", new_entry);
        fclose(file);
    }

    free(new_entry);
}

// Function to search for an entry in the phone book
char* search_entry(char* name) {
    FILE* file = fopen("phone_book.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
    } else {
        char* result = (char*)malloc(strlen(name) + 1);
        char line[100];
        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, name)!= NULL) {
                strcpy(result, line);
                break;
            }
        }
        fclose(file);
        return result;
    }
    return NULL;
}

// Function to display all entries in the phone book
void display_entries() {
    FILE* file = fopen("phone_book.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
    } else {
        char line[100];
        while (fgets(line, sizeof(line), file)) {
            printf("%s\n", line);
        }
        fclose(file);
    }
}

int main() {
    char* name;
    char* phone_number;
    char* result;

    while (1) {
        printf("1. Add entry\n2. Search entry\n3. Display entries\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", &name);
                printf("Enter phone number: ");
                scanf("%s", &phone_number);
                add_entry(name, phone_number);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", &name);
                result = search_entry(name);
                if (result!= NULL) {
                    printf("Entry found: %s\n", result);
                    free(result);
                } else {
                    printf("Entry not found.\n");
                }
                break;
            case 3:
                display_entries();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}