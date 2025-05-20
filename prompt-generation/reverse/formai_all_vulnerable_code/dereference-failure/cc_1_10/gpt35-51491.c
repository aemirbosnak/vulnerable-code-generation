//FormAI DATASET v1.0 Category: Password management ; Style: mind-bending
// Welcome to the ultimate password manager!
// This program uses advanced encryption techniques to keep your passwords safe and secure.
// Are you ready to dive into the world of mind-bending programming?
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100
#define MASTER_PASSWORD "Password123"

// Define our password structure
typedef struct password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

// Define our password database structure
typedef struct password_database {
    int num_passwords;
    password_t *passwords;
} password_database_t;

// Declare our functions
void print_options();
void add_password(password_database_t *database);
void view_passwords(password_database_t database);
void save_passwords(password_database_t database, char *filename);
void load_passwords(password_database_t *database, char *filename);
void encrypt_password(char *password, char *master_password);
void decrypt_password(char *password, char *master_password);

int main() {
    // Initialize our password database
    password_database_t database = {
        .num_passwords = 0,
        .passwords = NULL
    };
    
    // Initialize our master password
    char *master_password = MASTER_PASSWORD;
    
    // Load any saved passwords
    load_passwords(&database, "passwords.txt");
    
    // Welcome message
    printf("Welcome to the ultimate password manager!\n");
    printf("Please enter your master password:\n");
    
    // Get the user's input
    char user_input[MAX_PASSWORD_LENGTH];
    fgets(user_input, sizeof(user_input), stdin);
    
    // Check if the user's input matches the master password
    if (strcmp(user_input, master_password) != 0) {
        printf("Incorrect password. Goodbye.\n");
        return 0;
    }
    
    // Main loop
    int done = 0;
    while (!done) {
        // Print options
        print_options();
        
        // Get user input
        char choice[MAX_PASSWORD_LENGTH];
        fgets(choice, sizeof(choice), stdin);
        
        // Parse user input
        switch (atoi(choice)) {
            case 1:
                // Add new password
                add_password(&database);
                break;
            case 2:
                // View saved passwords
                view_passwords(database);
                break;
            case 3:
                // Save passwords to file
                save_passwords(database, "passwords.txt");
                break;
            case 4:
                // Exit program
                printf("Goodbye!\n");
                done = 1;
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    // Free memory allocated to passwords
    for (int i = 0; i < database.num_passwords; i++) {
        free(database.passwords[i].name);
        free(database.passwords[i].password);
    }
    free(database.passwords);
    
    return 0;
}

// Print the program's options
void print_options() {
    printf("\n");
    printf("What would you like to do?\n");
    printf("\t1. Add new password\n");
    printf("\t2. View saved passwords\n");
    printf("\t3. Save passwords to file\n");
    printf("\t4. Exit program\n");
    printf("Enter a choice: ");
}

// Add a new password to the database
void add_password(password_database_t *database) {
    // Get the name and password from the user
    char name[MAX_PASSWORD_LENGTH];
    printf("Name: ");
    fgets(name, sizeof(name), stdin);
    char password[MAX_PASSWORD_LENGTH];
    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    
    // Allocate space for the new password
    database->num_passwords++;
    database->passwords = realloc(database->passwords, database->num_passwords * sizeof(password_t));
    
    // Set the name and password
    strncpy(database->passwords[database->num_passwords - 1].name, name, sizeof(name));
    strncpy(database->passwords[database->num_passwords - 1].password, password, sizeof(password));
    
    // Encrypt the password using the master password
    encrypt_password(database->passwords[database->num_passwords - 1].password, MASTER_PASSWORD);
    
    // Confirmation message
    printf("Password added successfully!\n");
}

// View saved passwords
void view_passwords(password_database_t database) {
    // Check if there are any passwords
    if (database.num_passwords == 0) {
        printf("No passwords saved.\n");
        return;
    }
    
    // Print out each password
    for (int i = 0; i < database.num_passwords; i++) {
        // Decrypt the password using the master password
        decrypt_password(database.passwords[i].password, MASTER_PASSWORD);
        printf("%s: %s\n", database.passwords[i].name, database.passwords[i].password);
        // Encrypt the password again
        encrypt_password(database.passwords[i].password, MASTER_PASSWORD);
    }
}

// Save passwords to file
void save_passwords(password_database_t database, char *filename) {
    // Open the file for writing
    FILE *fp;
    fp = fopen(filename, "w");
    
    // Write each password to the file
    for (int i = 0; i < database.num_passwords; i++) {
        encrypt_password(database.passwords[i].password, MASTER_PASSWORD);
        fprintf(fp, "%s;%s\n", database.passwords[i].name, database.passwords[i].password);
        decrypt_password(database.passwords[i].password, MASTER_PASSWORD);
    }
    
    // Close the file
    fclose(fp);
    
    // Confirmation message
    printf("Passwords saved to %s!\n", filename);
}

// Load passwords from file
void load_passwords(password_database_t *database, char *filename) {
    // Open the file for reading
    FILE *fp;
    fp = fopen(filename, "r");
    
    // Read each line of the file
    char line[MAX_PASSWORD_LENGTH * 2];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Split the line into name and password
        char *name = strtok(line, ";");
        char *password = strtok(NULL, ";");
        // Remove the newline from the password
        password[strcspn(password, "\n")] = 0;
        // Decrypt the password
        decrypt_password(password, MASTER_PASSWORD);
        // Allocate space for the new password
        database->num_passwords++;
        database->passwords = realloc(database->passwords, database->num_passwords * sizeof(password_t));
        // Set the name and password
        strncpy(database->passwords[database->num_passwords - 1].name, name, sizeof(name));
        strncpy(database->passwords[database->num_passwords - 1].password, password, sizeof(password));
        // Encrypt the password again
        encrypt_password(database->passwords[database->num_passwords - 1].password, MASTER_PASSWORD);
    }
    
    // Close the file
    fclose(fp);
}

// Encrypt a password using the master password
void encrypt_password(char *password, char *master_password) {
    int len = strlen(password);
    int key_len = strlen(master_password);
    for (int i = 0; i < len; i++) {
        password[i] = password[i] ^ master_password[i % key_len];
    }
}

// Decrypt a password using the master password
void decrypt_password(char *password, char *master_password) {
    int len = strlen(password);
    int key_len = strlen(master_password);
    for (int i = 0; i < len; i++) {
        password[i] = password[i] ^ master_password[i % key_len];
    }
}