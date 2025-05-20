//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define KB 1024
#define MB (KB * KB)
#define GB (MB * KB)

#define FMT_SIZE "%.2f %cB"

typedef struct {
    char path[1024];
    double size;
} FileSize;

void get_dir_size(const char *path, double *total_size, double *file_count, double *dir_count) {
    DIR *d = opendir(path);
    if (!d) {
        printf("Error: could not open directory '%s'\n", path);
        exit(1);
    }

    struct dirent *ent;
    while ((ent = readdir(d))!= NULL) {
        if (ent->d_type == DT_DIR) {
            (*dir_count)++;
        } else {
            (*file_count)++;
            char full_path[1024];
            sprintf(full_path, "%s/%s", path, ent->d_name);
            struct statvfs stvfs;
            if (statvfs(full_path, &stvfs)!= 0) {
                printf("Error: could not get file system info for '%s'\n", full_path);
                continue;
            }
            double size = stvfs.f_blocks * stvfs.f_frsize;
            (*total_size) += size;
            FileSize fs;
            sprintf(fs.path, "%s", ent->d_name);
            fs.size = size;
            printf(FMT_SIZE, size, 'B');
            if (file_count > 1) {
                printf(", ");
            }
            printf("\n");
        }
    }

    closedir(d);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    double total_size = 0, file_size = 0, dir_count = 0;
    get_dir_size(argv[1], &total_size, &file_size, &dir_count);

    printf("Total size: ");
    printf(FMT_SIZE, total_size, 'B');
    printf("\nFiles: ");
    printf(FMT_SIZE, file_size, 'B');
    printf("\nDirectories: %d\n", dir_count);

    return 0;
}