//Falcon2-11B DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

typedef struct password_entry {
    char* password;
    char* username;
    int last_used;
} password_entry;

int main() {
    password_entry* passwords = malloc(sizeof(password_entry));

    printf("Enter number of passwords: ");
    int num_passwords;
    scanf("%d", &num_passwords);

    passwords = (password_entry*)malloc(num_passwords * sizeof(password_entry));

    for (int i = 0; i < num_passwords; i++) {
        printf("Username for password %d: ", i + 1);
        char username[MAX_PASSWORD_LENGTH];
        fgets(username, MAX_PASSWORD_LENGTH, stdin);
        username[strcspn(username, "\n")] = '\0';

        printf("Password for %s: ", username);
        char password[MAX_PASSWORD_LENGTH];
        fgets(password, MAX_PASSWORD_LENGTH, stdin);
        password[strcspn(password, "\n")] = '\0';

        passwords[i].username = strdup(username);
        passwords[i].password = strdup(password);
        passwords[i].last_used = -1;
    }

    printf("\n");
    printf("Password: ");
    fgets(passwords[0].password, MAX_PASSWORD_LENGTH, stdin);
    passwords[0].last_used = 0;

    for (int i = 1; i < num_passwords; i++) {
        printf("Password for %s: ", passwords[i - 1].username);
        fgets(passwords[i].password, MAX_PASSWORD_LENGTH, stdin);
        passwords[i].last_used = 0;
    }

    for (int i = 0; i < num_passwords; i++) {
        if (passwords[i].last_used!= -1) {
            printf("Password for %s was last used on %d\n", passwords[i].username, passwords[i].last_used);
        } else {
            printf("Password for %s has never been used\n", passwords[i].username);
        }
    }

    free(passwords);
    return 0;
}