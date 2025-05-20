//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void print_size(unsigned long long size) {
    if (size >= 1ULL << 30)
        printf("%.2f GB\n", size / (double)(1ULL << 30));
    else if (size >= 1ULL << 20)
        printf("%.2f MB\n", size / (double)(1ULL << 20));
    else if (size >= 1ULL << 10)
        printf("%.2f KB\n", size / (double)(1ULL << 10));
    else
        printf("%llu Bytes\n", size);
}

unsigned long long get_directory_size(const char *dir_path) {
    unsigned long long total_size = 0;
    struct dirent *entry;
    struct stat file_info;

    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("Could not open directory");
        return 0;
    }

    // Wonderful loop to explore each file and folder
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
            
            // Gathering file statistics
            if (stat(full_path, &file_info) == 0) {
                if (S_ISDIR(file_info.st_mode)) {
                    // If it's a directory, dive deeper (recursion!)
                    total_size += get_directory_size(full_path);
                } else {
                    // If it's a file, add its size to the total
                    total_size += file_info.st_size;
                }
            }
        }
    }
    
    closedir(dir);
    return total_size;
}

void analyze_disk_space(const char *path) {
    printf("\n🌟 Analyzing Disk Space at: %s 🌟\n\n", path);
    unsigned long long total_size = get_directory_size(path);
    printf("😊 Total size for '%s': ", path);
    print_size(total_size);
}

int main(int argc, char *argv[]) {
    printf("👋 Welcome to the Cheery Disk Space Analyzer! 🌈\n\n");
    
    if (argc < 2) {
        printf("🎉 No path provided! Analyzing your current directory instead.\n");
        analyze_disk_space(".");
    } else {
        // Iterate through the provided paths
        for (int i = 1; i < argc; i++) {
            printf("\n📂 Analyzing: %s\n", argv[i]);
            analyze_disk_space(argv[i]);
        }
    }

    printf("\n✨ Thank you for using the Cheery Disk Space Analyzer! Have a wonderful day! 🌸\n");
    
    return 0;
}