//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define MAX_DIR_ENTRIES 1024

typedef struct DirectoryEntry {
    char *name;
    int size;
    struct DirectoryEntry *next;
} DirectoryEntry;

void analyze_disk_space(char *directory)
{
    DirectoryEntry *head = NULL;
    DIR *dir = opendir(directory);
    struct dirent *entry;
    struct stat stat_buf;
    char full_path[256];

    if (dir)
    {
        while ((entry = readdir(dir)) != NULL)
        {
            if (entry->d_type == DT_DIR)
            {
                sprintf(full_path, "%s/%s", directory, entry->d_name);
                stat(full_path, &stat_buf);
                DirectoryEntry *new_entry = malloc(sizeof(DirectoryEntry));
                new_entry->name = strdup(entry->d_name);
                new_entry->size = stat_buf.st_size;
                new_entry->next = head;
                head = new_entry;
            }
        }
        closedir(dir);
    }

    // Print directory entries
    DirectoryEntry *current = head;
    while (current)
    {
        printf("%s: %d bytes\n", current->name, current->size);
        current = current->next;
    }

    // Free memory
    DirectoryEntry *prev = NULL;
    current = head;
    while (current)
    {
        prev = current;
        current = current->next;
        free(prev);
    }
}

int main()
{
    analyze_disk_space("/home/user");
    return 0;
}