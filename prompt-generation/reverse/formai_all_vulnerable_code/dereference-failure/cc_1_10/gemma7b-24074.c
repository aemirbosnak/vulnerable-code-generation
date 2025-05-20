//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWD_LEN 255

typedef struct Password {
    char *passwrd;
    int strength;
} Password;

int main() {
    Password password;
    password.passwrd = malloc(MAX_PASSWD_LEN);
    printf("Enter your password: ");
    fgets(password.passwrd, MAX_PASSWD_LEN, stdin);

    password.strength = check_password_strength(password.passwrd);

    switch (password.strength) {
        case 0:
            printf("Your password is very weak. Please use a stronger password.\n");
            break;
        case 1:
            printf("Your password is weak. Please use a stronger password.\n");
            break;
        case 2:
            printf("Your password is moderate. It could be stronger.\n");
            break;
        case 3:
            printf("Your password is strong. It meets the recommended criteria.\n");
            break;
        case 4:
            printf("Your password is very strong. It is highly unlikely to be cracked.\n");
            break;
    }

    free(password.passwrd);
    return 0;
}

int check_password_strength(char *passwrd) {
    int strength = 0;
    int min_chars = 0;
    int num_nums = 0;
    int has_symbols = 0;

    for (int i = 0; passwrd[i] != '\0'; i++) {
        if (islower(passwrd[i])) {
            min_chars++;
        } else if (isdigit(passwrd[i])) {
            num_nums++;
        } else if (isupper(passwrd[i]) || ispunct(passwrd[i])) {
            has_symbols++;
        }
    }

    if (min_chars >= 1) {
        strength++;
    }
    if (num_nums >= 1) {
        strength++;
    }
    if (has_symbols >= 1) {
        strength++;
    }

    return strength;
}