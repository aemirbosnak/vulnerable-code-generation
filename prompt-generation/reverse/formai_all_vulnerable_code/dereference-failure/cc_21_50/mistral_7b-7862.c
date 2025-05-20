//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: Dennis Ritchie
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void check_password_strength(char *password);

int main(int argc, char **argv) {
    char password[MAX_PASSWORD_LENGTH + 1];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <password>\n", argv[0]);
        return 1;
    }

    strcpy(password, argv[1]);
    check_password_strength(password);

    return 0;
}

void check_password_strength(char *password) {
    int length = strlen(password);
    int has_digit = 0, has_upper = 0, has_lower = 0, has_special = 0;

    if (length < MIN_PASSWORD_LENGTH) {
        printf("Password is too short (minimum %d characters).\n", MIN_PASSWORD_LENGTH);
        return;
    }

    for (int i = 0; password[i] != '\0'; ++i) {
        if (isdigit(password[i])) {
            has_digit = 1;
        } else if (isupper(password[i])) {
            has_upper = 1;
        } else if (islower(password[i])) {
            has_lower = 1;
        } else {
            switch (password[i]) {
                case '!':
                case '@':
                case '#':
                case '$':
                case '%':
                case '^':
                case '&':
                case '*':
                case '(':
                case ')':
                case '-':
                case '_':
                case '+':
                case '=':
                case '{':
                case '}':
                case '[':
                case ']':
                case '|':
                case '\\':
                case ';':
                case ':':
                case '\"':
                case '\'':
                case '<':
                case '>':
                case ',':
                case '.':
                case '/':
                case '?':
                case '`':
                case '~':
                    has_special = 1;
                    break;
                default:
                    printf("Password contains invalid character: %c.\n", password[i]);
                    return;
            }
        }
    }

    if (!has_digit || !has_upper || !has_lower || (!has_special && length < MAX_PASSWORD_LENGTH)) {
        printf("Password is weak.\n");
    } else {
        printf("Password is strong.\n");
    }
}