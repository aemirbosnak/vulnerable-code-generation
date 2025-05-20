//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

struct disk_stats {
    int total_size;
    int used_size;
    int free_size;
    int used_percent;
};

struct disk_stats get_disk_stats() {
    struct disk_stats stats;
    stats.total_size = 0;
    stats.used_size = 0;
    stats.free_size = 0;
    stats.used_percent = 0;

    // Calculate total size of the disk
    statvfs("/", &stats.total_size);

    // Calculate used size of the disk
    struct dirent *dir;
    DIR *dp = opendir("/");
    if (dp == NULL) {
        perror("Failed to open directory");
        return stats;
    }

    struct stat file_stats;
    while ((dir = readdir(dp))!= NULL) {
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            continue;
        if (stat(dir->d_name, &file_stats) == 0) {
            stats.used_size += file_stats.st_size;
        }
    }

    closedir(dp);

    // Calculate free size of the disk
    stats.free_size = stats.total_size - stats.used_size;

    // Calculate used percentage of the disk
    stats.used_percent = (stats.used_size * 100) / stats.total_size;

    return stats;
}

int main() {
    struct disk_stats stats = get_disk_stats();

    printf("Total disk size: %d bytes\n", stats.total_size);
    printf("Used disk size: %d bytes\n", stats.used_size);
    printf("Free disk size: %d bytes\n", stats.free_size);
    printf("Used percentage: %d%%\n", stats.used_percent);

    return 0;
}