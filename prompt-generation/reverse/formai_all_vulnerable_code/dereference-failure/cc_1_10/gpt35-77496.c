//FormAI DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_NUM_OF_PASSWORDS 10

// Password struct
typedef struct Password {
    char* site_name;
    char* user_name;
    char* password;
} Password;

// Function prototypes
void clear_buffer();
void add_password(Password passwords[], int* num_of_passwords);
void print_passwords(Password passwords[], int num_of_passwords);

int main() {
    // Initialize variables
    Password passwords[MAX_NUM_OF_PASSWORDS];
    int num_of_passwords = 0;
    char choice;

    // Start the program
    printf("C Password Management Program\n\n");
    printf("What would you like to do?\n");
    printf("1. Add a new password\n");
    printf("2. Print all saved passwords\n");
    printf("q. Quit the program\n");

    // Process user input
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%c", &choice);
        clear_buffer(); // clear the input buffer

        switch (choice) {
            case '1':
                add_password(passwords, &num_of_passwords);
                break;

            case '2':
                print_passwords(passwords, num_of_passwords);
                break;

            case 'q':
                printf("\nExiting Password Management Program...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }

        // Show the menu again
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new password\n");
        printf("2. Print all saved passwords\n");
        printf("q. Quit the program\n");
    }

    return 0;
}

/**
 * This function clears the input buffer
 **/
void clear_buffer() {
    while (getchar() != '\n');
}

/**
 * This function adds a new password to the list
 **/
void add_password(Password passwords[], int* num_of_passwords) {
    // Make sure we have not exceeded the maximum number of passwords
    if (*num_of_passwords == MAX_NUM_OF_PASSWORDS) {
        printf("\nCannot add a new password! The maximum number of passwords has been reached.\n");
        return;
    }

    // Allocate memory for new password struct
    Password* new_password = (Password*) malloc(sizeof(Password));

    // Save site name
    printf("\nEnter the site name: ");
    new_password->site_name = (char*) malloc(sizeof(char) * MAX_PASSWORD_LENGTH);
    scanf("%s", new_password->site_name);
    clear_buffer();

    // Save user name
    printf("Enter the user name: ");
    new_password->user_name = (char*) malloc(sizeof(char) * MAX_PASSWORD_LENGTH);
    scanf("%s", new_password->user_name);
    clear_buffer();

    // Save password
    printf("Enter the password: ");
    new_password->password = (char*) malloc(sizeof(char) * MAX_PASSWORD_LENGTH);
    scanf("%s", new_password->password);
    clear_buffer();

    // Add the password to the list
    passwords[*num_of_passwords] = *new_password;
    (*num_of_passwords)++;

    // Free memory used for new password
    free(new_password);

    printf("\nPassword added successfully!\n");
}

/**
 * This function prints all saved passwords
 **/
void print_passwords(Password passwords[], int num_of_passwords) {
    if (num_of_passwords == 0) {
        printf("\nThere are no saved passwords to display!\n");
        return;
    }

    printf("\nSite Name\tUser Name\tPassword\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < num_of_passwords; i++) {
        printf("%s\t\t%s\t\t%s\n", passwords[i].site_name, passwords[i].user_name, passwords[i].password);
    }
}