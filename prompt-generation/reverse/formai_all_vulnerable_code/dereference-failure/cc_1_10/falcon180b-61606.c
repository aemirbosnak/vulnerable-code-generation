//Falcon-180B DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char* username;
    char* password;
    int length;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    int length = strlen(password);
    if (length > MAX_PASSWORD_LENGTH) {
        printf("Error: Password is too long.\n");
        return;
    }

    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);
    passwords[num_passwords].length = length;

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
    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s (%d characters)\n", passwords[i].username, passwords[i].length);
    }
}

int main() {
    add_password("example@example.com", "password123");
    add_password("test@example.com", "qwertyuiop");

    int index = find_password("example@example.com");
    if (index!= -1) {
        printf("Password for %s: ", passwords[index].username);
        for (int i = 0; i < passwords[index].length; i++) {
            printf("*");
        }
        printf("\n");
    }

    print_passwords();

    return 0;
}