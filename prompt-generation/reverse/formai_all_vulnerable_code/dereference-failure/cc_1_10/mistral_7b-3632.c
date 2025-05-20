//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BACKUP_DIR "backup"
#define BACKUP_EXT ".bak"

struct file_info {
    char filename[256];
    char backup_filename[256];
    off_t file_size;
};

void create_backup_dir() {
    if (access(BACKUP_DIR, 0) == -1) {
        mkdir(BACKUP_DIR, 0755);
    }
}

void create_backup(char *filename) {
    struct stat st;
    struct file_info *file_data = calloc(1, sizeof(struct file_info));
    int fd_out;
    char backup_filename[256];

    strcpy(file_data->filename, filename);
    stat(filename, &st);
    file_data->file_size = st.st_size;

    sprintf(backup_filename, "%s/%s%s", BACKUP_DIR, file_data->filename, BACKUP_EXT);

    fd_out = open(backup_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_out == -1) {
        perror("Error creating backup file");
        free(file_data);
        return;
    }

    ssize_t bytes_read;
    char buffer[1024];
    int fd_in = open(filename, O_RDONLY);

    if (fd_in == -1) {
        perror("Error opening file for reading");
        close(fd_out);
        free(file_data);
        return;
    }

    while ((bytes_read = read(fd_in, buffer, sizeof(buffer))) > 0) {
        write(fd_out, buffer, bytes_read);
    }

    close(fd_in);
    close(fd_out);

    strcpy(file_data->backup_filename, backup_filename);
    printf("Created backup: %s -> %s\n", filename, backup_filename);

    free(file_data);
}

void backup_file(char *filename) {
    create_backup_dir();
    create_backup(filename);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_to_backup>\n", argv[0]);
        return 1;
    }

    backup_file(argv[1]);

    return 0;
}