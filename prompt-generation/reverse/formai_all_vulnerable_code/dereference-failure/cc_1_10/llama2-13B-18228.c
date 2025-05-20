//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 20
#define MAX_PASSWORDS 10

typedef struct {
    char *password;
    int frequency;
} password_t;

password_t passwords[MAX_PASSWORDS];
int current_password = 0;

void init_passwords() {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].password = (char *)malloc(PASSWORD_LENGTH * sizeof(char));
        passwords[i].frequency = 0;
    }
}

void add_password(const char *password) {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(password, passwords[i].password) == 0) {
            passwords[i].frequency++;
            break;
        }
    }
    if (i == MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached\n");
        return;
    }
}

void check_password(const char *password) {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(password, passwords[i].password) == 0) {
            printf("Password found! Frequency: %d\n", passwords[i].frequency);
            return;
        }
    }
    printf("Password not found\n");
}

void random_password() {
    char password[PASSWORD_LENGTH];
    int i;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = 'a' + (rand() % 26);
    }
    add_password(password);
}

int main() {
    srand(time(NULL));
    init_passwords();

    while (1) {
        printf("Enter a password: ");
        char password[PASSWORD_LENGTH];
        fgets(password, PASSWORD_LENGTH, stdin);
        add_password(password);

        check_password(password);

        if (current_password == MAX_PASSWORDS) {
            printf("Maximum number of passwords reached\n");
            break;
        }

        random_password();
    }

    return 0;
}