//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000

int main(int argc, char *argv[])
{
    // check if file path is provided
    if(argc < 2)
    {
        printf("Please provide the path of file to scan.\n");
        exit(1);
    }

    // open file in binary mode
    FILE *file_pointer = fopen(argv[1], "rb");

    // check if file is opened successfully
    if(file_pointer == NULL)
    {
        printf("Failed to open file.\n");
        exit(1);
    }

    // allocate memory to store file content
    char *file_content = (char*) malloc(MAX_FILE_SIZE);

    // read file content and store it in file_content
    int bytes_read = fread(file_content, sizeof(char), MAX_FILE_SIZE, file_pointer);

    if(bytes_read == 0)
    {
        printf("Failed to read file.\n");
        free(file_content);
        fclose(file_pointer);
        exit(1);
    }

    // define virus signature to detect
    char *virus_signature = "malware";

    // scan file for virus signature
    if(strstr(file_content, virus_signature) != NULL)
    {
        printf("Warning! %s is detected in file.\n", virus_signature);
    }
    else
    {
        printf("File is clean from viruses.\n");
    }

    // free memory and close file
    free(file_content);
    fclose(file_pointer);

    return 0;
}