//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum of a string
unsigned int checksum(const char *str)
{
    unsigned int sum = 0;
    while (*str)
    {
        sum += *str++;
    }
    return sum;
}

// Function to check if a checksum is valid
int checksum_valid(const char *str)
{
    unsigned int sum = 0;
    while (*str)
    {
        sum += *str++;
    }
    return (sum % 256) == 0;
}

// Main function
int main(int argc, char **argv)
{
    // Check if the user has provided a string
    if (argc < 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Calculate the checksum of the string
    unsigned int checksum_value = checksum(argv[1]);

    // Print the checksum
    printf("Checksum: %u\n", checksum_value);

    // Check if the checksum is valid
    if (checksum_valid(argv[1]))
    {
        printf("Checksum is valid.\n");
    }
    else
    {
        printf("Checksum is not valid.\n");
    }

    return EXIT_SUCCESS;
}