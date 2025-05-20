//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The smoking-room where the passwords are kept
struct password {
    char *username;
    char *password;
};

// The list of passwords
struct password_list {
    struct password *passwords;
    int num_passwords;
};

// Initialize the password list
struct password_list *init_password_list() {
    struct password_list *list = malloc(sizeof(struct password_list));
    list->passwords = NULL;
    list->num_passwords = 0;
    return list;
}

// Add a password to the list
void add_password(struct password_list *list, char *username, char *password) {
    struct password *new_password = malloc(sizeof(struct password));
    new_password->username = strdup(username);
    new_password->password = strdup(password);
    list->passwords = realloc(list->passwords, (list->num_passwords + 1) * sizeof(struct password));
    list->passwords[list->num_passwords++] = *new_password;
}

// Find a password in the list
struct password *find_password(struct password_list *list, char *username) {
    for (int i = 0; i < list->num_passwords; i++) {
        if (strcmp(list->passwords[i].username, username) == 0) {
            return &list->passwords[i];
        }
    }
    return NULL;
}

// Print the password list
void print_password_list(struct password_list *list) {
    for (int i = 0; i < list->num_passwords; i++) {
        printf("%s: %s\n", list->passwords[i].username, list->passwords[i].password);
    }
}

// Free the password list
void free_password_list(struct password_list *list) {
    for (int i = 0; i < list->num_passwords; i++) {
        free(list->passwords[i].username);
        free(list->passwords[i].password);
    }
    free(list->passwords);
    free(list);
}

// The main function
int main() {
    // Initialize the password list
    struct password_list *list = init_password_list();

    // Add some passwords to the list
    add_password(list, "Sherlock Holmes", "elementary");
    add_password(list, "John Watson", "faithful");
    add_password(list, "Mycroft Holmes", "brother");

    // Find a password in the list
    struct password *password = find_password(list, "Sherlock Holmes");

    // Print the password
    printf("The password for Sherlock Holmes is: %s\n", password->password);

    // Free the password list
    free_password_list(list);

    return 0;
}