//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32
#define CHARACTER_SET_LENGTH 62

typedef struct {
    char *password;
    int length;
} Password;

char *generate_password(int length) {
    char *password = malloc(length + 1);
    if (password == NULL) {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        password[i] = 'A' + rand() % 26;
    }

    password[length] = '\0';

    return password;
}

int main() {
    srand(time(NULL));

    int min_length = MIN_PASSWORD_LENGTH;
    int max_length = MAX_PASSWORD_LENGTH;
    char character_set[CHARACTER_SET_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    printf("Enter minimum password length (between %d and %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &min_length);

    printf("Enter maximum password length (between %d and %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &max_length);

    printf("Enter character set (up to %d characters): ", CHARACTER_SET_LENGTH - 1);
    scanf("%s", character_set);

    int password_length = rand() % (max_length - min_length + 1) + min_length;

    Password *password = malloc(sizeof(Password));
    if (password == NULL) {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }

    password->password = generate_password(password_length);
    password->length = password_length;

    printf("Generated password: %s\n", password->password);
    printf("Password length: %d\n", password->length);

    free(password->password);
    free(password);

    return 0;
}