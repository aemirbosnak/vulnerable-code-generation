//FormAI DATASET v1.0 Category: Password management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_PASSWORD_LENGTH 20

struct password {
    char name[MAX_SIZE];
    char username[MAX_SIZE];
    char password[MAX_PASSWORD_LENGTH];
};

void get_password(struct password *p) {
    printf("Enter website or app name: ");
    fgets(p->name, MAX_SIZE, stdin);

    printf("Enter username/email associated with the account: ");
    fgets(p->username, MAX_SIZE, stdin);

    printf("Enter password (must be %d characters or less): ", MAX_PASSWORD_LENGTH);
    fgets(p->password, MAX_PASSWORD_LENGTH, stdin);

    // remove newline characters from input
    p->name[strcspn(p->name, "\n")] = '\0';
    p->username[strcspn(p->username, "\n")] = '\0';
    p->password[strcspn(p->password, "\n")] = '\0';
}

void print_password(struct password p) {
    printf("Website/App: %s\n", p.name);
    printf("Username/Email: %s\n", p.username);
    printf("Password: %s\n", p.password);
}

int main() {
    int num_passwords;
    printf("Please enter the number of passwords to manage: ");
    scanf("%d", &num_passwords);

    // clear input buffer
    while(getchar() != '\n');

    struct password *passwords = malloc(num_passwords * sizeof(struct password));

    printf("Enter password information for each account:\n");

    for (int i = 0; i < num_passwords; i++) {
        printf("\nAccount %d\n", i + 1);
        get_password(&passwords[i]);
    }

    printf("\nPassword information entered:\n");

    for (int i = 0; i < num_passwords; i++) {
        printf("\nAccount %d\n", i + 1);
        print_password(passwords[i]);
    }

    free(passwords);

    return 0;
}