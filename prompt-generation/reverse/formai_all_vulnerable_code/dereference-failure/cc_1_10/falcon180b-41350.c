//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define PASSWORD_LENGTH 8

typedef struct {
    char *password;
    int length;
    int strength;
} password_t;

void *check_password_strength(void *arg) {
    password_t *password = (password_t *)arg;

    int lower = 0, upper = 0, digit = 0, special = 0;
    int length = strlen(password->password);

    for (int i = 0; i < length; i++) {
        if (isalnum(password->password[i])) {
            if (islower(password->password[i])) {
                lower = 1;
            } else if (isupper(password->password[i])) {
                upper = 1;
            }
        } else if (isdigit(password->password[i])) {
            digit = 1;
        } else {
            special = 1;
        }
    }

    password->strength = 0;

    if (length >= 12) {
        password->strength += 1;
    }

    if (lower && upper) {
        password->strength += 1;
    }

    if (digit || special) {
        password->strength += 1;
    }

    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_THREADS];
    password_t passwords[MAX_THREADS];

    srand(time(NULL));

    for (int i = 0; i < MAX_THREADS; i++) {
        passwords[i].password = (char *)malloc(PASSWORD_LENGTH + 1);
        for (int j = 0; j < PASSWORD_LENGTH; j++) {
            passwords[i].password[j] = rand() % 26 + 'a';
        }
        passwords[i].password[PASSWORD_LENGTH] = '\0';
        passwords[i].length = PASSWORD_LENGTH;

        pthread_create(&threads[i], NULL, check_password_strength, &passwords[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        printf("Password %d strength: %d\n", i + 1, passwords[i].strength);
        free(passwords[i].password);
    }

    return 0;
}