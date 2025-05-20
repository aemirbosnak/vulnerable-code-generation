//FormAI DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define FILENAME "passwords.txt"

struct Password {
    char website[MAX];
    char username[MAX];
    char password[MAX];
};

// function prototypes
void add_password(struct Password passwords[]);
void view_passwords(struct Password passwords[]);
void search_password(struct Password passwords[]);
void delete_password(struct Password passwords[]);

int main() {
    struct Password passwords[MAX];
    int choice, num_passwords = 0;

    // clear file before starting program
    FILE *file = fopen(FILENAME, "w");
    fclose(file);

    // main menu
    printf("Welcome to Sherlock Holmes' Password Manager\n");
    printf("---------------------------------------------\n");
    do {
        printf("\nPlease select an option:\n");
        printf("1. Add a new password\n");
        printf("2. View all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Delete a password\n");
        printf("5. Exit the program\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_password(passwords);
                num_passwords++;
                break;
            case 2:
                view_passwords(passwords);
                break;
            case 3:
                search_password(passwords);
                break;
            case 4:
                delete_password(passwords);
                num_passwords--;
                break;
            case 5:
                printf("\nThank you for using Sherlock Holmes' Password Manager. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

// add a new password to the file
void add_password(struct Password passwords[]) {
    FILE *file = fopen(FILENAME, "a");
    struct Password new_password;

    printf("\nPlease enter the website for the new password: ");
    scanf(" %[^\n]s", new_password.website);
    printf("Please enter the username for %s: ", new_password.website);
    scanf(" %[^\n]s", new_password.username);
    printf("Please enter the password for %s: ", new_password.website);
    scanf(" %[^\n]s", new_password.password);

    // write password to file
    fprintf(file, "%s,%s,%s\n", new_password.website, new_password.username, new_password.password);
    fclose(file);

    printf("\nNew password added successfully!\n");
}

// view all stored passwords
void view_passwords(struct Password passwords[]) {
    FILE *file = fopen(FILENAME, "r");
    char line[MAX];

    printf("\nAll stored passwords:\n");
    while(fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    if(feof(file)) {
        printf("End of file reached.");
    }

    fclose(file);
}

// search for a specific password by website name
void search_password(struct Password passwords[]) {
    FILE *file = fopen(FILENAME, "r");
    char line[MAX], website_search[MAX];
    int found_password = 0;

    printf("\nEnter the website name to search for: ");
    scanf("%s", website_search);

    while(fgets(line, sizeof(line), file)) {
        if(strstr(line, website_search) != NULL) {
            found_password = 1;
            printf("%s", line);
            break;
        }
    }

    if(!found_password) {
        printf("\nNo password found for %s.\n", website_search);
    }

    fclose(file);
}

// delete an existing password
void delete_password(struct Password passwords[]) {
    FILE *file = fopen(FILENAME, "r");
    FILE *temp_file = fopen("temp.txt", "w");
    char line[MAX], website_search[MAX];
    int found_password = 0;

    printf("\nEnter the website name whose password should be deleted: ");
    scanf("%s", website_search);

    while(fgets(line, sizeof(line), file)) {
        if(strstr(line, website_search) == NULL) {
            fprintf(temp_file, "%s", line);
        } else {
            found_password = 1;
        }
    }

    fclose(file);
    remove(FILENAME);
    fclose(temp_file);
    rename("temp.txt", FILENAME);

    if(found_password) {
        printf("\nPassword for %s deleted successfully.\n", website_search);
    } else {
        printf("\nNo password found for %s.\n", website_search);
    }
}