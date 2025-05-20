//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct SpaceAnalyzer
{
    char name[256];
    int size;
    struct SpaceAnalyzer* next;
} SpaceAnalyzer;

void analyzeSpace(char* directory)
{
    DIR* dir = opendir(directory);
    struct dirent* entry;
    SpaceAnalyzer* head = NULL;
    SpaceAnalyzer* tail = NULL;

    if (dir)
    {
        while ((entry = readdir(dir)) != NULL)
        {
            struct stat stat_buf;
            stat(entry->d_name, &stat_buf);
            SpaceAnalyzer* newAnalyzer = malloc(sizeof(SpaceAnalyzer));
            strcpy(newAnalyzer->name, entry->d_name);
            newAnalyzer->size = stat_buf.st_size;
            newAnalyzer->next = NULL;

            if (head == NULL)
            {
                head = newAnalyzer;
                tail = newAnalyzer;
            }
            else
            {
                tail->next = newAnalyzer;
                tail = newAnalyzer;
            }
        }

        closedir(dir);
    }

    tail = head;
    while (tail)
    {
        printf("%s: %d KB\n", tail->name, tail->size / 1024);
        free(tail);
        tail = tail->next;
    }
}

int main()
{
    analyzeSpace("/path/to/directory");
    return 0;
}