//Falcon2-11B DATASET v1.0 Category: Secure Password Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LEN 16
#define ALPHABET_SIZE 26
#define SPECIAL_CHAR_SIZE 10
#define DIGITS_SIZE 10

char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
char special_chars[] = "!@#$%^&*()-+";
char digits[] = "0123456789";

char *generate_password() {
    srand(time(NULL)); // seed the random number generator
    char *password = malloc(PASSWORD_LEN * sizeof(char));

    // pick a random uppercase letter
    int uppercase_index = rand() % ALPHABET_SIZE;
    password[0] = alphabet[uppercase_index];
    password[0] = (char) toupper(password[0]);

    // pick a random lowercase letter
    int lowercase_index = rand() % ALPHABET_SIZE;
    password[1] = alphabet[lowercase_index];

    // pick a random digit
    int digit_index = rand() % DIGITS_SIZE;
    password[2] = digits[digit_index];

    // pick a random special character
    int special_index = rand() % SPECIAL_CHAR_SIZE;
    password[3] = special_chars[special_index];

    for (int i = 4; i < PASSWORD_LEN; i++) {
        // pick a random character from the remaining characters
        int remaining_index = rand() % (ALPHABET_SIZE + SPECIAL_CHAR_SIZE + DIGITS_SIZE);

        if (remaining_index < ALPHABET_SIZE) {
            int alphabet_index = rand() % ALPHABET_SIZE;
            password[i] = alphabet[alphabet_index];
        } else if (remaining_index < ALPHABET_SIZE + SPECIAL_CHAR_SIZE) {
            int special_index = rand() % SPECIAL_CHAR_SIZE;
            password[i] = special_chars[special_index];
        } else if (remaining_index < ALPHABET_SIZE + SPECIAL_CHAR_SIZE + DIGITS_SIZE) {
            int digit_index = rand() % DIGITS_SIZE;
            password[i] = digits[digit_index];
        }
    }

    return password;
}

int main() {
    char *password = generate_password();
    printf("Your secure password is: %s\n", password);
    free(password);
    return 0;
}