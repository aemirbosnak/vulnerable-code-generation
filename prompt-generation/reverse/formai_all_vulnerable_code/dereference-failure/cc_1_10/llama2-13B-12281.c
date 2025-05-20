//LLAMA2-13B DATASET v1.0 Category: Data recovery tool ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define BUFFER_SIZE 4096

// Structure to store file information
typedef struct {
    char *name;
    char *data;
    size_t size;
} file_info_t;

// Function to read a file from the partition
file_info_t *read_file(const char *path) {
    // Open the file in read mode
    int fd = open(path, O_RDONLY, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }

    // Read the file's contents into a buffer
    char buffer[BUFFER_SIZE];
    size_t bytes_read = read(fd, buffer, BUFFER_SIZE);
    close(fd);

    // If the read was successful, store the file's name and contents in the file_info_t struct
    if (bytes_read > 0) {
        file_info_t *fi = malloc(sizeof(file_info_t));
        fi->name = buffer;
        fi->data = buffer + strlen(buffer) + 1;
        fi->size = bytes_read;
        return fi;
    } else {
        perror("Error reading file");
        return NULL;
    }
}

// Function to write a file to the partition
void write_file(const char *path, const char *data) {
    // Open the file in write mode
    int fd = open(path, O_WRONLY|O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    // Write the file's contents to the partition
    size_t bytes_written = write(fd, data, strlen(data));
    close(fd);
}

// Function to recover data from the partition
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <partition_path>\n", argv[0]);
        return 1;
    }

    // Open the partition
    int fd = open(argv[1], O_RDONLY, 0644);
    if (fd == -1) {
        perror("Error opening partition");
        return 1;
    }

    // Read the partition's directory
    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("Error reading partition directory");
        return 1;
    }

    // Iterate over the directory's entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // If the entry is a file, read its contents and store it in a file_info_t struct
        if (entry->d_type == DT_REG) {
            char *path = malloc(strlen(argv[1]) + strlen(entry->d_name) + 2);
            sprintf(path, "%s/%s", argv[1], entry->d_name);
            file_info_t *fi = read_file(path);
            if (fi == NULL) {
                perror("Error reading file");
                continue;
            }

            // Print the file's name and contents
            printf("File: %s\n", fi->name);
            printf("Data: %s\n", fi->data);
            printf("Size: %zu\n", fi->size);
        }
    }

    // Close the directory and partition
    closedir(dir);
    close(fd);

    return 0;
}