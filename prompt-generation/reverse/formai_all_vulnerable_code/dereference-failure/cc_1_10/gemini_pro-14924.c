//GEMINI-pro DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct password {
    char *name;
    char *password;
} password;

typedef struct password_list {
    password *passwords;
    int num_passwords;
} password_list;

// Create a new password list
password_list *new_password_list() {
    password_list *list = malloc(sizeof(password_list));
    list->passwords = NULL;
    list->num_passwords = 0;
    return list;
}

// Add a new password to the list
void add_password(password_list *list, char *name, char *password) {
    list->passwords = realloc(list->passwords, (list->num_passwords + 1) * sizeof(password));
    list->passwords[list->num_passwords].name = strdup(name);
    list->passwords[list->num_passwords].password = strdup(password);
    list->num_passwords++;
}

// Find a password by name
password *find_password(password_list *list, char *name) {
    for (int i = 0; i < list->num_passwords; i++) {
        if (strcmp(list->passwords[i].name, name) == 0) {
            return &list->passwords[i];
        }
    }
    return NULL;
}

// Delete a password by name
void delete_password(password_list *list, char *name) {
    for (int i = 0; i < list->num_passwords; i++) {
        if (strcmp(list->passwords[i].name, name) == 0) {
            free(list->passwords[i].name);
            free(list->passwords[i].password);
            list->passwords[i] = list->passwords[list->num_passwords - 1];
            list->num_passwords--;
            return;
        }
    }
}

// Print the password list
void print_password_list(password_list *list) {
    for (int i = 0; i < list->num_passwords; i++) {
        printf("%s: %s\n", list->passwords[i].name, list->passwords[i].password);
    }
}

// Free the password list
void free_password_list(password_list *list) {
    for (int i = 0; i < list->num_passwords; i++) {
        free(list->passwords[i].name);
        free(list->passwords[i].password);
    }
    free(list->passwords);
    free(list);
}

int main() {
    // Create a new password list
    password_list *list = new_password_list();

    // Add some passwords to the list
    add_password(list, "Google", "mygooglepassword");
    add_password(list, "Facebook", "myfacebookpassword");
    add_password(list, "Amazon", "myamazonpassword");

    // Find a password by name
    password *password = find_password(list, "Google");
    if (password != NULL) {
        printf("The password for Google is: %s\n", password->password);
    } else {
        printf("Password not found.\n");
    }

    // Delete a password by name
    delete_password(list, "Facebook");

    // Print the password list
    print_password_list(list);

    // Free the password list
    free_password_list(list);

    return 0;
}