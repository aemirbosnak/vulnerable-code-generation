//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_PATH 256
#define MAX_FILES 1024

typedef struct {
    char name[MAX_PATH];
    off_t size;
} FileInfo;

void display_banner() {
    printf("\n");
    printf("========================================\n");
    printf("      CYBERSPACE DISK ANALYZER         \n");
    printf("            VERSION 1.0                \n");
    printf("========================================\n");
}

void display_file_info(FileInfo *files, int count) {
    printf("\n-- File Analysis Result --\n");
    printf("%-40s %-10s\n", "File Name", "Size (bytes)");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-40s %-10ld\n", files[i].name, files[i].size);
    }

    printf("----------------------------------------\n");
}

void analyze_directory(const char *dir_path, FileInfo *files, int *file_count) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    dir = opendir(dir_path);
    if (!dir) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        if (stat(full_path, &file_stat) == 0) {
            if (S_ISREG(file_stat.st_mode)) {
                strncpy(files[*file_count].name, full_path, MAX_PATH);
                files[*file_count].size = file_stat.st_size;
                (*file_count)++;
            }
        } else {
            perror("Failed to get file status");
        }
    }

    closedir(dir);
}

void sort_files(FileInfo *files, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (files[i].size < files[j].size) {
                FileInfo temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    display_banner();

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileInfo files[MAX_FILES];
    int file_count = 0;

    analyze_directory(argv[1], files, &file_count);
    sort_files(files, file_count);
    display_file_info(files, file_count);

    printf("Analysis completed at: %s", ctime(&(time_t){time(NULL)}));
    printf("========================================\n\n");

    return EXIT_SUCCESS;
}