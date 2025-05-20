//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file using XOR encryption
void encrypt_file(FILE *input_file, FILE *output_file, unsigned char *key, int key_size)
{
    // Read the input file byte by byte
    unsigned char input_byte;
    while (fread(&input_byte, sizeof(unsigned char), 1, input_file))
    {
        // Encrypt the input byte using XOR operation with the key
        unsigned char encrypted_byte = input_byte ^ key[0];

        // Update the key using a rolling cipher (rotating the key by one)
        for (int i = 0; i < key_size - 1; i++)
        {
            key[i] = key[i + 1];
        }
        key[key_size - 1] = encrypted_byte;

        // Write the encrypted byte to the output file
        fwrite(&encrypted_byte, sizeof(unsigned char), 1, output_file);
    }
}

// Function to decrypt a file using XOR encryption
void decrypt_file(FILE *input_file, FILE *output_file, unsigned char *key, int key_size)
{
    // Read the encrypted file byte by byte
    unsigned char encrypted_byte;
    while (fread(&encrypted_byte, sizeof(unsigned char), 1, input_file))
    {
        // Decrypt the encrypted byte using XOR operation with the key
        unsigned char decrypted_byte = encrypted_byte ^ key[0];

        // Update the key using a rolling cipher (rotating the key by one)
        for (int i = 0; i < key_size - 1; i++)
        {
            key[i] = key[i + 1];
        }
        key[key_size - 1] = decrypted_byte;

        // Write the decrypted byte to the output file
        fwrite(&decrypted_byte, sizeof(unsigned char), 1, output_file);
    }
}

// Function to generate a random key of specified size
void generate_random_key(unsigned char *key, int key_size)
{
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random key byte by byte
    for (int i = 0; i < key_size; i++)
    {
        key[i] = rand() % 256;
    }
}

// Function to print the usage of the program
void print_usage()
{
    printf("Usage: file_encryptor [operation] [input_file] [output_file] [key_size]\n");
    printf("Operations:\n");
    printf("  -e: Encrypt a file\n");
    printf("  -d: Decrypt a file\n");
    printf("  -g: Generate a random key\n");
}

int main(int argc, char *argv[])
{
    // Check if there are enough arguments
    if (argc < 5)
    {
        print_usage();
        return EXIT_FAILURE;
    }

    // Get the operation (encrypt/decrypt/generate key)
    char *operation = argv[1];

    // Get the input and output file names
    char *input_file_name = argv[2];
    char *output_file_name = argv[3];

    // Get the key size
    int key_size = atoi(argv[4]);

    // Validate the key size
    if (key_size <= 0)
    {
        printf("Invalid key size: %d\n", key_size);
        return EXIT_FAILURE;
    }

    // Generate a random key if necessary
    unsigned char key[key_size];
    if (strcmp(operation, "-g") == 0)
    {
        generate_random_key(key, key_size);
        printf("Generated random key: ");
        for (int i = 0; i < key_size; i++)
        {
            printf("%02X", key[i]);
        }
        printf("\n");
        return EXIT_SUCCESS;
    }

    // Open the input and output files
    FILE *input_file = fopen(input_file_name, "rb");
    if (input_file == NULL)
    {
        printf("Error opening input file: %s\n", input_file_name);
        return EXIT_FAILURE;
    }
    FILE *output_file = fopen(output_file_name, "wb");
    if (output_file == NULL)
    {
        printf("Error opening output file: %s\n", output_file_name);
        fclose(input_file);
        return EXIT_FAILURE;
    }

    // Perform the encryption/decryption operation
    if (strcmp(operation, "-e") == 0)
    {
        // Get the key from the user
        printf("Enter the encryption key: ");
        for (int i = 0; i < key_size; i++)
        {
            scanf("%hhX", &key[i]);
        }
        encrypt_file(input_file, output_file, key, key_size);
        printf("File encrypted successfully.\n");
    }
    else if (strcmp(operation, "-d") == 0)
    {
        // Get the key from the user
        printf("Enter the decryption key: ");
        for (int i = 0; i < key_size; i++)
        {
            scanf("%hhX", &key[i]);
        }
        decrypt_file(input_file, output_file, key, key_size);
        printf("File decrypted successfully.\n");
    }
    else
    {
        print_usage();
        fclose(input_file);
        fclose(output_file);
        return EXIT_FAILURE;
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}