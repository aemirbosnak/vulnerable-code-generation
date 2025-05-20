//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

#define MAX_FILE_SIZE (1024 * 1024 * 1024)
#define BACKUP_FILE "/tmp/backup.bin"
#define BACKUP_MAGIC 0xDEADBEEF

typedef struct {
    int magic;
    char filename[256];
    char data[MAX_FILE_SIZE];
} file_backup_t;

void backup_file(const char *filename) {
    int fd_src, fd_dst;
    struct stat st;
    file_backup_t *backup;

    fd_src = open(filename, O_RDONLY);
    if (fd_src < 0) {
        perror("Error opening source file");
        return;
    }

    fstat(fd_src, &st);

    fd_dst = open(BACKUP_FILE, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_dst < 0) {
        perror("Error opening backup file");
        close(fd_src);
        return;
    }

    backup = mmap(NULL, sizeof(file_backup_t) + st.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd_dst, 0);
    if (backup == MAP_FAILED) {
        perror("Error mapping backup file");
        close(fd_src);
        close(fd_dst);
        return;
    }

    strcpy(backup->filename, filename);
    backup->magic = BACKUP_MAGIC;

    read(fd_src, backup->data, st.st_size);

    close(fd_src);

    msync(backup, sizeof(file_backup_t) + st.st_size, MS_SYNC);
    munmap(backup, sizeof(file_backup_t) + st.st_size);

    close(fd_dst);
}

int main() {
    const char *files_to_backup[] = {
        "/etc/passwd",
        "/etc/group",
        "/etc/shadow"
    };

    for (int i = 0; i < sizeof(files_to_backup) / sizeof(char *); ++i) {
        backup_file(files_to_backup[i]);
        printf("Backed up %s\n", files_to_backup[i]);
    }

    return 0;
}