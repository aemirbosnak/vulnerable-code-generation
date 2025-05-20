//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

// Linus Torvalds-style variable names
static bool is_init = false;
static char *charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+=-";
static int charset_len = 62;

void init_rand() {
    // Linus says: "Use the current time as seed"
    srand(time(NULL));
    is_init = true;
}

char *generate_password(int length) {
    if (!is_init)
        init_rand();

    char *password = malloc(length + 1);
    for (int i = 0; i < length; i++)
        password[i] = charset[rand() % charset_len];

    // Linus says: "Always terminate the string"
    password[length] = '\0';

    return password;
}

void print_usage() {
    printf("Usage: %s <length>\n", "secure_pwgen");
    printf("Generates a random password of the specified length.\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    int length = atoi(argv[1]);
    if (length <= 0) {
        printf("Invalid length: %d\n", length);
        return 1;
    }

    char *password = generate_password(length);
    printf("Generated password: %s\n", password);

    free(password);
    return 0;
}