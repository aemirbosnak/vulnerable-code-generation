//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_MAX_LENGTH 32
#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_DEFAULT_LENGTH 16
#define PASSWORD_ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
#define PASSWORD_NUM_CHARS 62

void generate_password(char *password, int length) {
    int i;
    for (i = 0; i < length; i++) {
        int random_index = rand() % PASSWORD_NUM_CHARS;
        password[i] = PASSWORD_ALPHABET[random_index];
    }
    password[length] = '\0';
}

int main(int argc, char *argv[]) {
    int password_length = PASSWORD_DEFAULT_LENGTH;
    char *password = NULL;

    if (argc > 1) {
        if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--length") == 0) {
            if (argc < 3) {
                printf("Error: Missing password length.\n");
                return 1;
            }
            password_length = atoi(argv[2]);
            if (password_length < PASSWORD_MIN_LENGTH || password_length > PASSWORD_MAX_LENGTH) {
                printf("Error: Password length must be between %d and %d characters.\n", PASSWORD_MIN_LENGTH, PASSWORD_MAX_LENGTH);
                return 1;
            }
        } else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            printf("Usage: %s [-l LENGTH] [-h]\n", argv[0]);
            printf("Options:\n");
            printf("  -l LENGTH, --length=LENGTH\n");
            printf("    Set the length of the generated password.\n");
            printf("  -h, --help\n");
            printf("    Show this help message.\n");
            return 0;
        } else {
            printf("Error: Invalid option.\n");
            return 1;
        }
    }

    password = (char *)malloc(password_length + 1);
    if (password == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return 1;
    }

    generate_password(password, password_length);

    printf("Generated password: %s\n", password);

    free(password);

    return 0;
}