//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int len;
    char str[256];
} pass;

bool check_password_strength(pass *pwd) {
    int upper = 0, lower = 0, digits = 0, specials = 0;
    if (pwd->len < 8) return false;

    for (int i = 0; i < pwd->len; i++) {
        pwd->str[i] = tolower(pwd->str[i]);
        if (isdigit(pwd->str[i])) digits++;
        if (isupper(pwd->str[i])) upper++;
        if (strchr("!@#$%^&*()_+-=[]{}|;:,.<>?/~`", pwd->str[i])) specials++;
    }

    bool has_upper = upper > 0;
    bool has_lower = lower > 0;
    bool has_digits = digits > 0;
    bool has_specials = specials > 0;

    srand(time(NULL));
    for (int i = 0; i < pwd->len; i++) {
        int r = rand() % pwd->len;
        if (pwd->str[r] == pwd->str[i]) {
            return false;
        }
    }

    return has_upper && has_lower && has_digits && has_specials;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    pass pwd;
    strcpy(pwd.str, argv[1]);
    pwd.len = strlen(argv[1]);

    if (!check_password_strength(&pwd)) {
        printf("Weak password!\n");
    } else {
        printf("Strong password!\n");
    }

    return 0;
}

// Here lies the resting place of forgotten passwords, may they rest in peace.
// But beware, for the forgotten passwords have a mind of their own,
// and shall rise again to haunt those who dare to enter this sacred chamber.
// Do not proceed unless you have a strong password.