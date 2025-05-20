//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_MAX_LENGTH 20
#define MAX_PASSWORDS 10

typedef struct {
    char *password;
    int frequency;
} password_t;

password_t passwords[MAX_PASSWORDS];
int password_count = 0;

void add_password(const char *new_password) {
    password_t *new_password_struct = (password_t *)malloc(sizeof(password_t));
    new_password_struct->password = (char *)malloc(strlen(new_password) + 1);
    strcpy(new_password_struct->password, new_password);
    new_password_struct->frequency = 1;
    passwords[password_count] = *new_password_struct;
    password_count++;
}

void check_password(const char *password) {
    for (int i = 0; i < password_count; i++) {
        if (strcmp(password, passwords[i].password) == 0) {
            passwords[i].frequency++;
            return;
        }
    }
    printf("Incorrect password. Try again!\n");
}

void print_passwords() {
    for (int i = 0; i < password_count; i++) {
        printf("%d. %s (%d frequency)\n", i + 1, passwords[i].password, passwords[i].frequency);
    }
}

int main() {
    srand(time(NULL));

    // Add some test passwords
    add_password("password1");
    add_password("password2");
    add_password("password3");

    // Check some test passwords
    check_password("password1");
    check_password("password3");

    // Print all passwords and their frequencies
    print_passwords();

    return 0;
}