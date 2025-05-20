//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to calculate the checksum of a given string */
int calculate_checksum(char *str) {
    int sum = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        sum += str[i];
    }
    return sum;
}

/* Function to check if the checksum of a given string is valid */
int is_valid_checksum(char *str) {
    int sum = 0;
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        sum += str[i];
    }
    return (sum % 10 == str[len - 1] - '0');
}

/* Function to generate a random string with a given length */
char *generate_random_string(int length) {
    char *str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = rand() % 10 + '0';
    }
    str[length] = '\0';
    return str;
}

/* Function to print a given string */
void print_string(char *str) {
    printf("%s\n", str);
}

/* Main function */
int main() {
    int length = 10; // Length of the string to be generated
    char *str = generate_random_string(length); // Generate a random string
    int checksum = calculate_checksum(str); // Calculate the checksum of the string
    int valid_checksum = is_valid_checksum(str); // Check if the checksum is valid
    if (valid_checksum) {
        printf("Checksum is valid.\n");
    } else {
        printf("Checksum is invalid.\n");
    }
    print_string(str); // Print the string
    return 0;
}