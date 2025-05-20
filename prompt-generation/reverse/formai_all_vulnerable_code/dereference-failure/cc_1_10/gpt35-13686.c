//FormAI DATASET v1.0 Category: File Encyptor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 4 // arbitrary, but fixed length
#define MAX_FILE_SIZE 100000 // maximum size of the file to be encrypted

void encrypt(char* input_file_name, char* output_file_name, char* key);
void decrypt(char* input_file_name, char* output_file_name, char* key);
char* read_file(char* file_name, long *file_size);
void write_file(char* file_name, char* file_content, long file_size);

int main()
{
    char input_file_name[100], output_file_name[100], key[KEY_LENGTH];
    int option;
    
    printf("C File Encryptor\n");
    printf("=================\n\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("Enter option (1 or 2): ");
    scanf("%d", &option);

    printf("Enter input file name: ");
    scanf("%s", input_file_name);

    printf("Enter output file name: ");
    scanf("%s", output_file_name);

    printf("Enter key (4 characters): ");
    scanf("%s", key);

    switch (option)
    {
        case 1:
            encrypt(input_file_name, output_file_name, key);
            printf("Encryption complete!\n");
            break;
        case 2:
            decrypt(input_file_name, output_file_name, key);
            printf("Decryption complete!\n");
            break;
        default:
            printf("Invalid option\n");
    }

    return 0;
}

void encrypt(char* input_file_name, char* output_file_name, char* key)
{
    char* file_content;
    char* encrypted_content;
    long file_size;

    file_content = read_file(input_file_name, &file_size); // read the input file
    encrypted_content = malloc(file_size * sizeof(char)); // allocate memory for the encrypted content
    memset(encrypted_content, 0, file_size); // zero out the memory

    for (int i = 0; i < file_size; i++) // XOR each byte of the input file with the key
    {
        encrypted_content[i] = file_content[i] ^ key[i % KEY_LENGTH];
    }

    write_file(output_file_name, encrypted_content, file_size); // write the encrypted content to the output file
    free(file_content);
    free(encrypted_content);
}

void decrypt(char* input_file_name, char* output_file_name, char* key)
{
    char* file_content;
    char* decrypted_content;
    long file_size;

    file_content = read_file(input_file_name, &file_size); // read the input file
    decrypted_content = malloc(file_size * sizeof(char)); // allocate memory for the decrypted content
    memset(decrypted_content, 0, file_size); // zero out the memory

    for (int i = 0; i < file_size; i++) // XOR each byte of the input file with the key
    {
        decrypted_content[i] = file_content[i] ^ key[i % KEY_LENGTH];
    }

    write_file(output_file_name, decrypted_content, file_size); // write the decrypted content to the output file
    free(file_content);
    free(decrypted_content);
}

char* read_file(char* file_name, long *file_size)
{
    FILE* file_pointer;
    char* file_content;

    file_pointer = fopen(file_name, "rb"); // open the file in binary read mode

    if (file_pointer == NULL)
    {
        printf("Error: cannot open file %s\n", file_name);
        exit(1);
    }

    fseek(file_pointer, 0, SEEK_END); // move the file pointer to the end of the file
    *file_size = ftell(file_pointer); // get the size of the file
    rewind(file_pointer); // move the file pointer to the beginning of the file
    file_content = malloc((*file_size) * sizeof(char)); // allocate memory for the file content
    fread(file_content, sizeof(char), *file_size, file_pointer); // read the file content into memory
    fclose(file_pointer); // close the file

    return file_content;
}

void write_file(char* file_name, char* file_content, long file_size)
{
    FILE* file_pointer;

    file_pointer = fopen(file_name, "wb"); // open the file in binary write mode

    if (file_pointer == NULL)
    {
        printf("Error: cannot open file %s\n", file_name);
        exit(1);
    }

    fwrite(file_content, sizeof(char), file_size, file_pointer); // write the file content to the file
    fclose(file_pointer); // close the file
}