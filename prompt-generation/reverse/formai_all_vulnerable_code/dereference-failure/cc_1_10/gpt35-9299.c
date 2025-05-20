//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void scan_file(char*);

/* Entry point of the program */
int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Usage: antivirus [file_path]\n");
        return 1;
    }

    scan_file(argv[1]);

    return 0;
}

void scan_file(char* file_path)
{
    /* Define the virus signatures */
    char* virus_sig[] = {"Worm", "Trojan", "Rootkit", "Spyware", "Ransomware", "Adware"};

    /* Open the file for scanning */
    FILE* file = fopen(file_path, "r");

    if(file == NULL)
    {
        printf("Could not open the file: %s\n", file_path);
        return;
    }

    /* Read the file */
    char* buffer = (char*)malloc(1024 * sizeof(char));
    size_t bytes_read = fread(buffer, sizeof(char), 1024, file);

    /* Scan the file for viruses */
    for(int i = 0; i < 6; i++)
    {
        if(strstr(buffer, virus_sig[i]) != NULL)
        {
            printf("The file: %s is infected with %s virus!\n", file_path, virus_sig[i]);
            fclose(file);
            free(buffer);
            return;
        }
    }

    fclose(file);
    free(buffer);

    printf("The file: %s is clean!\n", file_path);
}