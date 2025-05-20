//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define COLOR_DEFAULT "\x1B[0m"
#define COLOR_RED "\x1B[31m"
#define COLOR_GREEN "\x1B[32m"
#define COLOR_YELLOW "\x1B[33m"
#define COLOR_BLUE "\x1B[34m"
#define COLOR_MAGENTA "\x1B[35m"
#define COLOR_CYAN "\x1B[36m"
#define COLOR_WHITE "\x1B[37m"

const char* get_color(int index) {
    switch (index) {
        case 0: return COLOR_RED;
        case 1: return COLOR_GREEN;
        case 2: return COLOR_YELLOW;
        case 3: return COLOR_BLUE;
        case 4: return COLOR_MAGENTA;
        case 5: return COLOR_CYAN;
        default: return COLOR_WHITE;
    }
}

void analyze_directory(char* path, int depth, int* color_index, int* total_size) {
    DIR* dir;
    struct dirent* entry;
    struct stat file_stat;
    int i, size = 0;
    char full_path[1024];
    
    dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Failed to open directory: %s\n", path);
        exit(1);
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (lstat(full_path, &file_stat) == -1) {
            fprintf(stderr, "Failed to get file stat: %s\n", full_path);
            continue;
        }
        
        if (S_ISREG(file_stat.st_mode)) {
            size += file_stat.st_size;
        }
        else if (S_ISDIR(file_stat.st_mode)) {
            printf("%s", get_color(*color_index));
            for (i = 0; i < depth; i++)
                printf("|  ");
            printf("|--%s/\n", entry->d_name);
            (*color_index) = ((*color_index) + 1) % 7;
            analyze_directory(full_path, depth + 1, color_index, total_size);
        }
    }
    
    (*total_size) += size;
    printf("%s", get_color(*color_index));
    for (i = 0; i < depth; i++)
        printf("|  ");
    printf("|--Total size: %d bytes\n", size);
    closedir(dir);
}

int main(int argc, char* argv[]) {
    char* path;
    int color_index = 0, total_size = 0;
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }
    
    path = argv[1];
    printf("\n%sAnalyzing disk space usage of %s%s...\n", COLOR_MAGENTA, COLOR_GREEN, path);
    analyze_directory(path, 0, &color_index, &total_size);
    printf("%sTotal size of %s: %d bytes%s\n", COLOR_MAGENTA, path, total_size, COLOR_DEFAULT);
    
    return 0;
}