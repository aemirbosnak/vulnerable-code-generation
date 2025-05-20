//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_MIN_LENGTH 12
#define PASSWORD_MAX_LENGTH 20

void generate_random_number(int *num, int limit);
char generate_random_char(int is_digit, int is_special);
void generate_password(char *password);

int main() {
    char password[PASSWORD_MAX_LENGTH + 1];

    srand(time(NULL));
    generate_password(password);
    printf("Generated Password: %s\n", password);

    return 0;
}

void generate_random_number(int *num, int limit) {
    *num = rand() % limit;
}

char generate_random_char(int is_digit, int is_special) {
    char result;

    if (is_digit) {
        result = rand() % 10 + '0';
    } else if (is_special) {
        result = (rand() % 15) + '!';
    } else {
        result = rand() % 26 + 'a';
        if (rand() % 2)
            result += 26;
    }

    return result;
}

void generate_password(char *password) {
    int length = PASSWORD_MIN_LENGTH;
    int i;

    password[length] = '\0';

    for (i = 0; i < length; i++) {
        generate_random_char(0, 0), password[i] = generate_random_char(0, 0);
        if (i % 3 == 0)
            generate_random_char(1, 0), password[i] = generate_random_char(1, 0);
        if (i % 4 == 0)
            generate_random_number(&password[i], 10), password[i] += 48;
    }

    generate_random_char(0, 1), password[length++] = generate_random_char(0, 1);
    password[length++] = '\0';

    for (; length < PASSWORD_MAX_LENGTH; length++) {
        int rand_type = rand() % 3;

        switch (rand_type) {
            case 0:
                generate_random_char(0, 0), password[length] = generate_random_char(0, 0);
                break;
            case 1:
                generate_random_number(&password[length], 10), password[length] += 48;
                break;
            case 2:
                generate_random_char(1, 0), password[length] = generate_random_char(1, 0);
                break;
        }
    }
}