//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int has_digits(char* password); // helper function to check if password contains digits
int has_symbols(char* password); // helper function to check if password contains symbols
int has_uppercase(char* password); // helper function to check if password contains uppercase letters

struct ThreadArgs {
    char* password;
    int* result;
};

void* check_password_strength(void* args) {
    struct ThreadArgs* targs = (struct ThreadArgs*) args;
    int strength = 0;
    
    if (strlen(targs->password) < 8) {
        strength = 0;
    } else if (has_digits(targs->password) && has_symbols(targs->password) && has_uppercase(targs->password)) {
        strength = 3;
    } else if (has_digits(targs->password) && has_symbols(targs->password)) {
        strength = 2;
    } else if (has_digits(targs->password) || has_symbols(targs->password)) {
        strength = 1;
    }
    
    *targs->result = strength;

    free(targs->password);
    free(targs);

    return NULL;
}

int main() {
    char input[100];
    pthread_t thread_ids[10];
    int results[10];
    int i, count;

    printf("Enter up to 10 passwords to check their strength. Enter 'done' to exit.\n");

    while (1) {
        printf("Password: ");
        fgets(input, 100, stdin);

        if (strcmp(input, "done\n") == 0) {
            break;
        }

        if (count >= 10) {
            printf("Maximum number of passwords exceeded.\n");
            break;
        }

        char* password = (char*) malloc(strlen(input) + 1);
        strcpy(password, input);

        struct ThreadArgs* targs = (struct ThreadArgs*) malloc(sizeof(struct ThreadArgs));
        targs->password = password;
        targs->result = &results[count];

        pthread_create(&thread_ids[count], NULL, check_password_strength, targs);

        count++;
    }

    printf("\nResults:\n");

    for (i = 0; i < count; i++) {
        pthread_join(thread_ids[i], NULL);

        if (results[i] == 0) {
            printf("Weak password\n");
        } else if (results[i] == 1) {
            printf("Moderate password\n");
        } else if (results[i] == 2) {
            printf("Strong password\n");
        } else if (results[i] == 3) {
            printf("Very strong password\n");
        }
    }

    return 0;
}

int has_digits(char* password) {
    int i;
    for (i = 0; password[i] != '\0'; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            return 1;
        }
    }

    return 0;
}

int has_symbols(char* password) {
    int i;
    for (i = 0; password[i] != '\0'; i++) {
        if (password[i] < 'A' || (password[i] > 'Z' && password[i] < 'a') || password[i] > 'z') {
            return 1;
        }
    }

    return 0;
}

int has_uppercase(char* password) {
    int i;
    for (i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return 1;
        }
    }

    return 0;
}