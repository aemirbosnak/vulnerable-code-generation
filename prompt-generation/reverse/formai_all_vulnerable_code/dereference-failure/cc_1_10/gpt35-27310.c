//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 100
#define MAX_FILENAME_LENGTH 50
#define MAX_EXTENSION_LENGTH 10

char virus_db[][MAX_FILENAME_LENGTH] = {"trojan", "worm", "malware", "virus", "spyware"};

int is_virus(char *filename)
{
    char path[MAX_PATH_LENGTH];
    char name[MAX_FILENAME_LENGTH];
    char extension[MAX_EXTENSION_LENGTH];
    int i;
    int is_vir = 0;

    // Split filename into path, name and extension
    memset(path, '\0', sizeof(path));
    memset(name, '\0', sizeof(name));
    memset(extension, '\0', sizeof(extension));
    for (i = 0; i < strlen(filename); i++)
    {
        if (filename[i] == '/')
        {
            memset(path, '\0', sizeof(path));
        }
        else if (filename[i] == '.')
        {
            memset(extension, '\0', sizeof(extension));
            memset(name, '\0', sizeof(name));
        }
        else if (strlen(extension) < MAX_EXTENSION_LENGTH)
        {
            extension[strlen(extension) + 1] = '\0';
            extension[strlen(extension)] = filename[i];
        }
        else if (strlen(name) < MAX_FILENAME_LENGTH)
        {
            name[strlen(name) + 1] = '\0';
            name[strlen(name)] = filename[i];
        }
        else if (strlen(path) < MAX_PATH_LENGTH)
        {
            path[strlen(path) + 1] = '\0';
            path[strlen(path)] = filename[i];
        }
    }

    // Check if name contains any string in virus_db
    for (i = 0; i < sizeof(virus_db) / sizeof(virus_db[0]); i++)
    {
        if (strstr(name, virus_db[i]) != NULL)
        {
            is_vir = 1;
            break;
        }
    }

    return is_vir;
}

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (is_virus(argv[1]))
    {
        printf("Virus detected!\n");
        return 2;
    }

    printf("No virus detected\n");

    return 0;
}