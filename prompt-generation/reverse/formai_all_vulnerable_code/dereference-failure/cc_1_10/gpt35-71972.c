//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Define Virus Signatures
char *virus_signature[] = {"virus1", "virus2", "virus3"};

// Function to Check if File Contains Virus Signatures
int scan_file(char *file_path)
{
    FILE *file = fopen(file_path, "r");
    if (file == NULL)
    {
        perror("File could not be opened");
        return -1;
    }
    
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        for (int i = 0; i < sizeof(virus_signature)/sizeof(virus_signature[0]); i++)
        {
            if (strstr(buffer, virus_signature[i]) != NULL)
            {
                printf("WARNING: Virus signature '%s' found in file %s\n", virus_signature[i], file_path);
                return 1;
            }
        }
    }
    
    fclose(file);
    return 0;
}

// Recursive Function to Traverse Directory and Scan Files
void traverse_directory(char *path)
{
    DIR *dir = opendir(path);
    if (dir == NULL)
    {
        perror("Directory could not be opened");
        return;
    }
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        char *name = entry->d_name;
        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
            continue;

        char file_path[100];
        sprintf(file_path, "%s/%s", path, name);
        
        if (entry->d_type == DT_DIR)
            traverse_directory(file_path);
        else if (entry->d_type == DT_REG)
            scan_file(file_path);
    }
    
    closedir(dir);
}

// Main Function
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./antivirus <directory_path>\n");
        return -1;
    }

    traverse_directory(argv[1]);
    printf("Scan Completed.\n");

    return 0;
}