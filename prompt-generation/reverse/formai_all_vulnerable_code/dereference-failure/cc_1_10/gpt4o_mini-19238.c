//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/sha.h>

#define BUFFER_SIZE 1024
#define SUCCESS 0
#define FAILURE -1

void print_hash(unsigned char *hash)
{
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int hash_file(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        perror("Failed to open file");
        return FAILURE;
    }

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)))
    {
        SHA256_Update(&sha256, buffer, bytes_read);
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &sha256);
    fclose(file);

    printf("SHA256 hash of %s: ", filename);
    print_hash(hash);
    
    return SUCCESS;
}

char *read_input()
{
    char *input = (char *)malloc(BUFFER_SIZE);
    if (fgets(input, BUFFER_SIZE, stdin) == NULL)
    {
        free(input);
        return NULL;
    }
    input[strcspn(input, "\n")] = 0; // Remove newline character
    return input;
}

void encrypt(char *input, char *key)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        input[i] = input[i] ^ key[i % strlen(key)];
    }

    printf("Encrypted text: %s\n", input);
}

void decrypt(char *input, char *key)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        input[i] = input[i] ^ key[i % strlen(key)];
    }

    printf("Decrypted text: %s\n", input);
}

void menu()
{
    printf("Cryptography Program Menu:\n");
    printf("1. Hash a file (SHA-256)\n");
    printf("2. Encrypt a message\n");
    printf("3. Decrypt a message\n");
    printf("4. Exit\n");
}

int main()
{
    int choice;
    char *input = NULL;
    char *key = NULL;

    while (1)
    {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice)
        {
            case 1:
                input = read_input();
                if (input)
                {
                    hash_file(input);
                    free(input);
                }
                break;
            case 2:
                printf("Enter the message to encrypt: ");
                input = read_input();
                printf("Enter the encryption key: ");
                key = read_input();
                if (input && key)
                {
                    encrypt(input, key);
                    free(input);
                    free(key);
                }
                break;
            case 3:
                printf("Enter the message to decrypt: ");
                input = read_input();
                printf("Enter the decryption key: ");
                key = read_input();
                if (input && key)
                {
                    decrypt(input, key);
                    free(input);
                    free(key);
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid option, try again.\n");
        }
    }

    return 0;
}