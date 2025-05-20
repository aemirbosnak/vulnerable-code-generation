//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define FILE_NAME_LEN 100
#define BACKUP_DIR "backups/"

typedef struct {
    char name[FILE_NAME_LEN];
    char backup[FILE_NAME_LEN];
    time_t last_modified;
} FileInfo;

FileInfo files[MAX_FILES];
int num_files = 0;

void createBackup(char *file_name) {
    FILE *src, *dst;
    char src_file[FILE_NAME_LEN], dst_file[FILE_NAME_LEN];
    int i;

    strcpy(src_file, file_name);
    strcpy(dst_file, BACKUP_DIR);
    strcat(dst_file, src_file);

    if ((src = fopen(src_file, "rb")) == NULL) {
        printf("Error: Unable to open file %s for reading!\n", src_file);
        return;
    }

    if ((dst = fopen(dst_file, "wb")) == NULL) {
        printf("Error: Unable to open file %s for writing!\n", dst_file);
        fclose(src);
        return;
    }

    while (!feof(src)) {
        size_t bytes_read = fread(dst, 1, 1024, src);
        if (ferror(src)) {
            printf("Error: Failed to read file %s!\n", src_file);
            fclose(src);
            fclose(dst);
            return;
        }
    }

    fclose(src);
    fclose(dst);

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, src_file) == 0) {
            strcpy(files[i].backup, dst_file);
            printf("Backup created for %s: %s\n", src_file, dst_file);
            return;
        }
    }

    if (num_files < MAX_FILES) {
        strcpy(files[num_files].name, src_file);
        strcpy(files[num_files].backup, dst_file);
        num_files++;
    } else {
        printf("Error: Maximum number of files reached!\n");
    }
}

void listBackups() {
    int i;

    printf("\nListing backups:\n");
    for (i = 0; i < num_files; i++) {
        printf("%s -> %s\n", files[i].name, files[i].backup);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [file_name]\n", argv[0]);
        return 1;
    }

    createBackup(argv[1]);
    listBackups();

    return 0;
}