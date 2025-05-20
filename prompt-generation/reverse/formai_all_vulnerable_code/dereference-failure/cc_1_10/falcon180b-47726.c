//Falcon-180B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100
#define MAX_USER_LENGTH 50

struct Password {
    char *website;
    char *username;
    char *password;
};

struct User {
    char *name;
    char *email;
    struct Password passwords[MAX_PASSWORDS];
    int num_passwords;
};

void add_password(struct User *user) {
    printf("Enter website: ");
    char website[MAX_PASSWORD_LENGTH];
    scanf("%s", website);

    printf("Enter username: ");
    char username[MAX_PASSWORD_LENGTH];
    scanf("%s", username);

    printf("Enter password: ");
    char password[MAX_PASSWORD_LENGTH];
    scanf("%s", password);

    strncpy(user->passwords[user->num_passwords].website, website, MAX_PASSWORD_LENGTH);
    strncpy(user->passwords[user->num_passwords].username, username, MAX_PASSWORD_LENGTH);
    strncpy(user->passwords[user->num_passwords].password, password, MAX_PASSWORD_LENGTH);

    user->num_passwords++;
}

void view_passwords(struct User *user) {
    printf("Passwords for %s:\n", user->name);

    for (int i = 0; i < user->num_passwords; i++) {
        printf("Website: %s\n", user->passwords[i].website);
        printf("Username: %s\n", user->passwords[i].username);
        printf("Password: %s\n", user->passwords[i].password);
        printf("\n");
    }
}

void main() {
    struct User user;

    printf("Enter your name: ");
    scanf("%s", user.name);

    printf("Enter your email: ");
    scanf("%s", user.email);

    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_password(&user);
            break;
        case 2:
            view_passwords(&user);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);
}