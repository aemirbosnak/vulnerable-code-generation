//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_DIR_ENTRIES 1024

typedef struct DirectoryEntry {
    char name[256];
    struct DirectoryEntry* next;
} DirectoryEntry;

DirectoryEntry* analyze_disk_space(char* directory) {
    DirectoryEntry* head = NULL;
    DIR* dir = opendir(directory);
    struct dirent* dir_entry;
    struct stat stat_buf;

    if (!dir) {
        perror("Error opening directory");
        return NULL;
    }

    while ((dir_entry = readdir(dir)) != NULL) {
        if (dir_entry->d_type == DT_DIR) {
            stat(dir_entry->d_name, &stat_buf);
            DirectoryEntry* new_entry = malloc(sizeof(DirectoryEntry));
            strcpy(new_entry->name, dir_entry->d_name);
            new_entry->next = head;
            head = new_entry;
        }
    }

    closedir(dir);
    return head;
}

int main() {
    char* directory = "/path/to/directory";
    DirectoryEntry* entries = analyze_disk_space(directory);

    if (entries) {
        for (DirectoryEntry* entry = entries; entry; entry = entry->next) {
            printf("%s\n", entry->name);
        }
    } else {
        printf("Error analyzing disk space\n");
    }

    return 0;
}