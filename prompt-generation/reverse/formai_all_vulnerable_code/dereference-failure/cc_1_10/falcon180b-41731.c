//Falcon-180B DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct password_t {
    char *username;
    char *password;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    num_passwords++;
    passwords[num_passwords - 1].username = strdup(username);
    passwords[num_passwords - 1].password = strdup(password);
}

void delete_password(int index) {
    if (index < 0 || index >= num_passwords) {
        printf("Error: Invalid password index.\n");
        return;
    }

    free(passwords[index].username);
    free(passwords[index].password);

    num_passwords--;
    for (int i = index; i < num_passwords; i++) {
        passwords[i] = passwords[i + 1];
    }
}

void list_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%d. %s: %s\n", i + 1, passwords[i].username, passwords[i].password);
    }
}

void main() {
    add_password("example.com", "password123");
    add_password("gmail.com", "myemail@gmail.com");
    list_passwords();
    delete_password(1);
    list_passwords();
}