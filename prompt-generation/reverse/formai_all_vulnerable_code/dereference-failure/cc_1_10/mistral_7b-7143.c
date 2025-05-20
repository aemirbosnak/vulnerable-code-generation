//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <shadow.h>
#include <pwd.h>

#define TABLE_SIZE 101
#define HASH_FUNCTION(x) (abs((int) x) % TABLE_SIZE)

typedef struct Password {
    char username[21];
    char password[21];
    int hash;
} Password;

Password table[TABLE_SIZE];

void hash_password(const char *password, Password *pw) {
    int hash = 5381;

    for (int i = 0; password[i] != '\0'; ++i) {
        hash += (hash << 5) + hash + (unsigned char) password[i];
    }

    pw->hash = hash;
}

int search(const char *username, Password *pw) {
    int index = HASH_FUNCTION(strlen(username));
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (strcmp(pw[index].username, username) == 0) {
            strcpy(pw->username, pw[index].username);
            strcpy(pw->password, pw[index].password);
            pw->hash = pw[index].hash;
            return 1;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return 0;
}

int add_password(const char *username, const char *password) {
    Password new_pw;

    if (search(username, &new_pw) != 0) {
        printf("Error: User already exists.\n");
        return -1;
    }

    hash_password(password, &new_pw);

    int index = HASH_FUNCTION(strlen(username));
    new_pw.username[20] = '\0';
    strcpy(new_pw.username, username);
    strcpy(new_pw.password, password);

    table[index] = new_pw;
    printf("Password added successfully.\n");
    return 1;
}

int delete_password(const char *username) {
    Password to_delete;
    int index = HASH_FUNCTION(strlen(username));

    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (strcmp(table[index].username, username) == 0) {
            strcpy(&table[index].username[0], "");
            strcpy(&table[index].password[0], "");
            table[index].hash = 0;
            printf("Password deleted successfully.\n");
            return 1;
        }
        index = (index + 1) % TABLE_SIZE;
    }

    printf("Error: User not found.\n");
    return -1;
}

void display_password(const char *username) {
    Password pw;

    if (search(username, &pw) != 0) {
        printf("Username: %s\nPassword: %s\n", pw.username, pw.password);
    } else {
        printf("Error: User not found.\n");
    }
}

int main(int argc, char **argv) {
    char command[50];
    char username[21];
    char password[21];

    if (argc < 2) {
        printf("Usage: %s [add|delete|display|exit] <username> [password]\n", argv[0]);
        return -1;
    }

    strcpy(command, argv[1]);

    if (strcmp(command, "add") == 0 && argc > 3) {
        strcpy(username, argv[2]);
        strcpy(password, argv[3]);
        add_password(username, password);
    } else if (strcmp(command, "delete") == 0 && argc > 2) {
        strcpy(username, argv[2]);
        delete_password(username);
    } else if (strcmp(command, "display") == 0 && argc > 2) {
        strcpy(username, argv[2]);
        display_password(username);
    } else if (strcmp(command, "exit") == 0) {
        printf("Exiting GracefulPasswordManager...\n");
        return 0;
    } else {
        printf("Invalid command. Use [add|delete|display|exit] for operations.\n");
    }

    return 0;
}