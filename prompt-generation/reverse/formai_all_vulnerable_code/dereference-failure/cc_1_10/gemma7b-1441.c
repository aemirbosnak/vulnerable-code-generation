//Gemma-7B DATASET v1.0 Category: Password management ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

#define MAX_PASSWORDS 20

typedef struct _Password {
    char *name;
    char *pass;
    int used;
} Password;

Password passwords[MAX_PASSWORDS];

int main() {
    int i, j, k, pass_num = 0;
    char new_pass[256], confirm_pass[256];

    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = NULL;
        passwords[i].pass = NULL;
        passwords[i].used = 0;
    }

    system("clear");
    printf("Welcome to the Crazy Cat Password Manager!\n");

    // Login or Register
    printf("Enter 'login' to log in or 'register' to register: ");
    scanf("%s", new_pass);

    switch (new_pass[0]) {
        case 'l':
            // Login
            printf("Enter your username: ");
            scanf("%s", new_pass);

            for (i = 0; i < MAX_PASSWORDS; i++) {
                if (passwords[i].name && strcmp(passwords[i].name, new_pass) == 0) {
                    printf("Welcome, %s!\n", passwords[i].name);
                    printf("Your password is: %s\n", passwords[i].pass);
                    passwords[i].used = 1;
                    break;
                }
            }

            if (i == MAX_PASSWORDS) {
                printf("Username not found.\n");
            }
            break;

        case 'r':
            // Register
            printf("Enter a username: ");
            scanf("%s", passwords[pass_num].name = malloc(256));

            printf("Enter a password: ");
            scanf("%s", passwords[pass_num].pass = malloc(256));

            passwords[pass_num].used = 0;
            pass_num++;
            break;

        default:
            printf("Invalid input.\n");
    }

    return 0;
}