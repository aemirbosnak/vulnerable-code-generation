//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the file
void encrypt_file(const char *filename, const char *key)
{
    FILE *file;
    char buffer[256];

    file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    int key_length = strlen(key);
    int shift = key_length % 26; // Calculate the shift value to apply to the ASCII values
    printf("Shift value: %d\n", shift);

    // Iterate through each character in the file
    while (fread(buffer, sizeof(char), 256, file))
    {
        // Get the ASCII value of the character
        int ascii = (int)buffer[0];

        // Apply the shift value to the ASCII value
        ascii += shift;

        // If the ASCII value exceeds 'Z' (90), wrap it back to 'A' (65)
        if (ascii > 90)
            ascii -= 26;

        // Convert the ASCII value back to a character and store it in the buffer
        buffer[0] = (char)ascii;

        // Write the encrypted character to the output file
        fwrite(buffer, sizeof(char), 1, stdout);
    }

    // Close the file
    fclose(file);
}

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        printf("Usage: %s <filename> <key>\n", argv[0]);
        return 1;
    }

    encrypt_file(argv[1], argv[2]);

    return 0;
}