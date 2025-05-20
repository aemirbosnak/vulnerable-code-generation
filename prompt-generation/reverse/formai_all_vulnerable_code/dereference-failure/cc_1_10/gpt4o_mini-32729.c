//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

typedef struct {
    char name[MAX_PATH];
    long size;
} FileEntry;

void analyze_directory(const char *path, FileEntry *files, int *count);
void print_summary(FileEntry *files, int count);
void format_size(long size, char *buffer, size_t buffer_size);

int main(int argc, char *argv[]) {
    FileEntry files[MAX_PATH];
    int count = 0;
    char *start_path = "."; // Default to current directory

    if (argc > 1) {
        start_path = argv[1];
    }

    printf("Analyzing disk space for: %s\n", start_path);
    analyze_directory(start_path, files, &count);
    print_summary(files, count);

    return 0;
}

void analyze_directory(const char *path, FileEntry *files, int *count) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_PATH];

    if ((dir = opendir(path)) == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
            if (stat(full_path, &file_stat) == 0) {
                if (S_ISREG(file_stat.st_mode)) {
                    FileEntry new_file;
                    strncpy(new_file.name, full_path, MAX_PATH);
                    new_file.size = file_stat.st_size;
                    files[(*count)++] = new_file;
                } else if (S_ISDIR(file_stat.st_mode)) {
                    analyze_directory(full_path, files, count);
                }
            } else {
                perror("Error obtaining file statistics");
            }
        }
    }
    closedir(dir);
}

void print_summary(FileEntry *files, int count) {
    long total_size = 0;
    char size_buffer[20];

    printf("\nSummary of files:\n");
    printf("%-50s %10s\n", "File Name", "Size");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-50s ", files[i].name);
        format_size(files[i].size, size_buffer, sizeof(size_buffer));
        printf("%10s\n", size_buffer);
        total_size += files[i].size;
    }

    printf("----------------------------------------------------\n");
    printf("%-50s ", "Total Size");
    format_size(total_size, size_buffer, sizeof(size_buffer));
    printf("%10s\n", size_buffer);
}

void format_size(long size, char *buffer, size_t buffer_size) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit_index = 0;

    double size_in_units = (double)size;
    while (size_in_units >= 1024 && unit_index < 4) {
        size_in_units /= 1024;
        unit_index++;
    }

    snprintf(buffer, buffer_size, "%.2f %s", size_in_units, units[unit_index]);
}