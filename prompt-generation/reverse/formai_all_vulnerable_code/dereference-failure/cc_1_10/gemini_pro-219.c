//GEMINI-pro DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *password;
} Password;

Password *passwords = NULL;
int num_passwords = 0;

void add_password(char *name, char *password) {
    passwords = realloc(passwords, (num_passwords + 1) * sizeof(Password));
    passwords[num_passwords].name = strdup(name);
    passwords[num_passwords].password = strdup(password);
    num_passwords++;
}

void remove_password(char *name) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            free(passwords[i].name);
            free(passwords[i].password);
            passwords[i] = passwords[num_passwords - 1];
            num_passwords--;
            break;
        }
    }
}

char *get_password(char *name) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            return passwords[i].password;
        }
    }
    return NULL;
}

void print_passwords() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    add_password("facebook", "myfacebookpassword");
    add_password("google", "mygooglepassword");
    add_password("amazon", "myamazonpassword");

    printf("Passwords:\n");
    print_passwords();

    printf("Getting password for 'google': %s\n", get_password("google"));

    remove_password("facebook");

    printf("Passwords after removing 'facebook':\n");
    print_passwords();

    return 0;
}