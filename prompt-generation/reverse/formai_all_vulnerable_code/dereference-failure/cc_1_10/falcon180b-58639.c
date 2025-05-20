//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>

#define SECTOR_SIZE 512
#define KB 1024
#define MB (1024*KB)
#define GB (1024*MB)

struct file_info {
    char name[1024];
    off_t size;
};

void print_usage() {
    printf("Usage:./program <directory>\n");
}

void print_file_info(struct file_info *file) {
    printf("%s\t%ld\n", file->name, file->size);
}

void print_total_space(double total_space) {
    printf("Total space: %.2f GB\n", total_space/GB);
}

void print_used_space(double used_space) {
    printf("Used space: %.2f GB\n", used_space/GB);
}

void print_free_space(double free_space) {
    printf("Free space: %.2f GB\n", free_space/GB);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        print_usage();
        return 1;
    }

    char path[1024];
    strcpy(path, argv[1]);
    strcat(path, "/");

    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory\n");
        return 1;
    }

    struct dirent *ent;
    struct file_info files[100];
    int num_files = 0;

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            strcpy(files[num_files].name, ent->d_name);
            files[num_files].size = ent->d_reclen;
            num_files++;
        }
    }

    closedir(dir);

    double total_space = 0, used_space = 0, free_space = 0;

    for (int i = 0; i < num_files; i++) {
        struct statvfs buf;
        if (statvfs(path, &buf) == -1) {
            printf("Error getting file system info\n");
            return 1;
        }

        total_space += buf.f_blocks * buf.f_frsize;
        used_space += files[i].size;
    }

    free_space = total_space - used_space;

    printf("Files:\n");
    for (int i = 0; i < num_files; i++) {
        print_file_info(&files[i]);
    }

    print_total_space(total_space);
    print_used_space(used_space);
    print_free_space(free_space);

    return 0;
}