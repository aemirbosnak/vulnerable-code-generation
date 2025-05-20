//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// This function displays the file size in a human-readable format
void print_size(long long size) {
    char *suffixes[] = {"B", "KB", "MB", "GB", "TB"};
    int suffix_index = 0;
    while (size >= 1024 && suffix_index < 4) {
        size /= 1024;
        suffix_index++;
    }
    printf("%lld%s\t", size, suffixes[suffix_index]);
}

// This function recursively processes directories and prints out their contents
void process_dir(char *path, int depth) {
    // Create a directory object and open it
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Unable to open directory '%s'\n", path);
        return;
    }
    
    // Iterate over the directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Ignore the "." and ".." entries
        if (entry->d_name[0] == '.') {
            continue;
        }
        
        // Create the full path for the entry
        char entry_path[1024];
        sprintf(entry_path, "%s/%s", path, entry->d_name);
        
        // Print out the size and depth information
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("|- ");
        print_size(entry->d_type == DT_DIR ? 0 : entry->d_reclen);
        printf("%s\n", entry->d_name);
        
        // Recursively process subdirectories
        if (entry->d_type == DT_DIR) {
            process_dir(entry_path, depth + 1);
        }
    }
    
    // Close the directory
    closedir(dir);
}

int main(int argc, char *argv[]) {
    // Check that the user provided a directory path
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 0;
    }
    
    // Create a stat object for the directory
    struct stat dir_stat;
    if (stat(argv[1], &dir_stat) < 0) {
        printf("Error: Unable to stat directory '%s'\n", argv[1]);
        return 0;
    }
    
    // Print out the total space used by the directory
    printf("Total space used by '%s': ", argv[1]);
    print_size(dir_stat.st_size);
    printf("\n\n");
    
    // Process the directory and print out its contents recursively
    process_dir(argv[1], 0);
    
    return 0;
}