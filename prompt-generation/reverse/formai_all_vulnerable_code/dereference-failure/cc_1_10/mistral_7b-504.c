//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LEN 12
#define MAX_LEN 20

void generate_password(char *password, int length) {
    const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
    const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *digits = "0123456789";
    const char *symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    int lower, upper, digits_count, symbols_count;

    srand(time(NULL));

    lower = rand() % 16;
    password[0] = lowercase[lower];

    upper = rand() % 16;
    password[1] = uppercase[upper];

    digits_count = rand() % 5 + 2;
    for (int i = 2; i < length - symbols_count; i++) {
        password[i] = digits[rand() % 10];
        i++;
        if (digits_count > 0) {
            digits_count--;
        } else {
            symbols_count = rand() % 5 + 2;
            for (int j = 0; j < symbols_count; j++) {
                int symbol_index = rand() % strlen(symbols);
                password[i] = symbols[symbol_index];
                i++;
            }
        }
    }

    password[length - 1] = '\0';
}

int main(int argc, char **argv) {
    char password[MAX_LEN + 1];
    int length;

    if (argc != 2) {
        printf("Usage: %s <length>\n", argv[0]);
        return 1;
    }

    length = atoi(argv[1]);
    if (length < MIN_LEN || length > MAX_LEN) {
        printf("Error: Length must be between %d and %d.\n", MIN_LEN, MAX_LEN);
        return 1;
    }

    generate_password(password, length);
    printf("Generated password: %s\n", password);

    return 0;
}