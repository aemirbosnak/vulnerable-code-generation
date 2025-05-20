//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 64

typedef struct {
    char *password;
    int length;
} Password;

int is_valid_password(const Password *password) {
    if (password->length < PASSWORD_MIN_LENGTH ||
        password->length > PASSWORD_MAX_LENGTH) {
        return 0;
    }

    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;

    for (int i = 0; i < password->length; i++) {
        char c = tolower(password->password[i]);
        if (c >= 'a' && c <= 'z') {
            has_lowercase = 1;
        } else if (c >= 'A' && c <= 'Z') {
            has_uppercase = 1;
        } else if (c >= '0' && c <= '9') {
            has_digit = 1;
        } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '_' || c == '+' || c == '=' || c == '{' || c == '}' || c == '[' || c == ']' || c == '|' || c == ';' || c == ':' || c == '"' || c == '\'' || c == '<' || c == '>' || c == '.' || c == '?' || c == '/') {
            has_special = 1;
        }
    }

    return has_uppercase && has_lowercase && has_digit && has_special;
}

int main() {
    Password password;
    password.password = NULL;
    password.length = 0;

    char input[PASSWORD_MAX_LENGTH];
    printf("Enter password: ");
    fgets(input, PASSWORD_MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    password.password = strdup(input);
    password.length = strlen(password.password);

    if (is_valid_password(&password)) {
        printf("Valid password\n");
    } else {
        printf("Invalid password\n");
    }

    free(password.password);
    return 0;
}