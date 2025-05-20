//FormAI DATASET v1.0 Category: Modern Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define ALPHABET_SIZE 26
#define MAX_KEY_LENGTH 32
#define MAX_FILE_SIZE 10000

char* read_file(char* filename);

char* generate_key();

void encryption(char* message, char* key);

void decryption(char* message, char* key);

int main(int argc, char* argv[])
{
    srand(time(NULL));

    if (argc != 3)
    {
        printf("Usage: ./encryption [1 for encrypt or 0 for decrypt] [filename]\n");
        return 1;
    }

    int enc_dec_flag = atoi(argv[1]);
    char* filename = argv[2];

    if (enc_dec_flag != 0 && enc_dec_flag != 1)
    {
        printf("Invalid flag\n");
        return 1;
    }

    char* message = read_file(filename);
    if (!message)
    {
        printf("Error reading file\n");
        return 1;
    }

    char* key = generate_key();
    printf("Key: %s\n", key);

    if (enc_dec_flag == 1)
    {
        encryption(message, key);
        printf("Encryption complete\n");
    }
    else
    {
        decryption(message, key);
        printf("Decryption complete\n");
    }

    free(message);
    free(key);
    return 0;
}

char* read_file(char* filename)
{
    FILE* file = fopen(filename, "r");
    if (!file)
    {
        printf("Error opening file\n");
        return NULL;
    }

    char* buffer = (char*)malloc(sizeof(char) * MAX_FILE_SIZE);
    if (!buffer)
    {
        printf("Error allocating memory\n");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (file_size > MAX_FILE_SIZE)
    {
        printf("File too large\n");
        return NULL;
    }

    fread(buffer, sizeof(char), file_size, file);
    fclose(file);

    return buffer;
}

char* generate_key()
{
    char* key = (char*)malloc(sizeof(char) * MAX_KEY_LENGTH);
    if (!key)
    {
        printf("Error allocating memory\n");
        return NULL;
    }

    for (int i = 0; i < MAX_KEY_LENGTH - 1; i++)
    {
        key[i] = 'a' + rand() % ALPHABET_SIZE;
    }

    key[MAX_KEY_LENGTH - 1] = '\0';
    return key;
}

void encryption(char* message, char* key)
{
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++)
    {
        if (isalpha(message[i]))
        {
            int shift = key[i % key_length] - 'a';
            if (isupper(message[i]))
            {
                message[i] = ((message[i] - 'A' + shift) % 26) + 'A';
            }
            else
            {
                message[i] = ((message[i] - 'a' + shift) % 26) + 'a';
            }
        }
    }

    FILE* file = fopen("encrypted.txt", "w");
    fwrite(message, sizeof(char), message_length, file);
    fclose(file);
}

void decryption(char* message, char* key)
{
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++)
    {
        if (isalpha(message[i]))
        {
            int shift = key[i % key_length] - 'a';
            if (isupper(message[i]))
            {
                message[i] = ((message[i] - 'A' - shift + 26) % 26) + 'A';
            }
            else
            {
                message[i] = ((message[i] - 'a' - shift + 26) % 26) + 'a';
            }
        }
    }

    FILE* file = fopen("decrypted.txt", "w");
    fwrite(message, sizeof(char), message_length, file);
    fclose(file);
}