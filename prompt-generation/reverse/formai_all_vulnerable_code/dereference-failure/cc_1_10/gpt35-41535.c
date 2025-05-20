//FormAI DATASET v1.0 Category: File Backup System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define BLOCK_SIZE 4096 // block size of 4 KB
#define MAX_FILENAME_SIZE 256 // maximum filename size
#define MAX_BACKUP_FILES 5 // maximum number of backup files to keep

/* Function to create a backup file */
void create_backup_file(char* filename, char* backup_filename) {

    /* Open the source file */
    int src_fd = open(filename, O_RDONLY);
    if (src_fd == -1) {
        printf("Unable to open source file\n");
        return;
    }

    /* Create the backup file */
    int dest_fd = open(backup_filename, O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
    if (dest_fd == -1) {
        printf("Unable to create backup file\n");
        close(src_fd);
        return;
    }

    /* Copy data from source file to backup file */
    char buf[BLOCK_SIZE];
    int bytes_read;
    while ((bytes_read = read(src_fd, buf, BLOCK_SIZE)) > 0) {
        write(dest_fd, buf, bytes_read);
    }

    /* Close the file descriptors */
    close(src_fd);
    close(dest_fd);

    printf("Backup file created successfully\n");
}

/* Function to delete the oldest backup file */
void delete_oldest_backup(char* backup_prefix) {

    struct stat st;
    struct timespec ts_now;
    char filename[MAX_FILENAME_SIZE];
    char oldest_filename[MAX_FILENAME_SIZE];
    int oldest_time = -1;
    int count = 0;

    /* Loop through all backup files */
    while (1) {
        snprintf(filename, MAX_FILENAME_SIZE, "%s%d", backup_prefix, count);
        if (stat(filename, &st) == -1) {
            /* No more backup files */
            break;
        }
        ts_now = st.st_mtim;
        /* Check if this is the oldest backup file */
        if (oldest_time == -1 || (ts_now.tv_sec < oldest_time)) {
            oldest_time = ts_now.tv_sec;
            strcpy(oldest_filename, filename);
        }
        count++;
    }

    /* Delete the oldest backup file */
    if (oldest_time != -1) {
        if (remove(oldest_filename) == 0) {
            printf("Oldest backup file %s deleted successfully\n", oldest_filename);
        } else {
            printf("Error deleting oldest backup file %s\n", oldest_filename);
        }
    }
}

int main(int argc, char* argv[]) {

    char filename[MAX_FILENAME_SIZE];
    char backup_prefix[MAX_FILENAME_SIZE];
    char backup_filename[MAX_FILENAME_SIZE];
    int backup_count = 0;

    /* Get the filename and backup prefix from arguments */
    if (argc < 3) {
        printf("Usage: %s filename backup_prefix\n", argv[0]);
        return 1;
    }
    strncpy(filename, argv[1], MAX_FILENAME_SIZE);
    strncpy(backup_prefix, argv[2], MAX_FILENAME_SIZE);

    /* Create the backup filename by adding the backup count to the backup prefix */
    snprintf(backup_filename, MAX_FILENAME_SIZE, "%s%d", backup_prefix, backup_count);

    /* Create the first backup file */
    create_backup_file(filename, backup_filename);
    backup_count++;

    /* Keep creating backup files as needed */
    while (1) {
        /* Sleep for 1 hour */
        sleep(3600);

        /* Check if we need to delete the oldest backup file */
        if (backup_count > MAX_BACKUP_FILES) {
            delete_oldest_backup(backup_prefix);
        }

        /* Create the next backup file */
        snprintf(backup_filename, MAX_FILENAME_SIZE, "%s%d", backup_prefix, backup_count);
        create_backup_file(filename, backup_filename);
        backup_count++;
    }

    return 0;
}