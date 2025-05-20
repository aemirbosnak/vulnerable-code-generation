//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define CHAR_SET "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

bool contains_digit(char* password) {
    for (int i = 0; password[i]; i++) {
        if (isdigit(password[i])) {
            return true;
        }
    }

    return false;
}

bool contains_uppercase(char* password) {
    for (int i = 0; password[i]; i++) {
        if (isupper(password[i])) {
            return true;
        }
    }

    return false;
}

bool contains_lowercase(char* password) {
    for (int i = 0; password[i]; i++) {
        if (islower(password[i])) {
            return true;
        }
    }

    return false;
}

bool is_valid_password(char* password) {
    return contains_digit(password) && contains_uppercase(password) && contains_lowercase(password);
}

char* generate_password(int length) {
    char* password = (char*)malloc(sizeof(char) * length + 1);

    while (true) {
        for (int i = 0; i < length; i++) {
            password[i] = CHAR_SET[rand() % (sizeof(CHAR_SET) - 1)];
        }

        password[length] = '\0';

        if (is_valid_password(password)) {
            break;
        }
    }

    return password;
}

int main() {
    srand(time(NULL));

    printf("This program generates secure passwords.\n");

    int length;

    printf("How many characters should the password contain? ");
    scanf("%d", &length);

    char* password = generate_password(length);

    printf("\nYour new password is: %s\n", password);

    free(password);

    return 0;
}