//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define CHAR_SET_SIZE 6

const char *char_sets[CHAR_SET_SIZE] = {
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|\\:;\"<>,.?/~`",
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

void generate_password(int length, const char *char_set) {
    char password[length + 1];
    int i, random_index;

    srand(time(NULL));

    for (i = 0; i < length; i++) {
        random_index = rand() % strlen(char_set);
        password[i] = char_set[random_index];
    }

    password[length] = '\0';

    printf("%s\n", password);
}

int main() {
    int length, num_passwords;
    int i;

    printf("Enter password length (min %d, max %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid password length. Exiting...\n");
        return 1;
    }

    printf("Enter number of passwords to generate: ");
    scanf("%d", &num_passwords);

    printf("\nGenerated passwords:\n");

    for (i = 0; i < num_passwords; i++) {
        int random_char_set_index = rand() % CHAR_SET_SIZE;
        generate_password(length, char_sets[random_char_set_index]);
    }

    return 0;
}