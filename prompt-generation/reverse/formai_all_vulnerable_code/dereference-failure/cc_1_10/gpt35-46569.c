//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan_file(char* filename);

int main(int argc, char** argv)
{
    // check for filename argument
    if(argc != 2)
    {
        printf("Usage: ./scanner [filename]\n");
        return 1;
    }

    // scan the file
    scan_file(argv[1]);

    return 0;
}

void scan_file(char* filename)
{
    // open the file
    FILE* file = fopen(filename, "rb");
    if(file == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    // get file size
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // allocate memory for file contents
    char* file_contents = (char*) malloc(filesize);

    // read file contents into memory
    fread(file_contents, 1, filesize, file);

    // close the file
    fclose(file);

    // check for virus signature
    char* virus_signature = "f3k78d12o5a7h8s9t1y4";
    int signature_length = strlen(virus_signature);

    for(int i = 0; i < filesize - signature_length; i++)
    {
        // check for match with virus signature
        if(strncmp(file_contents + i, virus_signature, signature_length) == 0)
        {
            printf("Virus detected in file %s!\n", filename);
            return;
        }
    }

    printf("No viruses detected in file %s.\n", filename);

    // free memory
    free(file_contents);
}