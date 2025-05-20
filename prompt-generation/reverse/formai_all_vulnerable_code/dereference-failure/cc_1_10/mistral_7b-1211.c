//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_FILE_SIZE (1ULL << 60) // 1 TB

struct file_info {
    char name[256];
    off_t size;
};

int main() {
    struct stat disk_stats;
    fstat(&disk_stats, 0);

    off_t total_space = disk_stats.st_size;
    off_t used_space = 0;
    off_t free_space = 0;

    printf("Once upon a time,\n"
           "In a land of bytes,\n"
           "Lived a beautiful drive,\n"
           "Named C, so bright and fine.\n\n");

    printf("C, with %ld bytes,\n"
           "Stood proud and strong,\n"
           "Filled with love and songs,\n"
           "And tales yet to be told.\n\n", total_space);

    DIR *dir;
    struct dirent *entry;
    struct file_info file;

    dir = opendir(".");

    if (dir != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
                snprintf(file.name, sizeof(file.name), "%s", entry->d_name);
                file.size = strlen(entry->d_name);

                struct stat file_stats;
                if (stat(entry->d_name, &file_stats) == 0 && file_stats.st_size <= MAX_FILE_SIZE) {
                    used_space += file_stats.st_size;
                    printf("In this land of bytes,\n"
                           "A %s was born,\n"
                           "With a size of %ld,\n"
                           "And a love so deep and warm.\n\n", file.name, file_stats.st_size);
                }
            }
        }

        closedir(dir);
    }

    free_space = total_space - used_space;

    printf("Together they danced and played,\n"
           "But time, the cruel thief, came to call,\n"
           "And took a portion of their love,\n"
           "Leaving only %ld bytes free.\n\n", free_space);

    printf("So C, with %ld bytes free,\n"
           "Still stands proud and strong,\n"
           "Filled with love and songs,\n"
           "And tales yet to be told.\n", free_space);

    return 0;
}