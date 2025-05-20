//FormAI DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_DATA_LENGTH 1000

/*
 * This program takes a filename and a password as input, reads the contents of the file,
 * encrypts the data using a simple XOR encryption algorithm with the password as the key,
 * and writes the encrypted data to a new file with a ".enc" extension.
 */

void encrypt_data(char* data, char* password, size_t data_length, size_t password_length)
{
    for (size_t i = 0; i < data_length; i++)
    {
        // XOR each byte of data with the corresponding byte of password
        data[i] ^= password[i % password_length];
    }
}

int main(int argc, char* argv[])
{
    char file_name[MAX_FILE_NAME_LENGTH];
    char password[MAX_FILE_NAME_LENGTH];
    char file_data[MAX_FILE_DATA_LENGTH];
    size_t data_length = 0;
    size_t password_length = 0;

    // Check for valid arguments
    if (argc != 3)
    {
        printf("Usage: %s <file_name> <password>\n", argv[0]);
        return 1;
    }
    strncpy(file_name, argv[1], MAX_FILE_NAME_LENGTH);
    strncpy(password, argv[2], MAX_FILE_NAME_LENGTH);
    password_length = strlen(password);

    // Open the input file for reading
    FILE* input_file = fopen(file_name, "r");
    if (input_file == NULL)
    {
        printf("Unable to open file: %s\n", file_name);
        return 1;
    }

    // Read the contents of the file into memory
    while (fgets(file_data + data_length, MAX_FILE_DATA_LENGTH - data_length, input_file))
    {
        data_length = strlen(file_data);
        if (data_length == MAX_FILE_DATA_LENGTH - 1)
        {
            printf("File is too large to encrypt\n");
            return 1;
        }
    }

    // Close the input file
    fclose(input_file);

    // Encrypt the data
    encrypt_data(file_data, password, data_length, password_length);

    // Create the output file name
    char output_file_name[MAX_FILE_NAME_LENGTH + 5]; // 5 for ".enc\0"
    snprintf(output_file_name, MAX_FILE_NAME_LENGTH + 5, "%s.enc", file_name);

    // Create the output file for writing
    FILE* output_file = fopen(output_file_name, "w");
    if (output_file == NULL)
    {
        printf("Unable to create output file: %s\n", output_file_name);
        return 1;
    }

    // Write the encrypted data to the output file
    fwrite(file_data, sizeof(char), data_length, output_file);

    // Close the output file
    fclose(output_file);

    printf("Encryption successful. Encrypted file: %s\n", output_file_name);
    return 0;
}