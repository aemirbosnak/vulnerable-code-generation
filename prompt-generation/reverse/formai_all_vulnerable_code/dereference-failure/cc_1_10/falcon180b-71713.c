//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_SIZE 1000

char *password;
int password_length;
int has_uppercase;
int has_lowercase;
int has_number;
int has_special_char;

void initialize_password() {
    password = (char*)malloc(MAX_PASSWORD_SIZE * sizeof(char));
    password_length = 0;
    has_uppercase = 0;
    has_lowercase = 0;
    has_number = 0;
    has_special_char = 0;
}

void generate_password() {
    int i;
    for (i = 0; i < password_length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else if (!isalnum(password[i])) {
            has_special_char = 1;
        }
    }
}

int main() {
    int i;
    int score = 0;
    int length = 0;
    char *special_chars = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    initialize_password();

    printf("Welcome to the Medieval Password Strength Checker!\n");
    printf("Please enter your password:\n");
    scanf("%s", password);
    password_length = strlen(password);

    generate_password();

    if (password_length < 8) {
        printf("Your password is too short. It needs to be at least 8 characters long.\n");
        return 1;
    }

    score += (has_uppercase * 2);
    score += (has_lowercase * 2);
    score += (has_number * 2);
    score += (has_special_char * 2);

    if (score < 4) {
        printf("Your password is very weak. It needs to have at least one uppercase letter, one lowercase letter, one number, and one special character.\n");
    } else if (score < 8) {
        printf("Your password is weak. It needs to have at least one uppercase letter, one lowercase letter, one number, and one special character. It should also be longer.\n");
    } else {
        printf("Your password is strong. Well done!\n");
    }

    return 0;
}