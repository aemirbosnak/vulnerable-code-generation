//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100
#define NUM_THREADS 4

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int thread_id;
    int strength;
} PasswordCheck;

void *check_length(void *arg) {
    PasswordCheck *pw_check = (PasswordCheck *)arg;
    int len = strlen(pw_check->password);
    if (len >= 8) {
        pw_check->strength += 1; // Increase strength for length
    }
    pthread_exit(NULL);
}

void *check_uppercase(void *arg) {
    PasswordCheck *pw_check = (PasswordCheck *)arg;
    for (int i = 0; pw_check->password[i]; i++) {
        if (isupper(pw_check->password[i])) {
            pw_check->strength += 1; // Increase strength for uppercase
            break;
        }
    }
    pthread_exit(NULL);
}

void *check_lowercase(void *arg) {
    PasswordCheck *pw_check = (PasswordCheck *)arg;
    for (int i = 0; pw_check->password[i]; i++) {
        if (islower(pw_check->password[i])) {
            pw_check->strength += 1; // Increase strength for lowercase
            break;
        }
    }
    pthread_exit(NULL);
}

void *check_digits(void *arg) {
    PasswordCheck *pw_check = (PasswordCheck *)arg;
    for (int i = 0; pw_check->password[i]; i++) {
        if (isdigit(pw_check->password[i])) {
            pw_check->strength += 1; // Increase strength for digits
            break;
        }
    }
    pthread_exit(NULL);
}

void *check_special_characters(void *arg) {
    PasswordCheck *pw_check = (PasswordCheck *)arg;
    const char *special_chars = "!@#$%^&*()-_=+{}[]|:;\"'<>,.?/";
    for (int i = 0; pw_check->password[i]; i++) {
        if (strchr(special_chars, pw_check->password[i])) {
            pw_check->strength += 1; // Increase strength for special characters
            break;
        }
    }
    pthread_exit(NULL);
}

void evaluate_strength(int strength) {
    switch (strength) {
        case 5:
            printf("Your password is very strong!\n");
            break;
        case 4:
            printf("Your password is strong.\n");
            break;
        case 3:
            printf("Your password is medium.\n");
            break;
        case 2:
            printf("Your password is weak.\n");
            break;
        case 1:
        case 0:
            printf("Your password is very weak. Consider changing it!\n");
            break;
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    PasswordCheck pw_check;

    printf("Enter your password: ");
    fgets(pw_check.password, MAX_PASSWORD_LENGTH, stdin);
    pw_check.password[strcspn(pw_check.password, "\n")] = 0; // Remove newline
    pw_check.strength = 0;

    pthread_create(&threads[0], NULL, check_length, (void *)&pw_check);
    pthread_create(&threads[1], NULL, check_uppercase, (void *)&pw_check);
    pthread_create(&threads[2], NULL, check_lowercase, (void *)&pw_check);
    pthread_create(&threads[3], NULL, check_digits, (void *)&pw_check);
    pthread_create(&threads[4], NULL, check_special_characters, (void *)&pw_check);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    evaluate_strength(pw_check.strength);
    return 0;
}