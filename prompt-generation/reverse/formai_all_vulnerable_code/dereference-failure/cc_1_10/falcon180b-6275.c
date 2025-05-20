//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

// Function to synchronize files
void synchronize_files(char* source_dir, char* dest_dir) {
    DIR* dir;
    struct dirent* ent;
    dir = opendir(source_dir);
    if (dir == NULL) {
        printf("Error: Could not open source directory.\n");
        exit(1);
    }

    char dest_path[1024];
    strcpy(dest_path, dest_dir);
    strcat(dest_path, "/");

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char path[1024];
            strcpy(path, source_dir);
            strcat(path, "/");
            strcat(path, ent->d_name);
            char dest_dir_path[1024];
            strcpy(dest_dir_path, dest_path);
            strcat(dest_dir_path, ent->d_name);
            mkdir(dest_dir_path, 0777);
            synchronize_files(path, dest_dir_path);
        } else {
            char source_path[1024];
            strcpy(source_path, source_dir);
            strcat(source_path, "/");
            strcat(source_path, ent->d_name);

            char dest_file_path[1024];
            strcpy(dest_file_path, dest_path);
            strcat(dest_file_path, ent->d_name);

            int source_fd = open(source_path, O_RDONLY);
            if (source_fd < 0) {
                printf("Error: Could not open source file %s.\n", ent->d_name);
                exit(1);
            }

            int dest_fd = open(dest_file_path, O_WRONLY | O_CREAT, 0777);
            if (dest_fd < 0) {
                printf("Error: Could not create destination file %s.\n", ent->d_name);
                exit(1);
            }

            char buffer[BUFFER_SIZE];
            while (read(source_fd, buffer, BUFFER_SIZE) > 0) {
                write(dest_fd, buffer, read(source_fd, buffer, BUFFER_SIZE));
            }

            close(source_fd);
            close(dest_fd);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        exit(1);
    }

    synchronize_files(argv[1], argv[2]);

    printf("Files synchronized successfully.\n");
    return 0;
}