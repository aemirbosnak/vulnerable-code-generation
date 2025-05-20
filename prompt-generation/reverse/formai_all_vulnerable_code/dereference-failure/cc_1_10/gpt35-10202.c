//FormAI DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_PASSWORD_LEN 20

struct user {
    char *username;
    char *password;
};

struct login_session {
    struct user *active_user;
    int is_logged_in;
};

int create_user(struct user accounts[], int num_accounts);
int login(struct user accounts[], int num_accounts, struct login_session *session);
void change_password(struct login_session *session);
void print_accounts(struct user accounts[], int num_accounts);

int main() {
    int option;
    int num_accounts = 0;
    struct user accounts[MAX_ACCOUNTS];
    struct login_session session = { NULL, 0 };

    printf("PASSWORD MANAGER\n");

    do {
        printf("\nMENU\n");
        printf("1. Create an account\n");
        printf("2. Login\n");
        printf("3. Change password\n");
        printf("4. View all accounts\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                num_accounts = create_user(accounts, num_accounts);
                break;
            case 2:
                session.is_logged_in = login(accounts, num_accounts, &session);
                break;
            case 3:
                if (session.is_logged_in) {
                    change_password(&session);
                } else {
                    printf("You must be logged in to change your password\n");
                }
                break;
            case 4:
                print_accounts(accounts, num_accounts);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (option != 5);

    return 0;
}

int create_user(struct user accounts[], int num_accounts) {
    char username[50];
    char password[MAX_PASSWORD_LEN];
    
    if (num_accounts == MAX_ACCOUNTS) {
        printf("You have reached the maximum number of accounts\n");
        return num_accounts;
    }

    printf("Enter username: ");
    scanf("%s", username);

    for(int i = 0; i < num_accounts; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            printf("Username already taken\n");
            return num_accounts;
        }
    }

    printf("Enter password: ");
    scanf("%s", password);
    
    accounts[num_accounts].username = (char *)malloc(strlen(username) + 1);
    strcpy(accounts[num_accounts].username, username);

    accounts[num_accounts].password = (char *)malloc(strlen(password) + 1);
    strcpy(accounts[num_accounts].password, password);

    num_accounts++;

    printf("Account created successfully\n");

    return num_accounts;
}

int login(struct user accounts[], int num_accounts, struct login_session *session) {
    char username[50];
    char password[MAX_PASSWORD_LEN];

    if (session->is_logged_in) {
        printf("You are already logged in\n");
        return 1;
    }

    printf("Enter username: ");
    scanf("%s", username);

    for(int i = 0; i < num_accounts; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            printf("Enter password: ");
            scanf("%s", password);

            if (strcmp(password, accounts[i].password) == 0) {
                session->active_user = &accounts[i];
                printf("Login successful\n");
                return 1;
            } else {
                printf("Incorrect password\n");
                return 0;
            }
        }
    }

    printf("Account not found\n");

    return 0;
}

void change_password(struct login_session *session) {
    char old_password[MAX_PASSWORD_LEN];
    char new_password[MAX_PASSWORD_LEN];

    printf("Enter old password: ");
    scanf("%s", old_password);

    if (strcmp(old_password, session->active_user->password) == 0) {
        printf("Enter new password: ");
        scanf("%s", new_password);
        free(session->active_user->password);

        session->active_user->password = (char *)malloc(strlen(new_password) + 1);
        strcpy(session->active_user->password, new_password);

        printf("Password changed successfully\n");
    } else {
        printf("Incorrect password\n");
    }
}

void print_accounts(struct user accounts[], int num_accounts) {
    printf("TOTAL ACCOUNTS: %d\n", num_accounts);

    for(int i = 0; i < num_accounts; i++) {
        printf("Username: %s Password: %s\n", accounts[i].username, accounts[i].password);
    }
}