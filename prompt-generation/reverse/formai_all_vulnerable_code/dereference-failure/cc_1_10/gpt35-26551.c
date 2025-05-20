//FormAI DATASET v1.0 Category: File Backup System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>

#define BUFFER_SIZE 1024

void copy_file(char *source_file_path, char *destination_file_path) {
    int source_file, destination_file, bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    if ((source_file = open(source_file_path, O_RDONLY)) == -1) {
        printf("Error opening source file %s\n", source_file_path);
        return;
    }

    if ((destination_file = open(destination_file_path, O_CREAT|O_TRUNC|O_WRONLY, 0644)) == -1) {
        printf("Error opening destination file %s\n", destination_file_path);
        close(source_file);
        return;
    }

    while ((bytes_read = read(source_file, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(destination_file, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            printf("Error writing to destination file %s\n", destination_file_path);
            close(source_file);
            close(destination_file);
            return;
        }
    }

    close(source_file);
    close(destination_file);
    printf("Successfully copied file %s to %s\n", source_file_path, destination_file_path);
}

void backup_file(char *file_path, char *backup_path) {
    struct stat source_stat;
    struct stat destination_stat;

    if (stat(file_path, &source_stat) == -1) {
        printf("Error getting file info for %s\n", file_path);
        return;
    }

    if (stat(backup_path, &destination_stat) == -1) {
        if (errno != ENOENT) {
            printf("Error getting file info for %s\n", backup_path);
            return;
        }
    }

    if (destination_stat.st_mtime >= source_stat.st_mtime) {
        printf("File %s has not been modified, no need to backup\n", file_path);
        return;
    }

    printf("Backing up file %s to %s\n", file_path, backup_path);
    copy_file(file_path, backup_path);
}

int main() {
    char source_file_path[256];
    char destination_file_path[256];
    char backup_dir_path[256];

    printf("Enter source file path:\n");
    scanf("%s", source_file_path);

    printf("Enter destination file path:\n");
    scanf("%s", destination_file_path);

    printf("Enter backup directory path:\n");
    scanf("%s", backup_dir_path);

    char backup_file_path[512];
    sprintf(backup_file_path, "%s%s", backup_dir_path, strrchr(source_file_path, '/'));

    backup_file(source_file_path, backup_file_path);
    copy_file(source_file_path, destination_file_path);

    return 0;
}