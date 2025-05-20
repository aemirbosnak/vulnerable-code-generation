//Falcon-180B DATASET v1.0 Category: Password management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 100

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached.\n");
        return;
    }
    num_passwords++;
    passwords[num_passwords - 1].username = strdup(username);
    passwords[num_passwords - 1].password = strdup(password);
}

int search_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void delete_password(int index) {
    if (index < 0 || index >= num_passwords) {
        printf("Error: invalid password index.\n");
        return;
    }
    free(passwords[index].username);
    free(passwords[index].password);
    for (int i = index; i < num_passwords - 1; i++) {
        passwords[i] = passwords[i + 1];
    }
    num_passwords--;
}

void list_passwords() {
    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char *username = "example";
    char *password = "password";
    add_password(username, password);
    list_passwords();
    int index = search_password(username);
    if (index >= 0) {
        printf("Password found at index %d.\n", index);
    } else {
        printf("Password not found.\n");
    }
    delete_password(index);
    list_passwords();
    return 0;
}