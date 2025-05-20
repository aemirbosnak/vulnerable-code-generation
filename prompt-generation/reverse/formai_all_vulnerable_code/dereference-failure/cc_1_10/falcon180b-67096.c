//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to calculate the checksum of a given string
int calculateChecksum(char* str) {
    int sum = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        sum += str[i];
    }
    return sum;
}

// Function to validate the checksum of a given string
int validateChecksum(char* str, int checksum) {
    int sum = calculateChecksum(str);
    return sum == checksum;
}

// Function to generate a random string of given length
char* generateRandomString(int length) {
    char* result = (char*) malloc(length + 1);
    if (result == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    for (int i = 0; i < length; i++) {
        result[i] = rand() % 26 + 'a';
    }
    result[length] = '\0';
    return result;
}

// Function to read a string from user input
char* readString(char* prompt) {
    printf("%s", prompt);
    char* result = (char*) malloc(MAX_SIZE);
    if (result == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    fgets(result, MAX_SIZE, stdin);
    result[strcspn(result, "\n")] = '\0';
    return result;
}

int main() {
    printf("Welcome to the C Checksum Calculator!\n");
    printf("------------------------------------\n");

    // Generate a random string
    char* str = generateRandomString(10);
    printf("Random string: %s\n", str);

    // Calculate the checksum of the string
    int checksum = calculateChecksum(str);
    printf("Checksum: %d\n", checksum);

    // Read a string from user input
    char* userStr = readString("Enter a string: ");

    // Calculate the checksum of the user string
    int userChecksum = calculateChecksum(userStr);
    printf("User checksum: %d\n", userChecksum);

    // Validate the checksum of the user string
    if (validateChecksum(userStr, userChecksum)) {
        printf("Valid checksum!\n");
    } else {
        printf("Invalid checksum!\n");
    }

    return 0;
}