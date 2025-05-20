//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_FILES 1000
#define MAX_PATH 512

typedef struct {
    char name[MAX_PATH];
    char extension[10];
    off_t size;
    time_t created;
} FileMetadata;

void extract_metadata(const char *directory_path, FileMetadata *files, int *file_count) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *directory = opendir(directory_path);

    if (directory == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_REG) {  // Only regular files
            char full_path[MAX_PATH];
            snprintf(full_path, sizeof(full_path), "%s/%s", directory_path, entry->d_name);

            if (stat(full_path, &file_stat) == 0) {
                strncpy(files[*file_count].name, entry->d_name, MAX_PATH);
                files[*file_count].size = file_stat.st_size;
                files[*file_count].created = file_stat.st_ctime;

                const char *ext = strrchr(entry->d_name, '.');
                if (ext != NULL) {
                    strncpy(files[*file_count].extension, ext + 1, sizeof(files[*file_count].extension) - 1);
                } else {
                    strncpy(files[*file_count].extension, "none", sizeof(files[*file_count].extension) - 1);
                }

                (*file_count)++;
                if (*file_count >= MAX_FILES) {
                    break;
                }
            }
        }
    }
    closedir(directory);
}

void print_metadata(const FileMetadata *files, int file_count) {
    printf("File Name\tFile Size (bytes)\tCreated\t\tFile Extension\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < file_count; i++) {
        printf("%s\t\t%ld\t\t%s\t%s\n", files[i].name, files[i].size, ctime(&files[i].created), files[i].extension);
    }
}

void sort_files_by_size(FileMetadata *files, int file_count) {
    for (int i = 0; i < file_count - 1; i++) {
        for (int j = i + 1; j < file_count; j++) {
            if (files[i].size > files[j].size) {
                FileMetadata temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }
}

void save_metadata_to_file(const FileMetadata *files, int file_count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Could not open file for writing");
        return;
    }

    fprintf(file, "File Name,File Size (bytes),Created,File Extension\n");
    for (int i = 0; i < file_count; i++) {
        fprintf(file, "%s,%ld,%s,%s\n", files[i].name, files[i].size, ctime(&files[i].created), files[i].extension);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileMetadata files[MAX_FILES];
    int file_count = 0;

    extract_metadata(argv[1], files, &file_count);
    sort_files_by_size(files, file_count);
    print_metadata(files, file_count);

    save_metadata_to_file(files, file_count, "metadata.csv");

    return EXIT_SUCCESS;
}