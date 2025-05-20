//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store password information
struct password {
    char *name;
    char *password;
    struct password *next;
};

// Function to create a new password
struct password *new_password(char *name, char *password) {
    struct password *ptr = (struct password *)malloc(sizeof(struct password));
    ptr->name = name;
    ptr->password = password;
    ptr->next = NULL;
    return ptr;
}

// Function to display the passwords
void display_passwords(struct password *ptr) {
    if (ptr != NULL) {
        printf("%s: %s\n", ptr->name, ptr->password);
        display_passwords(ptr->next);
    }
}

// Function to search for a password
struct password *search_password(struct password *ptr, char *name) {
    if (ptr == NULL) {
        return NULL;
    }
    if (strcmp(ptr->name, name) == 0) {
        return ptr;
    }
    return search_password(ptr->next, name);
}

// Function to update a password
struct password *update_password(struct password *ptr, char *new_password) {
    if (ptr == NULL) {
        return NULL;
    }
    ptr->password = new_password;
    return ptr;
}

// Function to add a password
struct password *add_password(struct password *ptr, char *name, char *password) {
    struct password *new_ptr = new_password(name, password);
    if (ptr == NULL) {
        return new_ptr;
    }
    new_ptr->next = ptr;
    return ptr;
}

// Main function
int main() {
    struct password *root = NULL;

    // Create some passwords
    root = add_password(root, "John", "Doe123");
    root = add_password(root, "Jane", "Doe456");
    root = add_password(root, "Bob", "Smith789");

    // Display the passwords
    display_passwords(root);

    // Search for a password
    struct password *john = search_password(root, "John");
    if (john != NULL) {
        printf("Found John's password: %s\n", john->password);
    }

    // Update a password
    update_password(john, "NewJohnPassword!");

    // Display the passwords again
    display_passwords(root);

    return 0;
}