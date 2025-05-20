//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void execute_command(const char *command) {
    system(command);
}

void print_usage() {
    printf("Usage: disk_space_analyzer <directory>\n");
    printf("Examples:\n");
    printf("  disk_space_analyzer .\n");
    printf("  disk_space_analyzer /home/user\n");
}

int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void analyze_directory(const char *dir_name, int depth) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);

    if (dp == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_name, entry->d_name);
            
        struct stat file_info;
        if (stat(full_path, &file_info) < 0) {
            perror("Stat error");
            continue;
        }
        
        // Print file or directory info
        for (int i = 0; i < depth; i++) putchar('\t'); // Indent based on depth
        printf("%s\t%lld bytes\t%s\n", full_path, (long long)file_info.st_size, 
               is_directory(full_path) ? "[DIR]" : "[FILE]");
        
        if (is_directory(full_path)) {
            analyze_directory(full_path, depth + 1); // Recurse into the directory
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *base_dir = argv[1];
    
    if (!is_directory(base_dir)) {
        printf("Error: The specified path is not a directory: %s\n", base_dir);
        return EXIT_FAILURE;
    }

    printf("Analyzing disk space usage in directory: %s\n", base_dir);
    analyze_directory(base_dir, 0); // Start analyzing from the base directory

    return EXIT_SUCCESS;
}