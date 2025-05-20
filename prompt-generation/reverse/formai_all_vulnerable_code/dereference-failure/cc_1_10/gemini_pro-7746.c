//GEMINI-pro DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a password
typedef struct {
    char *name;
    char *password;
} Password;

// Function to create a new password
Password *create_password(char *name, char *password) {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = strdup(name);
    new_password->password = strdup(password);
    return new_password;
}

// Function to save a password to a file
void save_password(Password *password, FILE *file) {
    fprintf(file, "%s,%s\n", password->name, password->password);
}

// Function to load a password from a file
Password *load_password(char *name, FILE *file) {
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *name_loaded = strtok(line, ",");
        char *password_loaded = strtok(NULL, ",");
        if (strcmp(name, name_loaded) == 0) {
            return create_password(name, password_loaded);
        }
    }
    return NULL;
}

// Function to delete a password from a file
void delete_password(char *name, FILE *file) {
    FILE *new_file = fopen("passwords.txt", "w");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *name_loaded = strtok(line, ",");
        if (strcmp(name, name_loaded) != 0) {
            fprintf(new_file, "%s", line);
        }
    }
    fclose(new_file);
    fclose(file);
    remove("passwords.txt");
    rename("passwords.txt", "passwords.txt");
}

// Function to print all passwords
void print_passwords(FILE *file) {
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *name_loaded = strtok(line, ",");
        char *password_loaded = strtok(NULL, ",");
        printf("%s: %s\n", name_loaded, password_loaded);
    }
}

// Main function
int main() {
    // Create a new password
    Password *password = create_password("Google", "123456");

    // Save the password to a file
    FILE *file = fopen("passwords.txt", "a");
    save_password(password, file);
    fclose(file);

    // Load the password from the file
    file = fopen("passwords.txt", "r");
    Password *loaded_password = load_password("Google", file);
    fclose(file);

    // Print the loaded password
    printf("Loaded password: %s\n", loaded_password->password);

    // Delete the password from the file
    delete_password("Google", file);

    // Print all passwords
    file = fopen("passwords.txt", "r");
    print_passwords(file);
    fclose(file);

    // Free the allocated memory
    free(password->name);
    free(password->password);
    free(password);
    free(loaded_password->name);
    free(loaded_password->password);
    free(loaded_password);

    return 0;
}