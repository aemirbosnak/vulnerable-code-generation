//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PATH_SIZE 256

void recover_file(const char *deleted_file_path, const char *original_file_name) {
    if (rename(deleted_file_path, original_file_name) != 0) {
        perror("Error recovering file");
    } else {
        printf("Recovered file: %s\n", original_file_name);
    }
}

void list_deleted_files(const char *path) {
    struct dirent *entry;
    struct stat file_stat;
    char deleted_file_path[PATH_SIZE];

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    printf("Searching for deleted files in: %s\n", path);
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".deleted") != NULL) {
            snprintf(deleted_file_path, sizeof(deleted_file_path), "%s/%s", path, entry->d_name);
            printf("Found deleted file: %s\n", deleted_file_path);
            recover_file(deleted_file_path, deleted_file_path);

            // Remove ".deleted" to recover the file
            char original_file_name[PATH_SIZE];
            snprintf(original_file_name, sizeof(original_file_name), "%s/%s", path, entry->d_name);
            char temp_name[PATH_SIZE];
            snprintf(temp_name, sizeof(temp_name), "%s/%s", path, entry->d_name);
            char new_name[PATH_SIZE];
            strncpy(new_name, entry->d_name, strlen(entry->d_name) - strlen(".deleted"));
            new_name[strlen(entry->d_name) - strlen(".deleted")] = '\0';
            snprintf(original_file_name, sizeof(original_file_name), "%s/%s", path, new_name);
            rename(temp_name, original_file_name);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_with_deleted_files>\n", argv[0]);
        return EXIT_FAILURE;
    }

    list_deleted_files(argv[1]);
    return EXIT_SUCCESS;
}