//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <math.h>

#define BLOCK_SIZE 1024

typedef struct {
    char name[256];
    long size;
    float percentage;
} FileStat;

void get_file_stats(const char* path, FileStat* stats) {
    struct stat file_stat;
    stat(path, &file_stat);

    stats->size = file_stat.st_size;
    sprintf(stats->name, "%s", path);
}

void print_file_stats(FileStat* stats, int num_files) {
    printf("%-20s %10s %10s\n", "File Name", "Size (Bytes)", "Percentage");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < num_files; i++) {
        printf("%-20s %10ld %10.2f%%\n", stats[i].name, stats[i].size, stats[i].percentage);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Error: Please provide a directory path.\n");
        return 1;
    }

    DIR* dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("Error: Could not open directory.\n");
        return 1;
    }

    struct dirent* ent;
    FileStat stats[100];
    int num_files = 0;

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            char file_path[256];
            sprintf(file_path, "%s/%s", argv[1], ent->d_name);

            get_file_stats(file_path, &stats[num_files]);
            num_files++;
        }
    }

    closedir(dir);

    print_file_stats(stats, num_files);

    return 0;
}