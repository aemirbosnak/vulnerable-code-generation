//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define MAX_DIR_NAME_LENGTH 256

typedef struct DirEntry
{
    char name[MAX_DIR_NAME_LENGTH];
    struct DirEntry* next;
} DirEntry;

void analyzeDiskSpace(char* dirPath)
{
    DIR* dir = opendir(dirPath);
    if (!dir)
    {
        perror("Error opening directory");
        return;
    }

    DirEntry* head = NULL;
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_DIR)
        {
            DirEntry* newEntry = malloc(sizeof(DirEntry));
            strcpy(newEntry->name, entry->d_name);
            newEntry->next = head;
            head = newEntry;
        }
    }

    closedir(dir);

    for (DirEntry* entry = head; entry; entry = entry->next)
    {
        struct stat statBuf;
        stat(entry->name, &statBuf);
        long size = statBuf.st_size;
        printf("%s: %.2f MB\n", entry->name, size / 1048576.0);
    }
}

int main()
{
    analyzeDiskSpace("/path/to/directory");
    return 0;
}