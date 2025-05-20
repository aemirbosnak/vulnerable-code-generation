//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the checksum of a given string
unsigned int checksum(char *str) {
    unsigned int sum = 0;
    int i;

    // Iterate over the string and add the ASCII values of each character to the sum
    for (i = 0; str[i] != '\0'; i++) {
        sum += str[i];
    }

    // Return the sum modulo 256
    return sum % 256;
}

// Function to generate a random string of a given length
char *random_string(int length) {
    char *str = malloc(length + 1);
    int i;

    // Iterate over the string and generate a random character for each position
    for (i = 0; i < length; i++) {
        str[i] = rand() % 256;
    }

    // Null-terminate the string
    str[length] = '\0';

    // Return the string
    return str;
}

// Main function
int main() {
    // Generate a random string of length 10
    char *str = random_string(10);

    // Calculate the checksum of the string
    unsigned int checksum_value = checksum(str);

    // Print the string and its checksum
    printf("String: %s\n", str);
    printf("Checksum: %u\n", checksum_value);

    // Free the memory allocated for the string
    free(str);

    return 0;
}