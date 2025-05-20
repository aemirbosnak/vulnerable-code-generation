//FormAI DATASET v1.0 Category: File Backup System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILENAME_LEN 256
#define MAX_BACKUPS 10
#define BUFFER_SIZE 1024

void backup_file(char *filename) {
    // Ensure file exists and is readable by current user
    if (access(filename, R_OK) == -1) {
        perror("Cannot access file");
        return;
    }

    // Create backup filename with timestamp
    char backup_filename[MAX_FILENAME_LEN];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(backup_filename, MAX_FILENAME_LEN, "%Y%m%d%H%M%S_", tm);
    strncat(backup_filename, filename, MAX_FILENAME_LEN - strlen(backup_filename) - 1);

    // Open file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Cannot open file");
        return;
    }

    // Create backup directory if it doesn't exist
    struct stat backup_dir_stat;
    if (stat("backups", &backup_dir_stat) == -1) {
        mkdir("backups", 0700);
    }

    // Ensure backup directory is writable by current user
    if (access("backups", W_OK) == -1) {
        perror("Cannot write to backup directory");
        fclose(file);
        return;
    }

    // Determine next backup number and create backup filename
    int backup_num = 1;
    char full_backup_filename[MAX_FILENAME_LEN];
    do {
        snprintf(full_backup_filename, MAX_FILENAME_LEN, "backups/%s.%d", backup_filename, backup_num);
        backup_num++;
    } while (access(full_backup_filename, F_OK) != -1 && backup_num <= MAX_BACKUPS);

    // Check if maximum number of backups has been reached
    if (backup_num > MAX_BACKUPS) {
        fclose(file);
        return;
    }

    // Open backup file for writing
    FILE *backup_file = fopen(full_backup_filename, "w");
    if (backup_file == NULL) {
        perror("Cannot create backup file");
        fclose(file);
        return;
    }

    // Copy file contents to backup file
    char buffer[BUFFER_SIZE];
    size_t num_read;
    while ((num_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        fwrite(buffer, 1, num_read, backup_file);
    }

    // Close files
    fclose(file);
    fclose(backup_file);
}

int main(int argc, char **argv) {
    // Ensure filename is specified
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Backup file
    backup_file(argv[1]);

    return 0;
}