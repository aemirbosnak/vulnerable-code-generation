//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

#define KBYTE 1024
#define MBYTE (KBYTE*KBYTE)
#define GBYTE (KBYTE*MBYTE)
#define TBYTE (KBYTE*GBYTE)

void analyze_directory(char* path, unsigned long long *curr_size);

int main(int argc, char *argv[]) 
{
    unsigned long long total_size = 0;
    if (argc == 1) {
        analyze_directory(".", &total_size);
    } else {
        int i;
        for (i = 1; i < argc; i++) {
            analyze_directory(argv[i], &total_size);
        }
    }
    printf("\nTotal size of directories and files : ");
    if (total_size < KBYTE) {
        printf("%llu B\n", total_size);
    } else if (total_size < MBYTE) {
        printf("%llu KB\n", total_size/KBYTE);
    } else if (total_size < GBYTE) {
        printf("%llu MB\n", total_size/MBYTE);
    } else if (total_size < TBYTE) {
        printf("%llu GB\n", total_size/GBYTE);
    } else {
        printf("%llu TB\n", total_size/TBYTE);
    }
}

void analyze_directory(char* path, unsigned long long *curr_size) 
{
    struct dirent *de;
    DIR *dir;
    struct stat st;
    char next_path[1024];
    unsigned long long size;

    dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Unable to open directory : %s", path);
        return;
    }

    while ((de = readdir(dir)) != NULL) {
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
            continue;
        }
        sprintf(next_path, "%s/%s", path, de->d_name);
        if (lstat(next_path, &st) < 0) {
            printf("Error: Unable to access file : %s", next_path);
            continue;
        }
        if (S_ISREG(st.st_mode)) {
            size = st.st_size;
        } else if (S_ISLNK(st.st_mode)) {
            size = 0;
        } else if (S_ISDIR(st.st_mode)) {
            size = 0;
            analyze_directory(next_path, &size);
        } else {
            size = 0;
        }
        printf("%-50s %10llu bytes\n", next_path, size);
        *curr_size += size;
    }

    closedir(dir);
}