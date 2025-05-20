//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

// Function to create a unique filename for backup
char* create_backup_filename(char* original_file_name) {
    static char backup_file_name[100];
    int i = 0;

    strcpy(backup_file_name, original_file_name);
    strcat(backup_file_name, "_backup.");

    int backup_file_exists = 1;
    while (backup_file_exists) {
        i++;
        char num_str[5];
        sprintf(num_str, "%d", i);
        strcat(backup_file_name, num_str);

        struct stat backup_file_stat;
        if (stat(backup_file_name, &backup_file_stat) == -1) {
            backup_file_exists = 0;
        }
    }

    return backup_file_name;
}

// Function to copy the contents of a file to another file
int copy_file(char* src_file, char* dest_file) {
    int src_fd = open(src_file, O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file.");
        return 1;
    }

    int dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (dest_fd < 0) {
        perror("Error opening or creating destination file.");
        close(src_fd);
        return 1;
    }

    ssize_t bytes_read;
    char buffer[1024];
    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        write(dest_fd, buffer, bytes_read);
    }

    close(src_fd);
    close(dest_fd);

    return 0;
}

// Function to backup a file
void backup_file(char* file_name) {
    char backup_file_name[100];
    strcpy(backup_file_name, create_backup_filename(file_name));
    copy_file(file_name, backup_file_name);
    printf("File %s backed up to %s.\n", file_name, backup_file_name);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_to_backup>\n", argv[0]);
        return 1;
    }

    char file_name[100];
    strcpy(file_name, argv[1]);
    backup_file(file_name);

    return 0;
}