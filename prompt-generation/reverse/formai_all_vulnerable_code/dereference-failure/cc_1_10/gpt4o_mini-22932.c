//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>

#define FILE_PATH_MAX 256
#define BACKUP_DIR "backups/"
#define TIMESTAMP_FORMAT "%Y%m%d%H%M%S"

void create_backup_directory() {
    struct stat st = {0};
    
    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
    }
}

void get_current_timestamp(char *buffer, size_t size) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    strftime(buffer, size, TIMESTAMP_FORMAT, &tm);
}

void surreal_backup(const char *file_to_backup) {
    char timestamp[20];
    get_current_timestamp(timestamp, sizeof(timestamp));

    char backup_file[FILE_PATH_MAX];
    snprintf(backup_file, sizeof(backup_file), "%s%s_%s.bak", BACKUP_DIR, file_to_backup, timestamp);
    
    FILE *original = fopen(file_to_backup, "rb");
    if (original == NULL) {
        printf("The dreams of %s are shattered. Cannot open.\n", file_to_backup);
        return;
    }
    
    FILE *backup = fopen(backup_file, "wb");
    if (backup == NULL) {
        printf("Constructing a backup spaceship failed...\n");
        fclose(original);
        return;
    }

    char buffer[4096];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), original)) > 0) {
        fwrite(buffer, 1, bytes_read, backup);
    }

    printf("A surreal symphony: The stars have aligned and %s has been backed up as %s.\n", file_to_backup, backup_file);

    fclose(original);
    fclose(backup);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("A whisper in the void: No file is provided to backup!\n");
        return EXIT_FAILURE;
    }

    create_backup_directory();

    for (int i = 1; i < argc; i++) {
        surreal_backup(argv[i]);
    }

    printf("As the evening sun sets over the horizon of code, the backups swell with tales untold.\n");
    return EXIT_SUCCESS;
}