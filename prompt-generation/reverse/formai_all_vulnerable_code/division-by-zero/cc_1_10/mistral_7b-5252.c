//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 12
#define NUM_CHARS 4
#define NUM_DIGITS 4
#define NUM_SPECIAL 4

// Function to generate random number between min and max
int random_number(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

// Function to generate random character from a given character set
char random_char(char *set, int length) {
    int index = random_number(0, length - 1);
    return set[index];
}

// Function to generate a random password
void generate_password(char *password) {
    char char_set[NUM_CHARS][2] = {{"a-z"}, {"A-Z"}};
    char digits[NUM_DIGITS] = {"0123456789"};
    char special[NUM_SPECIAL] = {"!@#$%^&*()_+-=[]{}|;:,.<>?"};

    int char_index, digit_index, special_index;

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        if (i < NUM_CHARS) {
            password[i] = random_char(char_set[i], strlen(char_set[i]));
            i++;
        } else if (i < PASSWORD_LENGTH - NUM_DIGITS) {
            password[i] = random_char(digits, NUM_DIGITS);
        } else {
            password[i] = random_char(special, NUM_SPECIAL);
        }
    }

    password[PASSWORD_LENGTH] = '\0';
}

int main() {
    srand(time(NULL));

    char password[PASSWORD_LENGTH + 1];

    generate_password(password);

    printf("Generated Password: %s\n", password);

    return 0;
}