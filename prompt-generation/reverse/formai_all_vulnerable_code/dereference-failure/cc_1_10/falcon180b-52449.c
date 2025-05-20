//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define HASH_LENGTH 64

// Function to convert a string to uppercase
void to_uppercase(char *str) {
    int i = 0;
    while (str[i]!= '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to generate a random string of a given length
char *generate_random_string(int length) {
    char *str = malloc(length + 1);
    if (!str) {
        printf("Error: Could not allocate memory\n");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'A';
    }
    str[length] = '\0';
    return str;
}

// Function to calculate the hash of a string
char *calculate_hash(char *input) {
    char *hash = malloc(HASH_LENGTH + 1);
    if (!hash) {
        printf("Error: Could not allocate memory\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (i < strlen(input)) {
        hash[i] = input[i] ^ input[i + 1];
        i += 2;
    }
    hash[i] = '\0';
    return hash;
}

// Function to check if two strings are equal
bool strings_equal(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1!= len2) {
        return false;
    }
    for (int i = 0; i < len1; i++) {
        if (str1[i]!= str2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    // Generate a random string
    char *input = generate_random_string(10);

    // Convert the string to uppercase
    to_uppercase(input);

    // Calculate the hash of the string
    char *hash = calculate_hash(input);

    // Print the input string and its hash
    printf("Input string: %s\n", input);
    printf("Hash of input string: %s\n", hash);

    // Check if the hash is correct
    if (!strings_equal(input, hash)) {
        printf("Error: The hash is incorrect!\n");
    } else {
        printf("The hash is correct!\n");
    }

    free(input);
    free(hash);
    return 0;
}