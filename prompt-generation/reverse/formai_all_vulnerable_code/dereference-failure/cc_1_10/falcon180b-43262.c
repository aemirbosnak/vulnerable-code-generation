//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: distributed
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 64
#define MIN_PASSWORD_LENGTH 8

char *generate_random_password(int length) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_+-=[]{}|;:,.<>/?`~";
    char *password = malloc(length + 1);
    if (password == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for password\n");
        exit(1);
    }
    for (int i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[length] = '\0';
    return password;
}

int main() {
    int num_passwords = 10;
    int min_length = MIN_PASSWORD_LENGTH;
    int max_length = MAX_PASSWORD_LENGTH;

    if (min_length > max_length) {
        fprintf(stderr, "Error: Minimum password length cannot be greater than maximum password length\n");
        exit(1);
    }

    char **passwords = malloc(num_passwords * sizeof(char *));
    if (passwords == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for passwords\n");
        exit(1);
    }

    for (int i = 0; i < num_passwords; i++) {
        int length = rand() % (max_length - min_length + 1) + min_length;
        passwords[i] = generate_random_password(length);
    }

    printf("Generated passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\n", passwords[i]);
    }

    free(passwords);
    return 0;
}