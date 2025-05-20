//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 1024

typedef struct {
    char *password;
    int length;
} Password;

Password *create_password(const char *password) {
    Password *p = malloc(sizeof(Password));
    p->password = strdup(password);
    p->length = strlen(password);
    return p;
}

void delete_password(Password *p) {
    free(p->password);
    free(p);
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_uppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

int is_lowercase(char c) {
    return c >= 'a' && c <= 'z';
}

int is_special(char c) {
    return c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*';
}

int is_letter(char c) {
    return is_uppercase(c) || is_lowercase(c);
}

int is_password_valid(Password *p) {
    int has_digit = 0;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_special = 0;
    for (int i = 0; i < p->length; i++) {
        char c = p->password[i];
        if (is_digit(c)) {
            has_digit = 1;
        } else if (is_uppercase(c)) {
            has_uppercase = 1;
        } else if (is_lowercase(c)) {
            has_lowercase = 1;
        } else if (is_special(c)) {
            has_special = 1;
        }
    }
    return has_digit && has_uppercase && has_lowercase && has_special;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    Password *p = create_password(password);
    if (is_password_valid(p)) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is weak!\n");
    }

    delete_password(p);
    return 0;
}