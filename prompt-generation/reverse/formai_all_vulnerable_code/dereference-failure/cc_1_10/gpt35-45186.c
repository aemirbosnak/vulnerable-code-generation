//FormAI DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_BUFFER_SIZE 1024

void encrypt(char* input_filename, char* output_filename, char* password);
void decrypt(char* input_filename, char* output_filename, char* password);

int main()
{
    char input_filename[MAX_FILENAME_LEN], output_filename[MAX_FILENAME_LEN];
    char password[50];
    int choice;
    
    printf("*** Cyberpunk File Encyptor ***\n");
    printf("1. Encrypt a File\n");
    printf("2. Decrypt a File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    printf("Enter input filename: ");
    scanf("%s", input_filename);
    
    printf("Enter output filename: ");
    scanf("%s", output_filename);
    
    switch(choice)
    {
        case 1:
            encrypt(input_filename, output_filename, password);
            break;
        case 2:
            decrypt(input_filename, output_filename, password);
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
    }
    
    return 0;
}

void encrypt(char* input_filename, char* output_filename, char* password)
{
    FILE *f_input, *f_output;
    char buffer[MAX_BUFFER_SIZE];
    int i, j, k, len;
    
    f_input = fopen(input_filename, "rb");
    f_output = fopen(output_filename, "wb");
    
    if(f_input == NULL || f_output == NULL)
    {
        printf("Error: File not found.\n");
        exit(1);
    }
    
    // Compute password strength
    len = strlen(password);
    j = 2 * len;
    k = 3 * len;
    
    for(i = 0; i < MAX_BUFFER_SIZE; i++)
    {
        if(fread(&buffer[i], 1, 1, f_input) != 1)
            break;
        
        // XOR with password
        buffer[i] = buffer[i] ^ password[i % len];
        
        // Randomize bytes
        buffer[i] = buffer[i] + j;
        j = (j * 7) % 256;
        buffer[i] = buffer[i] - k;
        k = (k * 13) % 256;
    }
    
    fwrite(buffer, 1, i, f_output);
    
    fclose(f_input);
    fclose(f_output);
    
    printf("File encrypted successfully.\n");
}

void decrypt(char* input_filename, char* output_filename, char* password)
{
    FILE *f_input, *f_output;
    char buffer[MAX_BUFFER_SIZE];
    int i, j, k, len;
    
    f_input = fopen(input_filename, "rb");
    f_output = fopen(output_filename, "wb");
    
    if(f_input == NULL || f_output == NULL)
    {
        printf("Error: File not found.\n");
        exit(1);
    }
    
    // Compute password strength
    len = strlen(password);
    j = 2 * len;
    k = 3 * len;
    
    for(i = 0; i < MAX_BUFFER_SIZE; i++)
    {
        if(fread(&buffer[i], 1, 1, f_input) != 1)
            break;

        // Randomize bytes
        buffer[i] = buffer[i] + k;
        k = (k * 13) % 256;
        buffer[i] = buffer[i] - j;
        j = (j * 7) % 256;
        
        // XOR with password
        buffer[i] = buffer[i] ^ password[i % len];
    }
    
    fwrite(buffer, 1, i, f_output);
    
    fclose(f_input);
    fclose(f_output);
    
    printf("File decrypted successfully.\n");
}