//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void print_usage(char *program_name){
    printf("Usage: %s <directory>\n", program_name);
}

unsigned long long get_directory_size(char *path){
    DIR *directory = opendir(path);
    struct dirent *direntry;
    unsigned long long total_size = 0;

    if(directory == NULL){
        fprintf(stderr, "Error: Failed to open directory %s\n", path);
        return 0;
    }

    while((direntry = readdir(directory)) != NULL){
        char *entry_path = malloc((strlen(path) + strlen(direntry->d_name) + 2) * sizeof(char));
        strcpy(entry_path, path);
        strcat(entry_path, "/");
        strcat(entry_path, direntry->d_name);

        struct stat entry_stat;

        if(stat(entry_path, &entry_stat) == -1){
            fprintf(stderr, "Error: Failed to get file or directory stats for %s\n", entry_path);
            return 0;
        }

        if(strcmp(direntry->d_name, ".") != 0 && strcmp(direntry->d_name, "..") != 0){
            if(S_ISDIR(entry_stat.st_mode)){
                total_size += get_directory_size(entry_path);
            } else if(S_ISREG(entry_stat.st_mode)){
                total_size += entry_stat.st_size;
            }
        }

        free(entry_path);
    }

    closedir(directory);

    return total_size;
}

int main(int argc, char **argv){
    if(argc != 2){
        print_usage(argv[0]);
        return 1;
    }

    char *path = argv[1];

    unsigned long long total_size = get_directory_size(path);

    float size_kb = total_size / 1024.0;
    float size_mb = size_kb / 1024.0;
    float size_gb = size_mb / 1024.0;

    printf("Total disk space used by %s:\n", path);
    printf("%.2f GB\n", size_gb);

    return 0;
}