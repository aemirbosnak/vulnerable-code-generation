//GEMINI-pro DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct _passwordEntry {
    char *username;
    char *password;
} passwordEntry;

//GLOBAL VARIABLES
int numEntries = 0;
passwordEntry *entries = NULL;

void addEntry(char *username, char *password) {
    entries = (passwordEntry*)realloc(entries, sizeof(passwordEntry) * (numEntries + 1));
    entries[numEntries].username = strdup(username);
    entries[numEntries].password = strdup(password);
    numEntries++;
}

void printEntries() {
    for (int i = 0; i < numEntries; i++) {
        printf("username: %s\npassword: %s\n", entries[i].username, entries[i].password);
    }
}

int findEntry(char *username) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

char *hashPassword(char *password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);
    char *hashedPassword = (char *)malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hashedPassword + 2 * i, "%02x", hash[i]);
    }

    return hashedPassword;
}

int main() {
    addEntry("admin", hashPassword("password"));
    addEntry("user1", hashPassword("password1"));
    addEntry("user2", hashPassword("password2"));

    char username[256];
    char password[256];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    int entryIndex = findEntry(username);

    if (entryIndex == -1) {
        printf("Invalid username\n");
    } else {
        if (strcmp(hashPassword(password), entries[entryIndex].password) == 0) {
            printf("Login successful\n");
        } else {
            printf("Invalid password\n");
        }
    }

    return 0;
}