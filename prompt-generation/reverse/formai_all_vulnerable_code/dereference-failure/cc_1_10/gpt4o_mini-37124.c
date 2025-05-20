//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILENAME_LEN 256
#define MAX_BACKUP_LEN 12

void get_current_timestamp(char *timestamp) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(timestamp, 20, "%Y%m%d_%H%M%S", tm_info);
}

void backup_file(const char *source_file) {
    struct stat file_stat;
    if (stat(source_file, &file_stat) != 0) {
        perror("Stat failed on source file");
        return;
    }
    
    if (!S_ISREG(file_stat.st_mode)) {
        fprintf(stderr, "Error: %s is not a regular file!\n", source_file);
        return;
    }

    char timestamp[20];
    get_current_timestamp(timestamp);
    
    char backup_file_name[MAX_FILENAME_LEN];
    snprintf(backup_file_name, MAX_FILENAME_LEN, "%s_backup_%s", source_file, timestamp);
    
    FILE *source = fopen(source_file, "rb");
    if (!source) {
        perror("Error opening source file");
        return;
    }

    FILE *backup = fopen(backup_file_name, "wb");
    if (!backup) {
        perror("Error creating backup file");
        fclose(source);
        return;
    }

    const size_t buffer_size = 1024;
    char buffer[buffer_size];
    size_t bytes_read;

    printf("Backing up %s as %s...\n", source_file, backup_file_name);
    while ((bytes_read = fread(buffer, 1, buffer_size, source)) > 0) {
        fwrite(buffer, 1, bytes_read, backup);
    }

    fclose(source);
    fclose(backup);
    printf("Backup completed successfully: %s\n", backup_file_name);
}

void restore_file(const char *backup_file) {
    FILE *backup = fopen(backup_file, "rb");
    if (!backup) {
        perror("Error opening backup file");
        return;
    }
    
    char original_file_name[MAX_FILENAME_LEN];
    snprintf(original_file_name, MAX_FILENAME_LEN, "restored_%s", backup_file);
    
    FILE *restored = fopen(original_file_name, "wb");
    if (!restored) {
        perror("Error creating restored file");
        fclose(backup);
        return;
    }

    const size_t buffer_size = 1024;
    char buffer[buffer_size];
    size_t bytes_read;

    printf("Restoring backup from %s to %s...\n", backup_file, original_file_name);
    while ((bytes_read = fread(buffer, 1, buffer_size, backup)) > 0) {
        fwrite(buffer, 1, bytes_read, restored);
    }

    fclose(backup);
    fclose(restored);
    printf("Restoration completed successfully: %s\n", original_file_name);
}

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <backup|restore> <file>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *operation = argv[1];
    char *file_name = argv[2];

    if (strcmp(operation, "backup") == 0) {
        backup_file(file_name);
    } else if (strcmp(operation, "restore") == 0) {
        restore_file(file_name);
    } else {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}