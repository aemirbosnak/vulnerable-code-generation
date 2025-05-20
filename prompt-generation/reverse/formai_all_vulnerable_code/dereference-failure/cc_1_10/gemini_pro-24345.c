//GEMINI-pro DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure to store user credentials
typedef struct Credential {
    char *username;
    char *password;
} Credential;

// Structure to store all user credentials
typedef struct CredentialStore {
    int size;
    int capacity;
    Credential *credentials;
} CredentialStore;

// Function to create a new credential store
CredentialStore *createCredentialStore() {
    CredentialStore *store = (CredentialStore *)malloc(sizeof(CredentialStore));
    store->size = 0;
    store->capacity = 10;
    store->credentials = (Credential *)malloc(sizeof(Credential) * store->capacity);
    return store;
}

// Function to add a new credential to the store
void addCredential(CredentialStore *store, Credential credential) {
    if (store->size == store->capacity) {
        store->capacity *= 2;
        store->credentials = (Credential *)realloc(store->credentials, sizeof(Credential) * store->capacity);
    }
    store->credentials[store->size++] = credential;
}

// Function to find a credential by username
Credential *findCredential(CredentialStore *store, char *username) {
    for (int i = 0; i < store->size; i++) {
        if (strcmp(store->credentials[i].username, username) == 0) {
            return &store->credentials[i];
        }
    }
    return NULL;
}

// Function to print all credentials
void printCredentials(CredentialStore *store) {
    for (int i = 0; i < store->size; i++) {
        printf("%s: %s\n", store->credentials[i].username, store->credentials[i].password);
    }
}

// Function to free the memory allocated for the credential store
void freeCredentialStore(CredentialStore *store) {
    for (int i = 0; i < store->size; i++) {
        free(store->credentials[i].username);
        free(store->credentials[i].password);
    }
    free(store->credentials);
    free(store);
}

// Main function
int main() {
    // Create a new credential store
    CredentialStore *store = createCredentialStore();

    // Add some credentials to the store
    addCredential(store, (Credential) {"user1", "password1"});
    addCredential(store, (Credential) {"user2", "password2"});
    addCredential(store, (Credential) {"user3", "password3"});

    // Find a credential by username
    Credential *credential = findCredential(store, "user2");
    if (credential != NULL) {
        printf("Found credential for user %s: %s\n", credential->username, credential->password);
    } else {
        printf("Credential not found for user user2\n");
    }

    // Print all credentials
    printCredentials(store);

    // Free the memory allocated for the credential store
    freeCredentialStore(store);

    return 0;
}