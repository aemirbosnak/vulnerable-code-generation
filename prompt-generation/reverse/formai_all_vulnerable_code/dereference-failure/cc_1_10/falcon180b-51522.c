//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to calculate the checksum of a given string
int calculate_checksum(char *str) {
    int sum = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        sum += (int) str[i];
    }
    return sum % 256;
}

// Function to validate the checksum of a given string
int validate_checksum(char *str) {
    int sum = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        sum += (int) str[i];
    }
    return (sum % 256) == 0;
}

// Function to read a string from the user
char *read_string(char *prompt) {
    char *str = malloc(MAX_LENGTH);
    printf("%s", prompt);
    fgets(str, MAX_LENGTH, stdin);
    return str;
}

int main() {
    char *input_str;
    char *output_str;

    // Read the input string from the user
    input_str = read_string("Enter the input string: ");

    // Calculate the checksum of the input string
    int checksum = calculate_checksum(input_str);

    // Append the checksum to the end of the input string
    output_str = malloc(strlen(input_str) + 2);
    strcpy(output_str, input_str);
    sprintf(output_str + strlen(input_str), "%02X", checksum);

    // Print the input string and its checksum
    printf("Input string: %s\n", input_str);
    printf("Checksum: %02X\n", checksum);

    // Validate the checksum of the input string
    if (validate_checksum(output_str)) {
        printf("Checksum is valid.\n");
    } else {
        printf("Checksum is invalid.\n");
    }

    // Free the allocated memory
    free(input_str);
    free(output_str);

    return 0;
}