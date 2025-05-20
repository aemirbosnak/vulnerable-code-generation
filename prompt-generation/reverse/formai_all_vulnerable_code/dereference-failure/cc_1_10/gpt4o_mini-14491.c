//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_PATH 256
#define BACKUP_DIR "neon_backups"

void create_backup_directory() {
    struct stat st = {0};
    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
        printf("🌌 New backup directory created: %s\n", BACKUP_DIR);
    }
}

void get_timestamp(char *buffer, size_t len) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, len, "%Y-%m-%d_%H-%M-%S", t);
}

void backup_file(const char *filename) {
    char timestamp[20];
    get_timestamp(timestamp, sizeof(timestamp));

    char backup_filename[MAX_PATH];
    snprintf(backup_filename, sizeof(backup_filename), "%s/%s_%s.bak", BACKUP_DIR, filename, timestamp);

    FILE *source_file = fopen(filename, "rb");
    if (!source_file) {
        fprintf(stderr, "🚨 Error: Unable to open file: %s\n", filename);
        return;
    }

    FILE *backup_file = fopen(backup_filename, "wb");
    if (!backup_file) {
        fprintf(stderr, "🚨 Error: Unable to create backup file: %s\n", backup_filename);
        fclose(source_file);
        return;
    }

    char buffer[1024];
    size_t size;
    while ((size = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, size, backup_file);
    }

    printf("🔒 Backup created: %s to %s\n", filename, backup_filename);
    
    fclose(source_file);
    fclose(backup_file);
}

void list_files_in_directory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        fprintf(stderr, "🚨 Error: Unable to open directory: %s\n", directory);
        return;
    }

    printf("📂 Files in directory '%s':\n", directory);
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            printf(" - %s\n", entry->d_name);
        }
    }
    closedir(dp);
}

int main() {
    char cwd[MAX_PATH];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("🌆 Current working directory: %s\n", cwd);
    } else {
        perror("🚨 Error getting current directory");
        return EXIT_FAILURE;
    }

    create_backup_directory();
    list_files_in_directory(cwd);

    char filename[MAX_PATH];
    printf("🗄️ Enter the file name to backup (or 'exit' to quit): ");
    while (fgets(filename, sizeof(filename), stdin)) {
        // Remove newline character
        filename[strcspn(filename, "\n")] = 0;

        if (strcmp(filename, "exit") == 0) {
            break;
        }

        backup_file(filename);
        printf("🗄️ Enter the file name to backup (or 'exit' to quit): ");
    }

    printf("🌌 Program terminated. Stay safe in the neon city...\n");
    return EXIT_SUCCESS;
}