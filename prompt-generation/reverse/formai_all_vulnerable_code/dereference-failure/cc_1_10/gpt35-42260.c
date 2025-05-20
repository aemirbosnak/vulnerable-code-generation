//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: mind-bending
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define VIRUS_SIGNATURE "I_AM_A_VIRUS"
#define FILE_TYPE 8

int check_file(char *filename, unsigned char *buffer, long int file_size);

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *entry;

    if(argc != 2)
    {
        printf("Usage: antivirus <directory>\n");
        exit(0);
    }

    dir = opendir(argv[1]);

    if(dir == NULL)
    {
        printf("Unable to open directory: %s\n", argv[1]);
        exit(0);
    }

    while((entry = readdir(dir)) != NULL)
    {
        char path[1024];
        char *file_name = entry->d_name;

        snprintf(path, sizeof(path), "%s/%s", argv[1], file_name);

        if (entry->d_type != FILE_TYPE)
            continue;

        FILE *file = fopen(path, "rb");
        if(!file)
        {
            printf("Unable to open file: %s\n", file_name);
            continue;
        }

        fseek(file, 0, SEEK_END);
        long int file_size = ftell(file);
        fseek(file, 0, SEEK_SET);

        unsigned char *buffer = malloc(file_size);

        if(!buffer)
        {
            printf("Unable to allocate memory for file: %s\n", file_name);
            fclose(file);
            continue;
        }

        fread(buffer, file_size, 1, file);

        int virus_found = check_file(file_name, buffer, file_size);

        if(virus_found)
        {
            printf("Virus found in file: %s\n", file_name);
        }

        fclose(file);
        free(buffer);
    }

    closedir(dir);

    return 0;
}

int check_file(char *filename, unsigned char *buffer, long int file_size)
{
    char *virus_signature = VIRUS_SIGNATURE;
    size_t virus_size = strlen(virus_signature);

    if(file_size < virus_size)
        return 0;

    for(int i = 0; i < file_size - virus_size; i++)
    {
        if(memcmp(&buffer[i], virus_signature, virus_size) == 0)
        {
            return 1;
        }
    }

    return 0;
}