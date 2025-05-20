//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define BUFFER_SIZE 4096
#define RECOVERY_DIR "recovered_files"

void create_recovery_directory() {
    struct stat st = {0};

    if (stat(RECOVERY_DIR, &st) == -1) {
        mkdir(RECOVERY_DIR, 0700);
    }
}

void recover_file(const char *filepath) {
    char buffer[BUFFER_SIZE];
    int src_fd = open(filepath, O_RDONLY);
    if (src_fd < 0) {
        perror("Failed to open source file");
        return;
    }

    char *filename = strrchr(filepath, '/');
    filename = (filename == NULL) ? (char *)filepath : filename + 1;

    char dest_path[256];
    snprintf(dest_path, sizeof(dest_path), "%s/%s", RECOVERY_DIR, filename);

    int dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Failed to create destination file");
        close(src_fd);
        return;
    }

    ssize_t bytesRead;
    while ((bytesRead = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        write(dest_fd, buffer, bytesRead);
    }

    close(src_fd);
    close(dest_fd);
    
    if (bytesRead < 0) {
        perror("Failed to read file");
    } else {
        printf("Recovered: %s -> %s\n", filepath, dest_path);
    }
}

void scan_directory(const char *dir_name) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);
    
    if (dp == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            char filepath[256];
            snprintf(filepath, sizeof(filepath), "%s/%s", dir_name, entry->d_name);
            recover_file(filepath);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    create_recovery_directory();
    scan_directory(argv[1]);

    printf("\nRecovery completed! Files have been saved in '%s' directory.\n", RECOVERY_DIR);
    
    return EXIT_SUCCESS;
}