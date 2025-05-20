//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read phone numbers from input
void read_phone_numbers(char **phone_numbers, int *count) {
    // Open file for reading
    FILE *file = fopen("phone_numbers.txt", "r");

    // Read line by line
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Split line into individual numbers
        char *numbers[8];
        int i;
        for (i = 0; i < 8; i++) {
            char *token = strtok(line, " ");
            if (token!= NULL) {
                numbers[i] = token;
            } else {
                break;
            }
        }

        // Check if all 8 numbers were found
        if (i!= 8) {
            continue;
        }

        // Add phone number to array
        (*phone_numbers) = (char **)realloc(*phone_numbers, (sizeof(char **) * (*count + 1)));
        (*phone_numbers)[*count] = (char *)malloc(8 * sizeof(char));
        strcpy((*phone_numbers)[*count], line);

        // Increment count
        (*count)++;
    }

    // Close file
    fclose(file);
}

// Function to display phone numbers
void display_phone_numbers(char **phone_numbers, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\n", phone_numbers[i]);
    }
}

int main() {
    // Create array to store phone numbers
    char **phone_numbers = NULL;
    int count = 0;

    // Read phone numbers from file
    read_phone_numbers(&phone_numbers, &count);

    // Display phone numbers
    display_phone_numbers(phone_numbers, count);

    // Free memory
    for (int i = 0; i < count; i++) {
        free(phone_numbers[i]);
    }
    free(phone_numbers);

    return 0;
}