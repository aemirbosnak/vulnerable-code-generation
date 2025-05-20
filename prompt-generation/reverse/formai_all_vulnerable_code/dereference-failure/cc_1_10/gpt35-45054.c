//FormAI DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

struct Password {
    char *site;
    char *username;
    char *password;
};

struct Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char site[100], username[50], password[50];
    printf("Enter website: ");
    scanf("%s", site);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    struct Password p;
    p.site = malloc(strlen(site) + 1);
    p.username = malloc(strlen(username) + 1);
    p.password = malloc(strlen(password) + 1);
    strcpy(p.site, site);
    strcpy(p.username, username);
    strcpy(p.password, password);
    passwords[numPasswords++] = p;
}

void printPasswords() {
    for (int i = 0; i < numPasswords; i++) {
        printf("Website: %s\n", passwords[i].site);
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
    }
}

int main() {
    while (1) {
        int choice;
        printf("Welcome to password manager\n");
        printf("1. Add Password\n");
        printf("2. Print all Passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                printPasswords();
                break;
            case 3:
                printf("Thanks for using password manager!");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}