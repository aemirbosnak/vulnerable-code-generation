//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20
#define LOWER 97
#define UPPER 122
#define DIGITS 48
#define SPECIAL 33

char *generate_password(size_t length) {
    char *password;
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?`~";
    size_t password_length = length;
    int random_index;

    password = malloc(length + 1);
    if (password == NULL) {
        perror("Could not allocate memory for password");
        return NULL;
    }

    password[length] = '\0';

    srand(time(NULL));

    for (size_t i = 0; i < length; i++) {
        int random_character_type = rand() % 5;

        if (random_character_type < 3) {
            random_index = rand() % (sizeof(characters) - LOWER + 1) + LOWER;
            password[i] = characters[random_index];
        } else {
            switch (random_character_type) {
                case 3:
                    password[i] = (char)(rand() % (UPPER - LOWER + 1) + LOWER);
                    break;
                case 4:
                    password[i] = (char)(rand() % (DIGITS + 1) + 48);
                    break;
                case 5:
                    password[i] = (char)(rand() % (sizeof(characters) - SPECIAL + 1) + SPECIAL);
                    break;
            }
        }
    }

    return password;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <password length>\n", argv[0]);
        return 1;
    }

    size_t length = atoi(argv[1]);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Password length must be between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    char *password = generate_password(length);

    if (password == NULL) {
        return 1;
    }

    printf("Generated password: %s\n", password);

    free(password);

    return 0;
}