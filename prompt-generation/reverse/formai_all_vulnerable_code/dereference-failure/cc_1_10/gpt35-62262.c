//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: ephemeral
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define KB 1024
#define MB 1024*1024
#define GB 1024*1024*1024

void get_disk_space(char *dir_path, long *size) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    
    // Open directory
    dir = opendir(dir_path);
    if (!dir) {
        return;
    }

    // Loop through all entries in directory and get size of each file
    while ((entry = readdir(dir))) {
        char path[1024];
        sprintf(path, "%s/%s", dir_path, entry->d_name);
        lstat(path, &st);
        if (S_ISREG(st.st_mode)) {
            *size += st.st_size;
        } else if (S_ISDIR(st.st_mode) && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            get_disk_space(path, size);
        }
    }

    // Close directory
    closedir(dir);
}

int main() {
    char dir_path[1024];
    long disk_space = 0;

    // Get directory path from user
    printf("Enter directory path: ");
    scanf("%s", dir_path);

    // Get disk space of directory
    get_disk_space(dir_path, &disk_space);

    // Display disk space
    if (disk_space < KB) {
        printf("Disk space used: %ld bytes\n", disk_space);
    } else if (disk_space < MB) {
        printf("Disk space used: %.2f KB\n", (double)disk_space/KB);
    } else if (disk_space < GB) {
        printf("Disk space used: %.2f MB\n", (double)disk_space/MB);
    } else {
        printf("Disk space used: %.2f GB\n", (double)disk_space/GB);
    }

    return 0;
}