//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>

//Function to scan the file for viruses
void scanFile(char *fileName)
{
    FILE *file = fopen(fileName, "r"); //Open the file for reading
    char *line = NULL;
    size_t len = 0;

    while(getline(&line, &len, file) != -1) //Read the file line-by-line
    {
        for(int i = 0; i < strlen(line); i++) //Check each character in the line
        {
            if(isalpha(line[i]) || isspace(line[i])) //If it's not a special character or number
            {
                continue; //Skip to the next character
            }
            else
            {
                printf("\n%s - Infected with virus!", fileName); //Virus found
                fclose(file);
                return;
            }
        }
    }

    fclose(file);
}

//Function to scan the directory for files
void scanDirectory(char *dirName)
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dirName); //Open the directory

    while((entry = readdir(dir)) != NULL) //Read each entry in the directory
    {
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dirName, entry->d_name); //Build the path of the file/directory

        if(entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) //If the entry is a directory
        {
            scanDirectory(path); //Scan the directory recursively
        }
        else if(entry->d_type == DT_REG) //If the entry is a regular file
        {
            scanFile(path); //Scan the file for viruses
        }
    }

    closedir(dir);
}

int main(int argc, char **argv)
{
    if(argc == 1) //If the user didn't provide any arguments
    {
        printf("Usage: %s <directory or file name>\n", argv[0]);
        return 0;
    }

    for(int i = 1; i < argc; i++) //For each argument provided
    {
        if(opendir(argv[i]) != NULL) //If the argument is a directory
        {
            scanDirectory(argv[i]); //Scan the directory for viruses
        }
        else if(fopen(argv[i], "r") != NULL) //If the argument is a file
        {
            scanFile(argv[i]); //Scan the file for viruses
        }
        else //If the argument is not a file or directory
        {
            printf("%s - Invalid argument!\n", argv[i]);
        }
    }

    return 0;
}