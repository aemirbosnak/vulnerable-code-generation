//FormAI DATASET v1.0 Category: Compression algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 10000

// Function prototypes
void compress(char *);
void decompress(char *);

int main()
{
    char input[MAX_SIZE];  // String to store user input

    printf("Welcome!\n");
    printf("Please enter a string to compress:\n");
    fgets(input, MAX_SIZE, stdin);

    compress(input);    // Call compress function

    printf("The compressed string is: \n");
    decompress(input);    // Call decompress function

    return 0;
}

void compress(char *input)
{
    char *output = malloc(MAX_SIZE * sizeof(char)); // Allocate memory for compressed string
    char *temp_str = malloc(11 * sizeof(char)); // Temporary string to store binary values
    int i, j, count, len;

    len = strlen(input); // Get length of input string
    count = 1; // Initialize count

    for (i = 0, j = 0; i < len; i++) {
        if (input[i] == input[i+1]) { // If next character is the same as current character
            count++; // Increment count
        }
        else { // If next character is different
            // Convert count to binary and store in temporary string
            sprintf(temp_str, "%011d", count);
            // Concatenate binary string with character to represent compressed value
            output[j++] = input[i];
            strcat(output, temp_str);
            count = 1; // Reset count
        }
    }

    output[j] = '\0'; // Add null terminator to end of compressed string
    strcpy(input, output); // Replace input string with compressed string
    free(output); // Deallocate memory for output string
    free(temp_str); // Deallocate memory for temporary string
}

void decompress(char *input)
{
    int i, j, len, count, binary;
    char *output = malloc(MAX_SIZE * sizeof(char)); // Allocate memory for output string
    char bin_str[12]; // Temporary string to store binary values

    len = strlen(input); // Get length of compressed string

    for (i = 0, j = 0; i < len; i++) {
        // Check if current character is a letter
        if ((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122)) {
            // Add letter to output string
            output[j++] = input[i];
        }
        else { // If current character is a number (i.e. binary value)
            // Convert binary value from string to integer
            strncpy(bin_str, input+i, 11);
            bin_str[11] = '\0';
            binary = atoi(bin_str);
            // Get count value from binary value
            count = 0;
            for (int k = 0; k < 11; k++) {
                if (binary & (int) pow(2, k))
                    count++;
            }
            // Add count number of letters to output string
            for (int k = 0; k < count; k++) {
                output[j++] = input[i-1];
            }
            i += 10; // Increment i to skip binary value in input string
        }
    }

    printf("%s\n", output); // Print decompressed string
    free(output); // Deallocate memory for output string
}