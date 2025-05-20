//FormAI DATASET v1.0 Category: File Encyptor ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

#define BUFFER_SIZE 1024

int main() 
{
    char file_name[BUFFER_SIZE];
    printf("Enter the file name to be encrypted: ");
    fgets(file_name, BUFFER_SIZE, stdin);

    FILE *file_ptr = fopen(file_name, "r");
    if(file_ptr == NULL) 
    {
        printf("\nError: Unable to open the file!\n");
        return 1;
    }

    char output_file_name[BUFFER_SIZE];
    printf("Enter the name of the output file: ");
    fgets(output_file_name, BUFFER_SIZE, stdin);

    FILE *output_file_ptr = fopen(output_file_name, "w");
    if(output_file_ptr == NULL) 
    {
        printf("\nError: Unable to create the output file!\n");
        return 1;
    }

    char key[BUFFER_SIZE];
    printf("Enter the encryption key: ");
    fgets(key, BUFFER_SIZE, stdin);

    int key_length = strlen(key);
    int i = 0;

    char buffer[BUFFER_SIZE];
    while(fgets(buffer, BUFFER_SIZE, file_ptr)) 
    {
        for(i = 0; i < strlen(buffer) - 1; i++)
        {
            buffer[i] = buffer[i] + key[i % key_length];
        } 

        fputs(buffer, output_file_ptr);
    }

    printf("\nThe file %s has been encrypted successfully and saved as %s!\n", file_name, output_file_name);

    fclose(file_ptr);
    fclose(output_file_ptr);
    
    return 0;
}