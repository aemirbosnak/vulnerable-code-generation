//FormAI DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int copy_file(char *source_path, char *destination_path)
{
    int input_fd, output_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];
    struct stat file_stat;

    input_fd = open(source_path, O_RDONLY);

    if (input_fd == -1) {
        perror("Error opening input file");
        return 1;
    }

    fstat(input_fd, &file_stat);

    output_fd = open(destination_path, O_WRONLY | O_CREAT, file_stat.st_mode);

    if (output_fd == -1) {
        perror("Error creating output file");
        return 1;
    }

    while (bytes_read = read(input_fd, buffer, BUFFER_SIZE)) {
        if ((bytes_read == -1) && (errno != EINTR)) {
            perror("Error reading input file");
            return 1;
        } else if (bytes_read > 0) {
            char *out_ptr = buffer;
            while (bytes_written = write(output_fd, out_ptr, bytes_read)) {
                if ((bytes_written == -1) && (errno != EINTR)) {
                    perror("Error writing output file");
                    return 1;
                } else if (bytes_written == bytes_read) {
                    break;
                } else if (bytes_written > 0) {
                    out_ptr += bytes_written;
                    bytes_read -= bytes_written;
                }
            }

            if (bytes_written == -1) {
                perror("Error writing output file");
                return 1;
            }
        }
    }

    fsync(output_fd);
    close(input_fd);
    close(output_fd);
    return 0;
}

int copy_directory(char *source_path, char *destination_path)
{
    DIR *source_dir;
    struct dirent *dir_entry;

    if ((source_dir = opendir(source_path)) == NULL) {
        perror("Error opening source directory");
        return 1;
    }

    while ((dir_entry = readdir(source_dir)) != NULL) {
        if (strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0) {
            char source_entry_path[1024], dest_entry_path[1024];
            sprintf(source_entry_path, "%s/%s", source_path, dir_entry->d_name);
            sprintf(dest_entry_path, "%s/%s", destination_path, dir_entry->d_name);

            struct stat stat_buf;

            if (stat(source_entry_path, &stat_buf) == -1) {
                perror("Error copying file");
                return 1;
            }

            if (S_ISDIR(stat_buf.st_mode)) {
                mkdir(dest_entry_path, stat_buf.st_mode);
                copy_directory(source_entry_path, dest_entry_path);
            } else {
                copy_file(source_entry_path, dest_entry_path);
            }
        }
    }

    closedir(source_dir);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s source destination\n", argv[0]);
        return 0;
    }

    copy_directory(argv[1], argv[2]);

    printf("Done copying.\n");

    return 0;
}