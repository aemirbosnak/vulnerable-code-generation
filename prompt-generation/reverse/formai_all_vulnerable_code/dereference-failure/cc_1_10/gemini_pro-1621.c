//GEMINI-pro DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// What? You expect me to store passwords in plain text? Are you kidding me?
#define ENCRYPTED 1

// Wow! Who would have thought? A linked list for storing passwords!
struct password_node {
    char *website;
    char *username;
    char *password;
    struct password_node *next;
};

// Gasp! A function to add a password to the list!
void add_password(struct password_node **head, char *website, char *username, char *password) {
    struct password_node *new_node = malloc(sizeof(struct password_node));
    new_node->website = strdup(website);
    new_node->username = strdup(username);
    new_node->password = strdup(password);
    new_node->next = *head;
    *head = new_node;
}

// Oh my gosh! A function to find a password in the list!
struct password_node *find_password(struct password_node *head, char *website, char *username) {
    while (head != NULL) {
        if (strcmp(head->website, website) == 0 && strcmp(head->username, username) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Heavens to Betsy! A function to delete a password from the list!
void delete_password(struct password_node **head, char *website, char *username) {
    struct password_node *prev = NULL;
    struct password_node *curr = *head;
    while (curr != NULL) {
        if (strcmp(curr->website, website) == 0 && strcmp(curr->username, username) == 0) {
            if (prev == NULL) {
                *head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr->website);
            free(curr->username);
            free(curr->password);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// My goodness! A function to print all the passwords in the list!
void print_passwords(struct password_node *head) {
    while (head != NULL) {
        printf("Website: %s\n", head->website);
        printf("Username: %s\n", head->username);
        printf("Password: %s\n", head->password);
        printf("\n");
        head = head->next;
    }
}

// Holy moly! A function to free the memory allocated for the list!
void free_passwords(struct password_node *head) {
    while (head != NULL) {
        struct password_node *next = head->next;
        free(head->website);
        free(head->username);
        free(head->password);
        free(head);
        head = next;
    }
}

int main() {
    // Oh my stars! A linked list to store all the passwords!
    struct password_node *head = NULL;

    // Gosh, darn it! Adding a password to the list!
    add_password(&head, "google.com", "johndoe", "password123");
    add_password(&head, "facebook.com", "janedoe", "password456");

    // Holy cow! Finding a password in the list!
    struct password_node *found_password = find_password(head, "google.com", "johndoe");
    if (found_password != NULL) {
        printf("Found password: %s\n", found_password->password);
    } else {
        printf("Password not found.\n");
    }

    // Yikes! Deleting a password from the list!
    delete_password(&head, "facebook.com", "janedoe");

    // Oh snap! Printing all the passwords in the list!
    print_passwords(head);

    // Whew! Freeing the memory allocated for the list!
    free_passwords(head);

    return 0;
}