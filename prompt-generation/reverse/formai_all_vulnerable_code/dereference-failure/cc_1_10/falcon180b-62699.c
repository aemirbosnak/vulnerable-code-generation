//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BUF_SIZE 1024

typedef struct {
    char name[BUF_SIZE];
    unsigned long long size;
} File;

void get_files(const char* path, File* files, int count, unsigned long long* total_size) {
    DIR* dir = opendir(path);
    struct dirent* ent;

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            if (count >= BUF_SIZE) {
                printf("Too many files, exiting...\n");
                exit(1);
            }

            File file;
            sprintf(file.name, "%s", ent->d_name);
            file.size = ent->d_reclen;

            files[count] = file;
            count++;
            *total_size += file.size;
        }
    }

    closedir(dir);
}

void print_files(File* files, int count) {
    printf("Files:\n");

    for (int i = 0; i < count; i++) {
        printf("%-40s %10llu bytes\n", files[i].name, files[i].size);
    }
}

void print_summary(unsigned long long total_size, unsigned long long total_space) {
    printf("\nTotal size of all files: %llu bytes\n", total_size);
    printf("Total disk space: %llu bytes\n", total_space);
    printf("Free disk space: %llu bytes\n", total_space - total_size);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[BUF_SIZE];
    sprintf(path, "%s", argv[1]);

    File files[BUF_SIZE];
    int count = 0;
    unsigned long long total_size = 0;

    get_files(path, files, count, &total_size);

    print_files(files, count);
    print_summary(total_size, (unsigned long long)1 << 30);

    return 0;
}