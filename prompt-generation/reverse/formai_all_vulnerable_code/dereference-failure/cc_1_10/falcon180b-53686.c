//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_PASSWORD_LENGTH 32
#define NUM_PASSWORDS 5

// Function to generate a random password
char *generate_password(int length) {
    char *password = malloc(length + 1);
    if (password == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for password.\n");
        exit(EXIT_FAILURE);
    }

    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[]\\|;:'\",.<>/?";
    for (int i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[length] = '\0';

    return password;
}

// Function to write a password to a file
void write_password(FILE *file, const char *password) {
    if (fputs(password, file) == EOF) {
        fprintf(stderr, "Error: failed to write password to file.\n");
        exit(EXIT_FAILURE);
    }
}

// Function to generate multiple passwords and write them to a file
void generate_passwords(const char *filename, int num_passwords, int length) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: failed to open file '%s' for writing.\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_passwords; i++) {
        char *password = generate_password(length);
        write_password(file, password);
        free(password);
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    const char *filename = "passwords.txt";
    int num_passwords = NUM_PASSWORDS;
    int length = MAX_PASSWORD_LENGTH;

    generate_passwords(filename, num_passwords, length);

    printf("Passwords generated and saved to file '%s'.\n", filename);

    return 0;
}