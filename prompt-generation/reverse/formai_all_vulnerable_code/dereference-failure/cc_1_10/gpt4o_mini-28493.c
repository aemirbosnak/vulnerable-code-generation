//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILES 100
#define FILENAME_SIZE 256
#define BUFFER_SIZE 1024

typedef struct {
    char file_name[FILENAME_SIZE];
    struct stat file_info;
} File;

void scan_directory(const char *directory_path, File *files, int *file_count) {
    struct dirent *entry;   
    DIR *dp = opendir(directory_path);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {  // Regular file
            snprintf(files[*file_count].file_name, FILENAME_SIZE, "%s/%s", directory_path, entry->d_name);
            if (stat(files[*file_count].file_name, &files[*file_count].file_info) == 0) {
                (*file_count)++;
                if (*file_count >= MAX_FILES) {
                    break; // Limit reached
                }
            }
        }
    }

    closedir(dp);
}

void recover_files(File *files, int file_count) {
    char buffer[BUFFER_SIZE];
    size_t bytes;
    FILE *source_file, *dest_file;
    
    for (int i = 0; i < file_count; ++i) {
        char recovery_filename[FILENAME_SIZE];
        snprintf(recovery_filename, FILENAME_SIZE, "recovered_%s", files[i].file_name);

        source_file = fopen(files[i].file_name, "rb");
        dest_file = fopen(recovery_filename, "wb");

        if (source_file && dest_file) {
            while ((bytes = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                fwrite(buffer, 1, bytes, dest_file);
            }
            printf("Recovered: %s\n", recovery_filename);
        } else {
            printf("Failed to recover: %s\n", files[i].file_name);
        }

        if (source_file) fclose(source_file);
        if (dest_file) fclose(dest_file);
    }
}

void print_help() {
    printf("Usage: data_recovery_tool <directory_path>\n");
    printf("Scans the specified directory for files and attempts to recover them.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_help();
        return EXIT_FAILURE;
    }
    
    File files[MAX_FILES];
    int file_count = 0;
    
    scan_directory(argv[1], files, &file_count);
    
    if (file_count == 0) {
        printf("No files found in the specified directory.\n");
        return EXIT_FAILURE;
    }

    recover_files(files, file_count);
    
    return EXIT_SUCCESS;
}