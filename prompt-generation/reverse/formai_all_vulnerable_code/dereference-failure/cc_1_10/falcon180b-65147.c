//Falcon-180B DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERS];
    char password[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int num_passwords;
} User;

void create_user(User* user) {
    printf("Enter username: ");
    scanf("%s", user->username);
    user->num_passwords = 0;
}

void add_password(User* user) {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(user->password[user->num_passwords], password);
    user->num_passwords++;
}

int main() {
    User user;
    int choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Create User\n");
        printf("2. Add Password\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_user(&user);
                printf("\nUser created successfully.\n");
                break;
            case 2:
                if(user.num_passwords >= MAX_PASSWORDS) {
                    printf("\nMaximum number of passwords reached.\n");
                } else {
                    add_password(&user);
                    printf("\nPassword added successfully.\n");
                }
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    } while(choice!= 3);

    return 0;
}