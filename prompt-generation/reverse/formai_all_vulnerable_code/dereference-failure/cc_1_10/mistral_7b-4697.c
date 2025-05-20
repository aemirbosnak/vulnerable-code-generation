//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define PASSWORD_COUNT 5
#define CHAR_SET_SIZE 62

char char_set[CHAR_SET_SIZE] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  '!', '@', '#', '$', '%', '&', '*', '(', ')', '_', '+', '=', '-', ';', ':', '>', '<', ',', '.', '?'
};

void generate_password(char *password, size_t length) {
    size_t i, random_index;

    if (length > MAX_LENGTH || length < MIN_LENGTH) {
        fprintf(stderr, "Invalid password length. Must be between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        password[0] = '\0';
        return;
    }

    srand(time(NULL));

    for (i = 0; i < length; i++) {
        random_index = rand() % CHAR_SET_SIZE;
        password[i] = char_set[random_index];
    }

    password[length] = '\0';
}

int main(int argc, char *argv[]) {
    int i;
    char passwords[PASSWORD_COUNT][MAX_LENGTH + 1];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_passwords>\n", argv[0]);
        return EXIT_FAILURE;
    }

    srand(time(NULL));

    for (i = 0; i < atoi(argv[1]); i++) {
        generate_password(passwords[i], rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH);
        printf("Password %d: %s\n", i + 1, passwords[i]);
    }

    return EXIT_SUCCESS;
}