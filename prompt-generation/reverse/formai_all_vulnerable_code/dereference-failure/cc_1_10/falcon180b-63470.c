//Falcon-180B DATASET v1.0 Category: Password management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 50

typedef struct {
    char* username;
    char* password;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);
    num_passwords++;
}

int find_password(char* username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char command[100];
    char* token;

    while (1) {
        printf("> ");
        fgets(command, 100, stdin);
        token = strtok(command, " ");

        if (strcmp(token, "add") == 0) {
            char* username = strtok(NULL, " ");
            char* password = strtok(NULL, " ");
            add_password(username, password);
        } else if (strcmp(token, "find") == 0) {
            char* username = strtok(NULL, " ");
            int index = find_password(username);
            if (index!= -1) {
                printf("Password for %s: %s\n", passwords[index].username, passwords[index].password);
            } else {
                printf("No password found for %s.\n", username);
            }
        } else if (strcmp(token, "print") == 0) {
            print_passwords();
        } else if (strcmp(token, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}