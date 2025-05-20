//Falcon-180B DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 16

typedef struct {
    char *username;
    char *password;
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(char *password) {
    int i;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = rand() % 62 + 'a';
    }
    password[PASSWORD_LENGTH] = '\0';
}

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached.\n");
        return;
    }
    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);
    passwords[num_passwords].length = strlen(password);
    num_passwords++;
}

int find_password(char *username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void print_passwords() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    srand(time(NULL));
    add_password("example@example.com", "password123");
    add_password("test@test.com", "testpassword");
    print_passwords();
    return 0;
}