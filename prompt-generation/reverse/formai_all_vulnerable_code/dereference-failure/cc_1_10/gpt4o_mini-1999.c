//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_FILENAME 256
#define RECOVERY_DIR "./recovered_files"

void create_recovery_directory() {
    struct stat st = {0};
    if (stat(RECOVERY_DIR, &st) == -1) {
        mkdir(RECOVERY_DIR, 0700);
        printf("Recovery directory created: %s\n", RECOVERY_DIR);
    } else {
        printf("Recovery directory already exists: %s\n", RECOVERY_DIR);
    }
}

void recover_file(const char *filename) {
    char source_path[MAX_FILENAME];
    char destination_path[MAX_FILENAME];

    snprintf(source_path, sizeof(source_path), "./%s", filename);
    snprintf(destination_path, sizeof(destination_path), "%s/%s", RECOVERY_DIR, filename);

    if (access(source_path, F_OK) != -1) {
        printf("File already exists, skipping recovery: %s\n", source_path);
        return;
    }

    if (rename(source_path, destination_path) == 0) {
        printf("Recovered file: %s -> %s\n", source_path, destination_path);
    } else {
        printf("Failed to recover file: %s\n", filename);
    }
}

void scan_directory() {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(".")) != NULL) {
        printf("Scanning current directory for deletions...\n");
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) { // Regular file
                printf("Found file: %s\n", ent->d_name);
                recover_file(ent->d_name);
            }
        }
        closedir(dir);
    } else {
        perror("Could not open current directory");
    }
}

void show_instructions() {
    printf("Welcome to the Simple C Data Recovery Tool!\n");
    printf("This tool scans the current directory and attempts to recover deleted files.\n");
    printf("All recovered files will be placed in the 'recovered_files' directory.\n\n");
}

int main() {
    show_instructions();
    create_recovery_directory();
    scan_directory();

    printf("Data recovery process completed. Check the '%s' directory for any recovered files.\n", RECOVERY_DIR);
    return 0;
}