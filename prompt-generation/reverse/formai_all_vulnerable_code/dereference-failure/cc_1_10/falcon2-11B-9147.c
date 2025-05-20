//Falcon2-11B DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_USERS 100
#define MAX_PWDS 50
#define MAX_PWD_LEN 10
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char pwd[MAX_PWD_LEN];
} User;

User users[MAX_USERS];
int num_users = 0;

void add_user(char *name, char *pwd) {
    if (num_users == MAX_USERS) {
        fprintf(stderr, "Too many users, maximum is %d\n", MAX_USERS);
        return;
    }
    strcpy(users[num_users].name, name);
    strcpy(users[num_users].pwd, pwd);
    num_users++;
}

void display_users() {
    printf("Users:\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s: %s\n", users[i].name, users[i].pwd);
    }
}

void delete_user(char *name) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            for (int j = i; j < num_users - 1; j++) {
                strcpy(users[j].name, users[j + 1].name);
                strcpy(users[j].pwd, users[j + 1].pwd);
            }
            num_users--;
            break;
        }
    }
}

void set_password(char *name, char *old_pwd, char *new_pwd) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            if (strcmp(users[i].pwd, old_pwd) == 0) {
                strcpy(users[i].pwd, new_pwd);
                break;
            } else {
                fprintf(stderr, "Invalid old password\n");
                return;
            }
        } else {
            fprintf(stderr, "User not found\n");
            return;
        }
    }
}

int main() {
    char name[MAX_NAME_LEN];
    char pwd[MAX_PWD_LEN];
    char new_pwd[MAX_PWD_LEN];
    char *user_name;
    char *old_pwd;
    char *new_pwd_str;
    char choice;

    printf("Welcome to the password manager!\n");
    printf("1. Add user\n");
    printf("2. Display users\n");
    printf("3. Delete user\n");
    printf("4. Set password\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%c", &choice);

    while (choice!= '5') {
        switch (choice) {
            case '1':
                printf("Enter user name: ");
                fgets(name, MAX_NAME_LEN, stdin);
                fgets(name, MAX_NAME_LEN, stdin); // to remove the newline character
                fgets(name, MAX_NAME_LEN, stdin); // to remove the newline character
                printf("Enter password: ");
                fgets(pwd, MAX_PWD_LEN, stdin);
                fgets(pwd, MAX_PWD_LEN, stdin); // to remove the newline character
                fgets(pwd, MAX_PWD_LEN, stdin); // to remove the newline character
                add_user(name, pwd);
                break;
            case '2':
                display_users();
                break;
            case '3':
                printf("Enter user name to delete: ");
                fgets(name, MAX_NAME_LEN, stdin);
                fgets(name, MAX_NAME_LEN, stdin); // to remove the newline character
                fgets(name, MAX_NAME_LEN, stdin); // to remove the newline character
                delete_user(name);
                break;
            case '4':
                printf("Enter user name: ");
                fgets(name, MAX_NAME_LEN, stdin);
                fgets(name, MAX_NAME_LEN, stdin); // to remove the newline character
                fgets(name, MAX_NAME_LEN, stdin); // to remove the newline character
                printf("Enter old password: ");
                fgets(old_pwd, MAX_PWD_LEN, stdin);
                fgets(old_pwd, MAX_PWD_LEN, stdin); // to remove the newline character
                fgets(old_pwd, MAX_PWD_LEN, stdin); // to remove the newline character
                printf("Enter new password: ");
                fgets(new_pwd, MAX_PWD_LEN, stdin);
                fgets(new_pwd, MAX_PWD_LEN, stdin); // to remove the newline character
                fgets(new_pwd, MAX_PWD_LEN, stdin); // to remove the newline character
                new_pwd_str = malloc(MAX_PWD_LEN * sizeof(char));
                if (new_pwd_str == NULL) {
                    fprintf(stderr, "Memory allocation failed\n");
                    return 1;
                }
                strcpy(new_pwd_str, new_pwd);
                set_password(name, old_pwd, new_pwd_str);
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                fprintf(stderr, "Invalid choice\n");
        }
        printf("Enter your choice: ");
        scanf("%c", &choice);
    }

    return 0;
}