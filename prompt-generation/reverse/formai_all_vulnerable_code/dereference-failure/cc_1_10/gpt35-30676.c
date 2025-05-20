//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 256

// function to read a file and return the contents as a string
char* read_file(char* filename)
{
    char* buffer = NULL;
    long length;

    FILE* file = fopen(filename, "rb");

    if (file)
    {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        buffer = (char*)malloc(length + 1);

        if (buffer)
        {
            fread(buffer, 1, length, file);
            buffer[length] = '\0';
        }

        fclose(file);
    }

    return buffer;
}

// function to scan a file for a virus signature
int scan_file(char* filename, char* signature)
{
    char* file_contents = read_file(filename);

    if (file_contents)
    {
        if (strstr(file_contents, signature) != NULL)
        {
            printf("Virus detected in file: %s\n", filename);
            return 1;
        }
        else
        {
            printf("File is clean: %s\n", filename);
            return 0;
        }
    }
    else
    {
        printf("Unable to open file: %s\n", filename);
        return -1;
    }
}

int main()
{
    char filename[MAX_FILE_NAME_SIZE];
    char signature[] = "virus signature";
    int scan_result;

    printf("Enter file name to scan: ");
    scanf("%s", filename);

    scan_result = scan_file(filename, signature);

    if (scan_result == 1)
    {
        printf("File infected with virus\n");
    }
    else if (scan_result == 0)
    {
        printf("File is clean\n");
    }

    return 0;
}