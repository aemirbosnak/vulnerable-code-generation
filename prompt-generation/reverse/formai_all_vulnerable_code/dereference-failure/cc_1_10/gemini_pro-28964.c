//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the hash value of a string
unsigned int hash(char *str) {
    unsigned int h = 0;
    while (*str) {
        h = (h << 5) - h + *str++;
    }
    return h;
}

// Function to generate a random string of length n
char *generate_random_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to test the hash function
void test_hash() {
    // Generate a random string of length 100
    char *str1 = generate_random_string(100);

    // Calculate the hash value of the string
    unsigned int h1 = hash(str1);

    // Print the hash value
    printf("Hash value of '%s': %u\n", str1, h1);

    // Generate another random string of length 100
    char *str2 = generate_random_string(100);

    // Calculate the hash value of the second string
    unsigned int h2 = hash(str2);

    // Print the hash value
    printf("Hash value of '%s': %u\n", str2, h2);

    // Check if the hash values are different
    if (h1 != h2) {
        printf("The hash values are different, which is correct because the strings are different.\n");
    } else {
        printf("The hash values are the same, which is incorrect because the strings are different.\n");
    }

    // Free the allocated memory
    free(str1);
    free(str2);
}

int main() {
    // Test the hash function
    test_hash();

    return 0;
}