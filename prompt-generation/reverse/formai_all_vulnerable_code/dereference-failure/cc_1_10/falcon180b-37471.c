//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define PASSWORD_LENGTH 16
#define CHARACTER_SET_SIZE 94

bool is_valid_password(char *password) {
    int num_lowercase = 0;
    int num_uppercase = 0;
    int num_digits = 0;
    int num_special = 0;

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        char c = password[i];

        if (isdigit(c)) {
            num_digits++;
        } else if (isupper(c)) {
            num_uppercase++;
        } else if (islower(c)) {
            num_lowercase++;
        } else if (strchr("!@#$%^&*()_+-=[]{}\\|;':\",.<>/?", c)) {
            num_special++;
        }
    }

    return (num_lowercase > 0 && num_uppercase > 0 && num_digits > 0 && num_special > 0);
}

char *generate_password(void) {
    char *password = malloc(PASSWORD_LENGTH + 1);
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = rand() % CHARACTER_SET_SIZE + 33; // 33 is the ASCII code for the first printable character
    }
    password[PASSWORD_LENGTH] = '\0';
    return password;
}

int main() {
    srand(time(NULL));

    char *password = NULL;
    while (!is_valid_password(password)) {
        free(password);
        password = generate_password();
    }

    printf("Your secure password is: %s\n", password);
    free(password);

    return 0;
}