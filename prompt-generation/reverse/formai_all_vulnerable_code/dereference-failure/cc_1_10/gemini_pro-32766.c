//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum of a string
unsigned long long int checksum(const char *str) {
    unsigned long long int sum = 0;
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        sum += str[i];
    }
    return sum;
}

// Function to check if the checksum of a string is valid
int checksum_valid(const char *str) {
    unsigned long long int sum = checksum(str);
    size_t len = strlen(str);
    return (sum % len == 0);
}

// Function to generate a checksum for a string
char *generate_checksum(const char *str) {
    unsigned long long int sum = checksum(str);
    char *checksum = malloc(sizeof(char) * 11);
    sprintf(checksum, "%010llu", sum);
    return checksum;
}

// Function to add a checksum to a string
char *add_checksum(const char *str) {
    char *checksum = generate_checksum(str);
    size_t len = strlen(str);
    char *new_str = malloc(sizeof(char) * (len + 11));
    strcpy(new_str, str);
    strcat(new_str, checksum);
    free(checksum);
    return new_str;
}

// Function to remove the checksum from a string
char *remove_checksum(const char *str) {
    size_t len = strlen(str);
    char *new_str = malloc(sizeof(char) * (len - 10));
    strncpy(new_str, str, len - 10);
    new_str[len - 10] = '\0';
    return new_str;
}

// Function to test the checksum functions
int main() {
    // Test string
    const char *str = "Hello, world!";

    // Calculate the checksum of the string
    unsigned long long int sum = checksum(str);
    printf("Checksum: %llu\n", sum);

    // Check if the checksum is valid
    int valid = checksum_valid(str);
    printf("Checksum valid: %s\n", valid ? "true" : "false");

    // Generate a checksum for the string
    char *checksum = generate_checksum(str);
    printf("Generated checksum: %s\n", checksum);

    // Add the checksum to the string
    char *new_str = add_checksum(str);
    printf("String with checksum: %s\n", new_str);

    // Remove the checksum from the string
    char *original_str = remove_checksum(new_str);
    printf("Original string: %s\n", original_str);

    // Free the allocated memory
    free(checksum);
    free(new_str);
    free(original_str);

    return 0;
}