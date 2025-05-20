//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to hash the input string
int hash(char *str) {
    int len = strlen(str);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += str[i];
    }
    return sum;
}

// Function to generate a random salt
void generate_salt(char *salt, int length) {
    for (int i = 0; i < length; i++) {
        salt[i] = (char)(rand() % 26 + 'a');
    }
    salt[length] = '\0';
}

// Function to hash the input string with a given salt
int hash_with_salt(char *str, char *salt) {
    int len = strlen(str);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += str[i] + salt[i % strlen(salt)];
    }
    return sum;
}

int main() {
    char input[100];
    char salt[10];
    int length;

    printf("Enter the length of the salt: ");
    scanf("%d", &length);

    generate_salt(salt, length);

    printf("Enter the input string: ");
    scanf("%s", input);

    int hash_value = hash(input);
    int salted_hash = hash_with_salt(input, salt);

    printf("Hash value: %d\n", hash_value);
    printf("Salted hash: %d\n", salted_hash);

    return 0;
}