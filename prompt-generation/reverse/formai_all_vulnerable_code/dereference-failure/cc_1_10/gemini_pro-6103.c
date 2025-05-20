//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hash function
unsigned int hash(const char *str) {
    unsigned int h = 0;
    while (*str) {
        h = (h << 5) - h + *str++;
    }
    return h;
}

// Generate a random string
char *random_string(int length) {
    char *str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[length] = '\0';
    return str;
}

// Generate a histogram of hash values
int main() {
    // Set the number of random strings to generate
    int num_strings = 100000;

    // Set the length of the random strings
    int string_length = 10;

    // Generate the random strings
    char **strings = malloc(num_strings * sizeof(char *));
    for (int i = 0; i < num_strings; i++) {
        strings[i] = random_string(string_length);
    }

    // Compute the hash values of the random strings
    unsigned int *hashes = malloc(num_strings * sizeof(unsigned int));
    for (int i = 0; i < num_strings; i++) {
        hashes[i] = hash(strings[i]);
    }

    // Generate the histogram
    int histogram[65536];
    memset(histogram, 0, sizeof(histogram));
    for (int i = 0; i < num_strings; i++) {
        histogram[hashes[i]]++;
    }

    // Print the histogram
    for (int i = 0; i < 65536; i++) {
        printf("%d\t%d\n", i, histogram[i]);
    }

    // Free the memory
    for (int i = 0; i < num_strings; i++) {
        free(strings[i]);
    }
    free(strings);
    free(hashes);

    return 0;
}