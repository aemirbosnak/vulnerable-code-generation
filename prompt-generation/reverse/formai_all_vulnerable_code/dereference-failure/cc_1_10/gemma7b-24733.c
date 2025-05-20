//Gemma-7B DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    int strength;
} Password;

void generate_password(Password *passwords) {
    passwords->name = malloc(20);
    passwords->password = malloc(20);

    printf("Enter a username: ");
    scanf("%s", passwords->name);

    printf("Enter a password: ");
    scanf("%s", passwords->password);

    passwords->strength = calculate_password_strength(passwords->password);
}

int calculate_password_strength(char *password) {
    int strength = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) {
            strength++;
        }
        if (islower(password[i])) {
            strength++;
        }
        if (isdigit(password[i])) {
            strength++;
        }
        if (ispunct(password[i])) {
            strength++;
        }
    }

    return strength;
}

int main() {
    Password passwords[MAX_PASSWORDS];

    for (int i = 0; i < MAX_PASSWORDS; i++) {
        generate_password(&passwords[i]);
    }

    for (int i = 0; i < MAX_PASSWORDS; i++) {
        printf("Username: %s\n", passwords[i].name);
        printf("Password: %s\n", passwords[i].password);
        printf("Strength: %d\n", passwords[i].strength);
        printf("\n");
    }

    return 0;
}