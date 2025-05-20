//Gemma-7B DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 256

typedef struct Password {
    char *name;
    char *password;
    time_t timestamp;
} Password;

Password passwords[MAX_PASSWORDS];

void generate_passwords() {
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = malloc(MAX_PASSWORD_LENGTH);
        passwords[i].password = malloc(MAX_PASSWORD_LENGTH);

        passwords[i].name[0] = '\0';
        passwords[i].password[0] = '\0';

        passwords[i].timestamp = time(NULL);
    }
}

void add_password(char *name, char *password) {
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        if (passwords[i].name[0] == '\0') {
            strcpy(passwords[i].name, name);
            strcpy(passwords[i].password, password);

            return;
        }
    }

    printf("Error: Too many passwords.\n");
}

void list_passwords() {
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        if (passwords[i].name[0] != '\0') {
            printf("Name: %s, Password: %s, Timestamp: %ld\n", passwords[i].name, passwords[i].password, passwords[i].timestamp);
        }
    }
}

int main() {
    generate_passwords();

    add_password("John Doe", "Secret123!");
    add_password("Jane Doe", "StrongPassword!");
    list_passwords();

    return 0;
}