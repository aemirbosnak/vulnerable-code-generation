//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CHAR_COUNT 26
#define LOWER_CASE 0
#define UPPER_CASE 1
#define DIGITS 2
#define SPECIAL_CHARS 3
#define MIN_LENGTH 8
#define MAX_LENGTH 16

char *generate_password(int length) {
    char *password = malloc(length + 1);
    int random_char_type, random_index;

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        random_char_type = rand() % 4;
        if (length - i < MIN_LENGTH) {
            // Force at least one upper case, one lower case and one digit
            if (random_char_type == DIGITS && (length - i) % 3 != 0)
                random_char_type = (rand() % 2) ? LOWER_CASE : UPPER_CASE;
        }

        switch (random_char_type) {
            case LOWER_CASE:
                random_index = rand() % CHAR_COUNT;
                password[i] = 'a' + random_index;
                break;
            case UPPER_CASE:
                random_index = rand() % CHAR_COUNT;
                password[i] = 'A' + random_index;
                break;
            case DIGITS:
                random_index = rand() % 10;
                password[i] = '0' + random_index;
                break;
            case SPECIAL_CHARS:
                password[i] = "!@#$%^&*()_+-={}[]|\\:\"<>?,./~`"[rand() % 32];
                break;
        }
    }

    password[length] = '\0';

    return password;
}

int main() {
    int length;

    printf("Enter password length (min: %d, max: %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length. Exiting...\n");
        return 1;
    }

    char *password = generate_password(length);

    printf("Generated password: %s\n", password);

    free(password);

    return 0;
}