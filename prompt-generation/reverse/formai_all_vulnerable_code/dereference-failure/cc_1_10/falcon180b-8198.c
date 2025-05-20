//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to calculate the checksum of a given string
unsigned short calc_checksum(char *str) {
    unsigned short sum = 0;
    int i;

    for (i = 0; i < strlen(str); i++) {
        sum += (unsigned char) str[i];
    }

    return sum;
}

// Function to validate the checksum of a given string
int validate_checksum(char *str) {
    unsigned short calc_sum = calc_checksum(str);
    unsigned short given_sum = 0;

    // Extract the last two characters from the string
    char checksum_str[3];
    strncpy(checksum_str, str + strlen(str) - 2, 3);

    // Convert the checksum string to an integer
    sscanf(checksum_str, "%2hhx", &given_sum);

    return (calc_sum == given_sum);
}

int main() {
    char input_str[MAX_SIZE];
    printf("Enter a string (maximum %d characters): ", MAX_SIZE - 1);
    fgets(input_str, MAX_SIZE, stdin);

    // Remove the newline character from the input string
    input_str[strcspn(input_str, "\n")] = '\0';

    unsigned short calc_sum = calc_checksum(input_str);
    char checksum_str[3];
    sprintf(checksum_str, "%02x", calc_sum);

    // Append the checksum to the input string
    strcat(input_str, checksum_str);

    // Print the input string with the checksum
    printf("Input string with checksum: %s\n", input_str);

    // Validate the checksum
    if (validate_checksum(input_str)) {
        printf("Checksum is valid.\n");
    } else {
        printf("Checksum is invalid.\n");
    }

    return 0;
}