//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define FILE_NAME "passwords.txt"

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

void add_entry();
void view_entries();
void delete_entry();
void clear_buffer();

int main() {
    int choice;

    while (1) {
        printf("\nPassword Management System\n");
        printf("1. Add Password Entry\n");
        printf("2. View Password Entries\n");
        printf("3. Delete Password Entry\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clear_buffer(); // Clear input buffer

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void add_entry() {
    PasswordEntry entry;
    FILE *file = fopen(FILE_NAME, "a");
    
    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("Enter website: ");
    fgets(entry.website, sizeof(entry.website), stdin);
    entry.website[strcspn(entry.website, "\n")] = 0; // Remove newline

    printf("Enter username: ");
    fgets(entry.username, sizeof(entry.username), stdin);
    entry.username[strcspn(entry.username, "\n")] = 0; // Remove newline
    
    printf("Enter password: ");
    fgets(entry.password, sizeof(entry.password), stdin);
    entry.password[strcspn(entry.password, "\n")] = 0; // Remove newline

    fprintf(file, "%s|%s|%s\n", entry.website, entry.username, entry.password);
    fclose(file);
    printf("Entry added successfully.\n");
}

void view_entries() {
    PasswordEntry entry;
    FILE *file = fopen(FILE_NAME, "r");
    
    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("\nStored Password Entries:\n");
    while (fgets(entry.website, sizeof(entry.website), file)) {
        char *token = strtok(entry.website, "|");
        strcpy(entry.website, token);
        
        token = strtok(NULL, "|");
        strcpy(entry.username, token);
        
        token = strtok(NULL, "|");
        strcpy(entry.password, token);

        printf("Website: %s\nUsername: %s\nPassword: %s\n", entry.website, entry.username, entry.password);
    }
    fclose(file);
}

void delete_entry() {
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp_file = fopen("temp.txt", "w");
    PasswordEntry entry;
    char website_to_delete[MAX_LENGTH];

    if (!file || !temp_file) {
        perror("Unable to open files");
        return;
    }

    printf("Enter website to delete: ");
    fgets(website_to_delete, sizeof(website_to_delete), stdin);
    website_to_delete[strcspn(website_to_delete, "\n")] = 0; // Remove newline

    int found = 0;
    
    while (fgets(entry.website, sizeof(entry.website), file)) {
        char *token = strtok(entry.website, "|");
        strcpy(entry.website, token);

        token = strtok(NULL, "|");
        strcpy(entry.username, token);

        token = strtok(NULL, "|");
        strcpy(entry.password, token);

        if (strcmp(entry.website, website_to_delete) != 0) {
            fprintf(temp_file, "%s|%s|%s", entry.website, entry.username, entry.password);
        } else {
            found = 1;
        }
    }
    
    fclose(file);
    fclose(temp_file);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("Entry deleted successfully.\n");
    else
        printf("No entry found for the website: %s\n", website_to_delete);
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}