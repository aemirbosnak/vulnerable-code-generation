//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_LENGTH 8
#define WEAK 0
#define MODERATE 1
#define STRONG 2

bool has_digit(char c) {
    return (isdigit(c) != 0);
}

bool has_upper(char c) {
    return (isupper(c) != 0);
}

bool has_lower(char c) {
    return (islower(c) != 0);
}

bool has_special(char c, char *special) {
    int i = 0;
    while (special[i] != '\0') {
        if (c == special[i]) {
            return true;
        }
        i++;
    }
    return false;
}

int password_strength(char *password) {
    int length = strlen(password);
    int strength = WEAK;

    if (length < MIN_LENGTH) {
        return strength;
    }

    int digits = 0;
    int upper = 0;
    int lower = 0;
    int specials = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        if (has_digit(password[i])) {
            digits++;
        }
        if (has_upper(password[i])) {
            upper++;
        }
        if (has_lower(password[i])) {
            lower++;
        }
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' ||
            password[i] == '$' || password[i] == '%' || password[i] == '&' ||
            password[i] == '*' || password[i] == '(' || password[i] == ')' ||
            password[i] == '_' || password[i] == '+' || password[i] == '-' ||
            password[i] == '=' || password[i] == '{' || password[i] == '}' ||
            password[i] == '[' || password[i] == ']' || password[i] == '|' ||
            password[i] == '\\' || password[i] == ';' || password[i] == ':' ||
            password[i] == '<' || password[i] == '>' || password[i] == '?' ||
            password[i] == '!' || password[i] == '.' || password[i] == ',') {
            specials++;
        }
    }

    if (digits > 0) {
        strength++;
    }
    if (upper > 0) {
        strength++;
    }
    if (lower > 0) {
        strength++;
    }
    if (specials > 0) {
        strength++;
    }

    return strength;
}

int main() {
    char *password;
    int length;
    int strength;

    printf("Enter thy password: ");
    password = (char *)calloc(100, sizeof(char));
    fgets(password, 100, stdin);
    password[strcspn(password, "\n")] = '\0';

    strength = password_strength(password);

    switch (strength) {
        case WEAK:
            printf("Thy password is as weak as a butterfly.\n");
            break;
        case MODERATE:
            printf("Thy password is as strong as a falcon.\n");
            break;
        case STRONG:
            printf("Thy password is as strong as a dragon's hide.\n");
            break;
    }

    free(password);
    return 0;
}