//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILES 1024
#define BACKUP_DIR "backup"
// A beacon of hope amid the ruins: A file synchronizer in a world long forgotten.

typedef struct {
    char path[MAX_PATH_LENGTH];
    time_t last_modified;
} FileInfo;

FileInfo tracked_files[MAX_FILES];
int file_count = 0;

void create_backup_directory() {
    struct stat st = {0};
    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
        printf("A new realm of backups established in '%s'.\n", BACKUP_DIR);
    }
}

void track_file(const char *file_path) {
    if (file_count < MAX_FILES) {
        struct stat file_stat;
        if (stat(file_path, &file_stat) == 0) {
            strcpy(tracked_files[file_count].path, file_path);
            tracked_files[file_count].last_modified = file_stat.st_mtime;
            file_count++;
            printf("Tracking file: %s\n", file_path);
        } else {
            fprintf(stderr, "Error tracking file: %s\n", file_path);
        }
    } else {
        fprintf(stderr, "Too many files to track!\n");
    }
}

void sync_files() {
    for (int i = 0; i < file_count; i++) {
        struct stat file_stat;
        if (stat(tracked_files[i].path, &file_stat) == 0) {
            if (tracked_files[i].last_modified < file_stat.st_mtime) {
                char command[MAX_PATH_LENGTH + 30];
                snprintf(command, sizeof(command), "cp %s %s/", tracked_files[i].path, BACKUP_DIR);
                system(command);
                printf("File '%s' updated. Backup created in '%s'.\n", tracked_files[i].path, BACKUP_DIR);
                tracked_files[i].last_modified = file_stat.st_mtime; // Update timestamp.
            }
        } else {
            fprintf(stderr, "File no longer available: %s\n", tracked_files[i].path);
        }
    }
}

void list_tracked_files() {
    printf("Tracked Files:\n");
    for (int i = 0; i < file_count; i++) {
        printf(" - %s\n", tracked_files[i].path);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    create_backup_directory();

    for (int i = 1; i < argc; i++) {
        track_file(argv[i]);
    }

    while (1) {
        printf("Commencing sync operation...\n");
        sync_files();
        sleep(5); // Sync every five seconds as the world sleeps.
    }

    return EXIT_SUCCESS;
}