//FormAI DATASET v1.0 Category: File Synchronizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void synchronize(char *source, char *destination) {
    DIR *source_dir, *dest_dir;
    struct dirent *source_entry, *dest_entry;
    struct stat source_info, dest_info;
    char *source_file, *dest_file;

    source_dir = opendir(source);
    dest_dir = opendir(destination);

    while ((source_entry = readdir(source_dir)) != NULL) {
        source_file = source_entry->d_name;

        if (strcmp(source_file, ".") == 0 || strcmp(source_file, "..") == 0) {
            continue;
        }

        char source_path[512];
        sprintf(source_path, "%s/%s", source, source_file);
        int source_file_exists = lstat(source_path, &source_info);

        if (source_file_exists < 0) {
            printf("Error: Could not get info for %s\n", source_path);
            continue;
        }

        if (S_ISREG(source_info.st_mode)) {
            dest_entry = readdir(dest_dir);
            dest_file = dest_entry->d_name;

            if (strcmp(dest_file, ".") != 0 && strcmp(dest_file, "..") != 0) {
                char dest_path[512];
                sprintf(dest_path, "%s/%s", destination, dest_file);
                int dest_file_exists = lstat(dest_path, &dest_info);

                if (!dest_file_exists || (dest_file_exists && source_info.st_mtime > dest_info.st_mtime)) {
                    FILE *source_fd, *dest_fd;
                    source_fd = fopen(source_path, "r");
                    dest_fd = fopen(dest_path, "w");

                    if (source_fd == NULL || dest_fd == NULL) {
                        printf("Error: Could not open file\n");
                        continue;
                    }

                    char c = fgetc(source_fd);

                    while (c != EOF) {
                        fputc(c, dest_fd);
                        c = fgetc(source_fd);
                    }

                    printf("File copied: %s -> %s\n", source_path, dest_path);
                    fclose(source_fd);
                    fclose(dest_fd);
                }
            }
        }
    }

    closedir(source_dir);
    closedir(dest_dir);
}

int main() {
    char *source = "/Users/user/Documents/C";
    char *destination = "/Users/user/Desktop/Copy";

    synchronize(source, destination);

    return 0;
}