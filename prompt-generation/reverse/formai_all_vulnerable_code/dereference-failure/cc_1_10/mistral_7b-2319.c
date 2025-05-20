//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <shadow.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 50

typedef struct {
    char username[PASSWORD_LENGTH];
    char password[PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int count = 0;

void create_password(char* username, char* password) {
    if (count >= MAX_PASSWORDS) {
        printf("Vault is full!\n");
        return;
    }

    strcpy(passwords[count].username, username);
    strcpy(passwords[count].password, password);
    count++;
}

void list_passwords() {
    if (count == 0) {
        printf("No passwords found in Vault of the Last Men.\n");
        return;
    }

    printf("\nListing passwords in Vault of the Last Men:\n");
    for (int i = 0; i < count; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <command> <username> <password>\n", argv[0]);
        return 1;
    }

    char* command = argv[1];

    if (strcmp(command, "create") == 0) {
        create_password(argv[2], argv[3]);
        printf("Password created for %s.\n", argv[2]);
    } else if (strcmp(command, "list") == 0) {
        list_passwords();
    } else {
        printf("Invalid command: %s\n", command);
    }

    return 0;
}