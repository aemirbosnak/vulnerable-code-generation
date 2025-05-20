//FormAI DATASET v1.0 Category: Password management ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_NUM_PASSWORDS    100

typedef struct {
    char *username;
    char *password;
} CredPair;

typedef struct {
    CredPair *credentials;
    int      numPairs;
} CredentialManager;

void initializeManager(CredentialManager *mgr) {
    mgr->credentials = (CredPair*)calloc(MAX_NUM_PASSWORDS, sizeof(CredPair));
    mgr->numPairs = 0;
}

void addCredential(CredentialManager *mgr, char *username, char *password) {
    if (mgr->numPairs < MAX_NUM_PASSWORDS) {
        CredPair newPair;
        newPair.username = (char*)malloc(sizeof(char)*strlen(username));
        newPair.password = (char*)malloc(sizeof(char)*MAX_PASSWORD_LENGTH);
        strcpy(newPair.username, username);
        strcpy(newPair.password, password);
        mgr->credentials[mgr->numPairs++] = newPair;
    }
}

char* findPasswordForUsername(CredentialManager *mgr, char *username) {
    for (int i = 0; i < mgr->numPairs; i++) {
        if (strcmp(username, mgr->credentials[i].username) == 0) {
            return mgr->credentials[i].password;
        }
    }
    return NULL;
}

int main() {
    CredentialManager mgr;
    initializeManager(&mgr);
    addCredential(&mgr, "user1", "abcdef");
    addCredential(&mgr, "user2", "ghijkl");
    addCredential(&mgr, "user3", "mnopqr");
    
    char username[20];
    printf("Enter username: ");
    scanf("%s", username);
    
    char *password = findPasswordForUsername(&mgr, username);
    if (password) {
        printf("Password for %s: %s\n", username, password);
    } else {
        printf("No password found for %s\n", username);
    }
    
    return 0;
}