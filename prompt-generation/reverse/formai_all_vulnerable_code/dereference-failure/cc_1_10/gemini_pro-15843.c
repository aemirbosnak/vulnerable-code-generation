//GEMINI-pro DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *username;
    char *password;
} Credentials;

typedef struct {
    char *name;
    int num_credentials;
    Credentials *credentials;
} Account;

typedef struct {
    int num_accounts;
    Account *accounts;
} Database;

Database *database;

bool add_account(char *name) {
    database->accounts = realloc(database->accounts, (database->num_accounts + 1) * sizeof(Account));
    database->accounts[database->num_accounts].name = strdup(name);
    database->accounts[database->num_accounts].num_credentials = 0;
    database->accounts[database->num_accounts].credentials = NULL;
    database->num_accounts++;
    return true;
}

bool add_credential(char *username, char *password) {
    for (int i = 0; i < database->num_accounts; i++) {
        if (!strcmp(database->accounts[i].name, "me")) {
            database->accounts[i].credentials = realloc(database->accounts[i].credentials, (database->accounts[i].num_credentials + 1) * sizeof(Credentials));
            database->accounts[i].credentials[database->accounts[i].num_credentials].username = strdup(username);
            database->accounts[i].credentials[database->accounts[i].num_credentials].password = strdup(password);
            database->accounts[i].num_credentials++;
            return true;
        }
    }
    return false;
}

char *get_password(char *username) {
    for (int i = 0; i < database->num_accounts; i++) {
        for (int j = 0; j < database->accounts[i].num_credentials; j++) {
            if (!strcmp(database->accounts[i].credentials[j].username, username)) {
                return database->accounts[i].credentials[j].password;
            }
        }
    }
    return NULL;
}

int main() {
    database = malloc(sizeof(Database));
    database->num_accounts = 0;
    database->accounts = NULL;

    add_account("me");
    add_credential("username1", "password1");
    add_credential("username2", "password2");

    char *password = get_password("username1");
    printf("Password: %s\n", password);

    return 0;
}