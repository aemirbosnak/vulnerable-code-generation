//FormAI DATASET v1.0 Category: File Synchronizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

/* Function to check if the file exists */
int file_exists(const char *file_path) {
    return access(file_path, F_OK) != -1;
}

/* Function to check if the file is readable */
int file_readable(const char *file_path) {
    return access(file_path, R_OK) != -1;
}

/* Function to check if the file is writable */
int file_writable(const char *file_path) {
    return access(file_path, W_OK) != -1;
}

/* Function to copy a file from source to target */
int copy_file(const char *source, const char *target) {
    if (!file_exists(source)) {
        fprintf(stderr, "ERROR: Source file does not exist.\n");
        return 1;
    }
    if (!file_readable(source)) {
        fprintf(stderr, "ERROR: Source file is not readable.\n");
        return 1;
    }
    if (file_exists(target) && !file_writable(target)) {
        fprintf(stderr, "ERROR: Target file is not writable.\n");
        return 1;
    }
    int fd_read = open(source, O_RDONLY);
    if (fd_read == -1) {
        fprintf(stderr, "ERROR: Failed to open source file.\n");
        return 1;
    }
    int fd_write = open(target, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd_write == -1) {
        fprintf(stderr, "ERROR: Failed to create target file.\n");
        return 1;
    }
    char buffer[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(fd_read, buffer, sizeof(buffer))) > 0) {
        if (write(fd_write, buffer, bytes_read) != bytes_read) {
            fprintf(stderr, "ERROR: Failed to write to target file.\n");
            close(fd_read);
            close(fd_write);
            return 1;
        }
    }
    close(fd_read);
    close(fd_write);
    return 0;
}

/* Function to copy a directory from source to target */
int copy_directory(const char *source, const char *target) {
    DIR *dir = opendir(source);
    if (dir == NULL) {
        fprintf(stderr, "ERROR: Failed to open source directory.\n");
        return 1;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char source_path[strlen(source) + strlen(entry->d_name) + 2];
        strcpy(source_path, source);
        strcat(source_path, "/");
        strcat(source_path, entry->d_name);
        char target_path[strlen(target) + strlen(entry->d_name) + 2];
        strcpy(target_path, target);
        strcat(target_path, "/");
        strcat(target_path, entry->d_name);
        struct stat source_stat;
        if (stat(source_path, &source_stat) == -1) {
            fprintf(stderr, "ERROR: Failed to get file/directory stat.\n");
            closedir(dir);
            return 1;
        }
        if (S_ISDIR(source_stat.st_mode)) {
            if (mkdir(target_path, S_IRWXU) == -1) {
                fprintf(stderr, "ERROR: Failed to create target directory.\n");
                closedir(dir);
                return 1;
            }
            if (copy_directory(source_path, target_path) != 0) {
                closedir(dir);
                return 1;
            }
        } else if (S_ISREG(source_stat.st_mode)) {
            if (copy_file(source_path, target_path) != 0) {
                closedir(dir);
                return 1;
            }
        } else {
            fprintf(stderr, "WARNING: Unsupported mode.\n");
        }
    }
    closedir(dir);
    return 0;
}

/* Function to synchronize source to target */
int synchronize(const char *source, const char *target) {
    if (copy_directory(source, target) != 0) {
        return 1;
    }
    DIR *dir = opendir(target);
    if (dir == NULL) {
        fprintf(stderr, "ERROR: Failed to open target directory.\n");
        return 1;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char source_path[strlen(source) + strlen(entry->d_name) + 2];
        strcpy(source_path, source);
        strcat(source_path, "/");
        strcat(source_path, entry->d_name);
        char target_path[strlen(target) + strlen(entry->d_name) + 2];
        strcpy(target_path, target);
        strcat(target_path, "/");
        strcat(target_path, entry->d_name);
        if (!file_exists(source_path)) {
            if (remove(target_path) == -1) {
                fprintf(stderr, "ERROR: Failed to remove target file/directory.\n");
                closedir(dir);
                return 1;
            }
        }
    }
    closedir(dir);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "USAGE: %s source target\n", argv[0]);
        return 1;
    }
    if (synchronize(argv[1], argv[2]) != 0) {
        fprintf(stderr, "ERROR: Failed to synchronize.\n");
        return 1;
    }
    printf("Synchronization successful.\n");
    return 0;
}