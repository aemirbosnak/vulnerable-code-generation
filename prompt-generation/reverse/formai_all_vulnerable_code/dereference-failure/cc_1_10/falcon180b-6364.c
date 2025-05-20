//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 100

// function to calculate password strength
int password_strength(char *password) {
    int length = strlen(password);
    int uppercase_count = 0;
    int lowercase_count = 0;
    int number_count = 0;
    int special_count = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        } else if (islower(password[i])) {
            lowercase_count++;
        } else if (isdigit(password[i])) {
            number_count++;
        } else if (!isalnum(password[i])) {
            special_count++;
        }
    }

    int strength = 0;
    if (length >= 8) {
        strength++;
    }
    if (uppercase_count >= 1) {
        strength++;
    }
    if (lowercase_count >= 1) {
        strength++;
    }
    if (number_count >= 1) {
        strength++;
    }
    if (special_count >= 1) {
        strength++;
    }

    return strength;
}

// function to generate a random password
char *generate_password(int length) {
    char *password = (char *) malloc(length + 1);
    if (password == NULL) {
        printf("Error: memory allocation failed.\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        password[i] = rand() % 94 + 33;
    }
    password[length] = '\0';

    return password;
}

int main() {
    int length = 12;
    char *password = generate_password(length);
    int strength = password_strength(password);

    printf("Password: %s\n", password);
    printf("Password strength: %d\n", strength);

    return 0;
}