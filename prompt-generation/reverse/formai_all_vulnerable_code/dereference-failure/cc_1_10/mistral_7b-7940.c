//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10
#define BUF_SIZE 4096
#define BACKUP_DIR "backup"
#define BACKUP_EXT ".bkp"

struct file_meta {
    char filename[256];
    off_t file_size;
    time_t last_modified;
};

void make_backup_dir() {
    if (access(BACKUP_DIR, 0) == -1) {
        mkdir(BACKUP_DIR, 0755);
    }
}

int create_backup_file(const char *filename) {
    int fd;
    struct file_meta *file_meta;
    char backup_filename[256];

    if ((fd = open(filename, O_RDONLY)) < 0) {
        perror("Error opening file for read");
        return 1;
    }

    if ((file_meta = malloc(sizeof(struct file_meta))) == NULL) {
        perror("Error allocating memory for file meta data");
        close(fd);
        return 1;
    }

    strcpy(file_meta->filename, filename);
    file_meta->file_size = lseek(fd, 0, SEEK_END);
    file_meta->last_modified = time(NULL);

    snprintf(backup_filename, sizeof(backup_filename), "%s/%s%s", BACKUP_DIR, filename, BACKUP_EXT);

    if (open(backup_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644) < 0) {
        perror("Error creating backup file");
        free(file_meta);
        close(fd);
        return 1;
    }

    ssize_t bytes_read;
    char buffer[BUF_SIZE];

    while ((bytes_read = read(fd, buffer, BUF_SIZE)) > 0) {
        write(fileno(stdout), buffer, bytes_read);
        write(fileno(backup_filename), buffer, bytes_read);
    }

    close(fd);
    free(file_meta);

    printf("Created backup file: %s\n", backup_filename);
    return 0;
}

int main(int argc, char *argv[]) {
    make_backup_dir();

    if (argc < 2) {
        printf("Usage: %s <file_to_backup>\n", argv[0]);
        return 1;
    }

    return create_backup_file(argv[1]);
}