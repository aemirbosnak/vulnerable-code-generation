//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define MAX_DIR_ENTRIES 1024

typedef struct DirEntry {
    char name[256];
    struct DirEntry *next;
} DirEntry;

void analyze_disk_space(char *directory) {
    DIR *dir;
    struct dirent *entry;
    struct stat stat_buf;
    DirEntry *head = NULL;

    if ((dir = opendir(directory)) == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char full_path[PATH_MAX];
            snprintf(full_path, sizeof(full_path), "%s/%s", directory, entry->d_name);
            stat(full_path, &stat_buf);
            DirEntry *new_entry = malloc(sizeof(DirEntry));
            strcpy(new_entry->name, entry->d_name);
            new_entry->next = head;
            head = new_entry;
        }
    }

    closedir(dir);

    for (DirEntry *entry = head; entry; entry = entry->next) {
        printf("%s: %ld KB\n", entry->name, stat_buf.st_size / 1024);
    }

    free(head);
}

int main() {
    analyze_disk_space("/home/user");
    return 0;
}