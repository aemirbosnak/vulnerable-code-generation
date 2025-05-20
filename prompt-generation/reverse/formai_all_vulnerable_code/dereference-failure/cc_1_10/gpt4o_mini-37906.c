//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

typedef struct FileInfo {
    char *path;
    struct stat statbuf;
} FileInfo;

void synchronize_files(const char *source, const char *destination);
int copy_file(const char *src, const char *dst);
int file_is_identical(const char *file1, const char *file2);
void list_directory(const char *dir, void (*callback)(const char *));
void sync_files_in_directory(const char *source, const char *destination);

void file_callback(const char *filename) {
    printf("Found file: %s\n", filename);
}

void synchronize_files(const char *source, const char *destination) {
    struct stat st;
    
    if (stat(source, &st) == -1) {
        perror("Error accessing source");
        return;
    }

    if (S_ISDIR(st.st_mode)) {
        sync_files_in_directory(source, destination);
    } else {
        const char *dest_file = strcat(strdup(destination), strrchr(source, '/'));
        if (!file_is_identical(source, dest_file)) {
            copy_file(source, dest_file);
        }
    }
}

void sync_files_in_directory(const char *source, const char *destination) {
    DIR *dir = opendir(source);
    struct dirent *entry;

    if (!dir) {
        perror("Could not open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char source_path[MAX_PATH];
            char dest_path[MAX_PATH];
            snprintf(source_path, sizeof(source_path), "%s/%s", source, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", destination, entry->d_name);

            synchronize_files(source_path, dest_path);
        }
    }
    closedir(dir);
}

int copy_file(const char *src, const char *dst) {
    int src_fd = open(src, O_RDONLY);
    if (src_fd < 0) {
        perror("Can't open source file");
        return -1;
    }

    int dst_fd = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dst_fd < 0) {
        perror("Can't open destination file");
        close(src_fd);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(src_fd, buffer, sizeof(buffer))) > 0) {
        if (write(dst_fd, buffer, bytesRead) != bytesRead) {
            perror("Write error");
            close(src_fd);
            close(dst_fd);
            return -1;
        }
    }

    if (bytesRead < 0) {
        perror("Read error");
    }

    close(src_fd);
    close(dst_fd);
    return 0;
}

int file_is_identical(const char *file1, const char *file2) {
    struct stat stat1, stat2;

    if (stat(file1, &stat1) == -1 || stat(file2, &stat2) == -1) {
        return 0;
    }

    if (stat1.st_size != stat2.st_size) {
        return 0;
    }

    int fd1 = open(file1, O_RDONLY);
    int fd2 = open(file2, O_RDONLY);
    if (fd1 == -1 || fd2 == -1) {
        if (fd1 != -1) close(fd1);
        if (fd2 != -1) close(fd2);
        return 0;
    }

    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    while (1) {
        ssize_t bytesRead1 = read(fd1, buffer1, sizeof(buffer1));
        ssize_t bytesRead2 = read(fd2, buffer2, sizeof(buffer2));

        if (bytesRead1 == -1 || bytesRead2 == -1) {
            close(fd1);
            close(fd2);
            return 0;
        }

        if (bytesRead1 == 0 && bytesRead2 == 0) {
            break; // EOF reached for both
        }

        if (bytesRead1 != bytesRead2 || memcmp(buffer1, buffer2, bytesRead1) != 0) {
            close(fd1);
            close(fd2);
            return 0; // Files are not identical
        }
    }

    close(fd1);
    close(fd2);
    return 1; // Files are identical
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    synchronize_files(argv[1], argv[2]);
    return 0;
}