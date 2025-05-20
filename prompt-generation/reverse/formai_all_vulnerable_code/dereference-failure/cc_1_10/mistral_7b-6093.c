//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 100
#define BACKUP_DIR "backups/"

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char path[MAX_FILE_NAME_LENGTH];
    time_t last_modified;
} FileInfo;

FileInfo files[MAX_FILES];
int num_files = 0;

void createBackup(const char *path) {
    FILE *src, *dst;
    char src_file[MAX_FILE_NAME_LENGTH], dst_file[MAX_FILE_NAME_LENGTH];
    int i;

    strcpy(src_file, path);
    strcpy(dst_file, BACKUP_DIR);
    strcat(dst_file, src_file);

    if ((src = fopen(path, "rb")) == NULL) {
        perror("Error opening file for backup");
        return;
    }

    if (mkdir(BACKUP_DIR, 0755) == -1) {
        perror("Error creating backup directory");
        fclose(src);
        return;
    }

    if ((dst = fopen(dst_file, "wb")) == NULL) {
        perror("Error creating backup file");
        fclose(src);
        rmdir(BACKUP_DIR);
        return;
    }

    while (!feof(src)) {
        size_t bytes_read = fread(dst, 1, 1024, src);
        fwrite(dst, 1, bytes_read, dst);
    }

    fclose(src);
    fclose(dst);

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].path, src_file) == 0) {
            files[i].last_modified = time(NULL);
            break;
        }
    }

    if (i == num_files) {
        strcpy(files[num_files].name, src_file);
        strcpy(files[num_files].path, path);
        files[num_files].last_modified = time(NULL);
        num_files++;
    }

    printf("File '%s' backed up successfully.\n", src_file);

    remove(src_file);
    rmdir(dst_file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path_to_file>\n", argv[0]);
        return 1;
    }

    createBackup(argv[1]);

    return 0;
}