//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Struct to hold file information
struct file {
    char name[255];
    long size;
};

// Recursive function to find all files in directory and its subdirectories
void analyze_directory(char *path, struct file *files, int *file_count) {
    DIR *dir;
    struct dirent *ent;
    char new_path[255];

    if ((dir = opendir(path)) != NULL) {
        // Loop through directory
        while ((ent = readdir(dir)) != NULL) {
            // Ignore '.' and '..' entries
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }

            // Create full file path
            strcpy(new_path, path);
            strcat(new_path, "/");
            strcat(new_path, ent->d_name);

            // Check if file or directory
            DIR *subdir = opendir(new_path);
            if (subdir != NULL) {
                // If directory, recursively analyze it
                closedir(subdir);
                analyze_directory(new_path, files, file_count);
            } else {
                // If file, add it to file list
                files[*file_count].size = 0;
                strcpy(files[*file_count].name, new_path);
                FILE *fp = fopen(new_path, "r");
                if (fp != NULL) {
                    fseek(fp, 0L, SEEK_END);
                    files[*file_count].size = ftell(fp);
                    fclose(fp);
                }
                *file_count += 1;
            }
        }
        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    // Check for path argument
    if (argc < 2) {
        printf("Usage: %s [path]\n", argv[0]);
        return 1;
    }

    char *path = argv[1];

    // Analyze directory
    struct file files[10000];
    int file_count = 0;
    analyze_directory(path, files, &file_count);

    // Sort files by size in descending order
    for (int i = 0; i < file_count - 1; i++) {
        for (int j = i + 1; j < file_count; j++) {
            if (files[i].size < files[j].size) {
                struct file temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }

    // Print results
    printf("Disk space usage in %s:\n", path);
    float total_size = 0;
    for (int i = 0; i < file_count; i++) {
        printf("%s - %.2f MB\n", files[i].name, files[i].size / (1024.0 * 1024.0));
        total_size += files[i].size;
    }
    printf("Total size - %.2f MB\n", total_size / (1024.0 * 1024.0));

    return 0;
}