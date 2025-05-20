//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 1000
#define MAX_BACKUP_FILES 100

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char backup_file_name[MAX_FILE_NAME_LEN];
    int num_backups;
} FileBackup;

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <file_name> <num_backups>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    int num_backups = atoi(argv[2]);

    FileBackup *backup_files = malloc(sizeof(FileBackup) * num_backups);

    for (int i = 0; i < num_backups; i++) {
        backup_files[i].num_backups = num_backups;
        strcpy(backup_files[i].file_name, file_name);
        sprintf(backup_files[i].backup_file_name, "%s.%d", file_name, i + 1);
    }

    for (int i = 0; i < num_backups; i++) {
        FILE *src_file = fopen(file_name, "rb");
        FILE *dst_file = fopen(backup_files[i].backup_file_name, "wb");

        if (src_file == NULL || dst_file == NULL) {
            printf("Error: Failed to open file.\n");
            return 1;
        }

        char buffer[1024];
        int bytes_read;

        while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
            fwrite(buffer, 1, bytes_read, dst_file);
        }

        fclose(src_file);
        fclose(dst_file);
    }

    free(backup_files);

    return 0;
}