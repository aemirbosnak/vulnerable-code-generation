//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 50
#define SALT_LENGTH 10

struct Password {
    char username[PASSWORD_LENGTH];
    char password[PASSWORD_LENGTH];
    char salt[SALT_LENGTH];
};

void generate_salt(char *salt) {
    int i;
    for (i = 0; i < SALT_LENGTH; i++) {
        salt[i] = rand() % 26 + 'a';
    }
    salt[SALT_LENGTH] = '\0';
}

void hash_password(char *password, char *salt, char *hashed_password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        hashed_password[i] = password[i] + salt[i % SALT_LENGTH];
    }
    hashed_password[strlen(password)] = '\0';
}

int check_password(char *username, char *stored_password, char *salt) {
    char hashed_password[PASSWORD_LENGTH];
    hash_password(stored_password, salt, hashed_password);

    int i;
    for (i = 0; i < strlen(stored_password); i++) {
        if (toupper(stored_password[i]) != toupper(hashed_password[i])) {
            return 0;
        }
    }

    return 1;
}

void add_password(struct Password passwords[] , int *count, char *username, char *password) {
    if (*count >= MAX_PASSWORDS) {
        printf("Password manager is full.\n");
        return;
    }

    generate_salt(passwords[*count].salt);
    strcpy(passwords[*count].username, username);
    hash_password(password, passwords[*count].salt, passwords[*count].password);
    (*count)++;
}

void list_passwords(struct Password passwords[], int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("%d: %s - %s\n", i + 1, passwords[i].username, passwords[i].password);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <add|list> <username> <password>\n", argv[0]);
        return 1;
    }

    struct Password passwords[MAX_PASSWORDS];
    int count = 0;

    if (strcmp(argv[1], "add") == 0) {
        add_password(passwords, &count, argv[2], argv[3]);
    } else if (strcmp(argv[1], "list") == 0) {
        list_passwords(passwords, count);
    } else {
        printf("Invalid command. Use 'add' or 'list'\n");
        return 1;
    }

    return 0;
}