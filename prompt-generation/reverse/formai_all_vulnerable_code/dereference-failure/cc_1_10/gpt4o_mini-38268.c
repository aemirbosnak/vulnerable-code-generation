//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define BLOCK_SIZE 512
#define MAX_FILES 100
#define IMAGE_FILE "recovered_data.img"
#define RECOVERY_DIR "recovered_files"

void create_directory(const char *dirname) {
    if (mkdir(dirname, 0777) != 0) {
        if (errno != EEXIST) {
            perror("Failed to create directory");
            exit(EXIT_FAILURE);
        }
    }
}

void write_file(const char *filename, void *buffer, size_t size) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Failed to open file for writing");
        return;
    }
    write(fd, buffer, size);
    close(fd);
}

void recover_data(const char *drive_image) {
    int fd = open(drive_image, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open drive image");
        return;
    }

    unsigned char buffer[BLOCK_SIZE];
    size_t bytes_read, total_recovered = 0;
    char recovered_filename[256];
    create_directory(RECOVERY_DIR);

    while ((bytes_read = read(fd, buffer, BLOCK_SIZE)) > 0) {
        total_recovered += bytes_read;
        sprintf(recovered_filename, "%s/recovered_file_%zu.dat", RECOVERY_DIR, total_recovered / BLOCK_SIZE);
        write_file(recovered_filename, buffer, bytes_read);
        printf("Recovered file: %s, Size: %zu bytes\n", recovered_filename, bytes_read);
    }

    if (bytes_read < 0) {
        perror("Error reading drive image");
    }

    close(fd);
    printf("Total bytes recovered: %zu\n", total_recovered);
}

void list_recovered_files(const char *dirname) {
    struct dirent *entry;
    DIR *dp = opendir(dirname);
    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }

    printf("Recovered files:\n");
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) {
            printf(" - %s\n", entry->d_name);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <drive_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    recover_data(argv[1]);
    list_recovered_files(RECOVERY_DIR);

    return EXIT_SUCCESS;
}