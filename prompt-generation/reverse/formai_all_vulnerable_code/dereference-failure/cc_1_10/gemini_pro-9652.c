//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the checksum of a given string
unsigned long calculate_checksum(const char *str) {
    unsigned long checksum = 0;
    int i;

    for (i = 0; i < strlen(str); i++) {
        checksum += str[i];
    }

    return checksum;
}

// Generate a random string of a given length
char *generate_random_string(int length) {
    char *str = malloc(length + 1);
    int i;

    for (i = 0; i < length; i++) {
        str[i] = 'a' + (rand() % 26);
    }

    str[length] = '\0';

    return str;
}

// Test the checksum calculator
int main() {
    int i, j;
    char *str;

    // Calculate the checksums of 1000 random strings
    for (i = 0; i < 1000; i++) {
        str = generate_random_string(100);
        printf("String: %s\n", str);
        printf("Checksum: %lu\n\n", calculate_checksum(str));
        free(str);
    }

    // Calculate the checksums of 1000 strings of increasing length
    for (j = 1; j <= 1000; j++) {
        str = generate_random_string(j);
        printf("String: %s\n", str);
        printf("Checksum: %lu\n\n", calculate_checksum(str));
        free(str);
    }

    return 0;
}