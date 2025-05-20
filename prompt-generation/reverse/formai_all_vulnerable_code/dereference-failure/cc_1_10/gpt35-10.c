//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkVirus(char* filename);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./antivirus <filename>\n");
        return 1;
    }

    char* filename = argv[1];
    
    int status = checkVirus(filename);

    if(status)
        printf("Virus detected in file %s\n", filename);
    else
        printf("No virus detected in file %s\n", filename);

    return 0;
}

int checkVirus(char* filename)
{
    // Check file extension
    char* ext = strrchr(filename, '.');
    if(strcmp(ext, ".exe"))
        return 1;

    // Check for signature of known virus
    FILE* file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return 0;
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    
    int virusFound = 0;

    while((read = getline(&line, &len, file)) != -1)
    {
        if(strstr(line, "virus") || strstr(line, "malware"))
        {
            virusFound = 1;
            break;
        }
    }

    fclose(file);
    
    return virusFound;
}