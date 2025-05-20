//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define KILO_BYTE 1024
#define MEGA_BYTE (KILO_BYTE * 1024)
#define GIGA_BYTE (MEGA_BYTE * 1024)

long long int get_directory_size(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        return 0;
    }

    struct dirent *entry;
    long long int total_size = 0;

    while ((entry = readdir(dir)) != NULL) {
        char full_path[1024];
        sprintf(full_path, "%s/%s", path, entry->d_name);

        struct stat info;
        if (stat(full_path, &info) != 0) {
            continue;
        }
        if (S_ISDIR(info.st_mode)) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            total_size += get_directory_size(full_path);
        } else {
            total_size += info.st_size;
        }
    }
    closedir(dir);
    return total_size;
}

int main() {
    char path[1024];
    printf("Enter directory path: ");
    scanf("%s", path);

    long long int dir_size = get_directory_size(path);

    if (dir_size == 0) {
        printf("Directory does not exist or is empty.\n");
        return 0;
    }

    printf("Total directory size: ");

    if (dir_size < KILO_BYTE) {
        printf("%llu B\n", dir_size);
    } else if (dir_size < MEGA_BYTE) {
        printf("%.2f KB\n", (float)dir_size / KILO_BYTE);
    } else if (dir_size < GIGA_BYTE) {
        printf("%.2f MB\n", (float)dir_size / MEGA_BYTE);
    } else {
        printf("%.2f GB\n", (float)dir_size / GIGA_BYTE);
    }

    return 0;
}