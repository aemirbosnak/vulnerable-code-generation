//FormAI DATASET v1.0 Category: File Backup System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_FILES 1000

void backup(char *filename, char *backup_folder);
void create_backup_folder(char *backup_folder);
void delete_old_backups(char *backup_folder);
int get_file_number(char *backup_folder);
char *get_timestamp();

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./backup [filename]\n");
        return 0;
    }

    char *filename = argv[1];
    char backup_folder[MAX_FILE_NAME_LEN] = "backup";
    create_backup_folder(backup_folder);
    delete_old_backups(backup_folder);
    backup(filename, backup_folder);

    return 0;
}

// Writes a backup of the file with given filename to the given backup folder.
void backup(char *filename, char *backup_folder) {
    FILE *src_file = fopen(filename, "rb");
    if (src_file == NULL) {
        printf("Unable to open file: %s\n", filename);
        return;
    }

    char backup_filename[MAX_FILE_NAME_LEN];
    sprintf(backup_filename, "%s/%s_%s", backup_folder, filename, get_timestamp());

    FILE *dst_file = fopen(backup_filename, "wb");
    if (dst_file == NULL) {
        printf("Unable to create backup file: %s\n", backup_filename);
        fclose(src_file);
        return;
    }

    int c;
    while ((c = fgetc(src_file)) != EOF) {
        fputc(c, dst_file);
    }

    printf("Successfully created backup file: %s\n", backup_filename);
    fclose(src_file);
    fclose(dst_file);
}

// Creates a backup folder if it does not already exist.
void create_backup_folder(char *backup_folder) {
    DIR *dir = opendir(backup_folder);

    if (dir) {
        printf("Backup folder already exists: %s/\n", backup_folder);
        closedir(dir);
    } else if (mkdir(backup_folder, 0777) == -1) {
        printf("Unable to create backup folder: %s/\n", backup_folder);
        exit(1);
    } else {
        printf("Successfully created backup folder: %s/\n", backup_folder);
    }
}

// Deletes old backup files from the backup folder.
void delete_old_backups(char *backup_folder) {
    int max_files = MAX_FILES - 1;
    int num_files = get_file_number(backup_folder);

    if (num_files <= max_files) {
        printf("No old files to delete.\n");
        return;
    }

    DIR *dir = opendir(backup_folder);
    if (dir) {
        struct dirent *entry;
        int count = 0;
        while ((entry = readdir(dir)) != NULL && count < num_files - max_files) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char filename[MAX_FILE_NAME_LEN];
                sprintf(filename, "%s/%s", backup_folder, entry->d_name);
                remove(filename);
                printf("Successfully deleted backup file: %s\n", filename);
                count++;
            }
        }
        closedir(dir);
    } else {
        printf("Unable to read backup folder: %s/\n", backup_folder);
        exit(1);
    }
}

// Returns the number of files in the given backup folder.
int get_file_number(char *backup_folder) {
    int num_files = 0;

    DIR *dir = opendir(backup_folder);
    if (dir) {
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                num_files++;
            }
        }
        closedir(dir);
    } else {
        printf("Unable to read backup folder: %s/\n", backup_folder);
        exit(1);
    }

    return num_files;
}

// Returns a timestamp in the format of yyyy-mm-dd_hh-mm-ss.
char *get_timestamp() {
    time_t now = time(NULL);
    struct tm *ptm = localtime(&now);

    static char timestamp[MAX_FILE_NAME_LEN];
    sprintf(timestamp, "%d-%02d-%02d_%02d-%02d-%02d",
            ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday,
            ptm->tm_hour, ptm->tm_min, ptm->tm_sec);

    return timestamp;
}