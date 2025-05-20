//FormAI DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LENGTH 100 // Maximum string length for file name and key

int main()
{
    char file_name[MAX_STR_LENGTH], key[MAX_STR_LENGTH];
    FILE *file_in, *file_out;
    int i, key_len, file_size;
    
    // Getting file name from user
    printf("Enter the file name: ");
    fgets(file_name, MAX_STR_LENGTH, stdin);
    file_name[strcspn(file_name, "\n")] = 0; // Removing trailing newline
    
    // Getting key from user
    printf("\nEnter the key: ");
    fgets(key, MAX_STR_LENGTH, stdin);
    key[strcspn(key, "\n")] = 0; // Removing trailing newline
    
    // Opening file for reading
    file_in = fopen(file_name, "rb");
    if(file_in == NULL)
    {
        printf("\nError opening file!");
        return 1;
    }
    
    // Getting file size
    fseek(file_in, 0, SEEK_END);
    file_size = ftell(file_in);
    fseek(file_in, 0, SEEK_SET);
    
    // Opening file for writing
    file_out = fopen("encrypted_file.txt", "wb");
    if(file_out == NULL)
    {
        printf("\nError creating encrypted file!");
        return 1;
    }
    
    key_len = strlen(key);
    
    // Iterating over each byte of file
    for(i=0; i<file_size; i++)
    {
        // Reading a byte from file
        char byte;
        fread(&byte, 1, 1, file_in);
        
        // Encrypting the byte
        byte = byte ^ key[i%key_len];
        
        // Writing the encrypted byte to output file
        fwrite(&byte, 1, 1, file_out);
    }
    
    printf("\nFile encryption successful!");
    
    // Closing both files
    fclose(file_in);
    fclose(file_out);
    
    return 0;
}