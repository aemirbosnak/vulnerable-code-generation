//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LEN 8
#define MAX_LEN 32
#define PASS_LEN ((rand() % (MAX_LEN - MIN_LEN + 1)) + MIN_LEN)

#define UPPER 65
#define LOWER 97
#define DIGIT 48
#define SYMBOL 33

#define TOTAL (UPPER - LOWER + DIGIT - SYMBOL + 1)
#define CHANCE_UPPER (1.0 / 3.0)
#define CHANCE_LOWER (1.0 / 3.0)
#define CHANCE_DIGIT (1.0 / 3.0)
#define CHANCE_SYMBOL (1.0 / 3.0)

void generate_password(char *password) {
    int len = PASS_LEN;
    int upper_count = 0, lower_count = 0, digit_count = 0, symbol_count = 0;

    srand(time(NULL));

    for (int i = 0; i < len; i++) {
        double rand_num = ((double) rand() / RAND_MAX);
        char c;

        if (rand_num < CHANCE_UPPER) {
            c = (char) (rand() % (UPPER - LOWER + 1) + LOWER);
            password[i] = c;
            upper_count++;
        } else if (rand_num < CHANCE_UPPER + CHANCE_LOWER) {
            c = (char) (rand() % 26 + LOWER);
            password[i] = c;
            lower_count++;
        } else if (rand_num < CHANCE_UPPER + CHANCE_LOWER + CHANCE_DIGIT) {
            c = (char) (rand() % 10 + DIGIT);
            password[i] = c;
            digit_count++;
        } else {
            c = (char) (rand() % TOTAL + SYMBOL);
            password[i] = c;
            symbol_count++;
        }
    }

    printf("Password generated:\n");
    for (int i = 0; i < len; i++) {
        printf("%c", password[i]);
    }
    printf("\n");

    printf("Statistics:\n");
    printf("Uppercase letters: %d\n", upper_count);
    printf("Lowercase letters: %d\n", lower_count);
    printf("Digits: %d\n", digit_count);
    printf("Symbols: %d\n", symbol_count);
}

int main() {
    char password[PASS_LEN + 1];

    generate_password(password);

    return 0;
}