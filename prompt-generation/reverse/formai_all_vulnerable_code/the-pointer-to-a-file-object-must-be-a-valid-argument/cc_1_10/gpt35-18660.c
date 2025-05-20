//FormAI DATASET v1.0 Category: File Backup System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

// Define constants.
#define MAX_FILE_ENTRIES 1000
#define BUFFER_SIZE 1024
#define BACKUP_FOLDER_NAME "backup"

// Define structs.
struct file_entry {
    char filename[BUFFER_SIZE];
    size_t filesize;
    time_t modified_time;
};

// Declare functions.
void backup(char* file_list_file);
void create_backup_folder();
void read_file_list(char* file_list_file, struct file_entry* file_entries, int* num_entries);
void backup_files(struct file_entry* file_entries, int num_entries);
void create_backup_filename(char* backup_file, char* filename);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: backup <file list>\n");
        exit(1);
    }

    backup(argv[1]);

    return 0;
}

void backup(char* file_list_file) {
    struct file_entry file_entries[MAX_FILE_ENTRIES];
    int num_entries = 0;

    // Read the list of files to back up.
    read_file_list(file_list_file, file_entries, &num_entries);

    if (num_entries == 0) {
        printf("No files to back up.\n");
        return;
    }

    // Create the backup folder.
    create_backup_folder();

    // Create backups of the files.
    backup_files(file_entries, num_entries);
}

void create_backup_folder() {
    struct stat st = {0};

    // Create backup folder if it does not exist.
    if (stat(BACKUP_FOLDER_NAME, &st) == -1) {
        mkdir(BACKUP_FOLDER_NAME, 0700);
    }
}

void read_file_list(char* file_list_file, struct file_entry* file_entries, int* num_entries) {
    char buffer[BUFFER_SIZE];
    char* filename;
    FILE* fp = fopen(file_list_file, "r");

    // Read in each filename from the list and add to file_entries.
    while (fgets(buffer, sizeof(buffer), fp) && *num_entries < MAX_FILE_ENTRIES) {
        // Remove newline character from buffer.
        buffer[strcspn(buffer, "\n")] = 0;
        
        // Get file size and modified time.
        struct stat file_stat;
        stat(buffer, &file_stat);

        // Add entry to file_entries.
        strcpy(file_entries[*num_entries].filename, buffer);
        file_entries[*num_entries].filesize = file_stat.st_size;
        file_entries[*num_entries].modified_time = file_stat.st_mtime;

        (*num_entries)++;
    }

    fclose(fp);
}

void backup_files(struct file_entry* file_entries, int num_entries) {
    int i;
    FILE* source_file;
    FILE* backup_file;
    char backup_filename[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];

    for (i = 0; i < num_entries; i++) {
        // Create backup filename.
        create_backup_filename(backup_filename, file_entries[i].filename);

        // Open the source file.
        source_file = fopen(file_entries[i].filename, "r");

        // Open the backup file.
        backup_file = fopen(backup_filename, "w");

        // Copy the contents of the source file to the backup file.
        while (fgets(buffer, sizeof(buffer), source_file)) {
            fputs(buffer, backup_file);
        }

        // Close files.
        fclose(source_file);
        fclose(backup_file);
    }
}

void create_backup_filename(char* backup_file, char* filename) {
    time_t current_time;
    struct tm* time_info;
    char timestamp[BUFFER_SIZE];

    // Get current time.
    time(&current_time);
    time_info = localtime(&current_time);

    // Format timestamp.
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H-%M-%S", time_info);

    // Create backup filename.
    sprintf(backup_file, "%s/%s.backup.%s", BACKUP_FOLDER_NAME, filename, timestamp);
}