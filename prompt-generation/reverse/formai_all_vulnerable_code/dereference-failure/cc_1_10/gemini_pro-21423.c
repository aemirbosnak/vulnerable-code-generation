//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum of a string
unsigned short calculate_checksum(const char *str, size_t len)
{
    unsigned short checksum = 0;
    for (size_t i = 0; i < len; i++)
    {
        checksum += (unsigned char)str[i];
    }
    return checksum;
}

// Function to check if the checksum of a string is valid
int is_checksum_valid(const char *str, size_t len)
{
    unsigned short checksum = 0;
    for (size_t i = 0; i < len - 1; i++)
    {
        checksum += (unsigned char)str[i];
    }
    return checksum == (unsigned char)str[len - 1];
}

// Main function
int main(int argc, char **argv)
{
    // Check if the user has entered a string
    if (argc < 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the string from the user
    char *str = argv[1];

    // Calculate the length of the string
    size_t len = strlen(str);

    // Calculate the checksum of the string
    unsigned short checksum = calculate_checksum(str, len);

    // Print the checksum of the string
    printf("Checksum: %u\n", checksum);

    // Check if the checksum of the string is valid
    if (is_checksum_valid(str, len))
    {
        printf("Checksum is valid.\n");
    }
    else
    {
        printf("Checksum is invalid.\n");
    }

    return EXIT_SUCCESS;
}