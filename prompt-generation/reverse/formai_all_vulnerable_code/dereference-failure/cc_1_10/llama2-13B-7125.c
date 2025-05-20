//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

struct password {
    char *name;
    char *password;
};

struct password *passwords[MAX_PASSWORDS];
int attempts[MAX_PASSWORDS];

void init_passwords(void);
void set_password(char *name, char *password);
int verify_password(char *name);
void print_passwords(void);

int main(void) {
    init_passwords();

    while (1) {
        char *username;
        char *password;

        printf("Username: ");
        scanf("%s", username);

        printf("Password: ");
        scanf("%s", password);

        set_password(username, password);

        print_passwords();

        int choice;
        printf("Do you want to exit (1) or continue (2)? ");
        scanf("%d", &choice);

        if (choice == 1) {
            break;
        }
    }

    return 0;
}

void init_passwords(void) {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i] = malloc(sizeof(struct password));
        passwords[i]->name = NULL;
        passwords[i]->password = NULL;
    }

    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (i % 2 == 0) {
            passwords[i]->name = "User";
            passwords[i]->password = "Password";
        } else {
            passwords[i]->name = "Admin";
            passwords[i]->password = "Admin123";
        }
    }
}

void set_password(char *name, char *password) {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i]->name, name) == 0) {
            passwords[i]->password = password;
            break;
        }
    }
}

int verify_password(char *name) {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i]->name, name) == 0) {
            if (strcmp(passwords[i]->password, name) == 0) {
                return 1;
            }
        }
    }

    return 0;
}

void print_passwords(void) {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (passwords[i]->name != NULL) {
            printf("%s: %s\n", passwords[i]->name, passwords[i]->password);
        }
    }
}