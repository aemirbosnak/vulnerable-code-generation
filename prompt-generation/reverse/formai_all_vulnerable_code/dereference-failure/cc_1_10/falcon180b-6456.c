//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_BACKUP_FILES 10
#define MAX_PATH_LENGTH 256
#define BACKUP_DIR "backups"

typedef struct {
    char path[MAX_PATH_LENGTH];
    int size;
    time_t mtime;
} backup_file_t;

void backup_file(const char *path) {
    backup_file_t *backup;
    int i, fd;
    struct stat st;

    if (stat(path, &st) == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    if (S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Error: %s is a directory\n", path);
        exit(1);
    }

    if (mkdir(BACKUP_DIR, 0777) == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    fd = open(BACKUP_DIR, O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    backup = malloc(sizeof(backup_file_t) * MAX_BACKUP_FILES);

    if (backup == NULL) {
        fprintf(stderr, "Error: out of memory\n");
        exit(1);
    }

    for (i = 0; i < MAX_BACKUP_FILES; i++) {
        if (read(fd, &backup[i], sizeof(backup_file_t))!= sizeof(backup_file_t)) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(1);
        }

        if (backup[i].size == st.st_size && backup[i].mtime == st.st_mtime) {
            fprintf(stdout, "File is already backed up.\n");
            exit(0);
        }
    }

    close(fd);

    strncpy(backup[0].path, path, MAX_PATH_LENGTH);
    backup[0].size = st.st_size;
    backup[0].mtime = st.st_mtime;

    fd = open(BACKUP_DIR, O_WRONLY | O_CREAT | O_APPEND, 0777);

    if (fd == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    if (write(fd, backup, sizeof(backup_file_t) * MAX_BACKUP_FILES)!= sizeof(backup_file_t) * MAX_BACKUP_FILES) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    close(fd);

    fprintf(stdout, "File backed up successfully.\n");
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    backup_file(argv[1]);

    return 0;
}