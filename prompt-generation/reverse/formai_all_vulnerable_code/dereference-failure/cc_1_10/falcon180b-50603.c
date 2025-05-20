//Falcon-180B DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char *username;
    char *password;
    int length;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: too many passwords\n");
        return;
    }
    int length = strlen(password);
    if (length > MAX_PASSWORD_LENGTH) {
        printf("Error: password too long\n");
        return;
    }
    passwords[num_passwords] = (password_t) {
       .username = strdup(username),
       .password = strdup(password),
       .length = length
    };
    num_passwords++;
}

int compare_passwords(const void *a, const void *b) {
    password_t *p1 = (password_t *) a;
    password_t *p2 = (password_t *) b;
    return strcmp(p1->username, p2->username);
}

void print_passwords() {
    qsort(passwords, num_passwords, sizeof(password_t), compare_passwords);
    for (int i = 0; i < num_passwords; i++) {
        printf("%s (%d characters)\n", passwords[i].username, passwords[i].length);
    }
}

void delete_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);
            memmove(&passwords[i], &passwords[i + 1], (num_passwords - i - 1) * sizeof(password_t));
            num_passwords--;
            return;
        }
    }
    printf("Error: password not found\n");
}

int main() {
    add_password("example.com", "password123");
    add_password("google.com", "hunter2");
    print_passwords();
    delete_password("example.com");
    print_passwords();
    return 0;
}