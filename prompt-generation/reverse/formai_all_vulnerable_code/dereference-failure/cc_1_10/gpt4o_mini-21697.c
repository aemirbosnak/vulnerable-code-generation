//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILENAME 256
#define BACKUP_DIR "backup/"

void create_backup_directory() {
    struct stat st;
    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
    }
}

void backup_file(const char *filename) {
    char command[MAX_FILENAME * 2];
    snprintf(command, sizeof(command), "cp %s %s%s.bak", filename, BACKUP_DIR, filename);
    system(command);
}

void list_files_in_directory(const char *directory) {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(directory)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) { // Only process regular files
                printf("Found file: %s\n", ent->d_name);
                backup_file(ent->d_name);
            }
        }
        closedir(dir);
    } else {
        perror("Failed to open directory");
    }
}

void remove_backup_files() {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(BACKUP_DIR)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) { // Only process regular files
                char filepath[MAX_FILENAME];
                snprintf(filepath, sizeof(filepath), "%s%s", BACKUP_DIR, ent->d_name);
                remove(filepath);
                printf("Removed backup file: %s\n", filepath);
            }
        }
        closedir(dir);
    } else {
        perror("Failed to open backup directory");
    }
}

void print_usage() {
    printf("Usage:\n");
    printf("  ./backup_system <directory_to_backup>\n");
    printf("  ./backup_system -r  // to remove all backup files\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-r") == 0) {
        remove_backup_files();
        return EXIT_SUCCESS;
    }

    char *target_directory = argv[1];
    create_backup_directory();
    list_files_in_directory(target_directory);

    printf("Backup process completed.\n");

    return EXIT_SUCCESS;
}