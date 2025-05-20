//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/rand.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the maximum length of a subscriber's email address
#define MAX_EMAIL_LENGTH 256

// Define the maximum length of a subscriber's password
#define MAX_PASSWORD_LENGTH 64

// Define the structure of a subscriber
typedef struct {
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char salt[16];
} subscriber;

// Define the structure of the mailing list
typedef struct {
    subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list;

// Create a new mailing list
mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->num_subscribers = 0;
    return list;
}

// Add a new subscriber to the mailing list
void add_subscriber(mailing_list *list, char *email, char *password) {
    // Check if the mailing list is full
    if (list->num_subscribers == MAX_SUBSCRIBERS) {
        printf("Error: The mailing list is full.\n");
        return;
    }

    // Check if the email address is already in use
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Error: The email address is already in use.\n");
            return;
        }
    }

    // Generate a random salt
    RAND_bytes(list->subscribers[list->num_subscribers].salt, 16);

    // Hash the password with the salt
    SHA256(password, strlen(password), list->subscribers[list->num_subscribers].password);

    // Copy the email address to the subscriber's struct
    strcpy(list->subscribers[list->num_subscribers].email, email);

    // Increment the number of subscribers
    list->num_subscribers++;
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list *list, char *email) {
    // Find the subscriber's index
    int index = -1;
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            index = i;
            break;
        }
    }

    // Check if the subscriber was found
    if (index == -1) {
        printf("Error: The subscriber was not found.\n");
        return;
    }

    // Remove the subscriber from the list
    for (int i = index; i < list->num_subscribers - 1; i++) {
        list->subscribers[i] = list->subscribers[i + 1];
    }

    // Decrement the number of subscribers
    list->num_subscribers--;
}

// Print the mailing list
void print_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("%s\n", list->subscribers[i].email);
    }
}

// Get the index of a subscriber by their email address
int get_subscriber_index(mailing_list *list, char *email) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            return i;
        }
    }

    return -1;
}

// Authenticate a subscriber
int authenticate_subscriber(mailing_list *list, char *email, char *password) {
    // Get the subscriber's index
    int index = get_subscriber_index(list, email);

    // Check if the subscriber was found
    if (index == -1) {
        return 0;
    }

    // Hash the password with the salt
    SHA256(password, strlen(password), list->subscribers[index].password);

    // Compare the hashed password to the stored password
    return memcmp(list->subscribers[index].password, password, SHA256_DIGEST_LENGTH) == 0;
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "alice@example.com", "password1");
    add_subscriber(list, "bob@example.com", "password2");
    add_subscriber(list, "charlie@example.com", "password3");

    // Print the mailing list
    print_mailing_list(list);

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "bob@example.com");

    // Print the mailing list
    print_mailing_list(list);

    // Authenticate a subscriber
    int authenticated = authenticate_subscriber(list, "alice@example.com", "password1");

    // Print the authentication result
    if (authenticated) {
        printf("Authentication successful.\n");
    } else {
        printf("Authentication failed.\n");
    }

    // Free the mailing list
    free(list);

    return 0;
}