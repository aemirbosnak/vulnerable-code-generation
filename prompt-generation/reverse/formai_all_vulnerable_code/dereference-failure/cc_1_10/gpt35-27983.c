//FormAI DATASET v1.0 Category: File Backup System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

// This function creates a new directory.
void create_directory(const char* name) {
    mkdir(name, 0777);
}

// This function creates a unique backup directory name with the date and time.
void create_backup_directory(const char* source_path, char* backup_dir) {
    char new_directory[100] = "backup-";
    char datetime_str[20];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(datetime_str, sizeof(datetime_str), "%Y-%m-%d_%H-%M-%S", tm);
    sprintf(backup_dir, "%s%s_%s", source_path, new_directory, datetime_str);
}

// This function compresses the file to be backed up.
void compress_file(const char* file_path, const char* backup_dir) {
    char command[100];
    sprintf(command, "gzip -c %s > %s/%s.gz", file_path, backup_dir, file_path);
    system(command);
}

// This function decompresses the file to be restored.
void decompress_file(const char* file_path, const char* output_dir) {
    char command[100];
    sprintf(command, "gunzip -c %s > %s/%s", file_path, output_dir, file_path);
    system(command);
}

// This function backs up the file.
void backup_file(const char* file_path, const char* backup_dir) {
    compress_file(file_path, backup_dir);
}

// This function restores the file.
void restore_file(const char* file_path, const char* backup_path) {
    decompress_file(file_path, backup_path);
}

// This function backs up all the files in a directory.
void backup_directory(const char* source_dir, const char* backup_dir) {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(source_dir)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            // Ignore special directories . and ..
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                char file_path[100];
                sprintf(file_path, "%s/%s", source_dir, ent->d_name);
                backup_file(file_path, backup_dir);
            }
        }
        closedir(dir);
    }
}

int main() {
    const char* source_dir = "/path/to/source/dir";
    char backup_dir[100];
    create_backup_directory(source_dir, backup_dir);

    create_directory(backup_dir);
    backup_directory(source_dir, backup_dir);

    const char* file_path = "/path/to/source/dir/file.txt.gz";
    const char* backup_path = "/path/to/backup/dir/backup-2022-03-19_11-00-00";
    restore_file(file_path, backup_path);

    return 0;
}