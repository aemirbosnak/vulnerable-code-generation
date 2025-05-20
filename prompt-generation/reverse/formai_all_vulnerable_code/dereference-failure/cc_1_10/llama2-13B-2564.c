//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <utime.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

struct password {
    char *name;
    char *password;
};

struct password passwords[MAX_PASSWORDS];
int attempts = 0;

void add_password(char *name, char *password) {
    int i = 0;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i].name, name) != 0) {
            break;
        }
    }
    if (i == MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached\n");
        return;
    }
    passwords[i].name = name;
    passwords[i].password = password;
}

void check_password(char *name) {
    int i = 0;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            if (strcmp(passwords[i].password, getpass("Enter your password: ")) == 0) {
                printf("Correct password entered\n");
                return;
            } else {
                attempts++;
                printf("Incorrect password entered. Try again (%d attempts left)\n", attempts);
                if (attempts >= MAX_ATTEMPTS) {
                    printf("Maximum number of attempts reached. Access denied\n");
                    return;
                }
            }
        }
    }
    printf("Invalid username or password. Try again\n");
}

int main() {
    char username[50];
    char password[50];

    printf("Welcome to the password manager\n");

    while (1) {
        printf("Please enter your username: ");
        fgets(username, 50, stdin);
        if (username[strcspn(username, "\n")] == '\0') {
            break;
        }

        printf("Please enter your password: ");
        fgets(password, 50, stdin);
        if (password[strcspn(password, "\n")] == '\0') {
            break;
        }

        add_password(username, password);
        check_password(username);
    }

    return 0;
}