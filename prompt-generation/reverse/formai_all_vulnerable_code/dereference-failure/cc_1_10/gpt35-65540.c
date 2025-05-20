//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void get_total_directory_size(const char *name, int *total_size);
void human_readable_size(double size, char *human_size);

int main(void) {
    int total_size = 0;
    
    printf("C Disk Space Analyzer\n\n");
    printf("Calculating total size of current directory...\n\n");
    
    get_total_directory_size(".", &total_size);
    
    char human_size[16];
    human_readable_size(total_size, human_size);
    
    printf("Total size of current directory: %s\n", human_size);
    
    return 0;
}

void get_total_directory_size(const char *name, int *total_size) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;

    if (!(dir = opendir(name))) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            get_total_directory_size(path, total_size);
        } else {
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            if (stat(path, &file_info) == 0) {
                *total_size += file_info.st_size;
            }
        }
    }
    closedir(dir);
}

void human_readable_size(double size, char *human_size) {
    const char* units[] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
    int i = 0;
    while (size > 1024) {
        size /= 1024;
        i++;
    }
    sprintf(human_size, "%.2f %s", size, units[i]);
}