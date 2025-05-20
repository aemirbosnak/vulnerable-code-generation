//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_DIR_SIZE 1024
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_DIR_SIZE];
    int size;
} dir_entry;

void get_dir_entries(char* path, dir_entry entries[], int size) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    int count = 0;
    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (count >= size) {
            break;
        }

        if (entry->d_type == DT_DIR) {
            strncpy(entries[count].name, entry->d_name, MAX_DIR_SIZE);
            entries[count].size = 0;
            count++;
        } else {
            strncpy(entries[count].name, entry->d_name, MAX_FILE_SIZE);
            entries[count].size = entry->d_reclen;
            count++;
        }
    }

    closedir(dir);
}

void print_dir_entries(dir_entry entries[], int size) {
    for (int i = 0; i < size; i++) {
        if (entries[i].size == 0) {
            printf("%s\n", entries[i].name);
        } else {
            printf("%s (%d bytes)\n", entries[i].name, entries[i].size);
        }
    }
}

int main() {
    char path[MAX_DIR_SIZE] = {0};
    printf("Enter the directory path: ");
    scanf("%s", path);

    dir_entry entries[MAX_DIR_SIZE];
    int size = 0;

    get_dir_entries(path, entries, MAX_DIR_SIZE);

    print_dir_entries(entries, size);

    return 0;
}