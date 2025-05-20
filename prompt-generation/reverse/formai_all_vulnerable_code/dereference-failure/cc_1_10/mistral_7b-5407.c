//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BACKUP_DIR "backups/"
#define MAX_FILE_NAME 100

void create_backup(const char *file_path);
void get_timestamp(char *timestamp);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    create_backup(argv[1]);
    printf("Backup created successfully.\n");
    return 0;
}

void create_backup(const char *file_path) {
    char timestamp[20];
    char backup_file_path[MAX_FILE_NAME];
    FILE *src_file, *dest_file;

    strcpy(backup_file_path, BACKUP_DIR);
    strcat(backup_file_path, file_path);
    strcat(backup_file_path, "_backup.");
    get_timestamp(timestamp);
    strcat(backup_file_path, timestamp);

    src_file = fopen(file_path, "rb");
    if (src_file == NULL) {
        perror("Error opening source file.");
        return;
    }

    dest_file = fopen(backup_file_path, "wb");
    if (dest_file == NULL) {
        perror("Error creating backup file.");
        fclose(src_file);
        return;
    }

    while (!feof(src_file)) {
        int read_bytes = fread(dest_file, 1, 1024, src_file);
        if (read_bytes <= 0) {
            break;
        }
    }

    fclose(src_file);
    fclose(dest_file);
}

void get_timestamp(char *timestamp) {
    time_t rawtime;
    struct tm *timeinfo;

    char *dt;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H-%M-%S", timeinfo);

    dt = strrchr(timestamp, ' ');
    if (dt != NULL) {
        *dt = '\0';
    }
}