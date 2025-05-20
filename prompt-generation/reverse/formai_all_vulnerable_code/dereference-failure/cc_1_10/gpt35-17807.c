//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void analyze_directory(char* path, int depth);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please specify a directory to analyze.\n");
        exit(0);
    }

    char *directory_path = argv[1];
    printf("Analyzing directory: %s\n\n", directory_path);
    analyze_directory(directory_path, 0);

    return 0;
}

void analyze_directory(char* path, int depth) {
    DIR *directory = opendir(path);
    struct dirent *entry;
    struct stat data;
    int total_file_size = 0;
    int num_files = 0;  
    char tabs[depth + 1];

    for (int i = 0; i < depth; i++) {
        tabs[i] = '\t';
    }

    tabs[depth] = '\0';

    if (directory) {
        while ((entry = readdir(directory)) != NULL) {
            char *file_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
            sprintf(file_path, "%s/%s", path, entry->d_name);

            if (stat(file_path, &data) == 0) {
                if (S_ISDIR(data.st_mode)) {
                    if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                        printf("%s%s/\n", tabs, entry->d_name);
                        analyze_directory(file_path, depth+1);
                    }
                } else {
                    printf("%s%s (%li bytes)\n", tabs, entry->d_name, data.st_size);
                    total_file_size += data.st_size;
                    num_files++;
                }
            }

            free(file_path);
        }

        closedir(directory);

        printf("%sTotal directory size: %i bytes (across %i files)\n\n", tabs, total_file_size, num_files);
    }
}